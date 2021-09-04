#include <iostream>
#include <cmath>
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
            count+= A[i] * abs(k - (i-start));
            i++;
        } else{
            B[k] = A[j];
            count+= A[j] * abs((j-start)-k);
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
    long long array[n];
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &array[i]);
    }
    mergeSort(array, 0, n-1);
    printf("%lld" , count);
    return 0;
}