#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 101
using namespace std;


vector<int> vec[MAX];
int N, num;
void BFS(int node)
{
    int visited[MAX];
    memset(visited, 0, sizeof(visited));
    queue<int> que;
    que.push(node);
    while(!que.empty()){
        int start = que.front();
        que.pop();
        for(int i =0; i < N; i++){ 
            if(visited[i] == 0 && vec[start][i] == 1){
                visited[i] = 1;
                que.push(i);
            }
        }
    }
    for(int i =0; i < N; i++){
        cout<< visited[i]<<" ";
    }
    cout<<'\n';
}

int main()
{
    cin >> N;
    for(int i =0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> num;
            vec[i].push_back(num);
        }
    }
    for(int i =0; i < N; i++){
        BFS(i);
    }

    return 0;
}