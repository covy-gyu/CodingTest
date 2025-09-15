#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int case_num{0};
    cin >> case_num;
    
    vector<string> str_arr(case_num, "");
    for (int i = 0; i<case_num; i++)
    {
        int N{0};
        string str="";
        cin >> N >> str;
        
        for(int j =0; j<str.length(); j++)
        {
            for(int k =0; k < N; k++)
            {
                str_arr[i] += str[j];
            }
        }
    }
    for (const auto& str : str_arr) {
        cout << str << endl;
    }
}