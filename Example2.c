#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

struct mystr {
	struct mystr *next, *prev; 
	int age;
	char name[64]; 
	char *message; 
} *head;

int main()
{
	struct mystr *ptr1, *ptr2; 
	ptr1 = malloc(sizeof(struct mystr));
	
	ptr1->age = 20; 
	strcpy(ptr1->name, "Lee Seong Won");

	ptr1 -> message = malloc(128); 
	strcpy(ptr1->message, "Hello, World!!"); 

	ptr2 = malloc (sizeof(struct mystr)); 
	ptr2 -> age = 22; 
	strcpy(ptr2->name, "president Park");

	ptr2 -> message = malloc(128); 
	strcpy (ptr2->message, "Good by~!!"); 

	ptr1 -> next = ptr2; 
	ptr1 -> prev = 0;  
	ptr2 -> next = 0;  
	ptr2 -> prev = ptr1; 

	head = ptr1; 

	printf("\n----------------------------\n");
	for(ptr1 = head; ptr1 != 0; ptr1 = ptr1 -> next)
	{
		printf("age = [%d]\n" , ptr1->age); 
		printf("message = [%s]\n\n", ptr1->message); 
	}
	
	for(ptr1 = head; ptr1->next != 0; ptr1 = ptr1->next); 
	free(ptr1->message); 
	ptr1->prev->next = 0; 
	free(ptr1); 

	for(ptr1 = head; ptr1 != 0; ptr1 = ptr1 -> next)
	{
		printf("age = [%d]\n" , ptr1->age); 
		printf("message = [%s]\n\n", ptr1->message); 
	}
	return 0;
}
