#include <iostream>
#include <cmath>

#define ll long long
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        ll N = 0;
        ll K = 0;
        scanf("%lld %lld", &N, &K);
        if (N <= K)printf("%lld\n", N - 1);
        else {
            ll n = log(N * (K - 1) + 1) / log(K); // n = height - 1
            ll left = N - (1 - (ll) pow(K, n)) / (1 - K);
            if (left % K == 0)printf("%lld\n", (ll) pow(K, n - 1) + left - (left / K));
            else printf("%lld\n", (ll) pow(K, n - 1) + left - (left / K + 1));
        }
    }
    return 0;
}
