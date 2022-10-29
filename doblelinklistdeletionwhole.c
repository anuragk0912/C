#include <stdio.h>
#include <stdlib.h>
 

struct node {
    int data;
    struct node *prev, *next;
};
struct node* start = NULL;

 traverse(struct node *start)
{
    
    if (start == NULL) {
        printf("\nList is empty\n");
        return;
    }
    
    struct node* temp;
    temp = start;
    while (temp != NULL) {
        printf("Data = %d\n", temp->data);
        temp = temp->next;
    }
}
 
struct node* insertAtFront(struct node *start)
{
    int data;
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    newnode->data = data;
    newnode->prev = NULL;
 
    
    newnode->next = start;
    start = newnode;
    return start;
}
 
struct node* insertAtEnd(struct node *start)
{
    int data;
    struct node *newnode, *trav;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->prev = NULL;
    newnode->next = NULL;
    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    newnode->data = data;
    newnode->next = NULL;
    trav = start;
 
    
    if (start == NULL) {
 
        start = newnode;
    }
 
    
    else {
        while (trav->next != NULL){
            trav = trav->next;
        }
        newnode->prev = trav;
        trav->next = newnode;
        return start;
    }
}
 

struct node* insertAtPosition(struct node *start)
{
    int data, pos, i = 1;
    struct node *temp, *newnode;
    newnode = malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->prev = NULL;
 
    printf("\nEnter position : ");
    scanf("%d", &pos);
    
    if (start == NULL) {
        start = newnode;
        newnode->prev = NULL;
        newnode->next = NULL;
    }

    else if (pos == 1) {
      
      insertAtFront(start);
    }

    else {
      printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    newnode->data = data;
    temp = start;
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next = newnode;
        temp->next->prev = newnode;
    }
    return start;
}

struct node* deleteatfront(struct node* start){
    struct node *temp;
    if(start==NULL){
        printf("\n list is empty");
    }
    else{
        temp =start;
        start=start->next;
        start->prev = NULL;
        free(temp);
		return start; 
    }
}

struct node* deleteatEnd(struct node* start)
{
     struct node *temp;
    if(start==NULL){
        printf("\n list is empty");
    }
    
    while(temp->next!=NULL) {
        temp=temp->next;
    }
    if(start->next==NULL){
        start=NULL;
    }
    else{
        temp->prev->next=NULL;
        free(temp);
    } 
	return start; 
}

struct node* deleteatspot(struct node* start){
	struct node* p;
	struct node* q;
	struct node* ptr;
	ptr=start;
	q=start;
	printf("Enter a number to be deleted\n");
	int pos;
	scanf("%d", &pos);
	while(q->data !=pos)
	{
		p=q;
		q=q->next;
	}
	ptr=q;
	p->next=q->next;
	q->next->prev=p;
	free(ptr);
	return start;
}
	
 
 

int main()
{
   int choice;
   struct node* start;
    while (choice !=8) {
 
        printf("\n1 Traversing \n");
        printf("2  For insertion at"
                " starting\n");
        printf("3  For insertion at"
               " end\n");
        printf("4  For insertion at "
               "any position\n");
        printf("5  For delete at front\n");
        printf("6  For delete at end\n");
        printf("7  To exit\n");
        printf("8 for delete at position");
        printf("\nEnter Choice :\n");
        scanf("%d", &choice);
 
        switch (choice) {
        case 1:
            traverse(start);
            break;
        case 2:
            start=insertAtFront(start);
            break;
        case 3:
            start=insertAtEnd(start);
            break;
        case 4:
            start=insertAtPosition(start);
            break;
        case 5:
           start= deleteatfront(start);
            break;
        case 6:
            start=deleteatEnd(start);
            break;
        case 8:
        	start=deleteatspot(start);
		    break;    
        case 7:
            exit;
            break;
        }
    }
    return 0;
}
