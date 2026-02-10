#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comp, swap;

void merge(int a[], int l, int m, int r) {
  int n1 = m - l + 1, n2 = r - m;
  int L[n1], R[n2], i, j, k;
  
  for(i = 0; i < n1; i++) 
    L[i] = a[l + i];
  for(j = 0; j < n2; j++) 
    R[j] = a[m + 1 + j];
  
  i = 0;
  j = 0;
  k = l;
  while(i < n1 && j < n2) {
    comp++;
    if(L[i] <= R[j]) {
      a[k] = L[i];
      i++;
    } else {
      a[k] = R[j];
      j++;
    }
    k++;
  }
  while(i < n1) {
    a[k] = L[i];
    i++;
    k++;
  }
  while(j < n2) {
    a[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(int a[], int l, int r) {
  if(l < r) {
    int m = l + (r - l) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
  }
}

int main() {
  int n, ch, i, j, t;
  
  printf("Enter total number of integers: ");
  scanf("%d", &n);
  
  int a[n];
  srand(time(NULL));
  for(i = 0; i < n; i++) 
    a[i] = rand() % 1000 + 1;
  
  printf("\nUnsorted List:\n");
  for(i = 0; i < n; i++) 
    printf(" %d", a[i]);
  
  printf("\n\nChoose Sorting Algorithm:\n");
  printf("1. Bubble Sort\n");
  printf("2. Selection Sort\n");
  printf("3. Insertion Sort\n");
  printf("4. Merge Sort\n");
  printf("Enter choice: ");
  scanf("%d", &ch);
  
  comp = 0;
  swap = 0;
  
  if(ch == 1) {
    for(i = 0; i < n - 1; i++) {
      for(j = 0; j < n - i - 1; j++) {
        comp++;
        if(a[j] > a[j + 1]) {
          t = a[j];
          a[j] = a[j + 1];
          a[j + 1] = t;
          swap++;
        }
      }
    }
    printf("\nAlgorithm: Bubble Sort\n");
  }
  else if(ch == 2) {
    for(i = 0; i < n - 1; i++) {
      int min = i;
      for(j = i + 1; j < n; j++) {
        comp++;
        if(a[j] < a[min]) 
          min = j;
      }
      if(min != i) {
        t = a[i];
        a[i] = a[min];
        a[min] = t;
        swap++;
      }
    }
    printf("\nAlgorithm: Selection Sort\n");
  }
  else if(ch == 3) {
    for(i = 1; i < n; i++) {
      int key = a[i];
      j = i - 1;
      while(j >= 0 && a[j] > key) {
        comp++;
        a[j + 1] = a[j];
        j--;
        swap++;
      }
      if(j >= 0) 
        comp++;
      a[j + 1] = key;
    }
    printf("\nAlgorithm: Insertion Sort\n");
  }
  else if(ch == 4) {
    mergeSort(a, 0, n - 1);
    printf("\nAlgorithm: Merge Sort\n");
    printf("(Note: Merge Sort doesn't use swaps)\n");
  }
  else {
    printf("Invalid choice!\n");
    return 0;
  }
  
  printf("\nSorted List:\n");
  for(i = 0; i < n; i++) 
    printf(" %d", a[i]);
  printf("\n\nTotal Comparisons: %d\n", comp);
  if(ch != 4) 
    printf("Total Swaps: %d\n", swap);
  
  return 0;
}
