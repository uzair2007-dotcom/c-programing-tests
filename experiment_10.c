#include<stdio.h>
int main() {
int arr[] = {10, 20, 30, 40, 50};
int n, i;
// Calculate the number of elements in the array
n = sizeof(arr) / sizeof(arr[0]);
// Declare a pointer and initialize it to the last element of the array
// 'arr + n - 1' is the address of the last element (arr[n-1])
int *ptr = arr + n - 1;
printf("Array in original order: ");
for (i = 0; i < n; i++) {
printf("%d ", arr[i]);
}
printf("\n");
printf("Array in reverse order: ");
// Loop from the last element down to the first
// The loop continues as long as the pointer is at or after
// the base address 'arr' (which points to arr[0])
while (ptr >= arr) {
// Print the value at the address pointed to by 'ptr'
printf("%d ", *ptr);
// Move the pointer to the previous element in memory
ptr--;
}
printf("\n");
return 0;
}
