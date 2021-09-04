#include <iostream>
#include <cmath>
using namespace std;

long long time(long long k){// pow(5, k)
    long long result = 1;
    for (int i = 0; i < k; ++i) {
        result = result * 5;
    }
    return result;
}

int main(){
    long long T;
    scanf("%lld" ,&T);
    for (int i = 0; i < T; ++i) {
        long long test;
        scanf("%lld" ,&test);
        long long count = 0;
        long long k = 1;
        while (true){
            long long temp = test / time(k);
            if(temp == 0){
                break;
            } else{
                count += temp;
            }
            k++;
        }
        printf("%lld\n", count);
    }

    return 0;
}
//
//long long biggestTime(long long test){
//    long long i = 1;
//    while (test >= pow(5, i)){
//        i = i + 1;
//    }
//    return i - 1;
//}
//
//int main(){
//    long long T;
//    scanf("%lld", &T);
//    for (int i = 0; i < T; ++i) {
//        long long test;
//        scanf("%lld" , &test);
//        if(test < 5){
//            printf("0\n");
//        } else{
//            long long k = biggestTime(test);
//            long long count = 0;
//            if(k == 1){
//                count = test / 5;
//            } else{
//
//                for (int j = 1; j < k; ++j) {
//                    long long right = 1;
//                    long long left = 1;
//                    for (int g = 0; g < j - 1; ++g) {
//                        right = right * 5;
//                    }
//                    left = right * 5;
////                    count += (pow(5, j) - pow(5, j - 1)) * (k - j);
//                    count += (left - right) * (k - j);
//
//                }
//
//                count += k;
////                printf("%lld\n", count);
//                long long h = 1;
//                for (int g = 0; g < k; ++g) {
//                    h = h * 5;
//                }
//                count += (test - h) / 5;
//            }
//            printf("%lld\n", count);
//        }
//    }
//    return  0;
//}
//
//
//
//
//
//
//
//
