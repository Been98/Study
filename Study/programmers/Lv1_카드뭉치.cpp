#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    vector<string> a;
    int c1 = 0, c2 =0;
    for(int i =0; i < goal.size(); i++){
       if(goal[i] == cards1[c1]){
           a.push_back(cards1[c1]);
           c1++;
       }
        else if(goal[i] == cards2[c2]){
            a.push_back(cards2[c2]);
            c2++;
        }
    }
    if(a == goal)
        return "Yes";
    else
        return "No";
    return answer;
}