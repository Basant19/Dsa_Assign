
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};
 

int printsqrtn(struct Node* head)
{
    struct Node* sqrtn = NULL;
    int i = 1, j = 1;    

    while (head!=NULL)
    {  
        
        if (i == j*j)
        {  
            
            if (sqrtn == NULL)
                sqrtn = head;
            else
                sqrtn = sqrtn->next;
             
               
            j++;
        }
        i++;
         
        head=head->next;
    }    
    
    return sqrtn->data;
}
 
void print(struct Node* head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data)
{
    
    struct Node* new_node =
            (struct Node*) malloc(sizeof(struct Node));   
   
    new_node->data = new_data;
     
    
    new_node->next = (*head_ref);
     
   
    (*head_ref) = new_node;
}
 

int main()
{
    
    struct Node* head = NULL;
    push(&head, 42);
    push(&head, 76);
     push(&head, 760);
      push(&head, 26);
      push(&head, 67); 
      push(&head, 97);
      push(&head, 77);
    push(&head, 200);
    push(&head, 10);
    printf("Given linked list is:");
    print(head);
    printf("sqrt(n)th node is %d ",printsqrtn(head));    
    return 0;
}