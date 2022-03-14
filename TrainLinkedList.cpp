#include <stdio.h>
#include <stdlib.h>

struct car  {
    int passenger;
    char name;
    struct car*next;
}
int length;

car*init(int i){
    car* head = NULL;
	car* curr = NULL;
	car* pointer = NULL;
	length = n;
    int i;
	for (i = 0; i < n; i++) {
		curr = (car *)malloc(sizeof(car));
		printf("Enter the number of passenger in car %d: ", i + 1);
		scanf("%d", &(curr->passenger));
		printf("Enter the name of the car %d: ", i+1);
		scanf("%s", &(curr->name));
		curr->next = NULL;
		if (head == NULL) {
			head = curr;
		}
		else {
			pointer = head;
			while (pointer->next != NULL) {
				pointer = pointer ->next;
			}
			pointer->next = curr;
		}
	}
    return head;
}

void display(car* head, int length) {
	car* curr = head;
	printf("Train's length: %d\n", length);
	while(curr != NULL) {
		printf("Car %s: %d passenger(s)\n", curr ->name, curr ->passenger);
		curr = curr ->next;
	}
}

car* remove(car* head) {
	while (head->passenger == 0) {
		head = head->next;
	}
	car* curr = head;
	car* previous = NULL;
	while (curr != NULL) {
		if(curr ->passenger != 0) {
			previous = curr;
		}
		else {
			previous->next = curr->next;
			length -= 1;
		}
		curr = curr->next;
	}
	return head;
}

car* insert(car* head) {
	car* curr = head;
	while(curr ->next != NULL) {
		curr = curr->next;
	}
	car* new_car;
	new_car = (car *)malloc(sizeof(car));
	printf("Enter the number of passengers in new car: ");
	scanf("%d", &(new_car ->passenger));
	printf("Enter the name of the new car: ");
	scanf("%s", &(new_car ->name));
	length += 1;
	curr -> next = new_car;
	new_car ->n ext = NULL;
	return head;
}

int main() {
	int n;	
	car* head = NULL;
	printf("Enter the number of cars: ");
	scanf("%d", &n);
	length = n;
	head = init(n);
	display(head, length);
	head = remove(head);
	printf("After removing empty car: \n");
	display(head, length);
	
 insert(head);
	printf("After adding new car: \n");
	display(head, length);
	
	return 0;
}



