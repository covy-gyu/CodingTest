#include <vector>
using namespace std;
vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(),0);
    for(int i =0; i< prices.size() - 1; i++){
        int time = 0;
        for(int j = i + 1; j < prices.size(); j++){
            answer[i] = j-i;
            if(prices[i] > prices[j]){
                break;
            }
        }
    }
    return answer;
}