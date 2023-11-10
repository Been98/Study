#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, x, y;
    cin>>N;
    vector<pair<int,int>> vec;
    vector<int> rank;
    for(int i =0; i < N; i++){
        cin >> x >> y;
        vec.push_back(make_pair(x,y));
    }

    for(int i =0; i < vec.size(); i++){
        int num = 1;
        for(int j = 0; j < vec.size(); j++){
            if(vec[i].first < vec[j].first && vec[i].second < vec[j].second){
                num++;
            }
        }
        rank.push_back(num);
    }
    for(auto i : rank){
        cout<<i <<" ";
    }

    return 0;
}