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
    return c1.peso < c2.peso;
}

// Algoritmo para maximizar el número de contenedores cargados
int maximizarContenedores(const vector<Contenedor>& contenedores, int capacidadBuque) {
    int contenedoresCargados = 0;
    int capacidadRestante = capacidadBuque;

    // Ordenar los contenedores por peso de forma ascendente
    vector<Contenedor> contenedoresOrdenados = contenedores;
    sort(contenedoresOrdenados.begin(), contenedoresOrdenados.end(), compararContenedores);

    // Recorrer los contenedores y cargar tantos como sea posible
    for (const Contenedor& contenedor : contenedoresOrdenados) {
        if (contenedor.peso <= capacidadRestante) {
            contenedoresCargados++;
            capacidadRestante -= contenedor.peso;
        }
    }

    return contenedoresCargados;
}

int main() {
    vector<Contenedor> contenedores = {{5}, {8}, {2}, {1}, {7}};
    int capacidadBuque = 15;

    int contenedoresCargados = maximizarContenedores(contenedores, capacidadBuque);

    cout << "Número máximo de contenedores cargados: " << contenedoresCargados << endl;

    return 0;
}
