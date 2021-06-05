#include <stdio.h>
#include <stdlib.h>

int push(int s[], int N, int M, int topi, int i, int x);
int pop(int s[], int N, int M, int i, int topi);

int main()
{
    int M, N, i;
    printf("Enter the size of the Array: \n");
    scanf("%d", &N);
    printf("Enter the numbers of stack: \n");
    scanf("%d", &M);
    int s[M];
    printf("Enter the value of i: \n");
    scanf("%d", &i);

    int x1, x2;
    printf("Enter the data1: \n");
    scanf("%d", &x1);
    printf("Enter the data2: \n");
    scanf("%d", &x2);
    int topi = i * (N / M) - 1;
    topi = push(s, N, M, topi, i, x1);
    topi = push(s, N, M, topi, i, x2);

    printf("The stack is: \n");

    printf("%d\n", s[topi]);
    printf("%d\n", s[topi - 1]);
    printf("%d\n", pop(s, N, M, i, topi));

    return 0;
}

int push(int s[], int N, int M, int topi, int i, int x)
{

    if (topi == ((i + 1) * (N / M) - 1))
    {
        printf("Overflow");
        exit(0);
    }
    else
    {
        s[++topi] = x;
    }
    return topi;
}
int pop(int s[], int N, int M, int i, int topi)
{
    int temp;

    if (topi == i * (N / M) - 1)
    {
        printf("Underflow");
        exit(0);
    }
    else
    {
        temp = s[topi--];
    }
    return temp;
}