#include <stdio.h>

int prime(int total){
    int n;
    for(n = 1; n <= total; n++){
        if(n == 1){
            continue;
        }
        else if(n == total && total % n == 0){
            printf("%d ", n);
            return n;
        }
        else if(total % n == 0 && n != total){
            printf("%d ", n);
            return n;
        }
        else{
            continue;
        }
    }
    return n;
}
int main(){
    int num, origin;
    scanf("%d",&num);
    origin = num;
    while(num != 1){
        num = num / (prime(num));
        if(origin == num){
            break;
        }
    }
    return 0;
}