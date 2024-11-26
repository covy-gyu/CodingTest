#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// 닫힌 괄호의 짝을 바로 확인할 수 있도록 맵 선언
unordered_map<char, char> bracketPair = { {')','('},{']','['}, {'}','{'} };

// 인수로 받은 문자열 기준 괄호의 짝이 맞는지 확인
bool isValid(string& s, int start) {
	stack<char> stk;
	unsigned int sz = s.size();

	// 문자열을 순회하면서
	for (int i = 0; i < sz; i++) {

		char ch = s[(start + i) % sz];
		//ch가 닫힌 괄호인 경우
		if (bracketPair.count(ch)) {
			// 스택이 비었거나 top 원소가 ch와 짝이 맞는 열린 괄호가 아니면 false 반환
			if (stk.empty() || stk.top() != bracketPair[ch])
				return false;
			// ch와 짝이 맞는 열린 괄호면 해당 열린 괄호 제거
			stk.pop();
		}
		else {
			stk.push(ch); // 열린 괄호면 스택에 푸시
		}
	}

	// 스택이 비었으면 true를 반환(괄호 짝이 맞다는 의미)
	return stk.empty();
}

int solution(string s) {
	int answer = 0;
	int n = s.size();

	// 문자열을 순회하면서 괄호의 짝이 맞으면 answer를 1 증가 시킴
	for (int i = 0; i < n; i++) {
		answer += isValid(s, i);
	}
	return answer;
}