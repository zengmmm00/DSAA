#include <iostream>
#include <list>
using namespace std;
//void merge(int A[], int start, int end){
//    int n = end - start + 1;
//    list<int> a;
//    list<int> b;
//    for (int i = start; i < start + n / 2; ++i) {
//        a.push_back(A[i]);
//    }
//    for (int i = start + n / 2; i <= end; ++i) {
//        b.push_back(A[i]);
//    }
//    list<int> c;
//    while(!a.empty() && !b.empty()){
//        if(a.front() > b.front()){
//            c.push_back(b.front());
//            b.pop_front();
//        } else{
//            c.push_back(a.front());
//            a.pop_front();
//        }
//    }
//    while (!a.empty()){
//        c.push_back(a.front());
//        a.pop_front();
//    }
//    while (!b.empty()){
//        c.push_back(b.front());
//        b.pop_front();
//    }
//    for (int i = 0; i < n; ++i) {
//        A[start + i] = c.front();
//        c.pop_front();
//    }
//}
void merge(int A[], int start, int end){
    int n = end - start + 1;//size of B
    int B[n];
    int i = start;
    int j = start + n / 2;
//    for (int k = 0; k < n; ++k) {
//        if((A[i] < A[j] && i <= start + n / 2 -1) || j > end){
//            B[k] = A[i];
//            i++;
//        } else{
//            B[k] = A[j];
//            j++;
//        }
//    }
    int k = 0;
    while (i<=start + n / 2-1&&j<=end){
        if(A[i]<A[j]){
            B[k] = A[i];
            i++;
            k++;
        } else{
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i<=start + n / 2-1){
        B[k] = A[i];
        i++;
        k++;
    }

    while (j<=end){
        B[k] = A[j];
        j++;
        k++;
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
    while (true){
        int w;
        cin >> w;
        int array[w];
        for (int j = 0; j < w; ++j) {
            cin >> array[j];
        }
        mergeSort(array,0,w-1);
        for (int i = 0; i < w; ++i) {
            cout << array[i] << endl;
        }
    }
    return 0;
}