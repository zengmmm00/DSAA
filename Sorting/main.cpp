#include <iostream>
using namespace std;
int Partition(int A[], int lo, int hi){
    int p = rand() / (hi - lo + 1) + lo;
    int pivot = A[p];
    int L = lo;
    int R = hi;
    int B[sizeof(A)];

    for (int i = lo; i <= hi; ++i) {
        if(A[i] < pivot){
            B[L++] = A[i];
        } else{
            B[R--] = A[i];
        }
    }

}

int main() {

    return 0;
}