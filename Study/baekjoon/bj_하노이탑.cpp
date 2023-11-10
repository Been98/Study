#include <iostream>

using namespace std;


void hanoi(int n, int from, int to, int temp){
    if(n == 1)
        cout << from <<" " << to <<"\n";
    else{
        hanoi(n-1, from, temp , to);
        cout<<from<<" "<<to<<"\n";
        hanoi(n-1, temp, to, from);
    }
}

int main()
{
    int n;

    cin >> n;
    int cnt = (1 << n) -1;
    cout <<cnt<<"\n";
    hanoi(n, 1, 3, 2);

    return 0;
}