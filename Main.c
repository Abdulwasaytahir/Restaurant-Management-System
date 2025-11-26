#include <stdio.h>
// ANSI Color Codes
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define CYAN    "\033[1;36m"
#define MAGENTA "\033[1;35m"
#define WHITE   "\033[1;37m"

// Function declarations
void welcomeScreen();
void mainMenu();
void menuItemSubMenu();

// --- MAIN FUNCTION ---
int main() {
    welcomeScreen();
    mainMenu();
    return 0;
}

// --- WELCOME SCREEN ---
void welcomeScreen() {
    system("cls || clear");
    printf("\n%s=============================================%s\n", CYAN, RESET);
    printf("%s     WELCOME TO RESTAURANT MANAGEMENT SYSTEM%s\n", GREEN, RESET);
    printf("%s=============================================%s\n\n", CYAN, RESET);
}

// --- MAIN MENU FUNCTION ---
void mainMenu() {
    int choice;

    while (1) {
        printf("\n%s==================== MAIN MENU ====================%s\n", BLUE, RESET);
        printf("%s1.%s Manage Menu Items\n", YELLOW, RESET);
        printf("%s2.%s Manage Tables\n", YELLOW, RESET);
        printf("%s3.%s Manage Orders\n", YELLOW, RESET);
        printf("%s4.%s Generate Bills\n", YELLOW, RESET);
        printf("%s5.%s Exit System\n", RED, RESET);
        printf("----------------------------------------------------\n");

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
                printf("%sFeature coming in next milestone!%s\n", GREEN, RESET);
                break;
            case 5:
                printf("%sExiting the program... Goodbye!%s\n", RED, RESET);
                exit(0);
            default:
                printf("%sInvalid choice! Please try again.%s\n", RED, RESET);
        }
    }
}

// --- MENU ITEM SUB-MENU ---
void menuItemSubMenu() {
    int choice;

    while (1) {
        printf("\n%s================= MENU ITEM SUB-MENU =================%s\n", CYAN, RESET);
        printf("%s1.%s Create New Menu Item\n", YELLOW, RESET);
        printf("%s2.%s Find Menu Item\n", YELLOW, RESET);
        printf("%s3.%s Update Menu Item\n", YELLOW, RESET);
        printf("%s4.%s Delete Menu Item\n", YELLOW, RESET);
        printf("%s5.%s View All Menu Items\n", YELLOW, RESET);
        printf("%s6.%s Back to Main Menu\n", RED, RESET);
        printf("-------------------------------------------------------\n");

        printf("%sEnter your choice: %s", MAGENTA, RESET);
        scanf("%d", &choice);

        system("cls || clear");

        switch (choice) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                printf("%sFeature coming in next milestone!%s\n", GREEN, RESET);
                break;
            case 6:
                return; // Go back to Main Menu
            default:
                printf("%sInvalid choice! Try again.%s\n", RED, RESET);
        }
    }
}
