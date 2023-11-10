#include <iostream>
#include <algorithm>
#define MAX_N 1001

using namespace std;
int N;
int arr[MAX_N][3];

int main()
{
    arr[0][0] = 0;
    arr[0][1] = 0;
    arr[0][2] = 0;
    cin >> N;
    int num[3];
    for(int i =1; i <= N; i++){
        cin >> num[0] >> num[1] >> num[2];
        arr[i][0] = min(arr[i-1][1], arr[i-1][2]) + num[0];
        arr[i][1] = min(arr[i-1][0], arr[i-1][2]) + num[1];
        arr[i][2] = min(arr[i - 1][0], arr[i - 1][1]) + num[2];
    }
    cout << min({arr[N][0],arr[N][1], arr[N][2] });

    return 0;
}