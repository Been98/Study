#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
    int num = 0;
    vector<vector<int>> answer;
    for (int i = 0; i < arr1.size(); i++)
    {
        vector<int> vec;
        for (int j = 0; j < arr2[0].size(); j++)
        {
            num = 0;
            for (int k = 0; k < arr1[0].size(); k++)
                num += arr1[i][k] * arr2[k][j];
            vec.push_back(num);
        }
        answer.push_back(vec);
    }

    return answer;
}