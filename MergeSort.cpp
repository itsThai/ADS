#include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;
	struct Node* next;
};

struct Node* sorted(struct Node* a, struct Node* b) {
	struct Node* result = NULL;
	if (a == NULL)
		return b;
	else if (b == NULL)
		return a;

	if (a->data <= b->data) {
		result = a;
		result->next = sorted(a->next, b);
	}
	else {
		result = b;
		result->next = sorted(a, b->next);
	} return result;
}

void split(struct Node* source, struct Node** front, struct Node** back) {
	struct Node* slow = source;
	struct Node* fast = source->next;

	if (source == NULL || source->next == NULL) {
		*front = source;
		*back = NULL;
		return;
	}
	while (fast != NULL) {
		fast = fast->next;
		if (fast != NULL) {
			slow = slow->next;
			fast = fast->next;
		}
	}
	*front = source;
	*back = slow->next;
	slow->next = NULL;
}
void push(struct Node** head, int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
}
void mergesort(struct Node** head) {
	struct Node* a;
	struct Node* b;

	if (*head == NULL || (*head) ->next == NULL)
		return;

	split(*head, &a, &b);
	mergesort(&a);
	mergesort(&b);
	*head = sorted(a, b);
}
void display(struct Node* head) {
	struct Node* ptr = head;
	while (ptr) {
		printf("%d, ", ptr->data);
		ptr = ptr->next;
	}
	printf("end.\n");
}
int main(void) {
	int arr[] = { 3,5,1,6,7,2,10 };
	int n = 7;

	struct Node *head = NULL;
	for (int i = 0; i < n; i++)
		push(&head, arr[i]);
	mergesort(&head);
	display(head);

	return 0;
}
//complexity O(NlogN)