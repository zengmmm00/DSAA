#include <iostream>

#define ll long long
using namespace std;
struct node {
    ll id;
    node *next;
    node *last;
};

void insertNode(ll n, node *head, node *array[]) {
    head->last = nullptr;
    ll input = 0;
//    scanf("%lld", &input);
//    array[input] = head;
    head->id = -1;
//    node *second = new node;
//    head->next = second;

    node *p = head;
    for (int i = 0; i < n+1; ++i) {
        if (i == n ) {
            node *tmp = new node;
            tmp->last = p;
            p->next = tmp;
            tmp->next = nullptr;
        } else {
            node *tmp = new node;

            scanf("%lld", &input);
            array[input] = tmp;
            tmp->id = input;
            tmp->last = p;
            p->next = tmp;
            p = tmp;
        }

    }
}

void traverse(node *head) {
    node *p = head->next;
    while (p->next != nullptr) {
        printf("%lld ", p->id);
        p = p->next;
    }
    printf("\n");
}

int main() {
    int T = 0;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        ll n = 0;
        ll m = 0;
        scanf("%lld", &n);
        scanf("%lld", &m);
        node *head = new node;
        node *array[n];
        insertNode(n, head, array);
        ll x1, y1, x2, y2;
        for (int j = 0; j < m; ++j) {
            scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);

            node *oneStart = array[x1];
            node *oneEnd = array[y1];
            node *twoStart = array[x2];
            node *twoEnd = array[y2];

            if (oneEnd->next != twoStart) {//fen
                node *a = oneStart->last;
                node *b = oneEnd->next;
                node *c = twoStart->last;
                node *d = twoEnd->next;

                a->next = twoStart;
                twoEnd->next = b;
                c->next = oneStart;
                oneEnd->next = d;
                twoStart->last = a;
                b->last = twoEnd;
                oneStart->last = c;
                d->last = oneEnd;

            } else {//lian
                node *a = oneStart->last;
                node *b = twoEnd->next;

                a->next=twoStart;
                twoEnd->next=oneStart;
                oneEnd->next=b;
                twoStart->last=a;
                oneStart->last=twoEnd;
                b->last=oneEnd;
            }
        }
        traverse(head);
    }
    return 0;
}