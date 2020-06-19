#include <stdio.h>
#include <stdlib.h>


struct Node
{
int data;

struct Node* next;
};

typedef struct Node* node_t;


void printList(node_t n)
{
    while(n!=NULL)
    {
    printf("%d\n",n->data);
    n = n->next;
    }
}
void push(node_t * head, int val) {
    node_t * current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    /* now we can add a new variable */
    current->next = (node_t *) malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
}
void reverse_display(struct node* head){
	if(head){
		//recursive call to display in reverse order
		reverse_display(head->next);
		printf("%d ",head->data);
	}
}

int main()
{

node_t head =NULL;
node_t first =NULL;
node_t second =NULL;

head = (node_t)malloc(sizeof(struct Node));
first = (node_t)malloc(sizeof(struct Node));
second = (node_t)malloc(sizeof(struct Node));

head->data = 0;
head->next = first;
first->data = 1;
first->next = second;
second->data = 2;
second->next = NULL;

printList(head);


    printf("Hello world!\n");
    return 0;
}
