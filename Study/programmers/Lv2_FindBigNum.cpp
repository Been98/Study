//순차검색으로 시작해서 시간 초과해서 스택으로 변경
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> numbers)
{
    vector<int> answer(numbers.size(), -1);
    stack<int> s1;
    for (int i = 0; i < numbers.size(); i++)
    {
        while (!s1.empty() && numbers[s1.top()] < numbers[i])
        {
            answer[s1.top()] = numbers[i];
            s1.pop();
        }
        s1.push(i);
    }

    return answer;
}