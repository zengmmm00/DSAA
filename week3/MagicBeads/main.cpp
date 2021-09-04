#include <iostream>
using namespace std;
struct str{
    long long red;
    long long blue;
    long long group;
};
void GroupMerge(str A[], long long start, long long end){
    long long n = end - start + 1;//size of B
    str B[n];
    long long i = start;
    long long j = start + n / 2;
    for (long long k = 0; k < n; ++k) {
        if((A[i].group < A[j].group && i <= start + n / 2 -1) || j > end){
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

void redMerge(str A[], long long start, long long end){//blue < red
    long long n = end - start + 1;//size of B
    str B[n];
    long long i = start;
    long long j = start + n / 2;
    for (long long k = 0; k < n; ++k) {
        if((A[i].blue< A[j].blue && i <= start + n / 2 -1) || j > end){
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

void BlueMerge(str A[], long long start, long long end){//blue > red
    long long n = end - start + 1;//size of B
    str B[n];
    long long i = start;
    long long j = start + n / 2;
    for (long long k = 0; k < n; ++k) {
        if((A[i].red > A[j].red && i <= start + n / 2 -1) || j > end){
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

void GroupmergeSort(str A[], long long start, long long end, int a){
    if(end - start >= 1){
        long long n = (end - start + 1) / 2;

        GroupmergeSort(A, start, start + n-1,a);
        GroupmergeSort(A, start + n, end,a);
//        GroupMerge(A, start, end);
        if(a == 0){ GroupMerge(A, start, end);}
        else if(a == 1){redMerge(A, start, end);}
        else{BlueMerge(A, start, end);}
    }
}
int main() {
    long long T;
    scanf("%lld",&T);
    for (long long i = 0; i < T; ++i) {
        long long n;
        long long count = 0;
        scanf("%lld",&n);

        str beads[n];
        long long zero = 0;
        long long two = 0;
        for (long long j = 0; j < n; ++j) {
            scanf("%lld", &beads[j].blue);
            scanf("%lld", &beads[j].red);
            if(beads[j].blue < beads[j].red){
                beads[j].group = 0;
                zero++;
            } else if(beads[j].blue == beads[j].red){
                beads[j].group = 1;

            } else{
                beads[j].group = 2;
                two++;
            }
        }
        if(n == 1){
            printf("0\n");
            continue;
        }

        GroupmergeSort(beads, 0, n - 1, 0);
        if(zero != 0){
           GroupmergeSort(beads, 0, zero - 1, 1);
        }
        if(two != 0){
            GroupmergeSort(beads, n - two , n - 1,2);
        }
        //sort finish
        for (int j = 0; j < n - 1; ++j) {
            if(beads[j].red > beads[j+1].blue){
                count +=beads[j+1].blue;
                beads[j+1].red += beads[j].red - beads[j+1].blue;
            } else{
                count += beads[j].red;
            }
        }
        printf("%lld\n",count);
    }
    return 0;
}