#include <iostream>
#include <vector>
#define MAX 51

using namespace std;

vector<int> vec[MAX];
bool visited[MAX];
int cnt;

void DFS(int node){
    int size = vec[node].size();
    visited[node] = true;
    if(size == 0){
        cnt++;
        return;
    }
    for(int i =0; i < size; i++){
        int child = vec[node][i];
        if(!visited[child]){
            DFS(child);
        }
    }

}

int main()
{
    int N, num, dNum, root;
    cin>>N;
    for(int i =0; i < N; i++){
        cin>>num;
        if(num == -1){
            root = i;
        }
        else
            vec[num].push_back(i);
    }
    cin>> dNum;
    if(dNum == root){
        cout<<0;
        return 0;
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < vec[i].size(); j++){
            if(vec[i][j] == dNum){
                vec[i].erase(vec[i].begin() + j);
                break;
            }
        }
    }


    DFS(root);


    cout<<cnt;
    return 0;
}