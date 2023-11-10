#include <iostream>
#include <string>
#include <stack>
#include <vector>
#define MAX 1001

using namespace std;

bool visited[MAX][MAX];
int arr[MAX][MAX];
int M,N = 0;

int posX[4] = {-1, 1, 0, 0};
int posY[4] = {0, 0, -1, 1};
int cnt = 0;

void DFS(int start_x, int start_y){
    stack<pair<int, int>> stk;
    visited[start_x][start_y] = true;
    stk.push({start_x, start_y});
    while(!stk.empty()){
        int x = stk.top().first;
        int y = stk.top().second;
        stk.pop();
        for(int i =0; i < 4; i++){
            int newX = x + posX[i];
            int newY = y + posY[i];
            if(0 <= newX && newX < M && 0<= newY && newY< N && !visited[newX][newY]){
                if(arr[newX][newY] == 0){
                    arr[newX][newY] = 1;
                    stk.push({newX,newY});
                    visited[newX][newY] = true;
                }
            }
        }
        cnt++;
    }
}

int main(){
    cin >> M >>N;
    int num = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> num;
            arr[i][j] = num;
        }   
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if(arr[i][j] == 1)
                DFS(i,j);
        }
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (arr[i][j] == 0){
                cout<<-1;
                return 0;
            }
        }
    }

    cout << cnt;
    return 0;
}