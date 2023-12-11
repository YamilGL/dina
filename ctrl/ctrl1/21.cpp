#include <iostream>
#include <vector>

using namespace std;

// Función para intercambiar dos elementos en un vector
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Función para dividir el vector en dos partes y devolver el índice del pivote
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Tomamos el último elemento como pivote
    int i = low - 1;  // Índice del elemento más pequeño

    for (int j = low; j <= high - 1; j++) {
        // Si el elemento actual es menor o igual al pivote
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;  // Devuelve el índice del pivote
}

// Función principal de Quicksort
void quicksort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Encuentra el índice del pivote
        int pivotIndex = partition(arr, low, high);

        // Ordena las dos sub-arrays alrededor del pivote
        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

int main() {
    vector<int> arr = {12, 7, 3, 1, 5, 9};

    cout << "Array original: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    int n = arr.size();
    quicksort(arr, 0, n - 1);

    cout << "Array ordenado: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
