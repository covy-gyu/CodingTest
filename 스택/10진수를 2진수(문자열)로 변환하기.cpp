#include <stack>
#include <string>
#include <iostream>

using namespace std;

string solution(int d) {

	stack<int> st;

	int quotient = d;
	int	remainder = quotient % 2;

	while (quotient > 0) {
		st.push(remainder);
		quotient /= 2;
		remainder = quotient % 2;
	}

	string answer = "";
	while (!st.empty()) {
		answer.append(to_string(st.top()));
		st.pop();
	}
	return answer;
}

int main() {
	int decimal = 12345;

	cout << solution(decimal);
}