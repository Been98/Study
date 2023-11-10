#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[1001] = {false,};
vector<int> vec[1001];

void Dfs(int start){
    stack<int> stk;
    stk.push(start);
    while(!stk.empty()){
        int num = stk.top();
        stk.pop();
        if(visited[num])
            continue;
        visited[num] = true;
        cout<<num<<" ";
        for(int i = vec[num].size()-1; i >=0; i--){
            int next = vec[num][i];
            stk.push(next);
        }
    }
}
//재귀
void Dfs2(int start){
    visited[start] = true;
    cout<<start<<" ";
    for(int i =0; i < vec[start].size(); i++){
        int num = vec[start][i];
        if(!visited[num]){
            Dfs2(num);
        }
    }
}

void Bfs(int start){
    queue<int> que;
    que.push(start);
    visited[start] = true;
    while(!que.empty()){
        int num = que.front();
        que.pop();
        cout<<num<<" ";
        for(int i = 0;i < vec[num].size(); i++){
            int next = vec[num][i];
            if(!visited[next]){
                que.push(next);
                visited[next] = true;
            }
        }
    }
}

int main()
{
    int N, M, V; //N = 정점 수, M = 간선 수,V = 시작 정점
    cin>>N>>M>>V;
    int n1, n2;

    for(int i = 0; i < M; i++){
        cin>>n1>>n2;
        vec[n1].push_back(n2);
        vec[n2].push_back(n1);
    }
    for(int i =1; i<=N; i++){
        sort(vec[i].begin(), vec[i].end());
    }

    Dfs(V);
    cout<<"\n";
    for(int i = 0; i <= N; i++){
        visited[i] = false;
    }
    Bfs(V);
    return 0;
}