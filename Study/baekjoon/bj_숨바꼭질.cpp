#include <iostream>
#include <queue>

using namespace std;

bool visited[200001];

void BFS(int start, int end){
    visited[start]= true;
    queue <pair<int, int>> q;
    q.push(make_pair(start, 0));
    while(!q.empty()){
        int next = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(next < 0 || next > 100001) continue;
        if(next == end){
            cout<<cnt;
            break;
        }
        if(!visited[next + 1]){
            visited[next+1] = true;
            q.push(make_pair(next+1, cnt+1));
        }
        if(!visited[next -1]){
            visited[next-1] = true;
            q.push(make_pair(next-1, cnt+1));
        }
        if(!visited[next*2]){
            visited[next*2] = true;
            q.push(make_pair(next*2, cnt+1));
        }
    }
}

int main()
{
    int n,k;
    cin >> n >> k;
    BFS(n,k);



    return 0;
}