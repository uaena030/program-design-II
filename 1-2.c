#include <stdio.h>
#include <string.h>

int main(){
    int a;
    char str[100000];
    gets(str);
    scanf("%d",&a);
    switch(a){
        case 1:{
            for(int i= 0; str[i] != '\0'; i++){
                if(str[i] >= 'a' && str[i] <= 'z'){
                    str[i] -= 32;
                    printf("%c", str[i]);
                }
                else
                    printf("%c", str[i]); 
            }
            break;
        }
        case 2:{
            for(int i= 0; str[i] != '\0'; i++){
                if(str[i] >= 'A' && str[i] <= 'Z'){
                    str[i] += 32;
                    printf("%c", str[i]);
                }
                else
                    printf("%c", str[i]);
            }
            break;
        }
        case 3:{
            for(int i= 0; str[i] != '\0'; i++){
                if(i % 2 == 0 || i == 0){
                    if(str[i] >= 'a' && str[i] <= 'z'){
                        str[i] -= 32;
                        printf("%c", str[i]);
                    }
                    else
                        printf("%c", str[i]); 
                }
                else if(i % 2 != 0){
                    if(str[i] >= 'A' && str[i] <= 'Z'){
                        str[i] += 32;
                        printf("%c", str[i]);
                    }
                    else
                        printf("%c", str[i]);
                }
            }
            break;
        }
    }
    return 0;
}