#include <stdio.h>;
#include <stdlib.h>;

#define SIZE 5

int items[SIZE];
int front = -1, rear = -1;

int isFull() {
if ((front == rear + 1) || (front == 0 && rear == SIZE - 1))
return 1;
return 0;
}

int isEmpty() {
if (front == -1)
return 1;
return 0;
}

void enQueue(int element) {
if (isFull())
printf("\n Queue is full!! \n");
else {
if (front == -1)
front = 0;
rear = (rear + 1) % SIZE;
items[rear] = element;

printf("\n Inserted ->; %d\n", element);
}
}

int deQueue() {
int element;
if (isEmpty()) {
printf("\n Queue is empty !! \n");
return (-1);
} else {
element = items[front];
if (front == rear) {
front = -1;
rear = -1;
} else {
front = (front + 1) % SIZE;
}
printf("\n Deleted element ->; %d \n", element);
return (element);
}
}

void display() {
int i;
if (isEmpty())
printf("\n Empty Queue\n");
else {
printf("\n Front ->; %d ", front);

printf("\n Items ->; ");
for (i = front; i != rear; i = (i + 1) % SIZE) {
printf("%d ", items[i]);
}
printf("%d", items[i]);
printf("\n Rear ->; %d \n", rear);
}
}

int main() {
int choice, val;
while (1) {
printf("\n--- Circular Queue Menu ---");
printf("\n1. Insert");
printf("\n2. Delete");
printf("\n3. Display");
printf("\n4. Exit");
printf("\nEnter your choice: ");
scanf("%d", &choice);

switch (choice) {
case 1:
printf("Enter value to insert: ");
scanf("%d", &val);
enQueue(val);
break;
case 2:
deQueue();
break;
case 3:
display();

break;
case 4:
exit(0);
default:
printf("\nInvalid Choice!\n");
}
}
return 0;
}
