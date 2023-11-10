#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#define MAX 26

using namespace std;

int N;
bool visited[MAX][MAX];
int arr[MAX][MAX];
vector<int> vec;
int cnt;

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
            if(0<= newX && newX < N && 0 <= newY && newY <N && 
            !visited[newX][newY] && arr[newX][newY] ==1){
                visited[newX][newY] = true;
                stk.push(make_pair(newX, newY));
                cnt++;
            }
        }
    }
}

int main()
{
    cin >> N;
    string s;
    for(int i =0;i < N; i++){
        cin>>s;
        for(int j =0; j < N; j++){
            arr[i][j] = s[j] - '0';
        }
    }
    
    for(int i =0;i < N; i++){
        for(int j =0; j < N; j++){
            if(arr[i][j] == 1 && !visited[i][j]){
                cnt = 0;
                DFS(i,j);
                vec.push_back(cnt);
            }
        }
    }
    sort(vec.begin(), vec.end());

    cout<<vec.size()<<'\n';
    for(int a : vec){
        cout<<a<<'\n';
    }
    return 0;
}
