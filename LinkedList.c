#include "LinkedList.h"
#include <stdlib.h>


list* list_create(double val) { //create an NULL pointer head
	return list_construct(val, NULL);
}

list* list_construct(double val, list* next) { //intend for internal use, not by the user
	//create a new node with desired val and next pointer
	list* n = malloc(sizeof(list));
	n->value = val;
	n->next = next;
	return n;
}

int list_length(list* head) {
	int count = 0;
	for (list* i = head; i != NULL; i = i->next) {//traverse the list
		count++;
	}
	return count;
}

void list_append(list* head, double val) {
	for (list* i = head; i != NULL; i = i->next) { //traverse the list
		if (i->next == NULL) { //i is now the last element
			i->next = list_construct(val, NULL); //append a new node
			return;
		}
	} 
}

list* list_add_front(list* head, double val) {
	return list_construct(val, head->next);
}

void list_add(list* head, int index, double val) {
	if (index == 0) {
		printf("use list_add_front()\n");
		return;
	}
	int j = 0;//current index
	for (list* i = head; i != NULL; i = i->next) {//traverse the list
		if (j == index-1) { //reached the desired index - 1
			i->next = list_construct(val, i->next);
			return;
		}
		j++;
	}
	printf("invalid index!\n");//no matched index found
}

double list_get(list* head, int index) {
	int j = 0;//current index
	for (list* i = head; i != NULL; i = i->next) {//traverse the list
		if (j == index) {//reached desired index
			return i->value;
		}
		j++;
	}
	printf("invalid index! Returned -1\n"); //no match index found
	return -1;
}

list* list_delete_front(list* head) {
	list* newHead = head->next;
	free(head);
	return newHead;
}

void list_delete(list* head, int index) { 
	if (index == 0) { //delete the first element of the list
		printf("use delete_front()\n");
		return;
	}
	int j = 0;//count for current index
	for (list* i = head; i != NULL; i = i->next) { //traverse through the list
		if (j == index-1) {//reach the desired index-1
			list* nextN = i->next; //find the next node which intend to delete
			i->next = i->next->next;
			free(i->next); //free the current node
			return;
		}
		j++;
	}
	printf("invalid index!\n");
}


void list_free(list* head) {
	list* c = head;//current node
	list* temp;
	while (c != NULL) {
		temp = c;
		c = c->next; //traverse the list
		free(temp); //delete the previous node
	}
}

void list_print(list* head) {
	printf("[");
	for (list* i = head; i != NULL; i = i->next) { //traverse the list
		if (i != head) { //print space
			printf(", ");
		}
		printf("%lf", i->value);
	}
	printf("]\n");
}
