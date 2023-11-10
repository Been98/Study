#include <iostream>
#include <string>
#include <vector>
#define MAX 101

using namespace std;

bool visited[MAX];
vector<int> vec[MAX];
int count = 0;

void DFS(int start){
    visited[start] = true;
    for(int i = 0; i < vec[start].size(); i++){
        if(!visited[vec[start][i]]){
            count++;
            DFS(vec[start][i]);
        }
    }
}

int main()
{
    int N, M;
    int num1, num2;
    cin >> N >> M;
    for(int i =0; i <M; i++){
        cin>>num1 >> num2;
        vec[num1].push_back(num2);
        vec[num2].push_back(num1);
    }
    DFS(1);
    cout<<count;
    return 0;
}