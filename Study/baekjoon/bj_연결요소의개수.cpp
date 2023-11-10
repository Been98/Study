#include <iostream>
#include <vector>
#include <stack>

using namespace std;
bool visited[1001];

void dfs(int node, vector<int>* graph)
{
    visited[node] = true;

    for (int i = 0; i < graph[node].size(); i++)
    {
        int next_node = graph[node][i];

        if (!visited[next_node])
        {
            dfs(next_node, graph);
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> vec[N+1];
    int x,y;
    for(int i =0; i < M; i++){
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    int cnt = 0;
       for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            dfs(i, vec);
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}