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
#define WHITE   "\033[1;37m"

// ---------- STRUCTURE DEFINITION ----------
struct MenuItem {
    int itemID;          // Primary Key
    char name[30];
    float price;
};

// ---------- GLOBAL ARRAY & COUNTER ----------
struct MenuItem menu[MAX];
int menuCount = 0;

// ---------- FUNCTION DECLARATIONS ----------
void welcomeScreen();
void mainMenu();
void menuItemSubMenu();

void addMenuItem();
void displayMenuItems();
void searchMenuItem();

// ---------- MAIN FUNCTION ----------
int main() {
    welcomeScreen();
    mainMenu();
    return 0;
}

// ---------- WELCOME SCREEN ----------
void welcomeScreen() {
    system("cls || clear");
    printf("\n%s==============================================%s\n", CYAN, RESET);
    printf("%s     WELCOME TO RESTAURANT MANAGEMENT SYSTEM     %s\n", GREEN, RESET);
    printf("%s==============================================%s\n\n", CYAN, RESET);
}

// ---------- MAIN MENU ----------
void mainMenu() {
    int choice;

    while (1) {
        printf("\n%s==================== MAIN MENU ====================%s\n", BLUE, RESET);
        printf("1.%s Manage Menu Items%s\n", YELLOW, RESET);
        printf("2.%s Manage Tables (Coming Soon)%s\n", YELLOW, RESET);
        printf("3.%s Manage Orders (Coming Soon)%s\n", YELLOW, RESET);
        printf("4.%s Generate Bills (Coming Soon)%s\n", YELLOW, RESET);
        printf("5.%s Exit System%s\n", RED, RESET);
        printf("---------------------------------------------------\n");

        printf("%sEnter your choice: %s", MAGENTA, RESET);
        scanf("%d", &choice);

        system("cls || clear");

        switch (choice) {
            case 1:
                menuItemSubMenu();
                break;
            case 5:
                printf("%sExiting Program... Goodbye!%s\n", RED, RESET);
                exit(0);
            default:
                printf("%sInvalid choice! Try again.%s\n", RED, RESET);
        }
    }
}

// ---------- MENU ITEM SUB-MENU ----------
void menuItemSubMenu() {
    int choice;

    while (1) {
        printf("\n%s=============== MENU ITEM SUB-MENU ===============%s\n", CYAN, RESET);
        printf("1.%s Add New Menu Item%s\n", YELLOW, RESET);
        printf("2.%s Display All Menu Items%s\n", YELLOW, RESET);
        printf("3.%s Search Menu Item by ID%s\n", YELLOW, RESET);
        printf("4.%s Back to Main Menu%s\n", RED, RESET);
        printf("--------------------------------------------------\n");

        printf("%sEnter your choice: %s", MAGENTA, RESET);
        scanf("%d", &choice);

        system("cls || clear");

        switch (choice) {
            case 1:
                addMenuItem();
                break;
            case 2:
                displayMenuItems();
                break;
            case 3:
                searchMenuItem();
                break;
            case 4:
                return;
            default:
                printf("%sInvalid option! Please try again.%s\n", RED, RESET);
        }
    }
}

// ---------- ADD MENU ITEM ----------
void addMenuItem() {
    if (menuCount >= MAX) {
        printf("%sMenu is full! Cannot add more items.%s\n", RED, RESET);
        return;
    }

    int id, i;
    printf("%sEnter Item ID: %s", MAGENTA, RESET);
    scanf("%d", &id);

    // Duplicate check
    for (i = 0; i < menuCount; i++) {
        if (menu[i].itemID == id) {
            printf("%sError: Item ID already exists!%s\n", RED, RESET);
            return;
        }
    }

    menu[menuCount].itemID = id;

    printf("%sEnter Item Name: %s", MAGENTA, RESET);
    scanf(" %[^\n]", menu[menuCount].name);

    printf("%sEnter Item Price: %s", MAGENTA, RESET);
    scanf("%f", &menu[menuCount].price);

    menuCount++;

    printf("%sMenu Item added successfully!%s\n", GREEN, RESET);
}

// ---------- DISPLAY ALL MENU ITEMS ----------
void displayMenuItems() {
    if (menuCount == 0) {
        printf("%sNo menu items available.%s\n", RED, RESET);
        return;
    }

    printf("\n%s================ MENU ITEMS LIST ================%s\n", BLUE, RESET);
    printf("%s%-10s %-25s %-10s%s\n", YELLOW, "Item ID", "Name", "Price", RESET);
    printf("--------------------------------------------------\n");

    for (int i = 0; i < menuCount; i++) {
        printf("%-10d %-25s %-10.2f\n",
               menu[i].itemID,
               menu[i].name,
               menu[i].price);
    }
}

// ---------- SEARCH MENU ITEM ----------
void searchMenuItem() {
    int id, found = 0;

    printf("%sEnter Item ID to search: %s", MAGENTA, RESET);
    scanf("%d", &id);

    for (int i = 0; i < menuCount; i++) {
        if (menu[i].itemID == id) {
            printf("\n%sMenu Item Found!%s\n", GREEN, RESET);
            printf("%sItem ID:%s %d\n", CYAN, RESET, menu[i].itemID);
            printf("%sName:%s %s\n", CYAN, RESET, menu[i].name);
            printf("%sPrice:%s %.2f\n", CYAN, RESET, menu[i].price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("%sMenu Item not found!%s\n", RED, RESET);
    }
}
