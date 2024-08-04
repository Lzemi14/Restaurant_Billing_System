#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct items {
    int quantity;
    char item[20];
    float priceOfitem;
};

struct orders {
    char customer[20];
    int numOfitems;
    struct items iTem[50];
};

void billHeader(char name[30]) {
    printf("\n\t\t----------------------------------\n");
    printf("\n\n\t\t         ABC Restaurant         \n");
    printf("\n\t\t----------------------------------\n");
    printf("\n\t\tDATE: %s", __DATE__);
    printf("\n\t\tInvoice To: %s", name);
    printf("\n\t\t----------------------------------\n");
    printf("\n\t\tItems     Quantity     Total\n");
    printf("\t\t----------------------------------\n");
}

void billBody(char item[20], int quantity, float priceOfitem) {
    printf("\t\t%s          %d           %.2f     ", item, quantity, priceOfitem);
    printf("\n\t\t----------------------------------\n");
}

void billFooter(float total) {
    float discount = 0.1 * total;
    float netTotal = total - discount;
    float cgst = 0.09 * netTotal;
    float sgst = 0.07 * netTotal;
    float grandTotal = netTotal + cgst + sgst;
    printf("\n\t\tsubtotal                  %.2f", total);
    printf("\n\t\tDiscount @10%%            %.2f", discount);
    printf("\n\t\t----------------------------------\n");
    printf("\n\t\tnettotal                  %.2f", netTotal);
    printf("\n\t\tCGST @9%%                 %.2f", cgst);
    printf("\n\t\tSGST @7%%                 %.2f", sgst);
    printf("\n\t\t----------------------------------\n");
    printf("\n\t\tGrandtotal               %.2f", grandTotal);
    printf("\n\t\t----------------------------------\n");
    printf("\n\t\t----------------------------------\n");
}

int main() {
    char name[30], conT = 'y';

    struct orders odr;
    struct orders order;
    FILE *fp;

    while (conT == 'y') {
        float total = 0;
        int found = 0;
        char save;
        int option;
        printf("\n\n\t\t         ABC Restaurant         \n");
        printf("Please select operation: \n");
        printf("\n1. Generate new invoice");
        printf("\n2. Show all invoices");
        printf("\n3. Search invoice");
        printf("\n4. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &option);
        fgetc(stdin);

        switch (option) {
            case 1:
                system("clear");
                printf("\nPlease enter the name of the customer: ");
                fgets(odr.customer, 20, stdin);
                odr.customer[strlen(odr.customer) - 1] = '\0';

                printf("\nEnter number of items: ");
                scanf("%d", &odr.numOfitems);
                for (int i = 0; i < odr.numOfitems; i++) {
                    fgetc(stdin);
                    printf("\nEnter name of item %d: ", i + 1);
                    fgets(odr.iTem[i].item, 20, stdin);
                    odr.iTem[i].item[strlen(odr.iTem[i].item) - 1] = '\0';
                    printf("Enter the unit price of item: ");
                    scanf("%f", &odr.iTem[i].priceOfitem);
                    printf("Enter quantity of item: ");
                    scanf("%d", &odr.iTem[i].quantity);
                    total += odr.iTem[i].quantity * odr.iTem[i].priceOfitem;
                }
                billHeader(odr.customer);
                for (int i = 0; i < odr.numOfitems; i++) {
                    billBody(odr.iTem[i].item, odr.iTem[i].quantity, odr.iTem[i].priceOfitem);
                }
                billFooter(total);

                printf("\nDo you want to save this invoice [y/n]: ");
                scanf(" %c", &save);

                if (save == 'y') {
                    fp = fopen("RestaurantBill.txt", "a+");
                    fwrite(&odr, sizeof(struct orders), 1, fp);
                    if (fwrite != 0) {
                        printf("\n** Successfully saved **\n\n");
                    } else {
                        printf("\nERROR !!\n\n");
                    }
                    fclose(fp);
                } else {
                    printf("\n\n");
                }

                break;

            case 2:
                system("clear");

                printf("\n     ::::::::: All Previous Invoices ::::::::");
                fp = fopen("RestaurantBill.txt", "r");
                while (fread(&order, sizeof(struct orders), 1, fp)) {
                    total = 0;
                    billHeader(order.customer);
                    for (int i = 0; i < order.numOfitems; i++) {
                        billBody(order.iTem[i].item, order.iTem[i].quantity, order.iTem[i].priceOfitem);
                        total += order.iTem[i].quantity * order.iTem[i].priceOfitem;
                    }
                    billFooter(total);
                }

                fclose(fp);
                break;

            case 3:
                system("clear");
                printf("Enter name of customer: ");
                fgets(name, 30, stdin);
                name[strlen(name) - 1] = '\0';
                fp = fopen("RestaurantBill.txt", "r");
                printf("\n\t::::::: Invoice of %s :::::::", name);
                while (fread(&order, sizeof(struct orders), 1, fp)) {
                    total = 0;
                    if (strcmp(name, order.customer) == 0) {
                        billHeader(order.customer);
                        for (int i = 0; i < order.numOfitems; i++) {
                            billBody(order.iTem[i].item, order.iTem[i].quantity, order.iTem[i].priceOfitem);
                            total += order.iTem[i].quantity * order.iTem[i].priceOfitem;
                        }
                        billFooter(total);
                        found = 1;
                    }
                }
                if (found == 0) {
                    printf("\nSorry!! Invoice doesn't exist\n\n");
                }

                fclose(fp);
                break;

            case 4:
                system("clear");
                printf("\nExiting.......:)\n\n");
                exit(0);
                break;

            default:
                system("clear");
                printf("\nInvalid option!\n\n");
                break;
        }
        printf("\nDo you want to continue [y/n]: ");
        scanf(" %c", &conT);
    }
    printf("\n\n");
    return 0;
}
