#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
using namespace std;

// Función para transponer una matriz
vector<vector<int>> TrasponerMatriz(const vector<vector<int>>& matriz, int filas, int columnas) {
    vector<vector<int>> traspuesta(columnas, vector<int>(filas, 0));
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            traspuesta[j][i] = matriz[i][j];
        }
    }
    return traspuesta;
}

int main() {
    ifstream archivo("numeros_matriz.txt");
    int filas1, columnas1, filas2, columnas2;
    vector<int> numeros;
    int numero;

    if (archivo.is_open()) {
        // Leer filas y columnas de la primera matriz
        archivo >> filas1 >> columnas1;

        // Leer filas y columnas de la segunda matriz
        archivo >> filas2 >> columnas2;

        // Verificar que la multiplicación de matrices sea posible
        if (columnas1 != filas2) {
            cerr << "Error: No se pueden multiplicar las matrices. Dimensiones incompatibles.\n";
            return 1;
        }

        // Leer los números y almacenarlos en un vector
        while (archivo >> numero) {
            numeros.push_back(numero);
        }
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo.\n";
        return 1;
    }

    // Inicializar las dos matrices
    vector<vector<int>> matriz1(filas1, vector<int>(columnas1));
    vector<vector<int>> matriz2(filas2, vector<int>(columnas2));

    // Asignar los números a las matrices
    int index = 0;
    for (int i = 0; i < filas1; i++) {
        for (int j = 0; j < columnas1; j++) {
            matriz1[i][j] = numeros[index++];
        }
    }
    for (int i = 0; i < filas2; i++) {
        for (int j = 0; j < columnas2; j++) {
            matriz2[i][j] = numeros[index++];
        }
    }

    // Transponer la segunda matriz
    //vector<vector<int>> matriz_T = TrasponerMatriz(matriz2, filas2, columnas2);

    // Inicializar la matriz resultado
    vector<vector<int>> matriz3(filas1, vector<int>(columnas2, 0));
    auto start = chrono::high_resolution_clock::now();     
    // Multiplicación de matrices
    for (int i = 0; i < filas1; ++i) {
        for (int j = 0; j < columnas2; ++j) {
            for (int k = 0; k < columnas1; ++k) {
                matriz3[i][j] += matriz1[i][k] * matriz2[j][k];
            }
        }
    }
    auto end = chrono::high_resolution_clock::now();   
    auto elapsed_time = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    cout << "Tiempo de ejecucion: " << elapsed_time << " milisegundos" << endl;    
    // Imprimir el resultado de matriz3
    cout << "Resultado de la multiplicación de matrices:\n";
    //for (int i = 0; i < filas1; ++i) {
      //  for (int j = 0; j < columnas2; ++j) {
        //    cout << matriz3[i][j] << " ";
        //}
        //cout << endl;
    //}

    return 0;
}
