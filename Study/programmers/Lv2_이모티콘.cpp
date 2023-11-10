#include <string>
#include <vector>

using namespace std;
vector<int> sale = {40, 30, 20, 10};
vector<int> vec;
int emo_plus = 0;
int price = 0;

void DFS(vector<vector<int>> users, vector<int> emoticons)
{
    if (emoticons.size() == vec.size())
    { // 할인 사이즈 맞추기
        int pri = 0;
        int emo = 0;
        for (int i = 0; i < users.size(); i++)
        {
            int sum = 0;
            for (int j = 0; j < emoticons.size(); j++)
            {
                if (users[i][0] <= vec[j])
                {
                    sum += (emoticons[j] * (100 - vec[j]) / 100);
                }
            }
            if (sum >= users[i][1])
            { // 플러스 가입
                emo++;
            }
            else
                pri += sum;
        }
        if (emo_plus < emo)
        { // 플러스 가입자 비교
            emo_plus = emo;
            price = pri;
        }
        else if (emo_plus == emo && price < pri) // 같을 때 가격 비교
            price = pri;

        return;
    }

    for (int i = 0; i < 4; i++)
    { // sale 모든 경우 계산
        vec.push_back(sale[i]);
        DFS(users, emoticons);
        vec.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons)
{
    vector<int> answer;
    DFS(users, emoticons);

    answer.push_back(emo_plus);
    answer.push_back(price);

    return answer;
}