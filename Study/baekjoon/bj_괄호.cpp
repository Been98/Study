#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;


int main()
{
    vector<string> vec;
    vector<string> answer;
    string vps;
    int num;

    cin >> num;
    for(int i = 0; i < num; i++){
        cin >> vps;
        vec.push_back(vps);
    }
    for(string v : vec){
        stack<char> stk;
        bool flag = true;
        if(v.length() & 2 != 0 || v.front() == ')'){
            cout << "NO"<<"\n";
            continue;
        }
        for(int i = 0; i < v.length(); i++){
            if(v[i] == '(')
                stk.push(v[i]);
            else{
                if(!stk.empty()){
                    stk.pop();
                }
                else{
                    flag = false;
                    break;
                }
            }
        }
        if(stk.empty() && flag)
            cout<<"YES"<<"\n";
        else 
            cout<<"NO"<<"\n";
    }
    return 0;
}