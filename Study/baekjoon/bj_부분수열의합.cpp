#include <iostream>
#include <vector>

using namespace std;
int N, S;
int arr[20];
int cnt = 0;

void Func(int idx, int sum){
    if(idx == N){
        if(S==sum)
            cnt++;
        return;
    }
    Func(idx +1, sum);
    Func(idx+ 1, sum + arr[idx]);

}

int main()
{

    cin>> N >> S;
    for(int i =0; i < N; i++){
        cin >> arr[i];
    }
    Func(0, 0);
    if(S == 0) cnt--;

    cout << cnt;
    return 0; 
}
