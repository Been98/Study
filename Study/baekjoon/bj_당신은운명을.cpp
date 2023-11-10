#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s; 

    string korea = "KOREA";
    string yonsei = "YONSEI";
    int k = 0, y = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == korea[k]) {
            k++;
            if (k == korea.length()) {
                cout << "KOREA" << endl;
                return 0; 
            }
        } else if (s[i] == yonsei[y]) {
            y++;
            if (y == yonsei.length()) {
                cout << "YONSEI" << endl;
                return 0; 
            }
        }
    }

    return 0;
}