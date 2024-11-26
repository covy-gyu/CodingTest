#include <string>
#include <vector>
#include <stack>

using namespace std;

// 올바른 괄호 문자열인지 확인하는 함수
bool validCheck(string str) {
    stack<char> st;
    for (char c : str) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        }
        else {
            if (st.empty()) return false;
            char top = st.top();
            if ((c == ')' && top == '(') ||
                (c == ']' && top == '[') ||
                (c == '}' && top == '{')) {
                st.pop();
            }
            else {
                return false;
            }
        }
    }
    return st.empty();
}

// 회전하며 올바른 괄호 문자열인지 검사
int solution(string s) {
    int answer = 0;

    int s_len = s.length();
    for (int i = 0; i < s_len; i++) {
        // 문자열 회전
        string rotated = s.substr(i) + s.substr(0, i);
        if (validCheck(rotated)) answer++;
    }

    return answer;
}