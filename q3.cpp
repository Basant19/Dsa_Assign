
#include <bits/stdc++.h>

using namespace std;

  class Node {
  public:
	int data;
	Node* next;
};
Node* newNode(int data)
{
	Node* new_node = new Node;
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}
 Node* reverse(Node* head)
    {
        Node* prev=NULL;
        Node* curr=head;
        Node* nxt=NULL;
        
        while(curr != NULL)
        {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    
    void reorderList(Node* head) {
        
       
        Node* slow=head;
        Node* fast=head->next;
        
        while(fast != NULL && fast->next != NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
       
        Node* second=reverse(slow->next);
        slow->next=NULL;
        Node* first=head; 
        
        
        while(second != NULL)
        {
            Node* temp1=first->next;
            Node* temp2=second->next;
            first->next=second;
            second->next=temp1;
            first=temp1;
            second=temp2;
        }
    }
    void print(Node* head){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }


int main()
{
    Node* head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);
	print(head);
	reorderList(head);
	print(head);

    return 0;
}