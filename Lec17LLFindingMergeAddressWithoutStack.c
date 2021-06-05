#include <stdio.h>
#include <stdlib.h>
typedef struct node //creating Node data type
{
    /* data */
    int data;
    struct node *next;

} node;
void display(node *start)
{
    if (start != NULL)
    {
        printf("The linked list is : \n");
        while (start)
        {
            printf("%d\n", start->data);
            start = start->next;
        }
    }
}

node *createNode(int);
int listLength();
node *findMergeAddress(node *head1, node *head2);

node *createNode(int nodes)
{

    node *head = NULL; //pointing the first node
    node *tmp1 = NULL;
    node *tmp2 = NULL;
    while (nodes > 0)
    {

        if (head == NULL)
        {
            head = (node *)malloc(sizeof(node));
            printf("Enter the data for Node: \n");
            scanf("%d", &head->data);
            head->next = NULL;
            tmp1 = head;
            tmp2 = head;
        }
        else
        {
            tmp2 = (node *)malloc(sizeof(node));
            printf("Enter the data for Node: \n");
            scanf("%d", &tmp2->data);
            tmp2->next = NULL;
            tmp1->next = tmp2;
            tmp1 = tmp2;
        }

        nodes--;
    }

    return head;
}
int main()
{
    int node1, node2;
    printf("Enter the number opf 1st ll nodes: \n");
    scanf("%d", &node1);
    node *head1 = createNode(node1);
    printf("Enter the number opf 2nd ll nodes: \n");
    scanf("%d", &node2);
    node *head2 = createNode(node2);

    node *ptr = head1->next->next->next->next;
    node *ptr2 = head2->next->next->next;
    ptr2->next = ptr;


    ptr = findMergeAddress(head1, head2);
    if (ptr != NULL)
    {
        printf("%d\n", ptr->data);
    }
}
int listLength(node *head)
{
    int count = 0;
    if (head == NULL)
    {
        return count;
    }
    else
    {
        node *p = head;
        while (p != NULL)
        {
            count++;
            p = p->next;
        }
        return count;
    }
}

node *findMergeAddress(node *head1, node *head2)
{
    int ll1 = listLength(head1);
    int ll2 = listLength(head2);
    int diff;
    if (ll1 > 1 && ll2 > 1)
    {
        node *j, *i;
        if (ll1 > ll2)
        {

            diff = ll1 - ll2;
            j = head1;
            i = head2;
        }
        else
        {

            diff = ll2 - ll1;
            j = head2;
            i = head1;
        }
        while (diff > 0) //m - n
        {
            j = j->next;
            diff--;
        }

        while (j->next != NULL && i->next != NULL ) // n
        {

            if (i == j)
            {
                return i;
            }
            j = j->next;
            i = i->next;
        }
    }
    else
    {
        printf("merge not possible");
        return NULL;
    }
    printf("merge not possible");
    return NULL;
}
