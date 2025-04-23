#include <stdio.h>
#include <stdlib.h>

void insert(int **arr, int *n);
void update(int arr[], int n);
void deleteElement(int **arr, int *n);
void sort(int arr[], int n);
void search(int arr[], int n);
void display(int arr[], int n);

int main() {
    int *arr = NULL;
    int n, choice;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\n----- Menu -----\n");
        printf("1. Insert\n");
        printf("2. Update\n");
        printf("3. Delete\n");
        printf("4. Sort\n");
        printf("5. Search\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: insert(&arr, &n); break;
            case 2: update(arr, n); break;
            case 3: deleteElement(&arr, &n); break;
            case 4: sort(arr, n); break;
            case 5: search(arr, n); break;
            case 6: display(arr, n); break;
            case 7: printf("Exiting program.\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 7);

    free(arr);
    return 0;
}

void insert(int **arr, int *n) {
    int pos, val;
    printf("Enter position to insert (0 to %d): ", *n);
    scanf("%d", &pos);
    if (pos < 0 || pos > *n) {
        printf("Invalid position!\n");
        return;
    }
    printf("Enter value to insert: ");
    scanf("%d", &val);

    *arr = (int *)realloc(*arr, (*n + 1) * sizeof(int));
    if (*arr == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    for (int i = *n; i > pos; i--) {
        (*arr)[i] = (*arr)[i - 1];
    }
    (*arr)[pos] = val;
    (*n)++;
    printf("Element inserted successfully.\n");
}

void update(int arr[], int n) {
    int pos, val;
    printf("Enter position to update (0 to %d): ", n - 1);
    scanf("%d", &pos);
    if (pos < 0 || pos >= n) {
        printf("Invalid position!\n");
        return;
    }
    printf("Enter new value: ");
    scanf("%d", &val);
    arr[pos] = val;
    printf("Element updated successfully.\n");
}

void deleteElement(int **arr, int *n) {
    int pos;
    printf("Enter position to delete (0 to %d): ", *n - 1);
    scanf("%d", &pos);
    if (pos < 0 || pos >= *n) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = pos; i < *n - 1; i++) {
        (*arr)[i] = (*arr)[i + 1];
    }

    *arr = (int *)realloc(*arr, (*n - 1) * sizeof(int));
    if (*arr == NULL && *n > 1) {
        printf("Memory reallocation failed.\n");
        return;
    }

    (*n)--;
    printf("Element deleted successfully.\n");
}

void sort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Array sorted in ascending order.\n");
}

void search(int arr[], int n) {
    int val, found = 0;
    printf("Enter value to search: ");
    scanf("%d", &val);

    for (int i = 0; i < n; i++) {
        if (arr[i] == val) {
            printf("Element found at index %d\n", i);
            found = 1;
        }
    }
    if (!found) {
        printf("Element not found.\n");
    }
}

void display(int arr[], int n) {
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
