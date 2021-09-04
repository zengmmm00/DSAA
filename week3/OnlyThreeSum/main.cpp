#include <iostream>
using namespace std;
long long count;
void merge(long long A[], long long start, long long end){
    long long n = end - start + 1;//size of B
    long long B[n];
    long long i = start;
    long long j = start + n / 2;
    for (long long k = 0; k < n; ++k) {
        if((A[i] < A[j] && i <= start + n / 2 -1) || j > end){
            B[k] = A[i];
            i++;
        } else{
            B[k] = A[j];
            j++;
        }
    }
    for (long long k = 0; k < n; ++k) {
        A[start + k] = B[k];
    }
}
void mergeSort(long long A[], long long start, long long end){
    if(end - start >= 1){
        long long n = (end - start + 1) / 2;

        mergeSort(A, start, start + n-1);
        mergeSort(A, start + n, end);
        merge(A, start, end);
    }
}

int main() {
    long long n;
    scanf("%lld", &n);
    long long m;
    scanf("%lld", &m);
    long long array[n];
    for (long long i = 0; i < n; ++i) {
        scanf("%lld", &array[i]);
    }
    mergeSort(array, 0, n - 1);
    for (long long i = 0; i <= n-3; ++i) {//a1 = array[i]
        for (int j = i+1; j <= n-2; ++j) {
            long long third = m - array[i] - array[j];
            if(array[j] == third){
                long long sameThird = 0;
                while (array[j+ sameThird] == array[j+ sameThird + 1]){
                    sameThird++;
                }
                count+= (sameThird+1)*sameThird/2;
                j += sameThird;
                continue;
            }
            long long left = j + 1;
            long long right = n - 1;
            while (left <= right){
                long long numThird = 0;
                long long mid = (left + right) / 2;
                if(array[mid] == third){
                    numThird++;
                    for (long long k = mid + 1; k < n; ++k) {//go right
                        if(array[k] == array[k - 1]){numThird++;}
                        else{ break;}
                    }
                    for (int k = mid - 1; k >= 0 ; --k) {
                        if(array[k] == array[k + 1]){numThird++;}
                        else{ break;}
                    }

                    count += numThird;

                    break;

                } else if(array[mid] > third){
                    right = mid - 1;
                } else{
                    left = mid + 1;
                }
            }

        }
    }
    printf("%lld", count);

    return 0;
}