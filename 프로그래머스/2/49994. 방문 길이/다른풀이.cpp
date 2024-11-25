#include <string>
#include <iostream>

using namespace std;

bool visited[11][11][4]; // Ư�� ��ǥ���� Ư�� �������� �̵��� ���� �ִ��� üũ

// �����¿�� ��ǥ�� �̵��� �� �ʿ��� ��ǥ�� ������ �迭
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

// �� ���ڿ� �ش��ϴ� ������ �迭�� �ε����� ��ȯ
int todir(char dir) {
	int ret;
	if (dir == 'U')
		ret = 0;
	else if (dir == 'R')
		ret = 1;
	else if (dir == 'D')
		ret = 2;
	else
		ret = 3;
	return ret;
}

// Ư�� ��ǥ�� �־��� ��ǥ ����� ������� Ȯ��
bool isNotValid(int x, int y) { return x < 0 || y < 0 || x>10 || y>10; }
// ����� �ݴ� ������ ������ �迭 �ε��� ��ȯ
int opposite_direction(int dir) { return (dir + 2) % 4; }

int solution(string dirs) {
	int answer = 0;
	int x = 5, y = 5; // ���� ��ǥ�� ����

	for (auto c : dirs) {
		// �ݺ����� ��ȸ�ϸ� nx, ny�� x, y�� dirs��� �������� �� ��ġ�� ��
		int dir = todir(c);
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		// ��ǥ ����� ����� �� �̻� �̵����� ����
		if (isNotValid(nx, ny)) {
			continue;
		}

		// ���� ��ǥ�� ���� �湮���� ���� ��ǥ�� ���
		if (visited[y][x][dir] == false) {
			// �湮�� �ߺ� üũ���� �ʵ��� �ش� ����� ����� �湮�� üũ
			visited[y][x][dir] = true;
			visited[ny][nx][opposite_direction(dir)] = true;
			answer++;
		}
		// ���� ��ǥ�� �̵��� ��ǥ�� ������Ʈ
		x = nx;
		y = ny;
	}

	return answer;
}

int main() {
	string dirs = "RUDL";

	int cnt = solution(dirs);

	cout << cnt;

}