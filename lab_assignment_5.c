#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#pragma warning(disable:4996)

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	int count = 0;
	if (head != NULL) {
		count++;
		while (head->next != NULL) {
			count++;
			head = head->next;
		}
	}
	return count;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	int n = length(head);
	int i = 0;
	char* str = (char*)malloc((n+1) * sizeof(char));
	node* temp = head;
	if (temp != NULL) {
		for (i = 0; i < n; i++) {
			str[i] = temp->letter;
			temp = temp->next;
		}
		str[n] = '\0';
	}
	return str;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node* temp = (node*)malloc(sizeof(node));
	temp->letter = c;
	temp->next = NULL;
	if (*pHead == NULL) {
		*pHead = temp;
	}
	else {
		node* tmp = *pHead;
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = temp;
	}
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	while (*pHead != NULL) {
		node* temp = *pHead;
		*pHead = (*pHead)->next;
	}
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt", "r");

	fscanf(inFile, " %d\n", &numInputs);

	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile, " %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}