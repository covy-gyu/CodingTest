#include <string>
#include <vector>
#include <set>
#include <utility> // for std::pair
using namespace std;

int solution(string dirs) {
    // 시작 좌표
    pair<int, int> start = {5, 5};
    // 방문한 경로를 저장하는 집합
    set<pair<pair<int, int>, pair<int, int>>> visited;
    
    // 방향에 따른 이동 값
    vector<pair<int, pair<int,int>>> directions = {
        {'U', {0, 1}}, {'D', {0, -1}},
        {'R', {1, 0}}, {'L', {-1, 0}}
    };
    
    for (char dir : dirs) {
        // 현재 방향의 이동 값을 가져옴
        pair<int, int> move = {0, 0};
        if (dir == 'U') move = {0, 1};
        else if (dir == 'D') move = {0, -1};
        else if (dir == 'R') move = {1, 0};
        else if (dir == 'L') move = {-1, 0};

        // 이동 후 좌표 계산
        pair<int, int> next = {start.first + move.first, start.second + move.second};

        // 이동이 10x10 범위 내인지 확인
        if (next.first >= 0 && next.first <= 10 && next.second >= 0 && next.second <= 10) {
            // 방문 경로를 집합에 추가 (양방향으로 저장)
            visited.insert({start, next});
            visited.insert({next, start});

            // 위치 갱신
            start = next;
        }
    }

    // 방문한 경로의 수 반환
    return visited.size() / 2; // 양방향 저장이므로 나누기 2
}
