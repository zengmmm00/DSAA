#include <iostream>
using namespace std;
long long length;
long long target;
long long count;

void find(long long t, long long array[]){
    if(array[t] != 0 &&target % array[t] == 0){

        long long left = t + 1;
        long long right = length - 1;
      long long toFind = target / array[t];
      while (left <= right){
          long long mid = (left + right) / 2;
          if(array[mid] == toFind){
              count++;
//              printf("er");
//              cout << count << endl;
              return;
          } else if (array[mid] > toFind){
              right = mid -1;
          } else{
              left = mid + 1;
          }
      }
    }
}

int main() {
    scanf("%lld", &length);
    scanf("%lld", &target);
    long long array[length];
    for (long long i = 0; i < length; ++i) {
        scanf("%lld", &array[i]);
    }

    if(target == 0){
        for (int i = 0; i < length; ++i) {
            if(array[i] == 0 ){
                count++;
            }
        }
//        cout << count << endl;
        if(count == 0){
            printf("0");
        } else if(count == 1){
            long long n = length - 1;
            for (int i = 0; i < length; ++i) {
                if(array[i] != 0&&i != 0 && array[i] == array[i - 1]){
                    n--;
                }
            }
            printf("%lld", n);
        } else{//count >=2
            long long n = length - count + 1;
            for (int i = 0; i < length; ++i) {
                if(array[i] != 0 &&i != 0 && array[i] == array[i - 1]){
                    n--;
                }
            }
            printf("%lld",n);
        }
    } else{
        for (long long i = 0; i < length; ++i) {
            if(i != 0 && array[i] == array[i - 1]){
                continue;
            } else{
                find(i, array);
            }
        }
        printf("%lld", count);
    }

    return 0;
}