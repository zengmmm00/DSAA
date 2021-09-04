#include <iostream>
using namespace std;

int main() {
    int count ;
    cin >> count;
    for (int i = 0; i < count; ++i) {
        long long n;
        scanf("%d",&n);
        printf("%d\n",( n * (n + 1) * (2 * n + 1) / 6 + (n + 1) * n /2  ) / 2 );
    }
    return 0;
}