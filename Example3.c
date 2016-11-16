#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

struct mystr {
	struct mystr *next, *prev;
	int age; 
	int name[64]; 
	char *message; 
} *head; 
int main()
{
	int i = 1; 
	struct mystr *ptr1, *ptr2, *ptr3; 
	ptr1 = malloc(sizeof(struct mystr));
	ptr2 = malloc(sizeof(struct mystr)); 
	ptr3 = malloc(sizeof(struct mystr)); 

	ptr1 -> message = malloc(128); 
	ptr2 -> message = malloc(128); 
	ptr3 -> message = malloc(128); 

	ptr3 -> next = 0; 
	ptr1 -> next = ptr2; 
	ptr2 -> next = ptr3; 
	ptr1 -> prev = 0; 
	ptr3 -> prev = ptr2; 
	ptr2 -> prev = ptr1; 

	head = ptr1; 

	for(ptr1 = head;  ptr1 != 0; ptr1 = ptr1 -> next) 
	{
		printf("%d age : ", i); 
		scanf("%d", &ptr1 -> age); 
		printf("%d  name : ", i); 
		scanf("%s", ptr1 -> name); 
		printf("%d message : ", i); 
		scanf("%s", ptr1 -> message); 
		i++; 
	}

	i = 1; 
	for(ptr1 = head; ptr1 != 0; ptr1 = ptr1 -> next) 
	{
		printf("%d age : %d \n", i, ptr1 -> age); 
		printf("%d name : %s \n", i, ptr1 -> name); 
		printf("%s message : %s \n", i, ptr1 -> message);
		i++; 
	}

	return 0; 
}

