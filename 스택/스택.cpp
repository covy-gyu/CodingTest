#include <iostream>
#include <stack>

using namespace std;

int main() {
	stack<int> st; // int 타입의 스택 생성

	// push() : 요소를 스택 맨 위에 추가. 시간 복잡도 O(1)
	st.push(10);
	st.push(20);
	st.push(30);

	// 스택이 비어 있을 때까지 반복
	while (!st.empty()) {
		// top() : 스택에 마지막으로 삽입한 원소 반환. 시간 복잡도 : O(1)
		cout << st.top() << " "; // 현재 스택의 맨 위 요소 출력
		// pop() : 스택의 맨 위 원소 제거. 시간 복잡도 : O(1)
		st.pop(); //출력한 요소 제거
	}
	cout << endl;

	return 0;
}