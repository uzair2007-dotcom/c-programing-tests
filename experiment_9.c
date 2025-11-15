#include
// Define the structure for a student record
struct student_record {
char name[100]; // To store the student's name
int roll_number; // To store the roll number
int total_marks; // To store the total marks obtained
};
int main() {
// Create an array to hold the records for 5 students
struct student_record students[5];
int i;
int topper_index = 0; // Index to store the position of the topper
int max_marks; // Variable to store the highest marks found so far
printf("--- Enter Student Data ---\n");
// Loop to read data for 5 students
for (i = 0; i < 5; i++) {
printf("\n--- Student %d ---\n", i + 1);
printf("Enter name: ");
// Read the student's name (including spaces)
// The space before %[^\n] consumes any leftover newline from previous inputs
scanf(" %[^\n]s", students[i].name);
printf("Enter roll number: ");
scanf("%d", &students[i].roll_number);
printf("Enter total marks: ");
scanf("%d", &students[i].total_marks);
}
// --- Find the Topper ---
// Initialize max_marks and topper_index with the first student's data
max_marks = students[0].total_marks;
topper_index = 0;
// Loop through the rest of the students (from index 1) to find the topper
for (i = 1; i < 5; i++) {
if (students[i].total_marks > max_marks) {
// If a student with higher marks is found, update max_marks and topper_index
max_marks = students[i].total_marks;
topper_index = i;
}
}
// --- Display the Topper's Details ---
printf("\n\n--- !! Topper Details !! ---\n");
printf("Name: %s\n", students[topper_index].name);
printf("Roll Number: %d\n", students[topper_index].roll_number);
printf("Total Marks: %d\n", students[topper_index].total_marks);
return 0;
}
