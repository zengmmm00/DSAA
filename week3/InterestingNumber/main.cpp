#include <iostream>
#include <algorithm>
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
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        int n;
        scanf("%d", &n);
        int array[n];
        for (int j = 0; j < n; ++j) {
            scanf("%d", &array[j]);
        }
        mergeSort(array,0,n-1);

        if(n == 3){
            if(array[0] == array[1]){
                printf("wa\n");
            } else{
                printf("%d\n", array[0]);
            }
        } else{
            if(array[n-3]==array[n-4] || array[n-3] == array[n-2]){
                printf("wa\n");
            } else{

                printf("%d\n", array[n-3]);
            }
        }
    }
    return 0;
}