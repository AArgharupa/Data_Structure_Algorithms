#include <stdio.h>
#include <stdlib.h>
typedef struct node //creating Node data type
{
    /* data */
    int data;
    struct node *next;

} node;

node *head = NULL; //pointing the first node
node *tmp1 = NULL;
node *tmp2 = NULL;
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
void createNode();
int listLength();
void insertAtBegin();
void insertAtEnd();
void insertAtPosition();
node *middle();
node *middleUsingListLength();
void DeleteAtBegin();
node *reverse();
void findCycle();
int main()
{
    int n;
    printf("Enter the number of nodes: \n");
    scanf("%d", &n);
    if (n >= 1)
    {
        for (int i = 1; i <= n; i++)
        {
            createNode();
        }
    }
    else
    {
        printf("Thank u");
    }

    // tmp1 = head;

    // printf("The length of the linked list is : \n");
    // int length = listLength(head);
    // if (length == 0)
    // {
    //     printf("The linked list is empty");
    // }
    // else
    // {
    //     printf("%d\n", length);
    // }
    // int pos;
    // printf("Enter the pos: \n");
    // scanf("%d", &pos);
    // insertAtPosition(pos);
    // printf("New LL is: \n");
    //insertAtBegin(&head);
  //  display(head);

  //  display(reverse());

    // DeleteAtBegin();
    // display(head);
    // printf("The length of the linked list is : \n");
    // length = listLength(head);
    // if (length == 0)
    // {
    //     printf("The linked list is empty");
    // }
    // else
    // {
    //     printf("%d\n", length);
    // }
    // node *mid = middle();
    // if (mid != NULL)
    //     printf("%d\n", mid->data);
    // mid = middleUsingListLength();
    // if (mid != NULL)
    //     printf("%d\n", mid->data);
    head->next->next->next = head;
    findCycle();

    return 0;
}
void createNode()
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
}

int listLength()
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
void insertAtBegin()
{

    node *temp = (node *)malloc(sizeof(node));

    if (temp == NULL)
    {
        exit(0);
    }
    else
    {
        printf("Enter the data for Node: \n");
        scanf("%d", &temp->data);
        temp->next = head;
        head = temp;
    }
}

void insertAtEnd()
{

    node *temp = (node *)malloc(sizeof(node));
    if (temp != NULL)
    {
        printf("Enter the data for Node: \n");
        scanf("%d", &temp->data);
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            node *p;
            p = head;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = temp;
        }
    }
}

void insertAtPosition(int pos)
{

    int length = listLength();
    if (pos <= 0 || pos > length + 1)
    {
        printf("Invalid position\n");
    }
    else if (pos == 1)
    {
        insertAtBegin();
    }
    else if (pos == 1)
    {
        insertAtEnd();
    }
    else
    {

        node *temp = (node *)malloc(sizeof(node));

        if (temp == NULL)
        {
            exit(0);
        }
        else
        {
            printf("Enter the data for Node: \n");
            scanf("%d", &temp->data);
            node *p = head;
            while (pos - 2)
            {
                p = p->next;
                pos--;
            }
            node *tmp = p->next;
            p->next = temp;
            temp->next = tmp;
        }
    }
}

node *middle()
{
    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
node *middleUsingListLength()
{

    int n = listLength();
    node *ptr = head;
    for (int i = 1; i < ((n + 1) / 2); i++)
    {
        ptr = ptr->next;
    }

    return ptr;
}

void DeleteAtBegin()
{

    if (head != NULL)
    {
        node *tmp = head;
        head = head->next;
        free(tmp);
        tmp = NULL; //to avoid dangling pointer
    }
}

void DeleteAtLast()
{
    if (head == NULL)
    {
        return;
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        node *p = head, *q = NULL;
        while (p->next != NULL)
        {
            q = p;
            p = p->next;
        }
        q->next = NULL;
        free(p);
        p = NULL; //to avoid dangling pointer
    }
}

void deleteAtPosition(int pos)
{

    int length = listLength();
    if (pos <= 0 || pos > length)
    {
        printf("Invalid Location\n");
        return;
    }
    else if (pos == 1)
    {
        DeleteAtBegin();
    }
    else if (pos == length)
    {
        DeleteAtLast();
    }
    else
    {
        node *ptr;
        for (int i = 1; i < pos - 1; i++)
        {
            ptr = ptr->next;
        }
        node *q = ptr->next;
        ptr->next = ptr->next->next;
        free(q);
        ptr = NULL;
        q = NULL;
    }
}

node *reverse()
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    else
    {

        node *ptr1 = head, *ptr2 = head->next, *tmp;
        while (ptr2)
        {
            tmp = ptr2->next;
            ptr2->next = ptr1;
            if (ptr1 == head)
            {
                ptr1->next = NULL;
            }
            ptr1 = ptr2;
            ptr2 = tmp;
        }
        head = ptr1;
        return head;
    }
}

void findCycle(){

    node *fast = head, *slow = head;
    while(fast!=NULL || fast->next != NULL || fast->next->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            printf("Cycle exists\n");
            return;
        }
    }
    printf("Cycle not exists\n");
}

