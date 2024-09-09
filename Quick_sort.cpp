#include <bits/stdc++.h>
#include <chrono>
#include <fstream>
#include <vector>

using namespace std;

// Función de partición que organiza el array 
// en dos partes con respecto a un pivote.
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Elige el pivote (último elemento en este caso)
    int i = low - 1; // Índice del elemento más pequeño

    // Recorre arr[low..high] y mueve todos los elementos 
    // más pequeños al lado izquierdo del pivote.
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]); // Intercambia los elementos para organizar
        }
    }

    // Mueve el pivote después de los elementos más pequeños
    swap(arr[i + 1], arr[high]);  
    return i + 1; // Retorna la posición del pivote
}

// Implementación de la función QuickSort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Índice de partición

        // Llamadas recursivas para los elementos menores y mayores
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Función para leer números desde un archivo y almacenarlos en un vector
vector<int> readNumbersFromFile(const string &filename) {
    vector<int> numbers;
    ifstream infile(filename);
    int number;

    if (infile.is_open()) {
        while (infile >> number) {
            numbers.push_back(number);
        }
        infile.close();
    } else {
        cout << "No se pudo abrir el archivo " << filename << endl;
    }

    return numbers;
}

int main() {
    string filename = "numeros_semi_ordenados.txt"; // Nombre del archivo
    vector<int> arr = readNumbersFromFile(filename); // Leer los números desde el archivo

    if (arr.empty()) {
        cout << "No se encontraron números en el archivo." << endl;
        return 1;
    }

    int n = arr.size(); // Obtiene el tamaño del vector

    auto start = chrono::high_resolution_clock::now();  
    quickSort(arr, 0, n - 1); // Ordenar el vector usando QuickSort
    auto end = chrono::high_resolution_clock::now();
    auto elapsed_time = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    cout << "Tiempo de ejecucion: " << elapsed_time << " milisegundos" << endl;

    //cout << "Array ordenado\n";
    //for (int i = 0; i < n; i++) {
      //  cout << arr[i] << " ";
    //}
    //cout << endl;

    return 0;
}

