#include <iostream>
#include <vector>

using namespace std;

vector<int> dp(12, 0); 

void initializeDP() {
    dp[1] = 1; 
    dp[2] = 2; 
    dp[3] = 4; 
    for (int i = 4; i <= 11; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
}

int main() {
    int T;
    cin >> T;
    initializeDP();

    while (T--) {
        int N;
        cin >> N;
        cout << dp[N] << "\n"; 
    }

    return 0;
}