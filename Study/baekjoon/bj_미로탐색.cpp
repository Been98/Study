#include <iostream>
#include <vector>
#include <queue>
#define MAX 101

using namespace std;

bool visited[MAX][MAX] = {false,};
int arr[MAX][MAX];
int dist[MAX][MAX];
int N, M;

int posX[4] = {-1, 1, 0, 0};
int posY[4] = {0, 0, -1, 1};

void BFS(int start_x, int start_y){
    queue<pair<int, int>> que;
    visited[start_x][start_y] = true;
    que.push(make_pair(start_x,start_y));
    dist[start_x][start_y]++;
    while(!que.empty()){
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        for(int i = 0; i < 4; i++){
            int newX = x + posX[i];
            int newY = y + posY[i];
            if( (0 <= newX && newX < N)&& (0 <= newY && newY < M)&& !visited[newX][newY] && arr[newX][newY] == 1 ){
                visited[newX][newY] = true;
                que.push(make_pair(newX,newY));
                dist[newX][newY] = dist[x][y] + 1;
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    string s;
    for(int i =0; i < N; i++){
        cin >> s;
        for(int j = 0; j < M; j++){
            arr[i][j] = s[j] - '0';
        }
    }
    BFS(0,0);
    cout<<dist[N-1][M-1];
    return 0;
}