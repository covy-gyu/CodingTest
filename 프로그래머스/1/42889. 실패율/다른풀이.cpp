#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(pair<int, float>& a, pair<int, float>& b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer; // ���� ��
	vector<float> challenger(N + 2, 0.0); // �� ���������� ������ ���� �ִ� �������� ��
	vector<float> fail(N + 2, 0.0); // Ư�� ���������� ������ �������� ��

	// �� ���������� �ο��� �������� Ư�� ������������
	// ������ �ο�����, �� ���������� ������ ���� �ִ� �ο����� ����
	for (int i = 0; i < stages.size(); i++) {
		for (int j = 1; j <= stages[i]; j++) {
			challenger[j]++;
		}
		fail[stages[i]]++;
	}

	// failRatio�� �������� ����, first�� stage�����̰� second�� ������
	vector<pair<int, float>> failRatio(N);

	// �������� ���� �� �������� ����
	for (int i = 0; i < N; i++) {
		failRatio[i].first = i + 1;

		if (challenger[i + 1] == 0)
			failRatio[i].second = 0;
		else
			failRatio[i].second = fail[i + 1] / challenger[i + 1];
	}

	// ����� �������� �������� ������ ���ǿ� �°� ����
	sort(failRatio.begin(), failRatio.end(), compare);

	//���� ���� ��ȯ�ϱ� ���� �������� ����
	for (int i = 0; i < N; i++) {
		answer.push_back(failRatio[i].first);
	}

	return answer;
}

int main() {
	vector<int> stages = { 2,1,2,6,2,4,3,3 };

	for (const auto& v : solution(5, stages))
		cout << v << " ";
}