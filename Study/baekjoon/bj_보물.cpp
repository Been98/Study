#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, num;
    cin >> n;
    vector<int> arr1(n);
    vector<int> arr2(n);
    for(int i =0 ; i<n; i++){
        cin>> num;
        arr1[i] = num;
    }
    for(int i = 0; i<n; i++){
        cin>>num;
        arr2[i] = num;
    }
    
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end(), greater<int>());
    int sum=0;
    for(int i =0; i < n; i++){
        sum += arr1[i] * arr2[i];
    }
    cout<<sum;
    return 0;
}