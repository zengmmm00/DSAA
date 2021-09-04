#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int t,n;
    scanf("%d",&t);
    for (int i = 0; i < t; ++i) {
        scanf("%d",&n);
        char p[n+1];
        scanf("%s",p);
        sort(p,p+n);
        do{
            printf("%s\n",p);
        }while(next_permutation(p,p+n));
    }
    return 0;
}


