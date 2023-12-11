#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, vector<int>> longest_increasing_subsequence(const vector<int>& sequence) {
    int n = sequence.size();
    vector<int> lis(n, 1);

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (sequence[i] > sequence[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }

    int max_length = *max_element(lis.begin(), lis.end());
    int last_index = distance(lis.begin(), find(lis.begin(), lis.end(), max_length));

    vector<int> subsequence;
    int current_length = max_length;
    for (int i = last_index; i >= 0; --i) {
        if (lis[i] == current_length) {
            subsequence.push_back(sequence[i]);
            current_length -= 1;
        }
    }

    return {max_length, subsequence};
}

int main() {
    vector<int> sequence;
    int num;

    int count = 8;
    while (count != 0) {
        cin >> num;
        sequence.push_back(num);
        count--;
    }
    
    pair<int, vector<int>> result = longest_increasing_subsequence(sequence);
    int length = result.first;
    vector<int> longestSubsequence = result.second;

    cout << length << endl;
    cout << "-" << endl;

    for (int i = 0; i < length; i++) {
        cout << longestSubsequence[i] << endl;
    }

    return 0;
}



//

#include <iostream>
#include <vector>

using namespace std;

int nivel;
vector<int> s;
vector<vector<int>> todasLasSoluciones;
vector<int> p = {30, 15, 11, 8, 2};
vector<int> b = {10, 7, 6, 4, 2};
int n = p.size();
int M = 20;
vector<int> sInicial(n, -1);

void Generar(int &nivel, vector<int> &s) {
    s[nivel] = s[nivel] + 1;
}

bool Solucion(int &nivel, vector<int> &s) {
    return nivel == n;
}

bool Criterio(int &nivel, vector<int> &s) {
    return nivel < n;
}

void Retroceder(int &nivel, vector<int> &s) {
    s[nivel] = -1;
    nivel = nivel - 1;
}

void Backtracking(vector<int> &sInicial) {
    nivel = 0;
    s = sInicial;
    todasLasSoluciones.push_back(s);

    while (nivel > -1) {
        Generar(nivel, s);
        todasLasSoluciones.push_back(s);

        if (Solucion(nivel, s)) {
            Retroceder(nivel, s);
        } else if (Criterio(nivel, s)) {
            nivel++;
        } else {
            while (nivel > -1) {
                Retroceder(nivel, s);
            }
        }
    }
}

int main() {
    Backtracking(sInicial);

    cout << "Todas las soluciones:" << endl;
    for (int i = 0; i < todasLasSoluciones.size(); i++) {
        for (int j = 0; j < todasLasSoluciones[i].size(); j++) {
            cout << todasLasSoluciones[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
