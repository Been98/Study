#include <iostream>
#include <string>
#define MAX 2000000
using namespace std;

bool isP[MAX];

bool is_palindrom(int n){
    string s = to_string(n);
    for(int i =0; i < s.size()/2; i++){
        if(s[i] != s[s.size() -1 - i])
            return false;
    }
    return true;
}
void is_prime(){
    for(int i =2; i < MAX; i++){
        if(!isP[i]){
            for(int j = 2*i; j<= MAX; j+=i){
                isP[j] = true;
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int num = 0;
    cin >> num;
    is_prime();
    isP[0] = isP[1] = true;
    while(true){
        if(is_palindrom(num) && !isP[num]){
            cout<<num;
            break;
        }
        num++;
    }

    return 0;
}