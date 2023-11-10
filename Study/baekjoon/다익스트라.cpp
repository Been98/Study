#include <iostream>
#define INF 100000000
#define N 5
using namespace std;

int weight[N][N] = { //노드의 이동 비용 (간선) INF = 연결되지 않음
    {0, 7, 4, 6, 1},
    {INF, 0, INF, INF, INF},
    {INF, 2, 0, 5, INF},
    {INF, 3, INF, 0, INF},
    {INF, INF, INF,1,0}
    };

bool visit[N];
int dist[N];
int min_node;


//최소비용노드 탐색 함수
int get_small_node()
{
    int min = INF;
    int minpos = 0; //최소 비용 노드 저장 변수
    for(int i =0; i < N; i++){
        if(dist[i] < min && visit[i] == false) {
            min = dist[i];
            minpos = i;
        }
    }
    return minpos;
}

void dijkstra(int start){
    for(int i =0; i<N; i++){ //dist 초기화 
        dist[i] = weight[start][i];
    }
    visit[start] = true; 
    for(int repeat = 0; repeat < N -1; repeat++){
        min_node = get_small_node(); // 최소 비용 노드 탐색
        visit[min_node] = true; // 방문처리
        for(int i = 0; i < N; i++)
        {  // 방문하지 않은 노드 중에, 시작점이 최소비용노드를 경유하는게 더 가가우면 값 갱신
            if (visit[i] == false && dist[min_node] + weight[min_node][i] < dist[i]){
                dist[i] = dist[min_node] + weight[min_node][i];
            }
        }
    }
}

int main()
{
    dijkstra(0); //시간 복잡도 O(N^2) N-1만큼 반복하고 있고, 각각의 경우 노드를 찾을때 N번만큼 반복
    for(int i =0; i < N; i++)
        cout<<dist[i] << " ";
    return 0;
}