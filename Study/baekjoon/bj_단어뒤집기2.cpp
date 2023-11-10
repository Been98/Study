#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<char> stk;
void print(){
    while(!stk.empty()){
        cout<<stk.top();
        stk.pop();
    }
}
int main()
{
    string s;
    getline(cin, s);
    for(int i=0; i < s.size(); i++){
        if(s[i] == '<'){
            print();
            while(1){
                cout<<s[i];
                if(s[i] == '>') break;
                i++;
            }
        }
        else if(s[i] == ' '){
            print();
            cout<<" ";
        }
        else
            stk.push(s[i]);
    }
    print();
    return 0;
}