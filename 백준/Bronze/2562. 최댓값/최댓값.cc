#include <iostream>
using namespace std;

int main(){
    int N{0};
    int arr_max{0};
    int index{0};
    for(int i =0; i<9; i++){
        cin >> N;
        if (arr_max < N){
            arr_max = N;
            index = i+1;
        }
    }
    cout << arr_max <<endl;
    cout << index << endl;
}