#include <iostream>
#include <vector>

using namespace std;

int knapsack(int W, const vector<int>& weights, const vector<int>& values) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    
    return dp[n][W];
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        vector<int> prices(N);
        vector<int> weights(N);
        
        for (int i = 0; i < N; i++) {
            cin >> prices[i] >> weights[i];
        }
        
        int G;
        cin >> G;
        
        int totalValue = 0;
        
        while (G--) {
            int MW;
            cin >> MW;
            
            totalValue += knapsack(MW, weights, prices);
        }
        
        cout << totalValue << endl;
    }
    
    return 0;
}