#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;

    for(int i = 0; i < T; i++){
        int N,M, res = 1, tmp =1;
        cin >> N >> M;
        for(int j = M; j > M-N; j--){
            res = res * j;
            res = res / tmp++;
        }
        cout << res << "\n";

    }

    return 0;
}