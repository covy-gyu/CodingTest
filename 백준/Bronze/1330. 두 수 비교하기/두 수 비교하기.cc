#include <iostream>

using namespace std;

int main(){
    int a{0};
    int b{0};
    
    cin >> a >> b;
    
    if (a > b)
        cout << ">";
    else if (a < b)
        cout << "<";
    else
        cout <<"==";
    return 0;
}