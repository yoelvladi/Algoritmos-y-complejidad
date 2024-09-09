#include <iostream>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <vector>
using namespace std;

// Función para fusionar dos subarreglos de arr[].
// El primer subarreglo es arr[left..mid]
// El segundo subarreglo es arr[mid+1..right]
void merge(vector<int>& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1; // Tamaño del primer subarreglo
    int n2 = right - mid;    // Tamaño del segundo subarreglo

    // Crear vectores temporales
    vector<int> L(n1), R(n2);

    // Copiar datos a los vectores temporales L[] y R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    // Fusionar los vectores temporales de nuevo
    // en arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de L[], si los hay
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R[], si los hay
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// La función mergeSort divide el array en dos subarrays,
// los ordena de forma recursiva y luego los fusiona.
void mergeSort(vector<int>& arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);           // Ordenar la primera mitad
    mergeSort(arr, mid + 1, right);      // Ordenar la segunda mitad
    merge(arr, left, mid, right);        // Fusionar las dos mitades
}

// Función para imprimir un vector
void printVector(vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
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

// Código principal
int main()
{
    string filename = "numeros_semi_ordenados.txt"; // Nombre del archivo
    vector<int> arr = readNumbersFromFile(filename); // Leer los números desde el archivo

    if (arr.empty()) {
        cout << "No se encontraron números en el archivo." << endl;
        return 1;
    }

    int n = arr.size(); // Obtener el tamaño del vector

    auto start = chrono::high_resolution_clock::now();    
    mergeSort(arr, 0, n - 1); // Ordenar el vector usando mergeSort
    auto end = chrono::high_resolution_clock::now();
    auto elapsed_time = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    cout << "Tiempo de ejecucion: " << elapsed_time << " milisegundos" << endl;    
    cout << "\nEl vector ordenado es \n";
    //printVector(arr); // Imprimir el vector ordenado
    return 0;
}
