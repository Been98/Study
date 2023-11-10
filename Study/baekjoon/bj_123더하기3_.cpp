#include <iostream>
#define MOD 1000000009
#define MAX_N 1000000
using namespace std;

int N, T;
long long dp[MAX_N + 1];


int main()
{
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2; 
    dp[3] = 4;
    dp[4] = 7;

    for(int i =5; i <= MAX_N; i++){
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % MOD;
    }

    cin >> T;
    for(int i =0;  i < T; i++){
        cin >> N;
        cout<<dp[N] <<'\n';
    }


    return 0;
}