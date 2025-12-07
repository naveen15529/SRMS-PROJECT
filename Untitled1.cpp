#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "students.csv"
#define MAX 100

// Structure to hold student data
typedef struct {
    char name[50];
    int roll;
    char course[50];
    int year;
    float cgpa;
} Student;

// Array to store all students
Student students[MAX];
int count = 0;

// Load data from the CSV file
void loadData() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (!fp) {
        printf("No existing records found. Starting fresh.\n");
        return;
    }

    while (!feof(fp)) {
        Student s;
        if (fscanf(fp, "%49[^,],%d,%49[^,],%d,%f\n",
                   s.name, &s.roll, s.course, &s.year, &s.cgpa) == 5) {
            students[count++] = s;
        }
    }
    fclose(fp);

    printf("%d record(s) loaded from %s\n", count, FILE_NAME);
}

// Save data to CSV file
void saveData() {
    FILE *fp = fopen(FILE_NAME, "w");
    if (!fp) {
        printf("Error opening file for saving!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s,%d,%s,%d,%.2f\n",
                students[i].name,
                students[i].roll,
                students[i].course,
                students[i].year,
                students[i].cgpa);
    }

    fclose(fp);
    printf("Data saved successfully.\n");
}

// Add new student
void addStudent() {
    if (count >= MAX) {
        printf("Maximum limit reached!\n");
        return;
    }

    Student s;

    printf("\nEnter Student Name  : ");
    scanf(" %[^\n]", s.name);

    printf("Enter Roll Number   : ");
    scanf("%d", &s.roll);

    printf("Enter Course        : ");
    scanf(" %[^\n]", s.course);

    printf("Enter Year          : ");
    scanf("%d", &s.year);

    printf("Enter CGPA          : ");
    scanf("%f", &s.cgpa);

    students[count++] = s;

    printf("Student added successfully.\n");
}

// Display header
void displayHeader() {
    printf("\n%-20s %-10s %-20s %-6s %-6s\n",
           "Name", "RollNo", "Course", "Year", "CGPA");
    printf("---------------------------------------------------------------------\n");
}

// Display all students
void displayAll() {
    if (count == 0) {
        printf("No records available.\n");
        return;
    }

    displayHeader();

    for (int i = 0; i < count; i++) {
        printf("%-20s %-10d %-20s %-6d %.2f\n",
               students[i].name,
               students[i].roll,
               students[i].course,
               students[i].year,
               students[i].cgpa);
    }
    printf("---------------------------------------------------------------------\n");
}

// Search student by roll number
void searchStudent() {
    int r;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &r);

    for (int i = 0; i < count; i++) {
        if (students[i].roll == r) {
            printf("\nRecord Found:\n");
            displayHeader();
            printf("%-20s %-10d %-20s %-6d %.2f\n",
                   students[i].name,
                   students[i].roll,
                   students[i].course,
                   students[i].year,
                   students[i].cgpa);
            return;
        }
    }
    printf("No student found with Roll Number %d\n", r);
}

// Delete student by roll number
void deleteStudent() {
    int r;
    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &r);

    for (int i = 0; i < count; i++) {
        if (students[i].roll == r) {
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            printf("Record deleted successfully.\n");
            return;
        }
    }

    printf("No record found with Roll Number %d\n", r);
}

// Menu
void menu() {
    printf("\n===== STUDENT RESULT MANAGEMENT SYSTEM =====\n");
    printf("1. Display All Students\n");
    printf("2. Add Student\n");
    printf("3. Search Student\n");
    printf("4. Delete Student\n");
    printf("5. Save & Exit\n");
    printf("Choose an option: ");
}

int main() {
    loadData();

    int choice;
    while (1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: displayAll(); break;
            case 2: addStudent(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: saveData(); exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
