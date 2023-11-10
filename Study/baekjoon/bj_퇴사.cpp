#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int,int>> vec;
int MaxPri = 0;

void DFS(int num, int price){
    if(num > N) return;
    MaxPri = max(MaxPri, price);
    for(int i =num; i < N; i++){
            DFS(i + vec[i].first, price + vec[i].second);
    }    
}

int main()
{
    cin>>N;
    int x,y;
    for(int i =0; i < N; i++){
        cin>>x>>y;
        vec.push_back(make_pair(x,y));
    }
    DFS(0, 0);

    cout<<MaxPri;
    return 0;
}