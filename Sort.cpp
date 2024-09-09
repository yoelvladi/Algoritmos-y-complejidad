#include <bits/stdc++.h>
#include <chrono>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


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
    sort(arr.begin(),arr.end());
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