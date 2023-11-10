#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#define MAX 51

using namespace std;

int M,N,K;
int arr[MAX][MAX];
bool visited[MAX][MAX];

int cnt = 0;

int posX[4] = {-1, 1, 0, 0};
int posY[4] = {0, 0, -1, 1};

void DFS(int start_x, int start_y){
    stack<pair<int,int>> stk;
    visited[start_x][start_y] = true;
    stk.push(make_pair(start_x,start_y));
    cnt++;
    while(!stk.empty()){
        int x = stk.top().first;
        int y = stk.top().second;
        stk.pop();
        for(int i = 0; i < 4; i++){
            int newX = x + posX[i];
            int newY = y + posY[i];
            if(0<=newX && newX < N && 0<=newY && newY < M && !visited[newX][newY]
            && arr[newX][newY] == 1){
                visited[newX][newY] = true;
                stk.push(make_pair(newX,newY));
            }
        }
    }
}

int main()
{
    int T;
    cin>>T;
    vector<int> answer[T];
    int num1, num2;
    for(int i = 0; i < T; i++){
        cin>>M>>N>>K;
        for(int j = 0; j < K; j++){
            cin>>num1>>num2;
            arr[num2][num1] = 1;
        }
        for(int a = 0; a < N; a++){
            for(int b = 0; b < M; b++){
                if(!visited[a][b] && arr[a][b] == 1){
                    cnt = 0;
                    DFS(a,b);
                    answer[i].push_back(cnt);
                }
            }
        }
        memset(arr,0, sizeof(arr));
        memset(visited, false,sizeof(visited));
    }
    for(int i = 0; i < T; i++){
        cout<<answer[i].size()<<'\n';
    }
    return 0;
}
