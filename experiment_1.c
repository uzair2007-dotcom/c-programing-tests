#include
int main() {
int physics, chemistry, maths;
float average;
printf("Enter marks for Physics: ");
scanf("%d", &physics);
printf("Enter marks for Chemistry: ");
scanf("%d", &chemistry);
printf("Enter marks for Maths: ");
scanf("%d", &maths);
average = (physics + chemistry + maths) / 3.0;
printf("\nYour PCM Average: %.2f%%\n", average);
(average >= 50.0)
? printf("Status: Eligible for Admission\n")
: printf("Status: Not Eligible for Admission\n");
return 0;
}
