#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void push(int value);
void pop();
void display();

int stack[SIZE];
int top = -1;

int main()
{
    int value, choice;

    while (1) {
        printf("\n\n***** MENU *****\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            return 1;
        }

        switch (choice) {
        case 1:
            printf("Enter the value to insert: ");
            if (scanf("%d", &value) != 1) {
                printf("Invalid input.\n");
                return 1;
            }
            push(value);
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);

        default:
            printf("Wrong selection! Try again!\n");
        }
    }
}

void push(int value)
{
    if (top == SIZE - 1) {
        printf("Stack is full! Insertion is not possible.\n");
    } else {
        top++;
        stack[top] = value;
        printf(" successfully inserted %d.\n",stack[top]);
    }
}

void pop(void)
{
    if (top == -1) {
        printf("Stack is empty! Deletion is not possible.\n");
    } else {
        printf("Deleted: %d\n", stack[top]);
        top--;
    }
}

void display(void)
{
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}
