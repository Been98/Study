#include <iostream>
#include <vector>
#include <queue>
#define MAX_VERTEX 1001
#define MAX_EDGE 10001
#define INF 100000000

using namespace std;

int N, M, X;
vector<pair<int,int>> vec[MAX_VERTEX];
int dist[MAX_VERTEX];
int min_dis;

void dijk(int start, int end)
{
    for (int i = 0; i < MAX_VERTEX; i++)
        dist[i] = INF;
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    while(!pq.empty()){
        int cur = pq.top().second;
        int cur_dist = pq.top().first;
        pq.pop();
        if(cur == end){
            min_dis = dist[cur];
            break;
        }
        for(int i =0; i < vec[cur].size(); i++){
            int next = vec[cur][i].first;
            int n_dis = vec[cur][i].second;
            if(dist[next] > n_dis + cur_dist){
                dist[next] = n_dis + cur_dist;
                pq.push({n_dis, next});
            }
        }
    }

}



int main()
{
    cin>> N >> M >> X;
    for(int i =0; i < M; i++){
        int a,b,c;
        cin >> a >> b>> c;
        vec[a].push_back({b,c});
    }
    int ans = 0;
    int ans1,ans2;
    for(int i =1; i <= N; i++){
        dijk(i,X);
        ans1 = min_dis;
        dijk(X,i);
        ans2 = min_dis;
        if(ans < ans1 + ans2)
            ans = ans1 + ans2;
    }    
    cout << ans << '\n';
    return 0;
}