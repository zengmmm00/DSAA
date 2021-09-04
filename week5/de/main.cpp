#include <bits/stdc++.h>//Don't delete this line

using namespace std;

struct node {
    int co, ex;
    node *nxt;
    node() {nxt = NULL;}
    node(int c, int e): co(c), ex(e) {nxt = NULL;}
};

int main() {
    int t; scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        node* head = new node(-1, -1); //make a special head node
        node* tail = head; //initial tail==head, new node will be connected after tail
        int n; scanf("%d", &n);
        for(int j = 0; j < n; j++) {
            int co, ex; scanf("%d%d", &co, &ex);
            node* tmp = new node(co, ex); //make a new node
            tail -> nxt = tmp; //connect tmp to tail
            tail = tmp; //now tmp is the new tail
        }
        int m; scanf("%d", &m);
        node* current = head;
        node* current1 = head -> nxt;
        for(int j = 0; j < m; j++) {
            int co, ex; scanf("%d%d", &co, &ex);
            node* tmp = new node(co, ex); //make a new node
            //find the position where tmp should be insert;
            while(current1 != NULL&&current -> ex < tmp -> ex && current1 -> ex <= tmp -> ex ) {//find the first position where ex > tmp -> ex
                current = current -> nxt;
                current1 = current1 -> nxt;
            }
            if(current != NULL&&current -> ex == tmp -> ex) current -> co += tmp -> co;
            else{
                tmp -> nxt = current1;
                current -> nxt = tmp; //insert tmp;
                current = tmp;
            }
//
        }
        int q; scanf("%d", &q);
            current = head -> nxt;
            for(int j = 0; j < q; j++) {
                long long k; scanf("%lld", &k);
                while(current->nxt != NULL&&current -> ex < k) {
                    current = current->nxt;

                }
                if(current -> ex == k)printf("%d ", current -> co);
                else printf("0 ");
            }
            printf("\n");
    }
    return 0;
}