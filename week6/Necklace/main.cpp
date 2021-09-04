#include <iostream>
#include <cstring>
using namespace std;
int prefix[200001] = {0};
char pattern[200001];
int pattern_length = 0;
void Prefix(){
    int j = 0;
    for (int i = 1; i < pattern_length; ++i) {
        while (j!=0&&pattern[j]!=pattern[i]){
            j = prefix[j-1];
        }
        if(pattern[i]==pattern[j]){
            j++;
            prefix[i] = j;
        } else prefix[i] = 0;
    }
}
int main() {
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%s",pattern);
        pattern_length = strlen(pattern);
        Prefix();
        if(prefix[pattern_length-1] == 0)printf("%d\n",pattern_length);
        else {
            int k =pattern_length%(pattern_length-prefix[pattern_length-1]);
            if(k == 0)printf("0\n");
            else printf("%d\n",pattern_length-prefix[pattern_length-1]-k);
        }
    }
    return 0;
}