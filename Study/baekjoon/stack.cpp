#include <iostream>
#include <string>

using namespace std;

int arr[10000];
int s = -1;

void push();
void top();
void pop();
void size();
void empty();

int main()
{
    int count = 0;
    string a;
    scanf("%d", &count);
    for(int i =0; i < count; i++){
        cin>>a;
        if(a == "push")
            push();
        else if(a == "top")
            top();
        else if(a== "pop")
            pop();
        else if(a == "size")
            size();
        else if(a == "empty")
            empty();
        else
            continue;
    }

    return 0;
}
void push() {
    int b = 0;
    scanf("%d", &b);
    s++;
    arr[s] = b;
    return;
}
void top(){
    if (s == -1)
    {
        printf("-1\n");
        return;
    }
    printf("%d\n", arr[s]);
    return;
}
void pop() {
    if(s == -1){
        printf("-1\n");
        return;
    }
    printf("%d\n",arr[s]);
    s--;
    return;
}
void size(){
    printf("%d\n",s+1);
    return;
}
void empty(){
    if(s == -1)
        printf("1\n");
    else
        printf("0\n");
    return;
}
