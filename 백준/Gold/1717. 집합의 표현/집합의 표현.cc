#include <iostream>
#include <vector>
using namespace std;

static vector<int> parent;
void unionfunc(int a, int b);
int find(int a);
bool checkSame(int a, int b);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	parent.resize(N + 1);

	for (int i = 0; i <= N; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < M; i++) {
		int question, a, b;
		cin >> question >> a >> b;

		if (question == 0) {
			unionfunc(a, b);
		}
		else {
			if (checkSame(a, b)) {
				cout << "YES" << "\n";
			}
			else {
				cout << "NO" << "\n";
			}
		}
	}
}

void unionfunc(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) {
		parent[b] = a;
	}
}

int find(int a) {
	if (a == parent[a]) {
		return a;
	}
	else {
		return parent[a] = find(parent[a]);
	}
}

bool checkSame(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b) {
		return true;
	}
	return false;
}