void view_locker(char lockers[][MAX_ITEM_LENGTH]);
void rent_locker(char lockers[][MAX_ITEM_LENGTH]);
void end_rental(char lockers[][MAX_ITEM_LENGTH]);
void list_all_lockers(char lockers[][MAX_ITEM_LENGTH]);

int main()
{
	// array that stores locker contents
    char lockers[MAX_LOCKERS][MAX_ITEM_LENGTH];
    int menu_choice = 0;

    // Initialize lockers as empty
    for (int i = 0; i < MAX_LOCKERS; i++)
	{
        strcpy(lockers[i], "EMPTY");
    }

    // Main menu loop
    while (menu_choice != 5)
	{
        // display menu options
        printf("\nLocker Rental Menu\n");
        printf("=============================\n");
        printf("1. View a locker\n");
        printf("2. Rent a locker\n");
        printf("3. End a locker rental\n");
        printf("4. List all locker contents\n");
        printf("5. Quit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &menu_choice);

        // Handle user input/choice
        switch (menu_choice)
		{
            case 1:
                view_locker(lockers);
                break;
            case 2:
                rent_locker(lockers);
                break;
            case 3:
                end_rental(lockers);
                break;
            case 4:
                list_all_lockers(lockers);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    }

    return 0;
}

// Function to view a locker
void view_locker(char lockers[][MAX_ITEM_LENGTH]) {
    int locker_number;
    printf("Enter locker number (1-100): ");
    scanf("%d", &locker_number);

    if (locker_number < 1 || locker_number > MAX_LOCKERS)
	{
        printf("Sorry, there are only 100 lockers available.\n");
    } else
	{
        if (strcmp(lockers[locker_number - 1], "EMPTY") == 0)
		{
            printf("Locker %d is EMPTY.\n", locker_number);
        } else
		{
            printf("Locker %d contents: %s.\n", locker_number, lockers[locker_number - 1]);
        }
    }
}

// Function to rent a locker
void rent_locker(char lockers[][MAX_ITEM_LENGTH])
{
    int locker_number;
    char item[MAX_ITEM_LENGTH];
    printf("Enter locker number (1-100): ");
    scanf("%d", &locker_number);

    if (locker_number < 1 || locker_number > MAX_LOCKERS)
	{
        printf("Sorry, there are only 100 lockers available.\n");
    } else if (strcmp(lockers[locker_number - 1], "EMPTY") != 0)
	{
        printf("Sorry, but locker %d has already been rented!\n", locker_number);
    } else
	{
        printf("Enter the item you want to store in the locker: ");
		// read str w/ spaces
        scanf(" %[^\n]", item);
        strcpy(lockers[locker_number - 1], item);
        printf("Locker %d has been rented for %s storage.\n", locker_number, item);
    }
}

// Function to end a locker rental
void end_rental(char lockers[][MAX_ITEM_LENGTH])
{
    int locker_number;
    printf("Enter locker number (1-100): ");
    scanf("%d", &locker_number);

    if (locker_number < 1 || locker_number > MAX_LOCKERS)
	{
        printf("Sorry, there are only 100 lockers available.\n");
    } else if (strcmp(lockers[locker_number - 1], "EMPTY") == 0)
	{
        printf("Locker %d is not currently rented.\n", locker_number);
    } else
	{
        printf("Locker %d rental has ended, please take your %s.\n", locker_number, lockers[locker_number - 1]);
		//locker reset (empty)
        strcpy(lockers[locker_number - 1], "EMPTY");
    }
}

// Function to list all rented lockers
void list_all_lockers(char lockers[][MAX_ITEM_LENGTH])
{
    int any_rented = 0;

    for (int i = 0; i < MAX_LOCKERS; i++) 
	{
        if (strcmp(lockers[i], "EMPTY") != 0) 
		{
            printf("Locker %d: %s\n", i + 1, lockers[i]);
            any_rented = 1;
        }
    }

    if (!any_rented)
	{
        printf("No lockers are currently rented.\n");
    }
}