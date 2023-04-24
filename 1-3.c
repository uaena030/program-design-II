#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    int a, b, k = 0, g = 0;
    scanf("%d\n",&a);
    scanf("%d\n",&b);
    char str[b][100];
    if(a == 1){
        for(int i = 0; i < b; i++){
            gets(str[i]);
        }
        metoo:for(int j = 0; str[0][j] != '\0'; j++){
            k++;
        }//9
        int str2[k+1];//10
        for(int j = 0; str[0][j] != '\0'; j++){
            str2[j] = str[0][j];
        }
        str2[k] = '\0';//9
        for(int i = 1; i < b; i++){
            if(str[i][0] != str2[0]){
                printf("No longest common prefix\n");
                return 0;
            }
            for(int j = 0; str[i][j] != '\0'; j++){
                if(str[1][j] != str2[j]){
                    str2[j] = '\0';
                    k = j;
                    break;
                }
                if(i != 1 && str[i][j] != str2[j]){
                    g = j;
                    if(k != g){
                        k = g;
                    }
                    break;
                }
            }
        }
        for(int j = 0; j < k; j++){
            printf("%c", str2[j]);
        }
    }
    else if(a == 2){
        for(int i = 0; i < b; i++){
            gets(str[i]);
            for(int j = 0; str[i][j] != '\0'; j++){
                str[i][j] = tolower(str[i][j]);
            }
        }
        goto metoo;
    }
    return 0;
}