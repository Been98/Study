#include <iostream>
#include <map>

using namespace std;

int main()
{  
    int N, M;
    string s;
    int cnt = 0;
    map<string, bool> m;
    cin>> N >> M;
    for(int i =0; i < N; i++){
        cin>>s;
        m.insert(pair<string, bool>(s,true));
    }
    for(int i =0; i < M; i++){
        cin >> s;
        if(m[s] == true)
            cnt++;
    }
    cout<<cnt;
    return 0;
}