#include <iostream>
#include <vector>
#include <cstring>
#define MAX 10001

using namespace std;

vector<pair <int,int>> vec[MAX];
int dist[MAX];
bool visited[MAX];

void DFS(int node, int cur_dist){
    visited[node] = true;
    dist[node] = cur_dist;
    for(int i = 0; i < vec[node].size(); i++){
        int next = vec[node][i].first;
        int num = vec[node][i].second;
        if(!visited[next])
            DFS(next, dist[node] + num);
    }
}

int main()
{
    int n;
    cin >> n;
    int a,b,c;
    for(int i =0; i < n - 1; i++){
        cin>>a>>b>>c;
        vec[a].push_back(make_pair(b,c));
        vec[b].push_back(make_pair(a,c));
    }
    DFS(1,0);
    int max_node = 1;
    for(int i = 2; i <= n; i++){
        if(dist[i] > dist[max_node])
            max_node = i;
    }

    memset(visited, false, sizeof(visited));
    memset(dist, 0, sizeof(dist));
    DFS(max_node, 0);
    int max_dist = 0;
    for(int i = 1; i <= n; i++){
        if(dist[i] > max_dist){
            max_dist = dist[i];
        }
    }

    cout<<max_dist;
    return 0;
}