#include <iostream>
#include <algorithm>

using namespace std;

int num;
int arr[301];
int dp[301];

int main()
{
    cin >> num;
    for(int i = 1; i <= num; i++){
        cin >> arr[i];
    }
    dp[0] = 0;
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    dp[3] = max(arr[2] + arr[3], arr[1] + arr[3]);

    for(int i = 4; i <= num; i++){
        dp[i] = max(dp[i-2] + arr[i], dp[i-3] + arr[i-1] + arr[i]);
    }
    cout << dp[num];
    return 0;
}