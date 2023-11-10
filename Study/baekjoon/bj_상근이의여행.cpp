#include <iostream>
#include <vector>
#include <queue>
#define MAX 10001
#define MAX2 1001

using namespace std;

vector<int> vec[MAX];
bool visited[MAX2];
int answer = 0;

void BFS(int root, int cnt) {
    queue<int> q;
    q.push(root);
    visited[root] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int v : vec[cur]){
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
                answer++;
            }
        }
    }
}

int main()
{
    int T, N, M, a, b, num;
    cin>> T;
    for(int i =0; i < T; i++){
        cin>> N>> M;
        for(int j = 0; j < M; j++){
            cin >> a>>b;
            vec[a].push_back(b);
            vec[b].push_back(a);
        }
        BFS(1,0);
        cout<< answer<<"\n";
        answer = 0;
    }

    return 0;
}