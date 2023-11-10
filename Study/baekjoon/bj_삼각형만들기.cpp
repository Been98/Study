#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int tri(vector<int> arr){
    sort(arr.begin(), arr.end(), greater<int>());
    for(int i =0; i < arr.size()-2;i++){
        if(arr[i] < arr[i + 1] + arr[i + 2])
            return arr[i] + arr[i+1] + arr[i+2];
    }
    return -1;
}

int main()
{
    int n, straw;
    cin >> n;
    vector<int> arr;
    for(int i =0; i < n; i++){
        cin>>straw;
        arr.push_back(straw);
    }
    cout<<tri(arr);
}