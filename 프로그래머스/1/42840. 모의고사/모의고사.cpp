#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> p1 = {1,2,3,4,5};
    vector<int> p2 = {2,1,2,3,2,4,2,5};
    vector<int> p3 = {3,3,1,1,2,2,4,4,5,5};
    
    vector<int> answer;
    
    vector<int> matchCnt(3);
    
    for(int i = 0; i< answers.size(); i++){
        if(answers[i] == p1[i%p1.size()])
            matchCnt[0]++;
        if(answers[i] == p2[i%p2.size()])
            matchCnt[1]++;
        if(answers[i] == p3[i%p3.size()])
            matchCnt[2]++;
    }
    
    int max_score = *max_element(matchCnt.begin(), matchCnt.end());
    
    for( int i =0; i< 3; i++){
        if(matchCnt[i] == max_score)
            answer.push_back(i+1);
    }
    
    return answer;
}