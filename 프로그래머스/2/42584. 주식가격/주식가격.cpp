#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    size_t prices_sz = prices.size();
    
    vector<int> answer(prices_sz,0);
    
    for(int i =0; i< prices_sz - 1; i++){
        int time = 0;
        for(int j = i + 1; j < prices_sz; j++){
            answer[i] = j-i;
            if(prices[i] > prices[j]){
                break;
            }
        }
    }
    
    return answer;
}