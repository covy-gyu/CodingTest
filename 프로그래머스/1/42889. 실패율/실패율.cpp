#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<pair<int, double>> temp_vec; // 스테이지 번호와 실패율을 저장
    vector<int> answer;

    size_t clearPlayer = stages.size(); // 총 플레이어 수

    // 각 스테이지별 실패율 계산
    for (int i = 1; i <= N; i++) {
        int notClearPlayer = count(stages.begin(), stages.end(), i);

        // 실패율 계산 (플레이어가 없는 경우 실패율은 0)
        double failureRate = (clearPlayer == 0) ? 0.0 : static_cast<double>(notClearPlayer) / clearPlayer;

        temp_vec.push_back({i, failureRate});
        clearPlayer -= notClearPlayer; // 남은 플레이어 수 갱신
    }

    // 실패율 기준 내림차순 정렬, 실패율이 같다면 스테이지 번호 오름차순
    sort(temp_vec.begin(), temp_vec.end(), [](pair<int, double>& a, pair<int, double>& b) {
        if (a.second == b.second) {
            return a.first < b.first; // 스테이지 번호 오름차순
        }
        return a.second > b.second; // 실패율 내림차순
    });

    // 정렬된 스테이지 번호만 answer에 추가
    for (const auto& pair : temp_vec) {
        answer.push_back(pair.first);
    }

    return answer;
}