
//Selection sort, ordenando de menor a mayor
#include <iostream>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <vector>

using namespace std;

// Función para intercambiar a por b
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Función de ordenamiento por selección
void selectionSort(int array[], int size) {
    for (int step = 0; step < size - 1; step++) {
        int min_idx = step;
        for (int i = step + 1; i < size; i++) {
            // Selecciona el elemento más pequeño
            if (array[i] < array[min_idx]) {
                min_idx = i;
            }
        }
        // Pone el min en la posición correcta
        swap(&array[min_idx], &array[step]);
    }
}

// Función para mostrar por consola un array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// Función para leer números desde un archivo y almacenarlos en un vector
vector<int> readNumbersFromFile(const string &filename) {
    ifstream infile(filename);
    int number,sizes;
    infile >> sizes;
    vector<int> numbers(sizes);
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

// Código principal
int main() {
    string filename = "numeros.txt"; // Nombre del archivo
    vector<int> numbers = readNumbersFromFile(filename);

    if (numbers.empty()) {
        cout << "No se encontraron números en el archivo." << endl;
        return 1;
    }

    int size = numbers.size();
    int *data = numbers.data(); // Convierte el vector a un puntero de array

    auto start = chrono::high_resolution_clock::now();  
    selectionSort(data, size);
    auto end = chrono::high_resolution_clock::now();
    auto elapsed_time = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    cout << "Tiempo de ejecucion: " << elapsed_time/1000000 << " milisegundos" << endl;
    //cout << "Array en orden ascendente:\n";
    //printArray(data, size);

    return 0;
}
