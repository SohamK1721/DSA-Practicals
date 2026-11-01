#include <stdio.h>
void create (int arr[], int size) {
	printf("Enter %d elements :\n", size);
	for(int i= 0; i<size; i++) {
		scanf("%d", &arr[i]);
	}
}
void disp(int arr[],int size) {
	for(int i= 0; i<size; i++) {
		printf("%d \t", arr[i]);
	}
}
void search (int arr[], int size,int key) {
	int found = 0;

	for (int i = 0 ; i<size ; i++) {

		if ( arr[i]==key) {
			printf("\nelement found ! Element is %d \n", key);
			found = 1;
			break;
		}
	}
	if (found == 0) {
		printf("\nelement not found\n");
	}

}
void Binsearch(int arr[],int size, int key) {
	int Low = 0 ;
	int High = size - 1 ;
	int Mid;
	
	while(Low <= High) {
		Mid  = (High+Low)/2;
		if (key==arr[Mid]) {
			printf("Element found !!\n");
			return;
		}
		else if (key<arr[Mid]) {
			//Low = 0;
			High = Mid -1 ;
		}
		else {
			//Low = Mid +1 ;
			High = size - 1;
		}
	}
	printf("Element not found !!");
}
void displayMenu()
{
	printf("\n");
	printf("<<----------- MENU ------------>>\n");
	printf("1. Display Array\n");
	printf("2. Linear Search\n");
	printf("3. Binary Search\n");
	printf("4. Show Menu\n");
	printf("5. Exit\n");
	printf("<<------------------------------>>\n");
	printf("Enter your choice: ");
}

int main() {
	int arr[5];
	int key ;
	int choice;
	printf("Enter key to search: \n");
	scanf("%d", &key);
	create(arr,5);
	displayMenu();
	scanf("%d", &choice);
	while(choice != 5)
	{
		switch(choice)
		{
		case 1:
			printf("\nArray elements are:\n");
			disp(arr, 5);
			break;
		case 2:
			printf("\nEnter key to search: ");
			scanf("%d", &key);
                                   search(arr, 5, key);
			break;
		case 3:
			printf("\nEnter key to search: ");
			scanf("%d", &key);
			Binsearch(arr, 5, key);
			break;
		case 4:
			displayMenu();
			break;
		default:
			printf("\nInvalid choice! Please enter a number from 1 to 5.\n");
		}

		printf("\nEnter your choice: ");
		scanf("%d", &choice);
	}

	return 0;
}
