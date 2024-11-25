#include <iostream>
#include <stack>

using namespace std;

int main() {
	stack<int> st; // int Ÿ���� ���� ����

	// push() : ��Ҹ� ���� �� ���� �߰�. �ð� ���⵵ O(1)
	st.push(10);
	st.push(20);
	st.push(30);

	// ������ ��� ���� ������ �ݺ�
	while (!st.empty()) {
		// top() : ���ÿ� ���������� ������ ���� ��ȯ. �ð� ���⵵ : O(1)
		cout << st.top() << " "; // ���� ������ �� �� ��� ���
		// pop() : ������ �� �� ���� ����. �ð� ���⵵ : O(1)
		st.pop(); //����� ��� ����
	}
	cout << endl;

	return 0;
}