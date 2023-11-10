#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int cnt = 99;
    
    if(N < 100){
        cout<< N;
        return 0;
    }
    for(int i = 100; i <= N; i++){
        int h = i / 100;
        int t = (i / 10) % 10;
        int o = i % 10;
        if((h - t) == (t - o))
            cnt++;
    }
    cout << cnt;
    return 0;
}