#include <iostream>
#include <vector>
#define MAX 21

using namespace std;

int N;
int player[MAX][MAX];
bool visited[MAX];  //팀구분
int MinNum = 1000000000;

void DFS(int pCnt, int next){
    if(pCnt == N/2){ 
        int s,l;
        s = 0;
        l = 0;

        for(int i =1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(visited[i] && visited[j]) s += player[i][j]; 
                if(!visited[i] && !visited[j]) l += player[i][j];
            }
        }
        int tmp = abs(s - l);
        if(tmp < MinNum ) MinNum = tmp;
        return;
    }

    //중복된 사람 없이 팀 먼저 구성
    for(int i = next; i < N; i++){
        visited[i] = true;
        DFS(pCnt + 1, i +1);
        visited[i] = false;
    }
}

int main()
{
    cin >> N;

    for(int i =1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin>>player[i][j];
        }
    }
    DFS(0,1);

    cout<<MinNum;
    return 0;
}