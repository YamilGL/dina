#include<iostream>
#include<vector>

using namespace std;

int nivel;
vector<int> s;
int voa;
vector<int> soa;
int pact, bact;
vector<int> p={30,15,11,8,2};
vector<int> b={10,7,6,4,2};
int n = p.size();
int M = 20;
vector<int> sInicial(n, -1);

void Generar(int &nivel, vector<int>& s) {
    s[nivel] = s[nivel] + 1;
    pact = pact + p[nivel] * s[nivel];
    bact = bact + b[nivel] * s[nivel];
}

bool Solucion(int &nivel, vector<int>& s) {
    return ((nivel == n) && (pact <= M));
}

bool Criterio(int &nivel, vector<int>& s) {
    return ((nivel < n) && (pact <= M));
}

bool MasHermanos(int &nivel, vector<int>& s) {
    return (s[nivel] < 1);
}

void Retroceder(int& nivel, vector<int>& s) {
    pact = pact - p[nivel] * s[nivel];
    bact = bact - b[nivel] * s[nivel];
    s[nivel] = -1;
    nivel = nivel - 1;
}

void Backtracking(vector<int>& sInicial) {
    nivel = 0;
    s = sInicial;
    voa = -1;
    //soa
    pact = 0;
    bact = 0;
    n--;
    while (nivel > -1) {

        Generar(nivel, s);
        if (Solucion(nivel, s) && (bact > voa)) {
            voa = bact;
            soa = s;
        }
        if (Criterio(nivel, s)) {
            nivel++;
        }
        else
        {
            while ((!MasHermanos(nivel, s)) && (nivel > -1))
            {
                Retroceder(nivel, s);
            }
        }
    }
}


int main()
{
    Backtracking(sInicial);
    cout << "Mejor solucion: ";
    for (int i = 0; i < soa.size(); i++)
    {
        cout << soa[i] << " ";
    }
    cout << endl;

    return 0;
}



