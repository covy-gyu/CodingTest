// #include <cstdio>
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B;
    while (cin >> A >> B) {     // EOF가 되면 루프 종료
        cout << (A + B) << '\n';
    }
    return 0;
}
