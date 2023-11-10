#include <iostream>
#include <string>
#define MAX 10001

using namespace std;

int func(int num){
    int result = num;
    while(num > 0){
        result += num % 10;
        num /= 10;
    }
    return result;
}

int main()
{
    bool arr[MAX + 1] = {false,};
    int x = 10;
    for(int i =1; i < MAX; i++){
        int num = func(i);
        if( num < MAX)
            arr[num] = true;
    }
    
    for(int i =1; i < MAX; i++){
        if(!arr[i])
            cout<<i<<"\n";
    }

    return 0;
}