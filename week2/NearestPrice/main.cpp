#include <iostream>
using namespace std;

int meow(int t, int kind, int price[]){
    int left = 0;
    int right = kind - 1;
    while (left <= right){
        int mid = (left + right) / 2;
        if(t == price[mid]){
            return -1;
        } else if (t < price[mid]){
            right = mid - 1;
        } else{
            left = mid + 1;
        }
    }
    if(price[left - 1] <= t){
        return t - price[left - 1];
    } else{
        return -2;
    }
}

int main() {
    int day, kind;
    scanf("%d", &day);
    scanf("%d", &kind);

    int money[day];
    int price[kind];

    for (int i = 0; i < day; ++i) {
        scanf("%d", &money[i]);
    }

    for (int i = 0; i < kind; ++i) {
        scanf("%d", &price[i]);
    }
    for (int i = 0; i < day; ++i) {
        int ans = meow(money[i], kind, price);
        if(ans == -1){
            printf("Meow\n");
        } else if(ans == -2){
            printf("%d\n", money[i]);
        } else{
            printf("%d\n", ans);
        }
    }

    return 0;
}