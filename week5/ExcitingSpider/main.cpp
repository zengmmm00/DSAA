#include <iostream>

using namespace std;
int stack[300001];
bool exist[300001];
int array[300001];
int top = -1;
int n;
void push(int item) {
    top++;
    stack[top] = item;

}

void pop() {
    if (top != -1) {
        top--;
    }
}

bool smallestInLeft(int item, int j){
    if(top == -1)return false;
    for (int i = j; i <= n -1; ++i) {
        if(item > array[i])return false;
    }
    return true;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        scanf("%d", &n);

        for (int j = 0; j < n; ++j) {
            scanf("%d",&array[j]);
        }
        for (int j = 0; j < n; ++j) {
            int item = array[j];

            exist[item] = true;

            if (smallestInLeft(item, j+1)|| item == 1) {
                printf("%d ", item);

                while (smallestInLeft(stack[top],j+1)){
                    printf("%d ",stack[top]);

                    pop();
                }

            } else {
                push(item);
            }
        }
        for (int j = 0; j <= top; ++j) {
            printf("%d ", stack[top - j]);
        }
        for (int j = 0; j < n; ++j) {
            exist[j] = false;
        }
        top = -1;
        if(i != T-1)printf("\n");
    }
    return 0;
}