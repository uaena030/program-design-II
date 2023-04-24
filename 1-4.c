#include <stdio.h>
#include <string.h>

int main(){
    int j = 0, check = 0, oh, su, lol = 0;
    char str1[100000], str2[100000];
    gets(str1);
    gets(str2);
    su = strlen(str1);//6
    oh = strlen(str2);//3
    str1[su] = '\0';
    str2[oh] = '\0';
    for(int k = 0; k < su - 1; k++){
        if(str1[k] == str2[j] && str1[k] != ' '){
            lol++;
            j++;
            if(lol == oh){
                check++;
            }
        }
        else if(str1[k] == ' '){
            lol = 0;
            j = 0;
        }
        else if(j < oh){
            j++;
        }
    }
    printf("%d\n", check);
    return 0;
}