#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int num = 0;
    int sum = 0, sum2 = 0;
    cin>>num;
    vector<int> arr(num);
    vector<int> arr2;
    for(int i =0; i < arr.size(); i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    
    for(int i = 1; i < arr.size()+1; i++){
        for(int j = 0; j < i; j++){
            sum += arr[j];
        }
        arr2.push_back(sum);
        sum = 0;
    }
    for(int a: arr2){
        sum+=a;
    }
    cout<<sum;
    return 0;
}