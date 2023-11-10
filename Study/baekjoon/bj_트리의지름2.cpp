#include <iostream>
#include <vector>
#include <cstring>
#define MAX 100001

using namespace std;

vector<pair<int, int>> vec[MAX];
int dist[MAX];
bool visited[MAX];


void DFS(int node, int cur_dist){
    visited[node] = true;
    dist[node] = cur_dist;
    for(int i =0; i < vec[node].size(); i++){
        int next = vec[node][i].first;
        int weight = vec[node][i].second;
        if(!visited[next])
            DFS(next, dist[node] + weight);
    }
}

int main()
{
    int V;
    cin >> V;
    int num;
    for(int i =0; i < V; i++){
        cin>> num;
        while(true){
            int a,b;
            cin >>a;
            if(a == -1)
                break;
            cin >> b;
            vec[num].push_back(make_pair(a,b));
        }
    }
    DFS(1,0);
    int max_node = 1;
    for(int i = 2; i <= V; i++){
        if(dist[i] > dist[max_node]){
            max_node = i;
        }
    }
    memset(visited, false, sizeof(visited));
    memset(dist, 0, sizeof(dist));
    DFS(max_node, 0);

    int max_dist = 0;
    for(int i =1; i <= V; i++){
        if(dist[i] > max_dist)
            max_dist = dist[i];
    }

    cout<<max_dist;

    return 0;
}