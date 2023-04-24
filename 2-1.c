#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define NAME_LENGTH 50
#define True 1

struct node{
    char *name;
    struct node *next;
    struct node *prior;
    int *value;
};

struct node *insert(struct node **list, char *n, int *m){
    struct node *new_node;
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->name = (char*)malloc(sizeof(char) * NAME_LENGTH);
    new_node->value = (int*)malloc(sizeof(int) * 3);
    if (new_node == NULL) {
        printf("Error: malloc failed in add_to_list\n");
        exit(1);
    }
    strcpy(new_node->name, n);
    *(new_node->value) = *m;
    *(new_node->value + 1)= *(m + 1);
    *(new_node->value + 2) = *(m + 2);
    new_node->next = NULL;
    new_node->prior = NULL;
    if(*list == NULL){
        *list = new_node;
    }
    else{
        struct node *prev = *list;
        while(prev->next != NULL){
            prev = prev->next;
        }
        prev->next = new_node;
        new_node->prior = prev;
    }
    return new_node;
};

int main(){
    int son;
    char ccc;
    scanf("%d", &son);
    struct node *course = NULL;
    for(int i = 0; i < son; i++){
        int *num;
        char *coname;
        num = (int*)malloc(sizeof(int) * 3);
        coname = (char*)malloc(sizeof(char) * NAME_LENGTH);
        scanf("%d %d %d %s", &*(num+0), &*(num+1), &*(num+2), coname);
        insert(&course, coname, num);
    }
    struct node *sequence = course;
    printf("Current Course: %s\n[n] Next course. [p] Prior course [q] Quit:", sequence->name);
    while((ccc = getchar())!= 'q'){
        struct node *run = course;
        if(ccc == 'n'){
            while(*( run->value ) != *(sequence->value + 1)){
                if(run->next == NULL){
                    printf("\nThere is no next course.\n");
                    break;
                }
                run = run->next;
            }
            printf("\nCurrent Course: %s\n[n] Next course. [p] Prior course [q] Quit:", run->name);
            sequence = run;
        }
        else if(ccc == 'p'){
            while(run->next != NULL) {
		        run = run->next;
	        }
            while(*( run->value ) != *(sequence->value + 2)){
                if(run->prior == NULL){
                    printf("\nThere is no previous course.\n");
                    break;
                }
                run = run->prior;
            }
            printf("\nCurrent Course: %s\n[n] Next course. [p] Prior course [q] Quit:", run->name);
            sequence = run;
        }
    }
    return 0;
}