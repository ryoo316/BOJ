#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct STACK_{
    int top;
    int memo[10000];
}STACK;

int empty(STACK *a)
{
    return a->top == -1;
}

int top(STACK *a)
{
    if(!empty(a))
        return a->memo[a->top];
    else
        return -1;
}

void push(STACK *a, int n)
{
    a->memo[++a->top] = n;
}

int pop(STACK *a)
{
    if(!empty(a))
        return a->memo[a->top--];
    else
        return -1;
}

int size(STACK *a)
{
    return a->top+1;
}


int main()
{
    int n;
    scanf("%d",&n);

   STACK stack;
   stack.top = -1;


    for(int i=1;i<=n;i++){
        char t[100];
        scanf("%s", t);

        if(strcmp("push", t) == 0){
            int n;
            scanf("%d", &n);
            push(&stack, n);
        }

        if(strcmp("pop", t) == 0){
            printf("%d\n", pop(&stack));
        }
        if(strcmp("size", t) == 0){
            printf("%d\n", size(&stack));
        }
        if(strcmp("empty", t) == 0){
            printf("%d\n", empty(&stack));
        }
        if(strcmp("top", t) == 0){
            printf("%d\n", top(&stack));
        }

    }
}
