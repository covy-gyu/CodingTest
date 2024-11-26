#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// ���� ��ȣ�� ¦�� �ٷ� Ȯ���� �� �ֵ��� �� ����
unordered_map<char, char> bracketPair = { {')','('},{']','['}, {'}','{'} };

// �μ��� ���� ���ڿ� ���� ��ȣ�� ¦�� �´��� Ȯ��
bool isValid(string& s, int start) {
	stack<char> stk;
	unsigned int sz = s.size();

	// ���ڿ��� ��ȸ�ϸ鼭
	for (int i = 0; i < sz; i++) {

		char ch = s[(start + i) % sz];
		//ch�� ���� ��ȣ�� ���
		if (bracketPair.count(ch)) {
			// ������ ����ų� top ���Ұ� ch�� ¦�� �´� ���� ��ȣ�� �ƴϸ� false ��ȯ
			if (stk.empty() || stk.top() != bracketPair[ch])
				return false;
			// ch�� ¦�� �´� ���� ��ȣ�� �ش� ���� ��ȣ ����
			stk.pop();
		}
		else {
			stk.push(ch); // ���� ��ȣ�� ���ÿ� Ǫ��
		}
	}

	// ������ ������� true�� ��ȯ(��ȣ ¦�� �´ٴ� �ǹ�)
	return stk.empty();
}

int solution(string s) {
	int answer = 0;
	int n = s.size();

	// ���ڿ��� ��ȸ�ϸ鼭 ��ȣ�� ¦�� ������ answer�� 1 ���� ��Ŵ
	for (int i = 0; i < n; i++) {
		answer += isValid(s, i);
	}
	return answer;
}