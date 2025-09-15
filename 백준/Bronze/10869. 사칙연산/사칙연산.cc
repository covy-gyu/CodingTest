#include <iostream>
using namespace std;

int main(){
    int A{0};
    int B{0};
    cin >> A >> B;
    cout<<A+B<<endl;
    cout<<A-B<<endl;
    cout<<A*B<<endl;
    if(B!=0){
        cout <<A/B<<endl;
        cout <<A%B<<endl;
    }
}