#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int, vector<int>> pq;
    
    for(int i = 0; i < enemy.size(); i++){
        if(n >= enemy[i]){
            pq.push(enemy[i]);
            n -= enemy[i];
        }
        else{
            if(k < 1)
                break;
            if( !pq.empty() && pq.top() > enemy[i]){
                n += pq.top();
                pq.pop();
                pq.push(enemy[i]);
                n -= enemy[i];
            }
            k--;
        }
        answer++;
    }
    return answer;
}
