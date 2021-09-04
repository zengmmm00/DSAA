#include <iostream>
#include <vector>
using namespace std;
struct node {
    long long key;
    bool root = true;
    long long value;
    vector<node *> vec;
};
node *address[100003];
long long queue[100003] = {0};
int main() {
    long long T;
    scanf("%lld", &T);
    for (long long j = 1; j <= 100002; ++j) {
        node *p = new node;
        p->key = j;
        address[j] = p;
    }
    for (long long i = 1; i <= T; ++i) {
        long long N;
        scanf("%lld", &N);
        for (long long j = 1; j <= N; ++j) {
            scanf("%lld", &address[j]->value);
        }
        if (N == 1) {
            printf("Case #%lld: YES\n", i);
            continue;
        }
        long long c, d;
        long long rootKey = -1;
        for (long long j = 0; j < N - 1; ++j) {
            scanf("%lld %lld", &c, &d);
            address[d]->root = false;
            address[c]->vec.push_back(address[d]);
        }
        bool mul = false;
        for (long long j = 1; j <= N; ++j) {
            if (address[j]->root && !address[j]->vec.empty()) {
                rootKey = j;
            }
            if (address[j]->vec.size() > 2) {
                mul = true;
                break;
            }
        }
        if (mul || rootKey == -1) {
            for (long long j = 1; j <= N; ++j) {
                address[j]->root = true;
                vector<node *>().swap(address[j]->vec);
            }
            printf("Case #%lld: NO\n", i);
            continue;
        }
        long long front = 0, rear = 1;
        queue[front] = rootKey;
        bool min_root = false;
        bool max_root = false;
        while (rear < N) {
            node *f = address[queue[front]];
            if (f->vec.empty())break;
            if (f->value > f->vec[0]->value) {
                max_root = true;
            } else if (f->value < f->vec[0]->value) {
                min_root = true;
            }
            if (max_root && min_root) {
                mul = true;
                break;
            }
            queue[rear++] = f->vec[0]->key;
            if (f->vec.size() == 1)break;
            if (f->value > f->vec[1]->value) {
                max_root = true;
            } else if (f->value < f->vec[1]->value) {
                min_root = true;
            }
            if (max_root && min_root) {
                mul = true;
                break;
            }
            queue[rear++] = f->vec[1]->key;
            front++;
        }
        if (mul) printf("Case #%lld: NO\n", i);
        else if (rear == N) printf("Case #%lld: YES\n", i);
        else printf("Case #%lld: NO\n", i);
        for (long long j = 1; j <= N; ++j) {
            address[j]->root = true;
            vector<node *>().swap(address[j]->vec);
        }
    }
    return 0;
}