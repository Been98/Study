#include <iostream>
#include <algorithm>
#define MAX 1001

using namespace std;
int N;
int dp[MAX];
int arr[MAX];

int main()
{
    cin >> N;
    for(int i =1; i <= N; i++)
        cin>>arr[i];
    for(int i =1; i <= N; i++)
        dp[i] = 1;
    for(int i =1; i <= N; i++){
        for(int j = 1; j < i; j++){
            if(arr[i] < arr[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    sort(dp, dp+N+1);
    cout<<dp[N];
    return 0;
}