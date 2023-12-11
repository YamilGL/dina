#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> longestIncreasingSubsequence(const vector<int>& sequence) {
    int n = sequence.size();
    vector<int> dp(n, 1);
    vector<int> prev(n, -1);
    int maxLength = 1;
    int endIndex = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (sequence[i] > sequence[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
                if (dp[i] > maxLength) {
                    maxLength = dp[i];
                    endIndex = i;
                }
            }
        }
    }

    vector<int> subsequence;
    while (endIndex != -1) {
    // Skip elements that are equal to the last element of the subsequence
    while (endIndex != -1 && subsequence.size() > 0 && sequence[endIndex] == subsequence.back()) {
        endIndex = prev[endIndex];
    }

    if (endIndex != -1) {
        subsequence.push_back(sequence[endIndex]);
        endIndex = prev[endIndex];
    }
}

    reverse(subsequence.begin(), subsequence.end());

    return subsequence;
}

int main() {
    vector<int> sequence;
    int num;

    //while (cin >> num) {
    //    sequence.push_back(num);
    //}

    int count = 8;
    while (count!=0) {
        cin >>num;
        sequence.push_back(num);
        count--;
    }

    vector<int> longestSubsequence = longestIncreasingSubsequence(sequence);
    int length = longestSubsequence.size();

    cout << length << endl;
    cout << "-" << endl;

    for (int i = 0; i < length; i++) {
        cout << longestSubsequence[i] << endl;
    }

    return 0;
}