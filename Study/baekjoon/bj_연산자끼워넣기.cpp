#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> operands;
int operators[4];
int MinNum = 1000000001;
int MaxNum = -1000000001;

void DFS(int result, int idx){
    if(idx == operands.size()){
        if(result > MaxNum)
            MaxNum = result;
        if(result < MinNum)
            MinNum = result;
        return;
    }
    for(int i =0; i < 4; i++){
        if(operators[i] > 0){
            operators[i]--;
            if(i == 0)
                DFS(result + operands[idx], idx+1);
            else if(i ==1)
                DFS(result - operands[idx], idx+1);
            else if(i ==2)
                DFS(result * operands[idx], idx+1);
            else if(i ==3)
                DFS(result / operands[idx], idx+1);
            operators[i]++;    
        }
    }
}

int main()
{
    int N ,num;
    cin >> N;

    for(int i =0; i < N; i++){
        cin >> num;
        operands.push_back(num);
    }
    for(int i =0; i < 4; i++){
        cin >> operators[i];
    }
    DFS(operands[0], 1);
    cout<<MaxNum<<"\n"<<MinNum;
    return 0;
}