#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// ================= ANSI COLORS =================
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define CYAN    "\033[1;36m"
#define MAGENTA "\033[1;35m"

// ================= STRUCTURES =================
typedef struct {
    int id;
    char name[30];
    float price;
} Menu;

typedef struct {
    int tableNo;
    int seats;
} Table;

typedef struct {
    int orderID;
    int tableNo;
    int itemID;
    int quantity;
} Order;

typedef struct {
    int billID;
    int orderID;
    float total;
} Bill;

// ================= GLOBAL DATA =================
Menu menus[MAX];     int menuCount = 0;
Table tables[MAX];  int tableCount = 0;
Order orders[MAX];  int orderCount = 0;
Bill bills[MAX];    int billCount = 0;

// ================= UI FUNCTIONS =================
void header(const char *title) {
    system("cls || clear");
    printf("%s=====================================================%s\n", CYAN, RESET);
    printf("%s   %s%s\n", GREEN, title, RESET);
    printf("%s=====================================================%s\n\n", CYAN, RESET);
}

// ================= FILE HANDLING =================
void loadData(char *file, void *arr, int *count, size_t size) {
    FILE *fp = fopen(file, "rb");
    if (fp) {
        fread(count, sizeof(int), 1, fp);
        fread(arr, size, *count, fp);
        fclose(fp);
    }
}

void saveData(char *file, void *arr, int *count, size_t size) {
    FILE *fp = fopen(file, "wb");
    fwrite(count, sizeof(int), 1, fp);
    fwrite(arr, size, *count, fp);
    fclose(fp);
}

// ================= SORTING (BUBBLE SORT) =================
void sortMenuByID(int asc) {
    Menu t;
    for (int i = 0; i < menuCount - 1; i++)
        for (int j = 0; j < menuCount - i - 1; j++)
            if ((asc && menus[j].id > menus[j+1].id) ||
               (!asc && menus[j].id < menus[j+1].id)) {
                t = menus[j];
                menus[j] = menus[j+1];
                menus[j+1] = t;
            }
}

void sortMenuByName() {
    Menu t;
    for (int i = 0; i < menuCount - 1; i++)
        for (int j = 0; j < menuCount - i - 1; j++)
            if (strcmp(menus[j].name, menus[j+1].name) > 0) {
                t = menus[j];
                menus[j] = menus[j+1];
                menus[j+1] = t;
            }
}

// ================= MENU MODULE =================
void menuModule() {
    int ch;
    while (1) {
        header("MENU MANAGEMENT");
        printf("1. Add Menu Item\n");
        printf("2. Display Menu Items\n");
        printf("3. Sort Menu Items\n");
        printf("4. Back\n");
        printf("---------------------------------------------\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        if (ch == 1) {
            header("ADD MENU ITEM");
            printf("ID: "); scanf("%d", &menus[menuCount].id);
            printf("Name: "); scanf(" %[^\n]", menus[menuCount].name);
            printf("Price: "); scanf("%f", &menus[menuCount].price);
            menuCount++;
            saveData("menu.dat", menus, &menuCount, sizeof(Menu));
            printf(GREEN "\n✔ Menu Item Added Successfully\n" RESET);
            getchar(); getchar();
        }
        else if (ch == 2) {
            header("MENU LIST");
            printf("%-10s %-20s %-10s\n", "ID", "NAME", "PRICE");
            printf("---------------------------------------------\n");
            for (int i = 0; i < menuCount; i++)
                printf("%-10d %-20s %-10.2f\n",
                       menus[i].id, menus[i].name, menus[i].price);
            getchar(); getchar();
        }
        else if (ch == 3) {
            int s;
            header("SORT MENU");
            printf("1. Sort by ID (Ascending)\n");
            printf("2. Sort by ID (Descending)\n");
            printf("3. Sort by Name (A-Z)\n");
            printf("Choice: ");
            scanf("%d", &s);
            if (s == 1) sortMenuByID(1);
            else if (s == 2) sortMenuByID(0);
            else if (s == 3) sortMenuByName();
            printf(GREEN "\n✔ Sorted Successfully\n" RESET);
            getchar(); getchar();
        }
        else if (ch == 4) return;
    }
}

