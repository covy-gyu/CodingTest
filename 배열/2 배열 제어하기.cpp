#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
	return a > b;
}

vector<int> solution(vector<int> lst) {
	sort(lst.begin(), lst.end(), compare); // ������������ ����
	lst.erase(unique(lst.begin(), lst.end()), lst.end()); // �ߺ��� ����

	return lst;
}