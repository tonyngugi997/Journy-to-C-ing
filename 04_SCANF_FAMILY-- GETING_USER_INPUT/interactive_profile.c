

#include <stdio.h>

int main() {
    char name[50];
    int age;
    float height;
    char grade;

    printf("=== User Profile Creator ===\n\n");

    printf("Enter your name: ");
    scanf("%49s", name);  // Limit to 49 chars + null

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your height (meters): ");
    scanf("%f", &height);

    printf("Enter your grade (A, B, C, etc): ");
    scanf(" %c", &grade);  // Space before %c eats leftover newline

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

