#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    size_t row = board.size();        // 보드의 행 개수
    int answer = 0;                   // 터뜨린 인형의 개수
    stack<int> st;                    // 바구니 역할 스택

    for (size_t i = 0; i < moves.size(); i++) {
        int col = moves[i] - 1;       // 1-based index를 0-based로 변환

        for (size_t j = 0; j < row; j++) {
            if (board[j][col] != 0) {  // 해당 칸에 인형이 있는 경우
                int target = board[j][col]; // 인형 값
                board[j][col] = 0;          // 인형 제거
                
                if (!st.empty() && st.top() == target) {
                    st.pop();               // 동일한 인형 제거
                    answer += 2;            // 제거한 인형은 2개
                } else {
                    st.push(target);        // 바구니에 인형 추가
                }
                break;                      // 해당 열 탐색 종료
            }
        }
    }
    
    return answer; // 터뜨린 인형 개수 반환
}
