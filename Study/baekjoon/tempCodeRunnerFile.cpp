#include <iostream>
#include <vector>
#define MAX 51

using namespace std;

vector<int> vec[MAX];
bool visited[MAX];
int cnt;

void DFS(int node){
    int size = vec[node].size() == 0;
    visited[node] = true;
    if(size == 0){
        cnt++;
        return;
    }
    for(int i =0; i < vec[node].size(); i++){
        int child = vec[node][i];
        if(!visited[child]){
            DFS(child);
        }
    }

}

int main()
{
    int N, num, dNum;
    cin>>N;
    for(int i =0; i < N; i++){
        cin>>num;
        if(num == -1){
            continue;
        }
        vec[num].push_back(i);
    }
    cin>> dNum;
    for(int i =0; i< vec[dNum].size(); i++){
        vec[dNum].pop_back();
    }

    DFS(0);


    cout<<cnt;
    return 0;
}