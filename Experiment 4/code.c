#include <stdio.h> 
typedef struct student 
{ 
    char Name[40]; 
    int id; 
    float Marks; 
} stud; 
/* Function declarations */ 
void create(stud arr[]); 
void display(stud arr[]); 
void sort(stud arr[]); 
void search(stud arr[]); 
void modify(stud arr[]); 
int main() 
{ 
    int choice; 
    stud arr[5]; 
    do 
    { 
        printf("\n\n========== STUDENT MENU ==========\n"); 
        printf("1. Create Student Information\n"); 
        printf("2. Display Student Information\n"); 
        printf("3. Sort Students by Marks\n"); 
        printf("4. Search Student by ID\n"); 
        printf("5. Modify Student Information\n"); 
        printf("6. Exit\n"); 
        printf("==================================\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
        switch (choice) 
        { 
            case 1: 
                printf("\nEnter Student Information\n"); 
                create(arr); 
                break; 
            case 2: 
                printf("\nStudent Information\n"); 
                display(arr); 
                break; 
            case 3: 
                sort(arr); 
                break; 
            case 4: 
                search(arr); 
                break; 
            case 5: 
                modify(arr); 
                break; 
            case 6: 
                printf("\nExiting program...\n"); 
                break; 
            default: 
                printf("\nInvalid choice! Please enter a number from 1 to 6.\n"); 
        } 
    } while (choice != 6); 
    return 0; 
} 
/* Create Student Information */ 
void create(stud arr[]) 
{ 
    int i; 
 
    for (i = 0; i < 5; i++) 
    { 
        printf("\nEnter student %d name: ", i + 1); 
        scanf("%s", arr[i].Name); 
        printf("Enter student %d ID: ", i + 1); 
        scanf("%d", &arr[i].id); 
        printf("Enter student %d Marks: ", i + 1); 
        scanf("%f", &arr[i].Marks); 
    } 
} 
/* Display Student Information */ 
void display(stud arr[]) 
{ 
    int i; 
    for (i = 0; i < 5; i++) 
    { 
        printf("\nStudent %d Name : %s", i + 1, arr[i].Name); 
        printf("\nStudent %d ID   : %d", i + 1, arr[i].id); 
        printf("\nStudent %d Marks: %.2f\n", i + 1, arr[i].Marks); 
    } 
} 
/* Sort Students by Marks */ 
void sort(stud arr[]) 
{ 
    int i, j; 
    stud temp; 
    for (i = 0; i < 4; i++) 
    { 
        for (j = 0; j < 4 - i; j++) 
        { 
            if (arr[j].Marks < arr[j + 1].Marks) 
            { 
                temp = arr[j]; 
                arr[j] = arr[j + 1]; 
                arr[j + 1] = temp; 
            } 
        } 
    } 
    printf("\nStudents sorted by Marks (Highest to Lowest):\n"); 
    display(arr); 
} 
/* Search Student by ID */ 
void search(stud arr[]) 
{ 
    int id; 
    int i; 
    int found = 0; 
    printf("\nEnter Student ID to search: "); 
    scanf("%d", &id); 
    for (i = 0; i < 5; i++) 
    { 
        if (arr[i].id == id) 
        { 
            printf("\nStudent Found!\n"); 
            printf("Name  : %s\n", arr[i].Name); 
            printf("ID    : %d\n", arr[i].id); 
            printf("Marks : %.2f\n", arr[i].Marks); 
            found = 1; 
            break; 
        } 
    } 
 
    if (found == 0) 
    { 
        printf("\nStudent with ID %d not found.\n", id); 
    } 
} 
/* Modify Student Information */ 
void modify(stud arr[]) 
{ 
    int id; 
    int i; 
    int found = 0; 
    printf("\nEnter Student ID to modify: "); 
    scanf("%d", &id); 
    for (i = 0; i < 5; i++) 
    { 
        if (arr[i].id == id) 
        { 
            printf("\nStudent Found!\n"); 
            printf("Enter new name: "); 
            scanf("%39s", arr[i].Name); 
            printf("Enter new ID: "); 
            scanf("%d", &arr[i].id); 
            printf("Enter new Marks: "); 
            scanf("%f", &arr[i].Marks); 
            printf("\nStudent information modified successfully!\n"); 
            found = 1; 
            break; 
        } 
    } 
    if (found == 0) 
    { 
        printf("\nStudent with ID %d not found.\n", id); 
    } 
}
