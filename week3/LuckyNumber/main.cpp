#include <iostream>
#include <list>
using namespace std;
void merge(int A[], int start, int end){
    int n = end - start + 1;//size of B
    int B[n];
    int i = start;
    int j = start + n / 2;
    for (int k = 0; k < n; ++k) {
        if((A[i] < A[j] && i <= start + n / 2 -1) || j > end){
            B[k] = A[i];
            i++;
        } else{
            B[k] = A[j];
            j++;
        }
    }
    for (int k = 0; k < n; ++k) {
        A[start + k] = B[k];
    }
}
void mergeSort(int A[], int start, int end){
    if(end - start >= 1){
        int n = (end - start + 1) / 2;

        mergeSort(A, start, start + n-1);
        mergeSort(A, start + n, end);
        merge(A, start, end);
    }
}
int main() {
    int num;
    scanf("%d", &num);
    int array[num];
    int k;
    scanf("%d", &k);
    for (int i = 0; i < num; ++i) {
        scanf("%d" , &array[i]);
    }
    mergeSort(array, 0, num - 1);
    printf("%d", array[k - 1]);
    return 0;
}