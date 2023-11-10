#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    string word[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int answer = 0;
    for (int i = 0; i < 10; i++) {
        size_t n = s.find(word[i]);
        while (n != string::npos) {
            s.replace(n, word[i].length(), to_string(i));
            n = s.find(word[i]);
        }
    }
    answer = stoi(s);
    return answer;
}