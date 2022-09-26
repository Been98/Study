//수 정렬하기 
#include <iostream>
#include <string>

using namespace std;

void swap(int c1, int c2);
int arr[1000];
int main()
{
    int a =0;
    int b =0;
    int min = 1000;
    int index = 0;
    scanf("%d",&a);
    for(int i = 0; i<a; i++){
        scanf("%d",&b);
        arr[i] = b;
    }
    for(int i =0; i < a; i++){
        min = arr[i];
        index = i;
        for(int j = i+1; j <a; j++){
            if (min > arr[j])
            {
                min = arr[j];
                index = j;
            }

        }
        swap(i,index);
    }
    for(int i =0; i <a; i++){
        printf("%d ,",arr[i]);
    }
}
void swap(int c1, int c2){
    int temp = arr[c1];
    arr[c1] = arr[c2];
    arr[c2] = temp;
}