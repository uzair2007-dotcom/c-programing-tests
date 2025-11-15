#include
int main() {
int rows, cols, i, j;
int matrixA[50][50], matrixB[50][50], sumMatrix[50][50];
printf("Enter the number of rows (1-50): ");
scanf("%d", &rows);
printf("Enter the number of columns (1-50): ");
scanf("%d", &cols);
printf("\nEnter elements for the first matrix:\n");
for (i = 0; i < rows; ++i) {
for (j = 0; j < cols; ++j) {
printf("Enter element A[%d][%d]: ", i, j);
scanf("%d", &matrixA[i][j]);
}
}
printf("\nEnter elements for the second matrix:\n");
for (i = 0; i < rows; ++i) {
for (j = 0; j < cols; ++j) {
printf("Enter element B[%d][%d]: ", i, j);
scanf("%d", &matrixB[i][j]);
}
}
for (i = 0; i < rows; ++i) {
for (j = 0; j < cols; ++j) {
sumMatrix[i][j] = matrixA[i][j] + matrixB[i][j];
}
}
printf("\nSum of the two matrices:\n");
for (i = 0; i < rows; ++i) {
for (j = 0; j < cols; ++j) {
printf("%d ", sumMatrix[i][j]);
}
printf("\n");
}
return 0;
}
