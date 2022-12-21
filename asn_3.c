#include <stdio.h>
#include <conio.h>
#define size 100
typedef struct
{
    int top;
    int data[size];
    int top_min;
    int min[size];
}stack;
void init(stack *stk)
{
    stk->top = stk->top_min = -1;
}
int push(stack *stk, int v)
{
    if (stk->top == size - 1)
    {
        printf("Stack-Overflow");
        return 1;
    }
    else
    {
        stk->top++;
        stk->data[stk->top] = v;
        if(v<stk->min[0])
        {
            // printf("Inserted Element in Minimum Stack");
            stk->top_min++;
            stk->min[stk->top_min]=v;
        }
        // printf("Inserted Successfully\n");
    }
}
int getMin(stack *stk)
{
    int x;
    x= stk->min[stk->top_min];
    return x;
}
int pop(stack *stk)
{
    if (stk->top == -1)
    {
        printf("Underflow\n");
        return 1;
    }
    else
    {
        // printf("Deleted Successfully-%c", stk->data[stk->top]);
        if(stk->min[stk->top_min]==stk->data[stk->top])
        {
            stk->top_min--;
        }
        stk->top--;
        return 0;
    }
}
void display(stack *stk)
{
    printf("Displaying Stack\n");
    for (int i = 0; i <= stk->top; i++)
    {
        printf("%d\t", stk->data[i]);
    }
}
int main()
{
    stack stk;
    init(&stk);
    push(&stk, 5);
    push(&stk, 20);
    push(&stk, 30);
    push(&stk, 3);
    push(&stk, 12);
    push(&stk, 2);
    int x= getMin(&stk);
    printf("Minimum Element- %d\n",x);
    pop(&stk);
    x= getMin(&stk);
    printf("Minimum Element- %d\n",x);
    pop(&stk);
    x= getMin(&stk);
    printf("Minimum Element- %d\n",x);
    pop(&stk);
    x= getMin(&stk);
    printf("Minimum Element- %d\n",x);
    pop(&stk);
    x= getMin(&stk);
    printf("Minimum Element- %d\n",x);
    pop(&stk);
    x= getMin(&stk);
    printf("Minimum Element- %d\n",x);
    pop(&stk);
    printf("Minimum Element- %d\n",x);
    pop(&stk);
    printf("Minimum Element- %d\n",x);
    return 0;
}