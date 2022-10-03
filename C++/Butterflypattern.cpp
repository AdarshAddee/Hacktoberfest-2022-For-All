// Github username : RajatRathore123-github
// Aim : Added a butterfly pattern in C++
// Date : 3-10-2022

#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cout << "*";
        }
        int space = 2*(n-1);
        for(int j = 1; j <= space; j++){
            cout << " ";
        }
        for(int j = 1; j <= i; j++){
            cout << "*";
        }
        cout << endl;
    }
    for(int i = n; i >= 1; i--){
        for(int j = 1; j <= i; j++){
            cout << "*";
        }
        int space = 2*(n-1);
        for(int j = 1; j <= space; j++){
            cout << " ";
        }
        for(int j = 1; j <= i; j++){
            cout << "*";
        }
        cout << endl;
    }
}