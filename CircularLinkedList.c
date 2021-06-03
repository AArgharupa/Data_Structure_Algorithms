#include <stdio.h>
#include <stdlib.h>
typedef struct node //creating Node data type
{
    /* data */
    int data;
    struct node *next;

} node;
node *createNode(int nodes);
void display(node *start);
int listLength(node *head);
node *insertAtBegin(node *head);
void deleteAtEnd(node **head);
int main()
{

    int node1;
    printf("\nEnter the number opf 1st ll nodes: \n");
    scanf("%d", &node1);
    node *head = createNode(node1);
    //  display(head);
    node *ptr = head;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = head;
    //  printf("%d", listLength(head));

    //  head = insertAtBegin(head);
    display(head);
    printf("%d\n", listLength(head));
    deleteAtEnd(&head);
    display(head);
    printf("%d\n", listLength(head));
}
void display(node *start) //head
{
    if (start != NULL)
    {
        node *tmp = start; //head
        printf("The linked list is : \n");
        printf("%d\n", start->data);
        start = start->next;
        while (start != tmp)
        {
            printf("%d\n", start->data);
            start = start->next;
        }
    }
}
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
int listLength(node *head)
{

    int count = 0;
    if (head == NULL)
    {
        return count;
    }
    else if (head->next == head)
    {
        return ++count;
    }
    else
    {
        count = 1;
        node *ptr = head->next;
        while (ptr != head)
        {
            count++;
            ptr = ptr->next;
        }
        return count;
    }
}

node *insertAtBegin(node *head)
{
    node *ptr = (node *)malloc(sizeof(node)); //creating a node
    printf("Enter the data:\n");
    scanf("%d", &ptr->data);
    if (head == NULL)
    { //empty Linked List

        head = ptr;
        head->next = head;
        return head;
    }
    else if (head->next == head)
    { //linked list contaiining one node!

        ptr->next = head;
        head = ptr;
        ptr->next->next = head;

        return head;
    }
    else
    {

        ptr->next = head;
        head = ptr;
        ptr = head->next;
        while (ptr->next != head->next)
        {
            ptr = ptr->next;
        }
        ptr->next = head;
        return head;
    }
}

void deleteAtEnd(node **head)
{

    if (*head == NULL)
    {
        return;
    }
    else if ((*head)->next == *head)
    {
        free(*head);
        *head = NULL;
        return;
    }
    node *ptr1 = (*head)->next, *ptr2 = *head;
    while (ptr1->next != *head)
    {

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    ptr2->next = *head;
    free(ptr1);
}