// ================= TABLE MODULE =================
void tableModule() {
    int ch;
    while (1) {
        header("TABLE MANAGEMENT");
        printf("1. Add Table\n2. Display Tables\n3. Back\n");
        printf("Choice: ");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("Table No: "); scanf("%d", &tables[tableCount].tableNo);
            printf("Seats: "); scanf("%d", &tables[tableCount].seats);
            tableCount++;
            saveData("table.dat", tables, &tableCount, sizeof(Table));
            printf(GREEN "✔ Table Added\n" RESET);
            getchar(); getchar();
        }
        else if (ch == 2) {
            printf("\n%-10s %-10s\n", "TABLE", "SEATS");
            printf("----------------------\n");
            for (int i = 0; i < tableCount; i++)
                printf("%-10d %-10d\n", tables[i].tableNo, tables[i].seats);
            getchar(); getchar();
        }
        else if (ch == 3) return;
    }
}

// ================= ORDER MODULE =================
void orderModule() {
    int ch;
    while (1) {
        header("ORDER MANAGEMENT");
        printf("1. Add Order\n2. Display Orders\n3. Back\n");
        printf("Choice: ");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("Order ID: "); scanf("%d", &orders[orderCount].orderID);
            printf("Table No: "); scanf("%d", &orders[orderCount].tableNo);
            printf("Item ID: "); scanf("%d", &orders[orderCount].itemID);
            printf("Quantity: "); scanf("%d", &orders[orderCount].quantity);
            orderCount++;
            saveData("order.dat", orders, &orderCount, sizeof(Order));
            printf(GREEN "✔ Order Added\n" RESET);
            getchar(); getchar();
        }
        else if (ch == 2) {
            printf("\n%-10s %-10s %-10s %-10s\n",
                   "ORDER", "TABLE", "ITEM", "QTY");
            printf("--------------------------------------------\n");
            for (int i = 0; i < orderCount; i++)
                printf("%-10d %-10d %-10d %-10d\n",
                       orders[i].orderID,
                       orders[i].tableNo,
                       orders[i].itemID,
                       orders[i].quantity);
            getchar(); getchar();
        }
        else if (ch == 3) return;
    }
}

// ================= BILL MODULE =================
void billModule() {
    int ch;
    while (1) {
        header("BILL MANAGEMENT");
        printf("1. Generate Bill\n2. Display Bills\n3. Back\n");
        printf("Choice: ");
        scanf("%d", &ch);

        if (ch == 1) {
            float total = 0;
            printf("Bill ID: "); scanf("%d", &bills[billCount].billID);
            printf("Order ID: "); scanf("%d", &bills[billCount].orderID);

            for (int i = 0; i < orderCount; i++)
                for (int j = 0; j < menuCount; j++)
                    if (orders[i].itemID == menus[j].id)
                        total += menus[j].price * orders[i].quantity;

            bills[billCount].total = total;
            billCount++;
            saveData("bill.dat", bills, &billCount, sizeof(Bill));
            printf(GREEN "✔ Bill Generated: %.2f\n" RESET, total);
            getchar(); getchar();
        }
        else if (ch == 2) {
            printf("\n%-10s %-10s %-10s\n", "BILL", "ORDER", "TOTAL");
            printf("--------------------------------\n");
            for (int i = 0; i < billCount; i++)
                printf("%-10d %-10d %-10.2f\n",
                       bills[i].billID,
                       bills[i].orderID,
                       bills[i].total);
            getchar(); getchar();
        }
        else if (ch == 3) return;
    }
}

// ================= MAIN =================
int main() {
    loadData("menu.dat", menus, &menuCount, sizeof(Menu));
    loadData("table.dat", tables, &tableCount, sizeof(Table));
    loadData("order.dat", orders, &orderCount, sizeof(Order));
    loadData("bill.dat", bills, &billCount, sizeof(Bill));

    int choice;
    while (1) {
        header("RESTAURANT MANAGEMENT SYSTEM");
        printf("1. Manage Menu\n");
        printf("2. Manage Tables\n");
        printf("3. Manage Orders\n");
        printf("4. Billing System\n");
        printf("5. Exit\n");
        printf("---------------------------------------------\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) menuModule();
        else if (choice == 2) tableModule();
        else if (choice == 3) orderModule();
        else if (choice == 4) billModule();
        else if (choice == 5) {
            printf(YELLOW "\nProgram Terminated Successfully\n" RESET);
            exit(0);
        }
    }
}
