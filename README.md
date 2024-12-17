# Restaurant Management System

## Description

The **Restaurant Management System** is a C-based application designed to handle user registration, login, order management, bill generation, and invoice storage. The system allows users to manage restaurant orders, generate bills, and save those bills in CSV and binary formats. It is an easy-to-use application with a menu-driven interface and is ideal for those learning C programming and real-world application development.

## Features

- **User Registration & Login**: Create a new user account with a username and password, then log in to the system.
- **Generate Bills**: Create customer bills by selecting items, specifying quantities, and entering prices.
- **Save Bills**: Bills can be saved in both binary (`RestaurantBill.dat`) and CSV (`RestaurantBills.csv`) formats.
- **Search and View Invoices**: Search invoices by customer name and view them in a detailed format.
- **Discounts and VAT**: The system applies a discount and VAT to the total amount and displays the grand total.

## File Structure

## Prerequisites

To run this project, you need:

- A C compiler (like GCC)
- Basic knowledge of C programming
- A terminal or IDE that supports C programming

## Installation

Follow these steps to set up and run the **Restaurant Management System** on your machine:

1. **Clone the repository**:
   ```bash
   git clone https://github.com/alnooristiak/restaurantBillingSystem.git
   cd restaurantBillingSystem
   ```

gcc main.c -o restaurant_management_system

./restaurant_management_system

===== Restaurant Management System =====

1. Register
2. Login
3. Exit
   Enter your choice: 2

Enter username: john_doe
Enter password: mypassword
Registration successful! You can now log in.

========== RESTAURANT MENU ==========

1. Generate Invoice
2. Show All Invoices
3. Search Invoice
4. Exit
   Enter your choice: 1

Enter customer name: John Doe
Enter number of items: 2

Enter item 1: Pizza
Enter quantity: 2
Enter unit price: 10.00

Enter item 2: Pasta
Enter quantity: 1
Enter unit price: 15.00

Generating Bill...
============ ADV. RESTAURANT ============
Date: Mon Dec 7 2024
Invoice To: John Doe

---

## Items Qty Total

Pizza 2 20.00
Pasta 1 15.00

---

Sub Total: 35.00
Discount (10%): 3.50
Net Total: 31.50
VAT (15%): 4.73

---

## Grand Total: 36.23

Save the invoice? (y/n): y
Invoice saved successfully.

========== RESTAURANT MENU ==========

1. Generate Invoice
2. Show All Invoices
3. Search Invoice
4. Exit
   Enter your choice: 2

Displaying all invoices...
============ ADV. RESTAURANT ============
Date: Mon Dec 7 2024
Invoice To: John Doe

---

## Items Qty Total

Pizza 2 20.00
Pasta 1 15.00

---

Sub Total: 35.00
Discount (10%): 3.50
Net Total: 31.50
VAT (15%): 4.73

---

## Grand Total: 36.23

Customer Name,Date,Item,Quantity,Unit Price,Total
John Doe,Mon Dec 7 2024,Pizza,2,10.00,20.00
John Doe,Mon Dec 7 2024,Pasta,1,15.00,15.00

### Instructions

- **Clone the repository** to get started with the project.
- **Compile** the C program using a C compiler like GCC.
- **Run the executable** to interact with the system.

### Example Run

1. **Start the program** and register a user.
2. **Login** using the registered username and password.
3. **Generate an invoice** for a customer with items, quantities, and prices.
4. **View all invoices** or search invoices by customer name.

This **README.md** file will give users everything they need to understand how to set up, use, and contribute to the **Restaurant Management System**. It includes detailed instructions and code outputs for better understanding.
