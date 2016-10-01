#include <stdio.h>
#include <stdlib.h>

#define nuthin 0
typedef struct node{
	int val;
	struct node* next;
} node;

int main(void){
	//declare your starting point, and your iterator
	node* head = malloc(sizeof(node));
	node* iterate;
	//this will print out how many nodes I free at the end
	int freeInt = 0; 
	
	//supply the value of head and set its pointer to null
	head->val = 65;
	head->next = NULL;
	//set the iterate to point to the same place as head
	iterate = head;

	for(int i = 0;i < 10;i++){
		//to create new elements, allocate the memory for
		//the next pointer and move iterate into that space
		iterate->next = malloc(sizeof(node));
		iterate = iterate->next;
		//then set the new node's pointer to null
		iterate->next = NULL;
		//set the value of iterate and print it
		iterate->val = (head->val + i);
		printf("%c\n", iterate->val);
	}
	
	//free up the memory and print freed!
	iterate = head;
	while(iterate->next != NULL){
		iterate = iterate->next;
		free(head);
		head = iterate;
		printf("Freed!\n");
		freeInt++;
	}
	free(head);
	freeInt++;
	printf("Number of nodes freed: %i\n", freeInt);
	
	return nuthin; 
}
