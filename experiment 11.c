#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define FILENAME "employee.dat"
struct Employee {
int empId;
char name[100];
char position[50];
double salary;
};
typedef struct Employee Employee;
void flush_stdin() {
int c;
while ((c = getchar()) != '\n' && c != EOF);
}
void addEmployee() {
FILE *fp = fopen(FILENAME, "ab");
if (!fp) { printf("Error: Cannot open file!\n"); return; }
Employee emp;
printf("Enter ID: ");
scanf("%d", &emp.empId); flush_stdin();
printf("Enter Name: ");
fgets(emp.name, 100, stdin); emp.name[strcspn(emp.name, "\n")] = 0;
printf("Enter Position: ");
fgets(emp.position, 50, stdin); emp.position[strcspn(emp.position, "\n")] = 0;
printf("Enter Salary: ");
scanf("%lf", &emp.salary); flush_stdin();
fwrite(&emp, sizeof(Employee), 1, fp);
fclose(fp);
printf("Employee added.\n");
}
void listEmployees() {
FILE *fp = fopen(FILENAME, "rb");
if (!fp) { printf("No records found.\n"); return; }
Employee emp;
printf("\n--- Employee List ---\n");
printf("%-10s %-30s %-20s %-10s\n", "ID", "Name", "Position", "Salary");
printf("------------------------------------------------------------------\n");
while (fread(&emp, sizeof(Employee), 1, fp) == 1) {
printf("%-10d %-30s %-20s %-10.2f\n",
emp.empId, emp.name, emp.position, emp.salary);
}
printf("------------------------------------------------------------------\n");
fclose(fp);
}
void searchEmployee() {
FILE *fp = fopen(FILENAME, "rb");
if (!fp) { printf("Cannot open file.\n"); return; }
Employee emp;
int searchId, found = 0;
printf("Enter Employee ID to search: ");
scanf("%d", &searchId); flush_stdin();
while (fread(&emp, sizeof(Employee), 1, fp) == 1) {
if (emp.empId == searchId) {
printf("\n--- Employee Found ---\n");
printf("ID: %d\nName: %s\nPosition: %s\nSalary: %.2f\n",
emp.empId, emp.name, emp.position, emp.salary);
found = 1;
break;
}
}
if (!found) printf("Employee with ID %d not found.\n", searchId);
fclose(fp);
}
void updateEmployee() {
FILE *fp = fopen(FILENAME, "r+b");
if (!fp) { printf("Cannot open file.\n"); return; }
Employee emp;
int searchId, found = 0;
printf("Enter Employee ID to update: ");
scanf("%d", &searchId); flush_stdin();
while (fread(&emp, sizeof(Employee), 1, fp) == 1) {
if (emp.empId == searchId) {
printf("Found. Enter new Name: ");
fgets(emp.name, 100, stdin); emp.name[strcspn(emp.name, "\n")] = 0;
printf("Enter new Position: ");
fgets(emp.position, 50, stdin); emp.position[strcspn(emp.position, "\n")] = 0;
printf("Enter new Salary: ");
scanf("%lf", &emp.salary); flush_stdin();
fseek(fp, -sizeof(Employee), SEEK_CUR);
fwrite(&emp, sizeof(Employee), 1, fp);
found = 1;
printf("Record updated.\n");
break;
}
}
if (!found) printf("Employee with ID %d not found.\n", searchId);
fclose(fp);
}
void deleteEmployee() {
FILE *fp, *ft;
Employee emp;
int searchId, found = 0;
char tempFilename[] = "temp.dat";
printf("Enter Employee ID to delete: ");
scanf("%d", &searchId); flush_stdin();
fp = fopen(FILENAME, "rb");
if (!fp) { printf("Cannot open file.\n"); return; }
ft = fopen(tempFilename, "wb");
if (!ft) { printf("Cannot create temp file.\n"); fclose(fp); return; }
while (fread(&emp, sizeof(Employee), 1, fp) == 1) {
if (emp.empId == searchId) {
found = 1;
} else {
fwrite(&emp, sizeof(Employee), 1, ft);
}
}
fclose(fp);
fclose(ft);
if (found) {
remove(FILENAME);
rename(tempFilename, FILENAME);
printf("Record deleted.\n");
} else {
printf("Employee with ID %d not found.\n", searchId);
remove(tempFilename);
}
}
int main() {
int choice;
while (1) {
printf("\nEmployee DB Menu\n");
printf("1. Add\n2. List\n3. Search\n4. Update\n5. Delete\n0. Exit\n");
printf("Choice: ");
if (scanf("%d", &choice) != 1) {
printf("Invalid input.\n");
flush_stdin();
continue;
}
flush_stdin();
switch (choice) {
case 1: addEmployee(); break;
case 2: listEmployees(); break;
case 3: searchEmployee(); break;
case 4: updateEmployee(); break;
case 5: deleteEmployee(); break;
case 0: exit(0);
default: printf("Invalid choice.\n");
}
printf("Press Enter to continue...");
getchar();
}
return 0;
}
