#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    unordered_map<int, int> ma;
    int n,m, num;
    cin>>n;
    for(int i =0; i < n;i++){
        cin>>num;
        ma[num]++;
    }

    cin>>m;
    for(int i=0; i < m; i++){
        cin>>num;
        cout<<ma[num]<<" ";
    }

    return 0;
}