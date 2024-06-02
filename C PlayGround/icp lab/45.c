#include <stdio.h>

// Define the structure for a family member
struct FamilyMember {
    char name[50];
    int age;
    char relationship[50];
};

// Function to display a family member
void displayFamilyMember(struct FamilyMember member) {
    printf("Name: %s\n", member.name);
    printf("Age: %d\n", member.age);
    printf("Relationship: %s\n", member.relationship);
}

int main() {
    // Create a family member
    struct FamilyMember member;

    // Get the details of the family member from the user
    printf("Enter member name: ");
    fgets(member.name, sizeof(member.name), stdin);
    member.name[strlen(member.name) - 1] = '\0';  // Remove newline character

    printf("Enter member age: ");
    scanf("%d", &member.age);

    printf("Enter member relationship: ");
    scanf("%s", member.relationship);

    // Display the family member
    displayFamilyMember(member);

    return 0;
}
