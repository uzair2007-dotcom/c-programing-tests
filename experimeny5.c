#include <stdio.h>
// Iterative function to find factorial
long long factorialIterative(int n) {
long long fact = 1;
if (n < 0) {
return -1; // Factorial is not defined for negative numbers
}
for (int i = 1; i <= n; ++i) {
fact *= i;
}
return fact;
}
// Recursive function to find factorial
long long factorialRecursive(int n) {
if (n < 0) {
return -1; // Factorial is not defined for negative numbers
} else if (n == 0 || n == 1) {
return 1; // Base case
} else {
return n * factorialRecursive(n - 1); // Recursive step
}
}
int main() {
int num;
printf("Enter a non-negative integer: ");
scanf("%d", &num);
// Using iterative function
long long factIter = factorialIterative(num);
if (factIter == -1) {
printf("Factorial is not defined for negative numbers.\n");
} else {
printf("Factorial of %d (Iterative) = %lld\n", num, factIter);
}
// Using recursive function
long long factRec = factorialRecursive(num);
if (factRec == -1) {
printf("Factorial is not defined for negative numbers.\n");
} else {
printf("Factorial of %d (Recursive) = %lld\n", num, factRec);
}
return 0;
}
