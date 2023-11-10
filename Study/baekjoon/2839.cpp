//설탕 배달

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int num = 0;
    int a = 0, b = 0;
    cin >> num;
    a = num / 5;
    while(1){
        if(a < 0){
            cout <<"-1";
            return 0;
        }
        if((num-(5*a))%3 == 0){
            b = (num-(5*a)) / 3;
            break;
        }
        a--;
    }
    cout << a+b;
    return 0;
}