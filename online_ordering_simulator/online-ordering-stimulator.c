*
 * File: clothing_store_simulator.c
 *
 * Description:
 *   This program simulates a clothing store experience where the user can interactively
 *   select clothing items (shirts, shoes, or pants) and specify the quantity of each item
 *   they want to purchase. The program continuously prompts the user to enter the clothing
 *   type and quantity until the user chooses to exit. Upon exiting, the program calculates
 *   the total cost of the selected items based on predefined prices and displays a formatted
 *   bill showing the quantity, price, and total cost for each clothing item, along with the
 *   overall total cost.
 *
 * Features:
 *   - Interactive menu-based interface for selecting clothing items and quantities
 *   - Supports three clothing types: shirts, shoes, and pants
 *   - Predefined prices for each clothing type
 *   - Validates user input for clothing type and handles invalid inputs
 *   - Calculates the total cost based on the selected quantities and predefined prices
 *   - Displays a formatted bill with detailed information for each clothing item and the total cost
 *
 * Usage:
 *   1. Run the program.
 *   2. Enter the desired clothing type (shirt, shoes, or pants) when prompted.
 *   3. Enter the quantity for the selected clothing type when prompted.
 *   4. Repeat steps 2-3 to add more clothing items as needed.
 *   5. Enter 'exit' when prompted to quit the program and view the generated bill.
 *
 * Author: [Your Name]
 * Date: [Current Date]
 */

// Include necessary header files
#include <stdio.h>   // Provides input/output functions
#include <string.h>  // Provides string manipulation functions

// Define constants for clothing item prices using macros
#define SHIRT_PRICE 19.99
#define SHOE_PRICE 49.99
#define PANTS_PRICE 29.99

int main(void) {
    // Declare variables
    char userInput[20];  // Array to store user input for clothing type
    int shirtQuantity = 0, shoeQuantity = 0, pantsQuantity = 0;  // Variables to store quantities of each clothing item
    
    do {
        // Display menu options to the user
        printf("Enter the type of clothing needed (shirt, shoes, pants).\n");
        printf("Type 'exit' to quit and calculate the total cost.\n");

        // Read user input for clothing type
        scanf("%s", userInput);

        // Check user input and prompt for quantity based on clothing type
        if (strcmp(userInput, "shirt") == 0) {
            printf("Enter the quantity of shirts needed: ");
            scanf("%d", &shirtQuantity);
        } else if (strcmp(userInput, "shoes") == 0) {
            printf("Enter the quantity of shoes needed: ");
            scanf("%d", &shoeQuantity);
        } else if (strcmp(userInput, "pants") == 0) {
            printf("Enter the quantity of pants needed: ");
            scanf("%d", &pantsQuantity);
        } else if (strcmp(userInput, "exit") != 0) {
            // If user input is not a valid clothing type or 'exit', display an error message and continue the loop
            printf("Invalid clothing type. Please enter 'shirt', 'shoes', or 'pants'.\n");
            continue;
        }

        // If user input is not 'exit', display a success message for adding the clothing item
        if (strcmp(userInput, "exit") != 0) {
            printf("Clothing item '%s' added successfully.\n", userInput);
        }
    } while (strcmp(userInput, "exit") != 0);  // Repeat the loop until user enters 'exit'

    // Calculate the total cost based on quantities and prices of each clothing item
    float totalCost = (shirtQuantity * SHIRT_PRICE) + (shoeQuantity * SHOE_PRICE) + (pantsQuantity * PANTS_PRICE);

    // Display the formatted bill
    printf("\nClothing Item\tQuantity\tPrice\t\tTotal\n");
    printf("-------------------------------------------------------\n");
    printf("Shirts\t\t%d\t\t$%.2f\t\t$%.2f\n", shirtQuantity, SHIRT_PRICE, shirtQuantity * SHIRT_PRICE);
    printf("Shoes\t\t%d\t\t$%.2f\t\t$%.2f\n", shoeQuantity, SHOE_PRICE, shoeQuantity * SHOE_PRICE);
    printf("Pants\t\t%d\t\t$%.2f\t\t$%.2f\n", pantsQuantity, PANTS_PRICE, pantsQuantity * PANTS_PRICE);
    printf("-------------------------------------------------------\n");
    printf("Total Cost:\t\t\t\t\t$%.2f\n", totalCost);

    return 0;  // Indicate successful program execution
}