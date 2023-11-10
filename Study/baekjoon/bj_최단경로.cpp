#include <iostream>
#include <vector>
#include <queue>

#define INF 1000000      
#define MAX_VERTEX 20001 
#define MAX_EDGE 300001  

using namespace std;

int dist[MAX_VERTEX];
vector<pair<int,int>> edge[MAX_EDGE];

void dijkstra(int start_node){
    dist[start_node] = 0; //자기자신은 0
    priority_queue<pair<int, int>> pq; // pair<비용, 도착 노드> 형식의 우선 순위 큐이다.
    pq.push(make_pair(0,start_node));
    while(!pq.empty()){
        int current = pq.top().second;
        int cur_dis = -pq.top().first; // 비용은 음수화되어있는 상태이므로, 양수화해서 사용한다.
        pq.pop();
        if(dist[current] < cur_dis)
            continue;
        for(int i =0; i < edge[current].size(); i++){
            int next = edge[current][i].second;
            int n_dis = edge[current][i].first + cur_dis; //시작부터 해당 노드까지 거리 
            if(dist[next] > n_dis){
                dist[next] = n_dis;
                pq.push(make_pair(-n_dis, next)); //비용 음수화 
            }
        }
    }
}

int main()
{
    int v, e;
    cin >> v >> e;

    int start_node;
    cin >> start_node;

    for (int i = 1; i < v + 1; ++i)
    {
        dist[i] = INF;
    }

    for (int i = 0; i < e; ++i)
    {

        // 시작 노드, 도착 노드, 비용 입력
        int start, end, cost;
        cin >> start >> end >> cost;

        // 시작 노드에 따른 <비용, 도착 노드> 저장
        edge[start].push_back(make_pair(cost, end));
    }

    dijkstra(start_node);

    for (int i = 1; i < v + 1; ++i)
    {
        if (dist[i] == INF)
        {
            cout << "INF"
                 << " ";
        }
        else
        {
            cout << dist[i] << " ";
        }
    }

    return 0;
}
