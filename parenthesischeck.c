#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack{
    int size;
    int top;
    char *stk;
    char exp;
};
int isempty(struct stack *s){
    if (s->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
int isfull(struct stack *s){
    if (s->top == s->size - 1){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    struct stack *a;
    a = (struct stack*)malloc(sizeof(struct stack));
    a->top=-1;
    a->size=50;
    a->stk=(char *)malloc((a->size)*sizeof(char));
    char exp[50];
    printf("Enter the expression : ");
    scanf("%s",exp);
    // printf("%s",exp);
    int len = strlen(exp);
    // printf("%d",len);
    for (int i = 0; i <= len - 1; i++){
        if (strchr("([{", exp[i])){
            // a->stk=(char *)malloc(sizeof(char));
            a->top=a->top+1;
            a->stk[a->top]=exp[i];
        }
        else if(strchr(")]}", exp[i])){
            if(isempty(a)){
                printf("Encountered closed bracket first in expression\n");
                // free(a->stk);
                // free(a);
                break;
            }
            if((exp[i]==')'&&a->stk[a->top]=='(') || (exp[i]==']'&&a->stk[a->top]=='[') || (exp[i]=='}'&&a->stk[a->top]=='{')){
                a->top=a->top-1;
            }
        }
    }
    if(a->top==-1){
        printf("Paranthesis matched");
    }
    else{
        printf("Not matched");
    }
    // free(a->stk);
    // free(a);

    return 0;
}