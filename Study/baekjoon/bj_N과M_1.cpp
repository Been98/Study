#include <iostream>
#include <vector>

using namespace std;
int N, M;
bool visited[9];
vector<int> vec;


void DFS(int num){
    if(num == M){
        for(int i =0; i < M; i++){
            cout<< vec[i] << " ";
        }
        cout<<"\n";
        return;
    }
    for(int i = 1; i <= N; i++){
        if(!visited[i]) {
            visited[i] = true;
            vec.push_back(i);
            DFS(num + 1);
            vec.pop_back();
            visited[i] = false; //수열은 num보다 작은 수도 체크해야함
        }
    }
}

int main()
{
    cin >> N >> M;
    DFS(0);

    return 0;
}