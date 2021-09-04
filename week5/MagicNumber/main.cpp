#include <iostream>

#include<ctime>
using namespace std;

struct person {
    int height;
    int index;
    person() {}
    person(int h, int i) : height(h), index(i) {};
};

person stack[50010];
person array[50010];
int top = -1;
int lookRight[50010];
int lookLeft[50010];

void push(person item) {
    top++;
    stack[top] = item;
}

void pop() {
    if (top != -1) { top--; }
}

int main() {

    time_t begin,end;
    double ret;
    begin=clock();

    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        int n;
        scanf("%d", &n);
        for (int j = 0; j < n; ++j) {
            int input;
            scanf("%d", &input);
            person p(input, j + 1);
            array[j] = p;
        }
        //look right
        push(array[0]);
        if (n == 1) { lookRight[1] = 0; }
        else {
            for (int j = 1; j < n; ++j) {
                int item;
                item = array[j].height;
                int tmp = 0;
                while (item > stack[top].height && top != -1) {
                    lookRight[stack[top].index] = tmp;
                    tmp = stack[top].index;
                    pop();
                }
                person big(item, j + 1);
                push(big);
            }
        }
        for (int j = 0; j < top; ++j) {
            lookRight[stack[j].index] = stack[j + 1].index;
        }
        lookRight[n] = 0;
        //look left
        top = -1;
        push(array[n - 1]);
        if (n == 1) { lookLeft[1] = 0; }
        else {
            for (int j = n - 2; j >= 0; --j) {
                int item;
                item = array[j].height;
                int tmp = 0;
                while (item > stack[top].height && top != -1) {
                    lookLeft[stack[top].index] = tmp;
                    tmp = stack[top].index;
                    pop();
                }
                person big(item, j + 1);
                push(big);
            }
        }
        for (int j = top - 1; j >= 0; --j) {
            lookLeft[stack[j].index] = stack[j + 1].index;
        }
        lookLeft[0] = 0;
        printf("Case %d:\n", i+1);
        if(i == T-1){
            for (int k = 1; k <= n-1; ++k) {
                printf("%d %d\n", lookLeft[k], lookRight[k]);
            }
            printf("%d %d", lookLeft[n], lookRight[n]);
        } else{
            for (int k = 1; k <= n; ++k) {
                printf("%d %d\n", lookLeft[k], lookRight[k]);
            }
        }
        top = -1;
    }

    end=clock();
    ret=double(end-begin)/CLOCKS_PER_SEC;
    cout<<"runtime:   "<<ret<<endl;

    return 0;
}