#include <stdio.h>
#include <stdlib.h>

int push(int s[], int N, int top, int x)
{
    if (top == N - 1)
    {
        printf("Overflow condition!");
        exit(0);
    }
    else
    {
        s[++top] = x;
    }
    return top;
}

int pop(int s[], int N, int top)
{
    if (top == -1)
    {
        printf("Underflow condition!");
        exit(0);
    }
    else
    {
        top--;
    }
    return top;
}

int main()
{
    int N;
    printf("Enter the size: \n");
    scanf("%d", &N);
    int s[N];
    int top = -1;
    int x;
    for (int i = 0; i < N; i++)
    {
        printf("Enter the data: \n");
        scanf("%d", &x);
        top = push(s, N, top, x);
    }

    printf("The stack is: \n");
    for (int i = 0; i < top; i++)
        printf("%d\n", s[i]);

    printf("The stack after pop: \n");
    top = pop(s, N, top);
    for (int i = 0; i < top; i++)
        printf("%d\n", s[i]);

    return 0;
}