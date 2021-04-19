#include <stdio.h>
#include <stdlib.h>
#include "bibaLattice.h"

#define READ_ACCESS 0
#define WRITE_ACCESS 1

struct Object {
   char  title[50];
   int integrityLevel;
} object;

struct Subject {
   char  title[50];
   int integrityLevel;
} subject;

int accessType;

void printAccessLevels()
{
	printf("\nAccess Level: \n1. Untrusted\n2. User\n3. Application\n4. System\n5.Trusted\n \tEnter Number (1-5) : ");
}

void validateInput(int input, int rangeLimit)
{
	if(input<1 || input > rangeLimit)
	{
		printf("I\n\nnvalid input. Exiting...\n\n");
		exit(1);
	}		
}

void createSubject()
{
	int level;
	printf("Subject Name : " );
	scanf("%s", subject.title);
	printAccessLevels();
	scanf("%d", &object.integrityLevel);
	validateInput(object.integrityLevel, 5);
	printf("\n\n");
	
}

void createObject()
{
	printf("Object Name : " );
	scanf("%s", object.title);
	printAccessLevels();
	scanf("%d", &subject.integrityLevel);
	validateInput(subject.integrityLevel, 5);
	printf("\n\n");	
}

void getAccessType()
{
	printf("Access Type :\n1. Read Access\n2. Write Access\n3. Read & Write Access\n \tEnter Number (1-3) : " );
	scanf("%d", &accessType);
	validateInput(accessType, 3);
	printf("\n\n");
}

int readAccessCheck() 
{
	if(subject.integrityLevel < object.integrityLevel)
		return 0;
	return 1;
}

int writeAccessCheck() 
{
	if(subject.integrityLevel > object.integrityLevel)
		return 0;
	return 1;
}

int readAndWriteAccessCheck() 
{
	return readAccessCheck() && writeAccessCheck();
}

void printOutput(int output)
{
	printf("%s status for %s and %s : %s \n\n", (accessType==1) ? "Read Access" : (accessType==2) ? "Write Access" : "Read & Write Access", subject.title, object.title, (output == 0)?"DENIED" : "GRANTED");
	
}

int main(void)
{
	createSubject();
	createObject();
	getAccessType();
	switch(accessType)
	{
		case 1 : printOutput(readAccessCheck());
		break;
		case 2 : printOutput(writeAccessCheck());
		break;
		case 3 : printOutput(readAndWriteAccessCheck());
		break;
	}
	return 0;
}