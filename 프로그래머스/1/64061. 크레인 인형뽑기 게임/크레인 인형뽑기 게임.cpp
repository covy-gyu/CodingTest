#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    size_t row = board.size();
    size_t moves_sz = moves.size();
    int answer = 0;
    stack<int> st;
    
    for(int i =0; i<moves_sz; i++){
        int col = moves[i]-1;
        for(int j=0; j<row; j++){
            int target = board[j][col];
            if(target){
                if(!st.empty()){
                    if(st.top() == target){
                        st.pop();        
                        answer+=2;
                    }
                    else st.push(target);
                }
                else st.push(target);
                board[j][col] = 0;
                break;
            }
        }
    }

    return answer;
}