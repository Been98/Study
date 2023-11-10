//수 찾기
// vector로 풀다가 메모리 효율이 낮아 array로 변경
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
 
void BS(int* v1,int len, int key){
    int start = 0;
    int end = len -1;
    int mid;

    while(end >= start){
        mid = (start + end) /2;
        if(v1[mid] == key){
            printf("1\n");
            return;
        }
        else if(v1[mid] > key)
            end = mid - 1;
        else
            start = mid + 1;
    }
    printf("0\n");
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    bool flag;
    int num1 = 0, num2 = 0, len = 0;
    cin >> len;
    int v1[len];
    for(int i = 0; i < len; i++){
        cin >> v1[i];
    }
    sort(v1, v1+len);
    cin>> num1;
    for (int i = 0; i < num1; i++)
    {
        cin >> num2;
        BS(v1, len , num2);
    }
    return 0;
}
