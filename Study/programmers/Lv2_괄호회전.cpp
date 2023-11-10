#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    for(int i = 0; i < s.length(); i++){
        stack<char> stk;
        for(int j = 0; j < s.length(); j++){
            if(s[j] == '[' || s[j] == '{' || s[j] == '(')
                stk.push(s[j]);
            else{
                if(!stk.empty()){
                    if((stk.top() == '[' && s[j]  == ']') || (stk.top() == '(' && s[j]  == ')') || (stk.top() == '{' && s[j]  == '}')){
                        stk.pop();
                    }
                    else{
                        stk.push(s[j]);
                    }
                }
                else
                    stk.push(s[j]);
            }
        }
        if(stk.empty())
            answer++;
        s = s.substr(1) + s[0];
    }
    
    return answer;
}