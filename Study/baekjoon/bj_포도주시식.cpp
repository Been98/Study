#include <iostream>
#include <algorithm>
#define MAX_NUM 10001
using namespace std;
int n;
int DP[MAX_NUM];
int arr[MAX_NUM];

int main()
{
    cin >> n;
    for(int i =1; i <= n; i++)
        cin >> arr[i];
    
    DP[1] = arr[1];
    DP[2] = DP[1] + arr[2];

    for(int i =3; i <= n; i++){
        DP[i] = max({DP[i-1],DP[i-2] + arr[i],DP[i-3] + arr[i-1] + arr[i]});
    }
    cout << DP[n];


    return 0;
}