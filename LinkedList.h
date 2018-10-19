#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct node_struct {
	double value;
	struct node_struct* next;
} list;

list* list_create(double val);
list* list_construct(double val, list* next); //for internal use only
int list_length(list* head);
void list_append(list* head, double val);
list* list_add_front(list* head, double val);
void list_add(list* head, int index, double val);
double list_get(list* head, int index);
void list_delete(list* head, int index);
list* list_delete_front(list* head);
void list_free(list* head);
void list_print(list* head);
#endif // !LINKEDLIST_H

