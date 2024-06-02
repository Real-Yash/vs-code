#include <stdio.h>

// Define the structure for a bill item
struct BillItem {
    char name[50];
    float price;
    int quantity;
};

// Function to display a bill item
void displayBillItem(struct BillItem item) {
    printf("Item: %s\n", item.name);
    printf("Price: %.2f\n", item.price);
    printf("Quantity: %d\n", item.quantity);
    printf("Total: %.2f\n", item.price * item.quantity);
}

int main() {
    // Create a bill item
    struct BillItem item;

    // Get the details of the bill item from the user
    printf("Enter item name: ");
    fgets(item.name, sizeof(item.name), stdin);
    item.name[strlen(item.name) - 1] = '\0';  // Remove newline character

    printf("Enter item price: ");
    scanf("%f", &item.price);

    printf("Enter item quantity: ");
    scanf("%d", &item.quantity);

    // Display the bill item
    displayBillItem(item);

    return 0;
}
