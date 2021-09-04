#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
int pattern_length = 0;
int text_length =0;
void Prefix(char pattern[], int prefix[]) {
    int j = 0;
    for (int i = 1; i < pattern_length; ++i) {
//        if(pattern[i] == pattern[j]){
//            prefix[j] = prefix[j-1] + 1;
//            i++;
//        } else{
//            i = 0;
//        }
        while (j != 0 && pattern[j] != pattern[i]) {
            j = prefix[j - 1];
        }
        if (pattern[j] == pattern[i]) {
            j++;
            prefix[i] = j;
        }
    }
}

bool KMP(char text[], int prefix[], char pattern[]) {
    int j = 0;
//    if (strlen(pattern) == 1) {
//        for (int i = 0; i < strlen(text); ++i) {
//            if (pattern[0] == text[i])return true;
//        }
//        return false;
//    }

    for (int i = 0; i < text_length; ++i) {

        while (j != 0 && pattern[j] != text[i]) {
            j = prefix[j - 1];
        }
        if (pattern[j] == text[i]) { j++; }

        if (j >= pattern_length)return true;
    }
    return false;
}

int main() {
    int n;
    scanf("%d", &n);
    int repeater = 0;
    for (int i = 0; i < n; ++i) {
        char pattern[10002];
        int prefix[10002] = {0};
        scanf("%s", pattern);
        pattern_length = ceil(strlen(pattern)/3);

        Prefix(pattern, prefix);
        char text[10002];
        scanf("%s", text);
        text_length = strlen(text);
        if (KMP(text, prefix, pattern))repeater++;
    }
    printf("%d", repeater);
    return 0;
}