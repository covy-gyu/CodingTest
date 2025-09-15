#include <iostream>
#include <string>
using namespace std;

int main() {
    int N{0};
    string quot;   // 큰 수는 문자열로 받기
    cin >> N;
    cin >> quot;

    int sum{0};
    for (char c : quot) {
        sum += c - '0'; // 문자 → 숫자 변환
    }
    cout << sum;
}
