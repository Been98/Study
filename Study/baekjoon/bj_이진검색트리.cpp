#include <iostream>
#include <vector>
#define MAX 10000

using namespace std;

vector<int> prevec, postvec;

void postorder(int start, int end){
    if(start > end ) return;
    int root = prevec[start];
    int left_end = start +1;
    while(left_end <= end && prevec[left_end] < root){
        left_end++;
    }
    postorder(start+1, left_end -1);
    postorder(left_end, end);
    postvec.push_back(root);
}

int main()
{
    int num;
    while(cin >> num){
        prevec.push_back(num);
    }
    postorder(0, prevec.size()-1);

    for(int v : postvec){
        cout<<v<<"\n";
    }
    return 0;
}