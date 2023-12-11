#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Estructura para representar un contenedor
struct Contenedor {
    int peso;

    Contenedor(int p) : peso(p) {}
};

// Función para comparar contenedores en función de su peso
bool compararContenedores(const Contenedor& c1, const Contenedor& c2) {
    return c1.peso > c2.peso;
}

// Algoritmo para maximizar el número de toneladas cargadas
int maximizarToneladas(const vector<Contenedor>& contenedores, int capacidadBuque) {
    int toneladasCargadas = 0;

    // Ordenar los contenedores por peso de forma descendente
    vector<Contenedor> contenedoresOrdenados = contenedores;
    sort(contenedoresOrdenados.begin(), contenedoresOrdenados.end(), compararContenedores);

    // Recorrer los contenedores y cargar tantas toneladas como sea posible
    for (const Contenedor& contenedor : contenedoresOrdenados) {
        if (contenedor.peso <= capacidadBuque) {
            toneladasCargadas += contenedor.peso;
            capacidadBuque -= contenedor.peso;
        }
    }

    return toneladasCargadas;
}

int main() {
    vector<Contenedor> contenedores = {{5}, {8}, {2}, {1}, {7}};
    int capacidadBuque = 15;

    int toneladasCargadas = maximizarToneladas(contenedores, capacidadBuque);

    cout << "Número máximo de toneladas cargadas: " << toneladasCargadas << endl;

    return 0;
}
