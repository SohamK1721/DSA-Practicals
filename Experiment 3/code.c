#include <stdio.h>

// Function declarations
void bubble_sort(int arr[], int n);
void insertion_sort(int arr[], int n);
void selection_sort(int arr[], int n);
void quick_sort(int arr[], int low, int high);
void merge_sort(int arr[], int left, int right);
void display_menu(void);
void swap(int *a, int *b);
int partition(int arr[], int low, int high);
void merge(int arr[], int left, int mid, int right);
void display_array(int arr[], int n);

// Display array
void display_array(int arr[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

// Bubble Sort
void bubble_sort(int arr[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("\nThe bubble sorted array is:\n");
    display_array(arr, n);
}

// Insertion Sort
void insertion_sort(int arr[], int n)
{
    int i, j, temp;

    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = temp;
    }

    printf("\nThe insertion sorted array is:\n");
    display_array(arr, n);
}

// Selection Sort
void selection_sort(int arr[], int n)
{
    int i, j, min, temp;

    for (i = 0; i < n - 1; i++)
    {
        min = i;

        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    printf("\nThe selection sorted array is:\n");
    display_array(arr, n);
}

// Swap function
void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for Quick Sort
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    int j;

    for (j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}

// Quick Sort
void quick_sort(int arr[], int low, int high)
{
    int pi;

    if (low < high)
    {
        pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

// Merge function
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1];
    int rightArr[n2];

    int i, j, k;

    // Copy elements into temporary arrays
    for (i = 0; i < n1; i++)
    {
        leftArr[i] = arr[left + i];
    }

    for (j = 0; j < n2; j++)
    {
        rightArr[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    // Merge the arrays
    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }

        k++;
    }

    // Copy remaining elements of left array
    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy remaining elements of right array
    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Merge Sort
void merge_sort(int arr[], int left, int right)
{
    int mid;

    if (left < right)
    {
        mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Display Menu
void display_menu(void)
{
    printf("\n");
    printf("<<----------- MENU ------------>>\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Quick Sort\n");
    printf("5. Merge Sort\n");
    printf("6. Show Menu\n");
    printf("7. Exit\n");
    printf("<<------------------------------>>\n");
}

// Main function
int main(void)
{
    int n;
    int arr[100];
    int choice;
    int i;

    printf("Enter size of array: ");

    if (scanf("%d", &n) != 1 || n <= 0 || n > 100)
    {
        printf("Invalid array size!\n");
        return 1;
    }

    printf("Enter array elements:\n");

    for (i = 0; i < n; i++)
    {
        if (scanf("%d", &arr[i]) != 1)
        {
            printf("Invalid array element!\n");
            return 1;
        }
    }

    printf("\nThe array is:\n");
    display_array(arr, n);

    do
    {
        display_menu();

        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("\nInvalid input!\n");
            return 1;
        }

        switch (choice)
        {
            case 1:
                bubble_sort(arr, n);
                break;

            case 2:
                selection_sort(arr, n);
                break;

            case 3:
                insertion_sort(arr, n);
                break;

            case 4:
                quick_sort(arr, 0, n - 1);

                printf("\nThe quick sorted array is:\n");
                display_array(arr, n);
                break;

            case 5:
                merge_sort(arr, 0, n - 1);

                printf("\nThe merge sorted array is:\n");
                display_array(arr, n);
                break;

            case 6:
                display_menu();
                break;

            case 7:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice! Please enter a number from 1 to 7.\n");
        }

    } while (choice != 7);

    return 0;
}
