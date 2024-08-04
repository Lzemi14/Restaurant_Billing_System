# Restaurant_Billing_System
he Restaurant Billing System is a console-based application written in C that allows users to generate, save, view, and search invoices for a restaurant. The system can handle multiple customer orders and provide detailed billing information including item prices, quantities, discounts, and taxes.

## Features

- **Generate New Invoice**: Create a new invoice by entering customer details and order items.
- **Save Invoice**: Save generated invoices to a text file for future reference.
- **Show All Invoices**: Display all previously saved invoices.
- **Search Invoice**: Search and display invoices by customer name.

## Requirements

- GCC (GNU Compiler Collection) or any other C compiler
- Make (optional, for easier compilation)
- Git (for version control)

## Usage
When you run the program, you'll be presented with a menu:

Generate New Invoice: Enter the customer's name, number of items, and details for each item (name, quantity, unit price).
Save Invoice: Choose to save the generated invoice to a text file.
Show All Invoices: Display all saved invoices.
Search Invoice: Search for an invoice by entering the customer's name.
Exit: Exit the application.
## Sample Output
plaintext
Copy code
         ABC Restaurant
Please select operation: 

1. Generate new invoice
2. Show all invoices
3. Search invoice
4. Exit

Enter your choice: 1

Please enter the name of the customer: John Doe

Enter number of items: 2

Enter name of item 1: Burger
Enter the unit price of item: 5.99
Enter quantity of item: 2

Enter name of item 2: Fries
Enter the unit price of item: 2.99
Enter quantity of item: 1

    ABC Restaurant
    DATE: Aug 04 2024
    Invoice To: John Doe

    Items     Quantity     Total
    ----------------------------------
    Burger      2        11.98
    Fries       1        2.99

    Subtotal                  14.97
    Discount @10%             1.50
    ----------------------------------
    Net Total                 13.47
    CGST @9%                  1.21
    SGST @7%                  0.94
    ----------------------------------
    Grand Total               15.62
    ----------------------------------

Do you want to save this invoice [y/n]: y

** Successfully saved **
