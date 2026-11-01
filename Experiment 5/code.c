#include <stdio.h>

#define SIZE 5

struct stack
{
    int s[SIZE];
    int top;
} st;

int isFull(void)
{
    return st.top == SIZE - 1;
}

int isEmpty(void)
{
    return st.top == -1;
}

int pop(void)
{
    int item = st.s[st.top];
    st.top--;
    return item;
}

void push(int item)
{
    st.top++;
    st.s[st.top] = item;
}

void display(void)
{
    int i;

    if (isEmpty())
    {
        printf("\nStack is empty!!!\n");
    }
    else
    {
        printf("\nStack elements (Top to Bottom):\n");

        for (i = st.top; i >= 0; i--)
        {
            printf("%d\n", st.s[i]);
        }
    }
}

int main(void)
{
    int item, choice;
    char ans;

    st.top = -1;

    printf("\nImplementation of Stack");

    do
    {
        printf("\n\nMain Menu");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nEnter the item to be pushed: ");
                scanf("%d", &item);

                if (isFull())
                {
                    printf("\nStack is full (Overflow)!");
                }
                else
                {
                    push(item);
                    printf("\nItem pushed successfully.");
                }
                break;

            case 2:
                if (isEmpty())
                {
                    printf("\nEmpty stack (Underflow)!");
                }
                else
                {
                    item = pop();
                    printf("\nThe popped element is: %d", item);
                }
                break;

            case 3:
                display();
                break;

            case 4:
                printf("\nExiting program...");
                return 0;

            default:
                printf("\nInvalid choice!");
        }

        printf("\nDo you want to continue? (Y/N): ");
        scanf(" %c", &ans);

    } while (ans == 'Y' || ans == 'y');

    return 0;
}
