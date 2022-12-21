#include <stdio.h>
#define size 100
typedef struct
{
    int top;
    char data[size];
} stack;
void init(stack *stk)
{
    stk->top = -1;
}
int push(stack *stk, char v)
{
    if (stk->top == size - 1)
    {
        //printf("Stack-Overflow");
        return 1;
    }
    else
    {
        stk->top++;
        stk->data[stk->top] = v;
        //printf("Inserted Successfully\n");
    }
}
int pop(stack *stk)
{
    if (stk->top == -1)
    {
        //printf("Underflow");
        return 1;
    }
    else
    {
        //printf("Deleted Successfully-%c", stk->data[stk->top]);
        stk->top--;
        return 0;
    }
}
void display(stack *stk)
{
    printf("Displaying Stack\n");
    for (int i = 0; i <= stk->top; i++)
    {
        printf("%c\t", stk->data[i]);
    }
}
int main()
{
    stack s;
    init(&s);
    char str[100];
    printf("Enter Expression to Validate? ");
    scanf("%s", str);
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(')
        {
            push(&s, str[i]);
        }
        else if (str[i] == ')')
        {
            pop(&s);
        }
    }
    printf("Checking Validity of Expression\n");
    if (s.top == -1)
    {
        printf("Valid");
    }
    else
    {
        printf("INVALID EXPRESSION\n");
    }
    return 0;
}