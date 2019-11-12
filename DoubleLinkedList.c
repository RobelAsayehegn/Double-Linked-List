#include<stdio.h>
#include <stdlib.h>



struct node {
    int data;
    struct node * prev;
    struct node * next;
}*head, *last;

struct node *current = NULL;
void createList(int n);
void displayList();
void insertAtBeginning(int data);
void insertAtEnd(int data);
void insertAtN(int data, int position);
void deleteFromBeginning();
void deleteFromEnd();
void deleteFromN(int position);

int main(){
	
	int s,j=2,r;
	int n, data, position;
	do{ printf("\n#####################################################################\n");
		printf("Enter one to create List \n");
		
		printf("\nEnter two to add item at the begginning \n");
		printf("\nEnter three to add item at the end(last) \n");
		printf("\nEnter four add item at the middle \n");
		
		printf("\nEnter five to delete item at the begginning \n");
		printf("\nEnter six to delete item at the end(last) \n");
		printf("\nEnter seven delete item at the middle \n");
		printf("\nEnter eight to search an item \n");
		printf("\n#####################################################################\n");
		scanf("%d",&s);
	switch(s)
    {
	    case 1:
	    	printf("Enter the total number of nodes in list: ");
            scanf("%d", &n);

            createList(n);
            printf("\nData in the list \n");
    		displayList();
            break;
	    case 2:
	    	printf("Enter data of first node : ");
            scanf("%d", &data);

            insertAtBeginning(data);
            printf("\nData in the list \n");
    		displayList();
            break;
	    case 3:
	    	printf("Enter data of last node : ");
            scanf("%d", &data);

            insertAtEnd(data);
            printf("\nData in the list \n");
    		displayList();
            break;
	    case 4:
	  		printf("Enter the position where you want to insert new node: ");
            scanf("%d", &n);
            printf("Enter data of %d node : ", n);
            scanf("%d", &data);

            insertAtN(data, n);
            printf("\nData in the list \n");
    		displayList();
            break;
	    case 5:
		    deleteFromBeginning();
		    printf("\nData in the list \n");
    		displayList();
		    break;
	    case 6:
		    deleteFromEnd();
		    printf("\nData in the list \n");
    		displayList();
		    break;
	    case 7:
		    printf("Enter the node position which you want to delete: ");
            scanf("%d", &n);
            deleteFromN(n);
    		printf("\nData in the list \n");
    		displayList();
		    break;
		case 8:
		    printf("Enter the item you want to search: ");
            scanf("%d", &n);
            search(n);
    		printf("\nData in the list \n");
    		displayList();
		    break;

	    default:
	    	printf("no operation for this number");
    }j = 1;
printf("\nif you want to continue press num>0 else press 0:");
scanf("%d",&r);
}while(j<=r);
	
}

void createList(int n)
{
    int i, data;
    struct node *newNode;

    if(n >= 1)
    {
        
        head = (struct node *)malloc(sizeof(struct node));

        printf("Enter data of 1 node: ");
        scanf("%d", &data);

        head->data = data;
        head->prev = NULL;
        head->next = NULL;

        last = head;

        
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            printf("Enter data of %d node: ", i);
            scanf("%d", &data);

            newNode->data = data;
            newNode->prev = last; 
            newNode->next = NULL;

            last->next = newNode; 
            last = newNode;       
        }

        printf("\nlist created successfully\n");
    }
}

void displayList()
{
    struct node * temp;
    int n = 1;

    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        temp = head;
        printf("data in the list:\n");
        while(temp != NULL)
        {
            printf("DATA of %d node = %d\n", n, temp->data);
            n++;
            temp = temp->next;
        }
    }
}


void insertAtBeginning(int data)
{
    struct node * newNode;
    if(head == NULL)
    {
        printf("Error, List is Empty!\n");
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = head; 
        newNode->prev = NULL; 
        head->prev = newNode;
        head = newNode;
        printf("element created successfully\n");
    }
}


void insertAtEnd(int data)
{
    struct node * newNode;

    if(last == NULL)
    {
        printf("Error, List is empty!\n");
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = last;
        last->next = newNode;
        last = newNode;

        printf("element inserted successfully\n");
    }
}



void insertAtN(int data, int position)
{
    int i;
    struct node * newNode, *temp;

    if(head == NULL)
    {
        printf("Error, List is empty!\n");
    }
    else
    {
        temp = head;
        i=1;

        while(i<position-1 && temp!=NULL)
        {
            temp = temp->next;
            i++;
        }

        if(position == 1)
        {
            insertAtBeginning(data);
        }
        else if(temp == last)
        {
            insertAtEnd(data);
        }
        else if(temp!=NULL)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            newNode->data = data;
            newNode->next = temp->next; 
            newNode->prev = temp;        

            if(temp->next != NULL)
            {
               
                temp->next->prev = newNode;
            }
         
            temp->next = newNode;

            printf("element inserted successfullyn");
        }
        else
        {
            printf("Error, Invalid position\n");
        }
    }
}



void deleteFromBeginning()
{
    struct node * toDelete;

    if(head == NULL)
    {
        printf("Unable to delete. List is empty.\n");
    }
    else
    {
        toDelete = head;

        head = head->next; 
        
        if (head != NULL)
            head->prev = NULL; 

        free(toDelete); 
        printf("element deleted successfully.\n");
    }
}



void deleteFromEnd()
{
    struct node * toDelete;

    if(last == NULL)
    {
        printf("Unable to delete. List is empty.\n");
    }
    else
    {
        toDelete = last;

        last = last->prev; 
        
        if (last != NULL)
            last->next = NULL; 

        free(toDelete);
        printf("elemet deleted successfully.\n");
    }
}



void deleteFromN(int position)
{
    struct node *current;
    int i;

    current = head;
    for(i=1; i<position && current!=NULL; i++)
    {
        current = current->next;
    }

    if(position == 1)
    {
        deleteFromBeginning();
    }
    else if(current == last)
    {
        deleteFromEnd();
    }
    else if(current != NULL)
    {
        current->prev->next = current->next;
        current->next->prev = current->prev;

        free(current); 

        printf("deleted successfully.\n");
    }
    else
    {
        printf("Invalid position!\n");
    }
}

void search(int data) {
   int pos = 0;
   struct node *temp;
   
   if(head==NULL) {
      printf("Linked List not initialized");
      return;
   } 

   current = head;
   while(current!=NULL) {
      pos++;
      if(current->data == data) {
         printf("%d found at position %d\n", data, pos);
         
         printf("\n############################################\n");
         printf("press one for previous\n");
         printf("press two for next");
         printf("\n#############################################\n");
         
		 int con;
		 scanf("%d",&con);
         switch(con){
         	case 1:
         		temp = current->prev;
         		printf("the previous number is %d",temp->data);
         		break;
         	case 2:
         		temp = current->next;
         		printf("the next number is %d",temp->data);
         		break;
         	default:
         		printf("please enter valid number(1,2)");
         		break;
         		
		 }
         return;
      }

      if(current->next != NULL)
         current = current->next;
      else
         break;
   }

   printf("%d does not exist in the list\n", data);
}
