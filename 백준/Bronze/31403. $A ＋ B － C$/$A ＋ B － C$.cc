#include <iostream>
#include <string>

using namespace std;

int main(){
    int A{0};
    int B{0};
    int C{0};
    
    cin >> A;
    cin >> B;
    cin >> C;
    
    cout << A + B - C << endl;
    string A_str = to_string(A);
    string B_str = to_string(B);
    //string C_str = to_string(C);
    cout << stoi(A_str + B_str) - C;
    
}