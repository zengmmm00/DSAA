#include <iostream>
#include <cstring>
#include <algorithm>

#define ll long long
#define seed 139
using namespace std;
char s1[100001];
char s2[100001];
ll array1[100001] = {0};
ll array2[100001] = {0};
ll s1_length = 0;
ll s2_length = 0;
ll array1_length = 0;
ll array2_length = 0;

void Hash(char s[], ll array[], ll len, ll array_length) {
    ll base = 1;
    array[0] = (int) s[0];
    for (int i = 1; i < len; ++i) {
        base *= seed;
        array[0] = array[0] * seed + (int) s[i];
    }

    for (int i = 1; i < array_length; ++i) {
        array[i] = (array[i - 1] - (int) s[i - 1] * base) * seed + (int) s[i - 1 + len];
    }
}

bool check(ll len) {
    array1_length = s1_length - len + 1;
    array2_length = s2_length - len + 1;
    Hash(s1, array1, len, array1_length);
    Hash(s2, array2, len, array2_length);

    sort(array1, array1 + array1_length);
    for (int i = 0; i < array2_length; ++i) {
        ll left = 0;
        ll right = array1_length - 1;
        while (left <= right) {
            ll mid = (left + right) / 2;
            if (array1[mid] == array2[i]) {
                return true;
            } else if (array1[mid] > array2[i]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
    }
    return false;
}

int main() {
    scanf("%s", s1);
    scanf("%s", s2);
    s1_length = strlen(s1);
    s2_length = strlen(s2);
    ll right = s1_length < s2_length ? s1_length : s2_length;
    ll left = 0;
    if (check(right)) {
        printf("%lld", right);
    } else {
        ll mid = 0;
        while (left <= right) {
            mid = (left + right) / 2;
            if (check(mid)) {
                if(left == mid)break;
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        if(check(mid+1))mid++;
        printf("%lld", mid);
    }

    return 0;
}