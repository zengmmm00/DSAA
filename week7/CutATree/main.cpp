#include <iostream>
#include <vector>
#define Size 100002
using namespace std;
struct node {
    int value;
    int color;
    int red;
    int blue;
    vector<node *> son;
};
node *address[Size];
bool visit[Size];
void add_address(int a) {
    if (address[a] == nullptr) {
        node *p = new node{a};
        address[a] = p;
    }
}
int red_total;
int blue_total;
int count;
int num;
int N;
void sou(node *p) {
    if (!visit[p->value]) {
        visit[p->value] = true;
        for (int i = 0; i < p->son.size(); ++i) {
            if(visit[p->son[i]->value])continue;
            sou(p->son[i]);
            p->red+=p->son[i]->red;
            p->blue+=p->son[i]->blue;
        }
        if(p->red==0&&p->blue==blue_total||p->blue==0&&p->red==red_total)count++;
    }
}
int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        red_total = 0;
        blue_total = 0;
        count=0;
        scanf("%d", &N);
        if(N==1){printf("0\n");
            continue;}
        for (int j = 0; j < N - 1; ++j) {
            int a, b;
            scanf("%d %d", &a, &b);
            add_address(a);
            add_address(b);
            address[a]->son.push_back(address[b]);
            address[b]->son.push_back(address[a]);
        }
        for (int j = 0; j < N; ++j) {
            int c;
            scanf("%d", &c);
            if (c == 1){
                red_total++;
                address[j+1]->red++;
            }
            else if (c == 2){
                blue_total++;
                address[j+1]->blue++;
            }
        }
        sou(address[1]);
        if(address[1]->red==0&&address[1]->blue==blue_total||address[1]->blue==0&&address[1]->red==red_total)count--;
        for (int j = 1; j <= N; ++j) {
            visit[j]=false;
            address[j] = nullptr;
        }
        printf("%d\n",count);
    }
    return 0;
}