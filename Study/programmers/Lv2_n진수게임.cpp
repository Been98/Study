#include <string>
#include <vector>

using namespace std;

char code[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

string Func(int num, int n)
{
    string tmp = "";
    if (num == 0)
        return "0";
    while (num > 0)
    {
        tmp = code[num % n] + tmp;
        num = num / n;
    }
    // tmp = code[num%n] + tmp;
    return tmp;
}

string solution(int n, int t, int m, int p)
{
    string answer = "";
    string tmp = "";
    for (int i = 0; tmp.size() <= m * t; i++)
    {
        string s = Func(i, n);
        tmp += s;
    }
    for (int i = 0; i < t; i++)
    {
        answer += tmp[(m * i) + (p - 1)];
    }

    return answer;
}