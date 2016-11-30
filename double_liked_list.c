#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define SIZE 128

typedef struct USER
{
	char name[10]; 
	char *message; 
	char *address; 
	struct USER *link, *prev; 
} USER;

void add(USER **head, USER **tail, char *message, char *name, char *address);
//void delete();
void print(USER **head);
//void free(); 
void introduce(); 

int main()
{
	USER *next, *tail; 
	USER *head = NULL;
	char command[SIZE], name[SIZE], address[SIZE], message[SIZE];
	int age; 

	introduce(); 

	while(1)
	{

		printf("\nInput Command !! ( add, delete, print, end)  : ");
		scanf("%s", command);

		if( !strcmp(command, "add") ) 
		{
			printf("Input name, message, address \n ->"); 
			scanf("%s %s %s", name, message, address);
			add(&head, &tail, message, name, address);
		}
/*		else if( !strcmp(command, "del") )
			delete(); */
		else if( !strcmp(command, "print") )
			print(&head); 
		else if( !strcmp(command, "end") ) 
		{
			printf("Good By~!!\n\n"); 
			exit(1); 
		}
		else 
			printf(" Retry~!! \n\n");  
	}

//	free();

	return 0;
}

void introduce()
{
	printf("\n\n\t ---------- Double Linked List Example V.1.0 ----------\n\n");
}

void add(USER **head, USER **tail, char *message, char *name, char *address)
{
	USER *addUser;
	addUser = ( USER *)malloc( sizeof(USER) );
	if( addUser == NULL)
	{
		fprintf(stderr, "동적메모리 할당 실패!!\n"); 
		exit(1);
	}

	if( (*head) == NULL) 
	{
		(*head) = addUser; 
		(*tail) = addUser; 
		addUser -> link = addUser -> prev = NULL; 
		addUser -> message = (char *)malloc(SIZE);
		addUser -> address = (char *)malloc(SIZE);
	}
	else 
	{
		(*tail) -> link = addUser;
		(*tail) -> prev = (*tail);
		(*tail) = addUser;
		addUser -> message = (char *)malloc(SIZE);
		addUser -> address = (char *)malloc(SIZE);
	}

	strcpy( addUser -> name , name); 
	strcpy( addUser -> address, address); 
	strcpy( addUser -> message , message); 
}
/*
void delete()
{
	return;
}
*/
void print(USER **head)
{
	USER *tmp; 
	tmp = (*head); 

	system("clear"); 
	printf("\n\n"); 

	while( tmp != NULL)
	{
		printf("\t이름 : %s, 메시지 : %s, 주소 : %s\n", tmp -> name, tmp -> message, tmp -> address); 
		tmp = tmp -> link;
	}
}
/*
void free()
{
	return; 
}
*/
