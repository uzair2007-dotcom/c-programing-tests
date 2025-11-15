#include
int main() {
int start, end, i, temp;
int sum = 0;
printf("Enter the starting number: ");
scanf("%d", &start);
printf("Enter the ending number: ");
scanf("%d", &end);
if (start > end) {
temp = start;
start = end;
end = temp;
}
for (i = start; i <= end; i++) {
if (i % 2 != 0) {
sum = sum + i;
}
}
printf("Sum of odd numbers between %d and %d is: %d", start, end, sum);
return 0;
}
