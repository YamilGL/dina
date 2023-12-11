#include <iostream>
#include <vector>

using namespace std;

string encontrarSubsecuenciaComun(const string& X, const string& Y) {
    int m = X.length();
    int n = Y.length();

    // Crear una tabla para almacenar las longitudes de las subsecuencias comunes
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Llenar la tabla utilizando el enfoque de programación dinámica
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Reconstruir la subsecuencia común a partir de la tabla
    int longitud = dp[m][n];
    string subsecuencia;

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            subsecuencia = X[i - 1] + subsecuencia;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return subsecuencia;
}

int main() {
    string X = "ABCBDAB";
    string Y = "BDCABA";

    string subsecuenciaComun = encontrarSubsecuenciaComun(X, Y);

    cout << "Subsecuencia Comun: " << subsecuenciaComun << endl;

    return 0;
}
