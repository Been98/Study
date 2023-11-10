#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX_VERTEX 801
#define MAX_EDGE 200001
#define INF 987654321

using namespace std;

vector<pair<int,int>> vec[MAX_VERTEX];
int dist[MAX_VERTEX];
int n, e;


void dijk(int start)
{
    for(int i =0; i <= n; i++){
        dist[i] = INF;
    }
    dist[start] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, start});
    while(!pq.empty()){
        int cur = pq.top().second;
        int cur_dis = pq.top().first;
        pq.pop();
        for(int i =0; i < vec[cur].size(); i++){
            int next = vec[cur][i].first;
            int next_dis =  vec[cur][i].second;
            if(dist[next] > cur_dis + next_dis){
                dist[next] = cur_dis + next_dis;
                pq.push({dist[next], next});
            }
        }
    }

}


int main()
{

    cin >> n>> e;
    int a, b, c, v1,v2;
    int sTov1, sTov2, v1Tov2, v1Ton, v2Ton;
    for(int i =0; i < e; i++){
        cin>>a>>b>>c;
        vec[a].push_back({b,c});
        vec[b].push_back({a,c});
    }
    cin >> v1>> v2;
    dijk(1);
    sTov1 = dist[v1];
    sTov2 = dist[v2];

    dijk(v1);
    v1Tov2 = dist[v2];
    v1Ton = dist[n];

    dijk(v2);
    v2Ton = dist[n];

    int result = INF;

    result = min(result, sTov1 + v1Tov2 + v2Ton);
    result = min(result, sTov2 + v1Tov2 + v1Ton);

    if(v1Tov2 == INF || result == INF) cout<<-1;
    else cout<<result;
    return 0;
}