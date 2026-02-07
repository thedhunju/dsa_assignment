#include <stdio.h>

void swp(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void minH(int arr[], int size, int index) {
    int smallest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;
    if (left < size && arr[left] < arr[smallest])
        smallest = left;
    if (right < size && arr[right] < arr[smallest])
        smallest = right;
    if (smallest != index) {
        swp(&arr[index], &arr[smallest]);
        minH(arr, size, smallest);
    }
}

void maxH(int arr[], int size, int index) {
    int largest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;
    if (left < size && arr[left] > arr[largest])
        largest = left;
    if (right < size && arr[right] > arr[largest])
        largest = right;
    if (largest != index) {
        swp(&arr[index], &arr[largest]);
        maxH(arr, size, largest);
    }
}

void buildMin(int arr[], int size) {
    int i;
    for (i = size/2 - 1; i >= 0; i--)
        minH(arr, size, i);
}

void buildMax(int arr[], int size) {
    int i;
    for (i = size/2 - 1; i >= 0; i--)
        maxH(arr, size, i);
}

void show(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int size, i;
    printf("Enter size: ");
    scanf("%d", &size);
    int arr[size], minHeap[size], maxHeap[size];
    printf("Enter elements:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
        minHeap[i] = arr[i];
        maxHeap[i] = arr[i];
    }
    buildMin(minHeap, size);
    buildMax(maxHeap, size);
    printf("Min Heap: ");
    show(minHeap, size);
    printf("Max Heap: ");
    show(maxHeap, size);
    return 0;
}