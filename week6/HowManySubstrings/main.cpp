#include <iostream>
#include <cstring>
using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        char str [1001];
        scanf("%s", &str);
        int n = strlen(str);
        printf("%d", (n + 1) * n / 2);
        if (i != T -1) printf("\n");
    }
    return 0;
}