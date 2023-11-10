#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string num;
    cin>>num;
    sort(num.begin(), num.end(), greater<>());
    cout<<num;

    return 0;
}