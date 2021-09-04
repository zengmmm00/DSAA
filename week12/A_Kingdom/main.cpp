#include <iostream>
using namespace std;
int matix[1003][1003];
int main() {
    int T;
    scanf("%d",&T);
    for (int i = 0; i < T; ++i) {
        int n,m;
        scanf("%d %d",&n,&m);
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <=n ; ++k) {
                matix[j][k]=0;
            }
        }
        for (int j = 0; j < m; ++j) {
            int a,b;
            scanf("%d %d",&a,&b);
            matix[a][b] = matix[a][b] + 1;
        }
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <=n ; ++k) {
                printf("%d ",matix[j][k]);
            }
            printf("\n");
        }

    }
    return 0;
}