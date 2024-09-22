#include <stdio.h>
#include <string.h>

//clothing item prices
#define shirt_price 19.99
#define shoe_price 49.99
#define pants_price 29.99
//shipping costs
#define usa_standard_shipping 5.99
#define usa_expedited_shipping 9.99
#define mexico_standard_shipping 7.99
#define mexico_expedited_shipping 12.99
#define canada_standard_shipping 6.99
#define canada_expedited_shipping 11.99
//tax rates
#define usa_tax_rate 0.08
#define mexico_tax_rate 0.16
#define canada_tax_rate 0.12


int main(void)
{
	//array to store user input
	//variables to store quantity of users purchase
	char userinput[20];
	int shirtquantity = 0, shoequantity = 0, pantsquantity = 0;

	do
	{
		printf("Enter the type of clothing needed (shirt, shoes, pants).\n");
		printf("Type 'exit' to quit and calculate the total cost.\n");

		//reads user input for clothing type
		scanf("%s", userinput);

		if (strcmp(userInput, "exit") != 0)
		{
			int quantity;
			printf("Enter the quantity of %s needed: ", userInput);
			scanf("%d", &quantity);

			switch (userInput[0])
			{
				// s, shirt or shoes
				case 's':
					if (strcmp(userInput, "shirt") == 0)
					{
						shirtQuantity += quantity;
					}
					else if (strcmp(userInput, "shoes") == 0)
					{
						shoeQuantity += quantity;
					}
					else
					{
						printf("Invalid item. Try again.\n");
					}
					break;

				// p, pants
				case 'p':
					if (strcmp(userInput, "pants") == 0)
					{
						pantsQuantity += quantity;
					}
					else
					{
						printf("Invalid item. Try again.\n");
					}
					break;
				default:
					printf("Invalid item. Try again.\n");
			}
			printf("Clothing item '%s' successfully added to your cart.\n", userInput);
		}
	} while (strcmp(userInput, "exit") != 0);

	char destination[20], shippingMethod[20];
	float shippingCost = 0.0, taxRate = 0.0;

	printf("Enter the shipping destination (USA, Mexico, Canada): ");
	scanf("%s", destination);

	printf("Enter the shipping method (standard, expedited): ");
	scanf("%s", shippingMethod);

	switch (destination[0])
	{
		case 'U': case 'u':
			taxRate = USA_TAX;
			if (shippingMethod[0] == 's' || shippingMethod[0] == 'S')
			{
				shippingCost = USA_STANDARD;
			}
			else if (shippingMethod[0] == 'e' || shippingMethod[0] == 'E')
			{
				shippingCost = USA_EXPEDITED;
			}
			break;
		case 'M': case 'm':
			taxRate = MEXICO_TAX;
			if (shippingMethod[0] == 's' || shippingMethod[0] == 'S')
			{
				shippingCost = MEXICO_STANDARD;
			} else if (shippingMethod[0] == 'e' || shippingMethod[0] == 'E')
			{
				shippingCost = MEXICO_EXPEDITED;
			}
			break;
		case 'C': case 'c':
			taxRate = CANADA_TAX;
			if (shippingMethod[0] == 's' || shippingMethod[0] == 'S')
			{
				shippingCost = CANADA_STANDARD;
			}
			else if (shippingMethod[0] == 'e' || shippingMethod[0] == 'E')
			{
				shippingCost = CANADA_EXPEDITED;
			}
			break;
		default:
			printf("Invalid destination. Defaulting to USA standard shipping.\n");
			taxRate = USA_TAX;
			shippingCost = USA_STANDARD;
	}

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

		return 0;
}