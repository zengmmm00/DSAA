#include <iostream>

#define ll long long
using namespace std;

struct node {
    char digit;
    node *next;
    node *last;
};

int main() {
    int T = 0;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        node *head = new node;
        node *tail = new node;
        head->next = tail;
        tail->last = head;
        tail->next = nullptr;
        node *p = head->next;
        ll n = 0;
        scanf("%lld", &n);
        char b;
        scanf("%c", &b);
        for (ll j = 0; j < n; ++j) {
            char input;
            scanf("%c", &input);
            switch (input) {
                case 'r':
                    if(j != n-1){
                        j++;
                        scanf("%c", &input);
                        if (p == tail) {
                            node *q = new node;
                            q->digit = input;
                            node *tmp = p->last;

                            p->last = q;
                            q->last = tmp;
                            tmp->next = q;
                            q->next = p;
                            p = p->last;
                        } else {
                            p->digit = input;
                        }
                    }
                    break;
                case 'I':
                    p = head->next;
                    break;
                case 'H':
                    if (p != head->next) {
                        p = p->last;
                    }
                    break;
                case 'L':
                    if (p != tail) {
                        p = p->next;
                    }
                    break;
                case 'x'://delete node at p position
                    if (p != tail) {
                        p =p->last;
//                        delete p->next;
                        p->next=p->next->next;
                        p->next->last=p;
                        p=p->next;//
                    }
                    break;
                default:
                    node *q = new node;
                    q->digit = input;
                    node *tmp = p->last;

                    p->last = q;
                    q->last = tmp;
                    tmp->next = q;
                    q->next = p;

//                    p = p->next;
                    break;
            }
        }
        node *trav = head->next;
        while (trav != tail) {
            printf("%c", trav->digit);
            trav = trav->next;
        }
        printf("\n");
        delete trav;
        trav = nullptr;
        delete head;
        head = nullptr;
    }
    return 0;
}