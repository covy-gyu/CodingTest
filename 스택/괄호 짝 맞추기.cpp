#include <stack>
#include <string>
#include <iostream>

using namespace std;

bool solution(string s) {
	stack<char> st;
	for (char c : s) {
		if (c == '(') {
			st.push(c);
		}
		else if (c == ')') {
			if (st.empty()) {
				return false;
			}
			else {
				st.pop();
			}
		}
	}
	return st.empty();
}

int main() {
	string s = "(())()";

	cout << solution(s);
}