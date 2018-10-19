#include "stdafx.h"
#include "LinkedList.h"
#include <stdlib.h>

int main() {
	list* l = list_create(0); //create a list with value 0
	list_append(l, 1);
	list_append(l, 2);
	list_append(l, 3);
	list_append(l, 4);
	list_print(l); //expected: [0, 1, 2, 3, 4]
	l = list_add_front(l,-2);
	list_add(l, 1, -1);
	list_add(l, 2, 0);
	list_print(l); //expected: [-2, -1, 0, 1, 2, 3, 4]
	list_delete(l, 6);
	l = list_delete_front(l);
	list_delete(l, 4);
	list_print(l); //expected: [-1, 0, 1, 2]
	printf("The length of list is: %d\n", list_length(l)); //expected: 4
	printf("The element on index 2 is: %lf\n", list_get(l, 2)); //expected: 1
	list_free(l);
	return 0;
}