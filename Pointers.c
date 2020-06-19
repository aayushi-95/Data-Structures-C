#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int val;
    struct node* next;
}node_t;


void printList(node_t * head)
{
    node_t * current = head;
    if(head==NULL)
        printf("List is empty");

    else
    {
        while(current)
        {
            printf("%d-> ",current->val);
            current = current->next;
        }
    }
}

void enqueue(node_t * head, int val)
{

    node_t * current = head;
    if(head==NULL)
      {
         printf("List is empty");
         head->val = val;
         head->next = NULL;
      }

    else
    {

        while(current->next!=NULL)
        {

            current = current->next;
        }
    current->next = (node_t*)malloc(sizeof(node_t));
        current->next->val = val;
        current->next->next= NULL;

    }
}

void push(node_t ** head, int val)
{
    node_t * new_node = NULL;
    new_node = (node_t*)malloc(sizeof(node_t));

    new_node->val = val;
    new_node->next = *head;
    *head = new_node;
}

int pop(node_t** head)
{
    node_t * temp = NULL;
    int retval = -1;

    if(*head==NULL)
        return -1;

    temp = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = temp;

    return retval;


}

int remove_last(node_t* head)
{
    int retval = -1;
     node_t * current = head;
     node_t * temp_node = NULL;
    if(head==NULL)
      {
         printf("List is empty");
      }


      else if(head->next==NULL)
      {
          retval = head->val;
          free(head);
          return retval;
      }
    else
    {

        while(current->next->next!=NULL)
        {

            current = current->next;
        }


       retval = current->next->val;
       free(current->next);
       current->next = NULL;

       return retval;

    }

}


int remove_by_index(node_t** head, int n)
{
    int i =0;
    int retval = -1;
    node_t * current = *head;
    node_t * temp_node = NULL;


    if(n==0)
    {
        return pop(head);
    }

    for(i=0;i<n-1;i++)
    {
        if(current->next==NULL)
        {
            return -1;//Meaning that index does not exist, as the link is shorter
        }

        current = current->next;
    }

    temp_node = current->next;
    retval = temp_node->val;
    current->next = temp_node->next;
    free(temp_node);

    return retval;


}


int remove_by_val(node_t** head, int val)
{
    node_t *previous, *current;
    if(*head==NULL)
    {
        return -1;
    }

    if((*head)->val==val)
    {
        return pop(head);
    }

    previous = current = (*head);

    while(current)
    {
        if(current->val==val)
        {
            previous->next = current->next;
            free(current);
            return val;
        }

        previous = current;
        current = current->next;
    }

    return -1;
}

int main()
{
    printf("Iterating over a linked list\n");

    node_t * head = NULL;
    node_t*first=NULL;
    node_t *second = NULL;
    head = (node_t*)malloc(sizeof(node_t));
     first = (node_t*)malloc(sizeof(node_t));
      second = (node_t*)malloc(sizeof(node_t));
    head->val = 1;
    head->next = first;
    first->val = 2;
    first->next = second;
    second->val = 3;
    second->next = NULL;

    enqueue(head,4);
    push(&head,13);
int n = pop(&head);
printf("Value popped: %d\n",n);

int m = remove_last(head);
printf("Last Value Removed: %d\n",m);

int l = remove_by_index(&head,1);
printf("Element at index 2 removed was: %d\n",l);

    printList(head);


remove_by_val(&head, 3);
printf("Element 3 was removed\n");

    printList(head);
}
