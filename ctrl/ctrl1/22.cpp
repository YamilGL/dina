#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Función para fusionar dos subvectores ordenados y eliminar duplicados
void mergeAndRemoveDuplicates(vector<int>& arr, int low, int mid, int high) {
    vector<int> merged;
    int i = low, j = mid + 1;

    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            merged.push_back(arr[i]);
            i++;
        } else if (arr[j] < arr[i]) {
            merged.push_back(arr[j]);
            j++;
        } else {
            // Si los elementos son iguales, solo añadir uno de ellos (eliminar duplicados)
            merged.push_back(arr[i]);
            i++;
            j++;
        }
    }

    // Añadir los elementos restantes de ambos subvectores
    while (i <= mid) {
        merged.push_back(arr[i]);
        i++;
    }

    while (j <= high) {
        merged.push_back(arr[j]);
        j++;
    }

    // Copiar el contenido ordenado y sin duplicados de vuelta al vector original
    for (int k = 0; k < merged.size(); k++) {
        arr[low + k] = merged[k];
    }
}

// Función principal de "divide y vencerás" para eliminar duplicados
void removeDuplicatesDivideAndConquer(vector<int>& arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;

        // Llamadas recursivas en ambas mitades
        removeDuplicatesDivideAndConquer(arr, low, mid);
        removeDuplicatesDivideAndConquer(arr, mid + 1, high);

        // Fusionar las dos mitades y eliminar duplicados
        mergeAndRemoveDuplicates(arr, low, mid, high);
    }
}

int main() {
    vector<int> arr = {3, 7, 2, 3, 7, 8, 1, 2, 8, 4, 5, 6, 9, 1};

    cout << "Vector original: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Ordenar y eliminar duplicados
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    cout << "Vector sin duplicados: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
