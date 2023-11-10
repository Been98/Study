#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n = 0,k = 0;
    int num;
    int answer = 0;
    cin>>n >>k;
    vector<int> vec;
    for(int i = 0; i < n; i++){
        cin >> num;
        vec.push_back(num);
    }
    for(int i = n-1; i >= 0; i--){
        if(k >= vec[i]){
            int num2 = k % vec[i];
            answer +=  k/vec[i];
            k = num2;
        }
    }
    cout <<answer;
    return 0;
}