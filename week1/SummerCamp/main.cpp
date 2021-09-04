//#include <iostream>
//using namespace std;
//int main() {
//    int test;
//    cin >> test;
//    int people;
//    bool done =false;
//    for (int i = 0; i < test; ++i) {
//        cin >> people;
//        done = false;
//        for (int k = 0; k <= people / 2; ++k) {
//            for (int a = 0; a < people / 2; ++a) {
//                if(2* people == (2 * a + k -1)* k){
//                    done = true;
//                    cout << k << endl;
//                    break;
//                }
//            }
//            if(done){
//                break;
//            }
//            if(k == people / 2){
//                cout <<"impossible" << endl;
//            }
//        }
//    }
//    return 0;
//}

#include <iostream>
#include <math.h>

using namespace std;

void sol(long long total){
    if(total == 1){
        cout << "impossible" << endl;
        return;
    }
    if(total % 2 != 0){//total is odd
        cout << 2 << endl;
        return;
    }
    for (int i = 0; i < 83; ++i) {
        if(pow(2, i) == total){
            cout << "impossible" << endl;
            return;
        }
    }
    int n;
    long long m;
    for (int j = 1; j < total; ++j) {
       n = 2*j + 1;
       if((total / n) * n == total){
           m = total/n;//total = m * n
           break;
       }
    }
    if(m > n / 2){
        cout << n << endl;
    } else{
        cout << 2 * m << endl;
    }
}

int main(){
    int count;
    cin >> count;
    if(count == 0){
        return 0;
    }
    for (int i = 0; i < count; ++i) {
        long long total;
        cin >> total;
        sol(total);
    }

    return 0;
}