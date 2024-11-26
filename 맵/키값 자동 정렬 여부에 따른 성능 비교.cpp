#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int main() {
	const int NUM_ELEMENTS = 10000000; // 비교할 요소의 수
	map<int, int> orderedMap;
	unordered_map<int, int> unorderedMap;

	clock_t start, end;

	// map에 삽입했을 때 시간 측정
	start = clock();
	for (int i = 0; i < NUM_ELEMENTS; ++i) {
		orderedMap[i] = rand();
	}
	end = clock();
	cout << "map Insertion Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
	// 13 seconds.

	// unordered_map에 삽입했을 때 시간 측정
	start = clock();
	for (inti = 0; i < NUM_ELEMENTS; ++i) {
		unorderedMap[i] = rand();
	}
	end = clock();
	cout << "unordered_map Insertion Time; " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
	// 4 seconds.

	return 0;
}