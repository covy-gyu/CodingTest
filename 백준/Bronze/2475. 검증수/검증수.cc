#include <iostream>
using namespace std;
int main(){
    int N1{0};
    int N2{0};
    int N3{0};
    int N4{0};
    int N5{0};
    cin >> N1 >> N2 >> N3 >> N4 >> N5;

    int sum = N1*N1 + N2*N2 + N3*N3 + N4*N4 + N5*N5;

    int remainder = sum % 10;
    cout << remainder;

}