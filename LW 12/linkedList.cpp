#include<stdio.h>
#include<malloc.h>

typedef struct _node{
	int val;
	struct _node *next;
}Node;

            
Node * arrayToLinkedList(int arr[],int size)
{
	Node *head;
	Node *temp;
	int i;
	
	head = (Node *) malloc(sizeof(Node));
    temp = head;
    
	for(i=0;i<size;i++){
		if(i == size - 1){
			temp->val = arr[i];
			temp->next = NULL;
		}else{
			temp->val = arr[i];
			temp->next = (Node *)malloc(sizeof(Node));
			temp = temp->next;
		}
	}
	return head;
}

void addToLast(Node * head,int val){
	
	Node *temp = head;
	while(temp->next != NULL)
		temp = temp->next;
	
    temp->next = (Node *) malloc(sizeof(Node));
    temp->next->val = val;  
	temp->next->next = NULL;        
}


void removeLast(Node *head){
    Node *temp = head;
	while(temp->next->next != NULL)   
        temp = temp->next;
	free(temp->next);
	temp->next= NULL;
}


int addToIndex(Node ** head,int val,int n)
{
	Node* temp = *head;
	if (n == 0){
        *head = (Node *) malloc(sizeof(Node));
        (*head)->val = val;
        (*head)->next = temp;
        return 0;
    }
    
    for (int i=0; temp!=NULL && i<n-1; i++)
         temp = temp->next;
    if (temp == NULL || temp->next == NULL)
         return -1;
 
	Node *toBeAdded = (Node *) malloc(sizeof(Node));
	toBeAdded->val = val;
	
    Node *next = temp->next;
	temp->next = toBeAdded;
    toBeAdded->next = next;
	return 0;
}


int removeByIndex(Node ** head,int n){
	Node* temp = *head;
	if (n == 0){
        *head = temp->next;  
        free(temp);           
        return 0;
    }
    
    for (int i=0; temp!=NULL && i<n-1; i++)
         temp = temp->next;

    if (temp == NULL || temp->next == NULL)
         return -1;
    
    Node *next = temp->next->next;
    free(temp->next);  
    temp->next = next;
	return 0;
}

void printList(Node *head){
	Node *temp = head;
	while(temp){
		printf("%d ",temp->val);
		temp = temp->next;
	}
	printf("\n");
}

int main(){
	
	int arr[10] = {0,1,2,3,4,5,6,7,8,9};
	Node *list;
	list = arrayToLinkedList(arr,10);
	printList(list);
	
	addToLast(list,10);
	printList(list);
	
	removeLast(list);
	printList(list);
	
	removeByIndex(&list,0);
	printList(list);
	
	addToIndex(&list,0,0);
	printList(list);
	
	removeByIndex(&list,4);
	printList(list);
	
	addToIndex(&list,4,4);
	printList(list);
}

