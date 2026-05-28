#include <stdio.h>
#include <string.h>

int main() {
    char buffer[100];
    char name[50];
    int age;
    float height;
    char grade;

    printf("=== User Profile Creator (fgets + sscanf) ===\n\n");

    printf("Enter your name: ");
    if (!fgets(name, sizeof(name), stdin)) {
        return 1;
    }
    name[strcspn(name, "\n")] = '\0';

    printf("Enter your age: ");
    if (!fgets(buffer, sizeof(buffer), stdin)) {
        return 1;
    }
    if (sscanf(buffer, "%d", &age) != 1) {
        printf("Invalid age.\n");
        return 1;
    }

    printf("Enter your height (meters): ");
    if (!fgets(buffer, sizeof(buffer), stdin)) {
        return 1;
    }
    if (sscanf(buffer, "%f", &height) != 1) {
        printf("Invalid height.\n");
        return 1;
    }

    printf("Enter your grade (A, B, C, etc): ");
    if (!fgets(buffer, sizeof(buffer), stdin)) {
        return 1;
    }
    if (sscanf(buffer, " %c", &grade) != 1) {
        printf("Invalid grade.\n");
        return 1;
    }

    printf("\n--- Your Profile ---\n");
    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("Height: %.2f m\n", height);
    printf("Grade: %c\n", grade);

    if (age >= 18) {
        printf("Status: Adult\n");
    } else {
        printf("Status: Minor\n");
    }

    return 0;
}
