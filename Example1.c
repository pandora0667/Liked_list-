#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

struct mystr { 
	struct mystr *next, *prev; 
	int age; 
	char name[64]; 
	char *message; 
}; 

int main()
{
	struct mystr *head; 
	head = malloc (sizeof(struct mystr));

	head->age = 20; 
	strcpy (head->name, "Lee Seong Won"); 

	head->message = malloc(128); 
	strcpy (head->message, "Hello, World!!"); 
	
	printf("age = [%d]\n", head->age);
	printf("name = [%s]\n", head->name);
	printf("message = [%s]\n", head->message);

	return 0;
}

