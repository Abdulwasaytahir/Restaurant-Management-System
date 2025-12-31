#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// ANSI Color Codes
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define CYAN    "\033[1;36m"
#define MAGENTA "\033[1;35m"

// ---------- STRUCTURE ----------
struct MenuItem {
    int itemID;          // Primary Key
    char name[30];
    float price;
};

// ---------- GLOBAL DATA ----------
struct MenuItem menu[MAX];
int menuCount = 0;

// ---------- FUNCTION DECLARATIONS ----------
void welcomeScreen();
void mainMenu();
void menuItemSubMenu();

void loadDummyData();
void addMenuItem();
void displayMenuItems();
void searchMenuItem();
void editMenuItem();
void deleteMenuItem();

// ---------- MAIN ----------
int main() {
    welcomeScreen();
    loadDummyData();   // Dummy Data auto load
    mainMenu();
    return 0;
}

// ---------- WELCOME SCREEN ----------
void welcomeScreen() {
    system("cls || clear");
    printf("\n%s==============================================%s\n", CYAN, RESET);
    printf("%s   WELCOME TO RESTAURANT MANAGEMENT SYSTEM   %s\n", GREEN, RESET);
    printf("%s==============================================%s\n\n", CYAN, RESET);
}

// ---------- DUMMY DATA ----------
void loadDummyData() {
    menu[0] = (struct MenuItem){101, "Burger", 250};
    menu[1] = (struct MenuItem){102, "Pizza", 1200};
    menu[2] = (struct MenuItem){103, "Pasta", 650};
    menu[3] = (struct MenuItem){104, "Sandwich", 300};
    menu[4] = (struct MenuItem){105, "Coffee", 200};
    menuCount = 5;
}

// ---------- MAIN MENU ----------
void mainMenu() {
    int choice;

    while (1) {
        printf("\n%s==================== MAIN MENU ====================%s\n", BLUE, RESET);
        printf("1. %sManage Menu Items%s\n", YELLOW, RESET);
        printf("2. %sManage Tables%s\n", YELLOW, RESET);
        printf("3. %sManage Orders%s\n", YELLOW, RESET);
        printf("4. %sGenerate Bills%s\n", YELLOW, RESET);
        printf("5. %sExit System%s\n", RED, RESET);
        printf("---------------------------------------------------\n");

        printf("%sEnter your choice: %s", MAGENTA, RESET);
        scanf("%d", &choice);

        system("cls || clear");

        switch (choice) {
            case 1:
                menuItemSubMenu();
                break;

            case 2:
            case 3:
            case 4:
                printf("%s================ COMING SOON =================%s\n", CYAN, RESET);
                printf("%sThis module will be available in future milestones.%s\n",
                       YELLOW, RESET);
                break;

            case 5:
                printf("%sExiting Program... Goodbye!%s\n", RED, RESET);
                exit(0);

            default:
                printf("%sInvalid choice! Try again.%s\n", RED, RESET);
        }
    }
}

// ---------- MENU ITEM SUB MENU ----------
void menuItemSubMenu() {
    int choice;

    while (1) {
        printf("\n%s=========== MENU ITEM MANAGEMENT ===========%s\n", CYAN, RESET);
        printf("1. Add New Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Record\n");
        printf("4. Edit / Update Record\n");
        printf("5. Delete Record\n");
        printf("6. Back to Main Menu\n");
        printf("--------------------------------------------\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        system("cls || clear");

        switch (choice) {
            case 1: addMenuItem(); break;
            case 2: displayMenuItems(); break;
            case 3: searchMenuItem(); break;
            case 4: editMenuItem(); break;
            case 5: deleteMenuItem(); break;
            case 6: return;
            default:
                printf("%sInvalid option!%s\n", RED, RESET);
        }
    }
}

// ---------- ADD ----------
void addMenuItem() {
    if (menuCount >= MAX) return;

    int id;
    printf("Enter Item ID: ");
    scanf("%d", &id);

    for (int i = 0; i < menuCount; i++) {
        if (menu[i].itemID == id) {
            printf("%sItem ID already exists!%s\n", RED, RESET);
            return;
        }
    }

    menu[menuCount].itemID = id;
    printf("Enter Item Name: ");
    scanf(" %[^\n]", menu[menuCount].name);
    printf("Enter Item Price: ");
    scanf("%f", &menu[menuCount].price);

    menuCount++;
    printf("%sMenu item added successfully!%s\n", GREEN, RESET);
}

// ---------- DISPLAY ----------
void displayMenuItems() {
    if (menuCount == 0) {
        printf("%sNo menu items available.%s\n", RED, RESET);
        return;
    }

    printf("\n%-10s %-20s %-10s\n", "Item ID", "Name", "Price");
    printf("------------------------------------------\n");

    for (int i = 0; i < menuCount; i++) {
        printf("%-10d %-20s %-10.2f\n",
               menu[i].itemID,
               menu[i].name,
               menu[i].price);
    }
}

// ---------- SEARCH ----------
void searchMenuItem() {
    int id, found = 0;

    printf("Enter Item ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < menuCount; i++) {
        if (menu[i].itemID == id) {
            printf("%sRecord Found!%s\n", GREEN, RESET);
            printf("ID: %d\nName: %s\nPrice: %.2f\n",
                   menu[i].itemID,
                   menu[i].name,
                   menu[i].price);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("%sRecord Not Found!%s\n", RED, RESET);
}

// ---------- EDIT ----------
void editMenuItem() {
    int id, index = -1;

    printf("Enter Item ID to edit: ");
    scanf("%d", &id);

    for (int i = 0; i < menuCount; i++) {
        if (menu[i].itemID == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("%sRecord Not Found!%s\n", RED, RESET);
        return;
    }

    printf("Current Name: %s\n", menu[index].name);
    printf("Enter New Name: ");
    scanf(" %[^\n]", menu[index].name);

    printf("Current Price: %.2f\n", menu[index].price);
    printf("Enter New Price: ");
    scanf("%f", &menu[index].price);

    printf("%sRecord Updated Successfully!%s\n", GREEN, RESET);
}

// ---------- DELETE ----------
void deleteMenuItem() {
    int id, index = -1;

    printf("Enter Item ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < menuCount; i++) {
        if (menu[i].itemID == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("%sRecord Not Found!%s\n", RED, RESET);
        return;
    }

    // Array shifting logic
    for (int i = index; i < menuCount - 1; i++) {
        menu[i] = menu[i + 1];
    }

    menuCount--;
    printf("%sRecord Deleted Successfully!%s\n", GREEN, RESET);
}
