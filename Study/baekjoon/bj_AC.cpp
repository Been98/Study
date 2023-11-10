#include <string>
#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int T;
    cin >> T;

    for(int j = 0; j <T; j++){
        string s; 
        int n; //arr size
        string arr;
        cin>>s>>n>>arr;
        deque<int> dq;
        string num = "";

        for(int i =0; i < arr.length(); i++){
            if(arr[i] == '[') continue;
            if(isdigit(arr[i])){
                num += arr[i];
            }
            else if(arr[i] == ',' || arr[i] == ']'){
                if(!num.empty()){
                    dq.push_back(stoi(num));
                    num = "";
                }
            }
        }
        bool isR = false;
        bool isE = false;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'R'){
                isR = !isR;
            }   
            else if(s[i] == 'D'){
               if(dq.empty()){
                    isE = true;
                    break;
               }
               else{
                    if(isR)
                        dq.pop_back();
                    else
                        dq.pop_front();
               }
            }
        }
        if (isE) {
            cout << "error" << endl;
        } else {
            cout << '[';
            while (!dq.empty()) {
                if (isR) {
                    cout << dq.back();
                    dq.pop_back();
                } else {
                    cout << dq.front();
                    dq.pop_front();
                }
                if (!dq.empty()) cout << ',';
            }
            cout << ']' << endl;
        }
    }
    return 0;
}