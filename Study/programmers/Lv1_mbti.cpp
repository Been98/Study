#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

string solution(vector<string> survey, vector<int> choices)
{
    string answer = "";
    string aa;
    int b;
    int r = 0, t = 0, c = 0, f = 0, j = 0, m = 0, a = 0, n = 0;
    for (int i = 0; i < survey.size(); i++)
    {
        b = choices[i] - 4;
        if (b < 0)
        {
            aa = survey[i].at(0);
        }
        else if (b > 0)
        {
            aa = survey[i].at(1);
        }
        else
            continue;
        if (aa == "R")
            r += abs(b);
        else if (aa == "T")
            t += abs(b);
        else if (aa == "C")
            c += abs(b);
        else if (aa == "F")
            f += abs(b);
        else if (aa == "J")
            j += abs(b);
        else if (aa == "M")
            m += abs(b);
        else if (aa == "A")
            a += abs(b);
        else if (aa == "N")
            n += abs(b);
    }
    aa = "";
    if (r >= t)
        aa.push_back('R');
    else
        aa.push_back('T');
    if (c >= f)
        aa.push_back('C');
    else
        aa.push_back('F');
    if (j >= m)
        aa.push_back('J');
    else
        aa.push_back('M');
    if (a >= n)
        aa.push_back('A');
    else
        aa.push_back('N');
    answer = aa;
    return answer;
}