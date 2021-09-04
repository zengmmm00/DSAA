#include <iostream>
#include <cstring>

using namespace std;
char s[200001];
char t[200001];

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        int n, m;
        scanf("%d %d", &n, &m);
        scanf("%s\n%s", s, t);
        int location = -1;
        for (int j = 0; j < n; ++j) {
            if (s[j] == '*')location = j;
        }
        bool check = true;
        if (location == -1) {
            if (m != n)check = false;
            else {

                for (int j = 0; j < n; ++j) {
                    if (s[j] != t[j]) {
                        check=false;
                        break;
                    }
                }

            }
        } else {
            if (m < n - 1) { check=false;}
            else {
                for (int j = 0; j <= location - 1; ++j) {
                    if (s[j] != t[j]) {
                        check = false;
                        break;
                    }
                }
                for (int j = 0; j < n - location - 1; ++j) {
                    if (s[n - 1 - j] != t[m - 1 - j]) {
                        check = false;
                        break;
                    }
                }
            }
        }
        if (check)printf("YES");
        else printf("NO");
        if (i != T - 1) printf("\n");
    }
    return 0;
}