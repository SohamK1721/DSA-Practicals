#include <stdio.h>
int length(char[]);
void compare(char[], char[]);
void palindrom(char[]);
void substring(char[], char[]);
void copy(char[], char[]);
void reverse(char[]);
void displayMenu();

int i, j;
int main()
{
    int choice;
    char str[50];
    char str2[50];
    int exit = 0;
    displayMenu();
    do
    {
        printf("ENTER CHOICE (7 for Display Menu):\n");
        scanf("%d", &choice);
        if(choice != 7 && choice != 8)
        {
            printf("Enter String: ");
            scanf("%s", str);
        }
        switch(choice)
        {
            case 1:
                printf("Length of the String is %d\n\n", length(str));
                break;
            case 2:
                printf("Enter second String: ");
                scanf("%s", str2);
                copy(str, str2);
                break;
            case 3:
                reverse(str);
                break;
            case 4:
                palindrom(str);
                break;
            case 5:
                printf("Enter substring String: ");
                scanf("%s", str2);
                substring(str, str2);
                break;
            case 6:
                printf("Enter second String: ");
                scanf("%s", str2);
                compare(str, str2);
                break;
            case 7:
                displayMenu();
                break;
            case 8:
                exit = 1;
                break;
            default:
                printf("Invalid Choice\n");
        }
    }while(exit == 0);
    return 0;
}
void displayMenu()
{
    printf("\n<<-----------Menu------------->>\n");
    printf("1. Length\n");
    printf("2. Copy String in another String\n");
    printf("3. Reverse String\n");
    printf("4. Check for Palindrome\n");
    printf("5. Check for substring\n");
    printf("6. Compare String with another\n");
    printf("7. Display Menu\n");
    printf("8. Exit\n");
}
int length(char a[])
{
    int len = 0;
    while(a[len] != '\0')
    {
        len++;
    }
    return len;
}
void compare(char str[], char str2[])
{
    int flag = 0;
    i = 0;
    while(str[i] != '\0' || str2[i] != '\0')
    {
        if(str[i] != str2[i])
        {
            flag = 1;
            break;
        }
        i++;
    }
    if(flag == 0)
        printf("Both Strings are Equal\n\n");
    else
        printf("Strings are Not Equal\n\n");
}
void palindrom(char a[])
{
    int l = length(a);
    int flag = 0;
    for(i = 0; i < l/2; i++)
    {
        if(a[i] != a[l-i-1])
        {
            flag = 1;
            break;
        }
    }
    if(flag == 0)
        printf("String is Palindrome\n\n");
    else
        printf("String is Not Palindrome\n\n");
}
void substring(char a[], char b[])
{
    int al = length(a);
    int bl = length(b);
    int flag = 0;
    int count = 0;
    for(i = 0; i <= al-bl; i++)
    {
        count = 0;
        for(j = 0; j < bl; j++)
        {
            if(a[i+j] == b[j])
                count++;
        }
        if(count == bl)
        {
            flag++;
        }
    }
    if(flag == 0)
    {
        printf("The String B is not substring of A\n\n");
    }
    else
    {
        printf("The String B is substring of A and it occurs %d times\n\n", flag);
    }
}
void copy(char a[], char b[])
{
    int i = 0;
    while(b[i] != '\0')
    {
        a[i] = b[i];
        i++;
    }
    a[i] = '\0';
    printf("Copied String is: %s\n\n", a);
}
void reverse(char a[])
{
    int al = length(a);
    char temp;
    for(i = 0; i < al/2; i++)
    {
        temp = a[i];
        a[i] = a[al-i-1];
        a[al-i-1] = temp;
    }
    printf("Reversed String is: %s\n\n", a);
}
