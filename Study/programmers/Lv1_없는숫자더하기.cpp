#include <string>
#include <vector>
#include <algorithm>
//다른 사람 푼거 보니까 총합에서 빼더라 = 간단하게 생각해보자
using namespace std;

int solution(vector<int> numbers)
{
    int answer = 0;
    int num = 0;
    sort(numbers.begin(), numbers.end());
    for (int i = 0; i < 10; i++)
    {
        if (i == numbers[num])
        {
            num++;
            continue;
        }
        answer += i;
    }

    return answer;
}