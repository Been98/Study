#include <iostream>
#include <map>

using namespace std;

int main()
{
    int A,B;
    map<int, bool> m;
    cin>> A >> B;

    for(int i =0; i < A + B; i++){
        int tmp;
        cin >> tmp;

        if(m[tmp] == true)
            m.erase(tmp);
        else
            m[tmp] = true;
    }
    cout<< m.size();

    return 0;
}