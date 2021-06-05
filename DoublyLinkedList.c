#include <stdio.h>
#include <stdlib.h>
typedef struct node //creating Node data type
{
    /* data */
    int data;
    struct node *next;
    struct node *prev;

} node;
node *createNode(int nodes);
node* insertAtBegin(node* head);
node* deleteAtBegin(node *head);
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
int main(){

    int nodes;
    printf("\nEnter the number nodes : \n");
    scanf("%d", &nodes);
    node *head = createNode(nodes);

    display(head);
    // head = insertAtBegin(head);
    // display(head);

    head = deleteAtBegin(head);
    display(head);

    
   

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
            head->prev = NULL;
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
            tmp2->prev = tmp1;
            tmp1->next = tmp2;
            tmp1 = tmp2;
        }

        nodes--;
    }

    return head;
}

node* insertAtBegin(node* head){

     node * tmp1 = (node *)malloc(sizeof(node));
            printf("Enter the data for Node: \n");
            scanf("%d", &tmp1->data);
            tmp1->next = NULL;
            tmp1->prev = NULL;

    if(head == NULL){
        head = tmp1;

    }else{
        head->prev = tmp1;
        tmp1->next = head;
        head = tmp1;
    }
    tmp1 = NULL;
    return head;
}

node* deleteAtBegin(node *head){
    if(head == NULL){

        return NULL;

    }else if(head->next == NULL){
        free(head);
        head = NULL;
    }else{
        head->next->prev = NULL;
        node* ptr = head->next;
        free(head);
        head = ptr;
        ptr = NULL;
    }

    return head;


}