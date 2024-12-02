#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    // 각 행의 이전, 다음 정보를 저장
    vector<int> prev(n), next(n);
    for (int i = 0; i < n; ++i) {
        prev[i] = i - 1;
        next[i] = i + 1;
    }
    next[n - 1] = -1;  // 마지막 행의 다음은 없음

    stack<int> removed;  // 삭제된 행을 저장
    int current = k;

    for (string c : cmd) {
        if (c[0] == 'U') {
            // 위로 이동
            int x = stoi(c.substr(2));
            while (x--) current = prev[current];
        } else if (c[0] == 'D') {
            // 아래로 이동
            int x = stoi(c.substr(2));
            while (x--) current = next[current];
        } else if (c[0] == 'C') {
            // 현재 행 삭제
            removed.push(current);  // 삭제된 행 저장
            if (prev[current] != -1) next[prev[current]] = next[current];
            if (next[current] != -1) prev[next[current]] = prev[current];
            current = (next[current] != -1) ? next[current] : prev[current];
        } else if (c[0] == 'Z') {
            // 가장 최근에 삭제된 행 복원
            int restore = removed.top();
            removed.pop();
            if (prev[restore] != -1) next[prev[restore]] = restore;
            if (next[restore] != -1) prev[next[restore]] = restore;
        }
    }

    // 최종 결과 생성
    string answer(n, 'O');
    while (!removed.empty()) {
        answer[removed.top()] = 'X';
        removed.pop();
    }

    return answer;
}
