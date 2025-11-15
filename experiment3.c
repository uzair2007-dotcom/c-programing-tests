#include <stdio.h>

int main() {
    int choice;
    float a, b, res;

menu:
    printf("\nMenu:\n1.Add\n2.Subtract\n3.Multiply\n4.Divide\n5.Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if(choice == 5) {
        printf("Exit\n");
        return 0;
    }

    if(choice < 1 || choice > 5) {
        printf("Wrong choice\n");
        goto menu;
    }

    printf("Enter two numbers: ");
    scanf("%f %f", &a, &b);

    switch(choice) {
        case 1:
            res = a + b;
            printf("Sum = %.2f\n", res);
            break;
        case 2:
            res = a - b;
            printf("Difference = %.2f\n", res);
            break;
        case 3:
            res = a * b;
            printf("Product = %.2f\n", res);
            break;
        case 4:
            if(b == 0) {
                printf("Cannot divide by zero\n");
                goto menu;
            }
            res = a / b;
            printf("Quotient = %.2f\n", res);
            break;
    }
    goto menu;
}
