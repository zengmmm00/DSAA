#include <iostream>
using namespace std;
struct person{
    int height;
    int index;
    person() {}
    person(int h, int i) : height(h), index(i) {};
};
person array[50010];
person stack[50010];
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
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        int n;
        scanf("%d", &n);
        //input array
        for (int j = 1; j <= n; ++j) {
            int input;
            scanf("%d", &input);
            person p(input, j);
            array[j] = p;
        }
        if(n == 1){
            printf("Case %d:\n0 0", i+1);
            if(i != T-1)printf("\n");
        } else{
            //look right
            push(array[1]);
            for (int j = 2; j <= n ; ++j) {//item = array[j].height
                int tmp= 0;
                while (array[j].height > stack[top].height && top != -1){
                    lookRight[stack[top].index] = tmp;
                    tmp = stack[top].index;
                    pop();
                }
                person big(array[j].height, j);
                push(big);
            }
            for (int j = 0; j < top; ++j) {
                lookRight[stack[j].index] = stack[j + 1].index;
            }
            lookRight[n] = 0;
            //look left
            top = -1;
            push(array[n]);
            for (int j = n-1; j >= 1 ; --j) {
                int tmp =0;
                while (array[j].height> stack[top].height && top != -1) {
                    lookLeft[stack[top].index] = tmp;
                    tmp = stack[top].index;
                    pop();
                }
                person big(array[j].height, j);
                push(big);
            }
            for (int j = 0; j < top; ++j) {
                lookLeft[stack[j].index] = stack[j+1].index;
            }
            lookLeft[1] = 0;
            printf("Case %d:\n", i+1);
            for (int j = 1; j <= n-1; ++j) {
                printf("%d %d\n", lookLeft[j], lookRight[j]);
            }
            printf("%d %d", lookLeft[n], lookRight[n]);

            if(i != T-1)printf("\n");
        }
        top = -1;
    }

    return 0;
}