#include <iostream>
char stack[30000];
int top = -1;
void push(char item){
    top++;
    stack[top] = item;
}

char pop(){
    if(top == -1){
        return 'f';
    } else{
        top--;
        return stack[top+1];
    }
}

bool check(char b, char bracket){
    if(b == '{' && bracket =='}')return true;
    if(b == '[' && bracket ==']')return true;
    if(b == '(' && bracket ==')')return true;
    return false;
}
int main() {
    int T;
    scanf("%d",&T);

    for (int i = 0; i < T; ++i) {
        bool ans = true;
        int left = 0;
        int right = 0;
        int n;
        scanf("%d\n", &n);
        if(n ==1){
            char bracket;
            scanf("%c", &bracket);
            printf("NO\n");
            continue;
        }
        for (int j = 0; j < n; ++j) {
            char bracket;
            scanf("%c", &bracket);
            if(bracket == '{' ||bracket =='('||bracket=='['){
                push(bracket);
                left++;
            } else{
                right++;
                if(!check(pop(), bracket)){
                    ans = false;
                }
            }
        }
        if(ans && left == right){
            printf("YES\n");
        } else{
            printf("NO\n");
        }
        top = -1;
    }
    return 0;
}