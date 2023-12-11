#include <iostream>
#include <vector>

using namespace std;

int countWaysToMakeChange(int amount) {
    const int numCoins = 5;
    const int coinDenominations[] = {1, 5, 10, 25, 50};

    vector<int> ways(amount + 1, 0);
    ways[0] = 1;

    for (int i = 0; i < numCoins; i++) {
        for (int j = coinDenominations[i]; j <= amount; j++) {
            ways[j] += ways[j - coinDenominations[i]];
        }
    }

    return ways[amount];
}

int main() {
    int amount;

    while (cin >> amount) {
        int ways = countWaysToMakeChange(amount);
        cout << ways << endl;
    }

    return 0;
}
