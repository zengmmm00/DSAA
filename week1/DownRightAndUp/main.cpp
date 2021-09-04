#include <iostream>
#include <math.h>
#include <algorithm>
#include <sstream>
using namespace std;

long long T;//pow(4, 8) < 100000 < pow(4, 9)
long long input;
int k;
int x = 1;
int y = 1;
long long test;
int a;
long long upLeft = 1;
//string got[1000000000000000001];
void sol(long long T, int k){
//    cout << "k = " << k << endl;
//    cout << "test = " << test << endl;
//    cout << "a = " << a << endl;
//    cout << "x = " << x << endl;
//    cout << "y = " << y << endl;
//    cout << "upLeft = " << upLeft << endl;

    if(k == 0){
        int b = input - upLeft;
//        cout << b << endl;
        if(b == 0){
//            cout << "(" << x << "," << y << ")" << endl;

        } else if(b == 1){
//            cout << "(" << x + 1 << "," << y << ")" << endl;
            x += 1;
        } else if(b == 2){
//            cout << "(" << x + 1<< "," << y + 1<< ")" << endl;
            x += 1;
            y += 1;
        } else{
//            cout << "(" << x << "," << y + 1 << ")" << endl;
            y += 1;
        }
        stringstream sx, sy;
        sx << x;
        sy << y;
        cout << "(" + sx.str() + "," + sy.str() + ")" << endl;
        x = 1;
        y = 1;
        test = 0;
        a = 0;
        upLeft = 1;
    } else{
        test = pow(4, k);
        a = T / test;
        if(a == 0 || T == test){

        } else if(a == 1 || T == 2 * test){
            x += sqrt(test);
            upLeft += test ;
        } else if(a == 2 || T == 3 * test){
            x += sqrt(test);
            y += sqrt(test);
            upLeft += 2 * test ;
        } else if(a == 3 || T == 4 * test){
            y += sqrt(test);
            upLeft += 3 * test ;
        }
//        cout << "k = " << k << endl;
//        cout << "test = " << test << endl;
//        cout << "a = " << a << endl;
//        cout << "x = " << x << endl;
//        cout << "y = " << y << endl;
//        cout << "upLeft = " << upLeft << endl;
        sol(T - upLeft + 1, k -1);
    }
}

void getCoordinate(){
    for (int i = 0; i < 10; ++i) {
        if( T / pow(4, i) < 1){
            k = i - 1;
            break;
        }
    }
    sol(T , k);
}


int main() {
//
//    for (int i = 1; i < 65; ++i) {
//        input = i;
//        T = input;
//        getCoordinate();
//    }
//    for (int i = 1; i < 65; ++i) {
//        cout << got[i] << endl;
//    }
    input = 1000000000000000000;
    T = input;
    getCoordinate();
    return 0;
}