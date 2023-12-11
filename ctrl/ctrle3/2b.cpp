#include <iostream>
#include <vector>

using namespace std;

int encontrarCoincidencia(const vector<int>& X, int inicio, int fin) {
    if (inicio > fin) {
        return -1; // No hay coincidencia en el rango actual
    }

    int medio = inicio + (fin - inicio) / 2;

    if (X[medio] == medio) {
        return medio; // Coincidencia encontrada en el índice medio
    } else if (X[medio] > medio) {
        // Buscar a la izquierda del medio
        return encontrarCoincidencia(X, inicio, medio - 1);
    } else {
        // Buscar a la derecha del medio
        return encontrarCoincidencia(X, medio + 1, fin);
    }
}

int encontrarCoincidencia(const vector<int>& X) {
    return encontrarCoincidencia(X, 0, X.size() - 1);
}

int main() {
    vector<int> X = {-10, -5, 1, 3, 7, 9, 12, 17}; // Ejemplo de vector ordenado

    int indiceCoincidencia = encontrarCoincidencia(X);

    if (indiceCoincidencia != -1) {
        cout << "Existe un indice i tal que X[i] = i. El valor de i es: " << indiceCoincidencia << endl;
    } else {
        cout << "No existe un indice i tal que X[i] = i." << endl;
    }

    return 0;
}
