#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
	return a > b;
}

vector<int> solution(vector<int> lst) {
	sort(lst.begin(), lst.end(), compare); // 내림차순으로 정렬
	lst.erase(unique(lst.begin(), lst.end()), lst.end()); // 중복값 제거

	return lst;
}