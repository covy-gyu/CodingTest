#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
	size_t rows = arr1.size();
	size_t cols = arr2[1].size();
	size_t inner = arr2.size();

	// 결과 행렬 초기화
	vector<vector<int>> answer(rows, vector<int>(cols, 0));

	// 행렬 곱셈
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			for (size_t k = 0; k < inner; k++) {
				answer[i][j] = arr1[i][k] * arr2[k][j];
			}
		}
	}

	return answer;
}