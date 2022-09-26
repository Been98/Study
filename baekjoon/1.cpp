#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    long a,b,c;
    long count = 0;
    scanf("%ld %ld %ld",&a,&b,&c);
    if(b >= c )
        count = -1;
    else
        count = a /(c-b) + 1;       
    printf("%ld", count);
}