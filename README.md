"# restaurantBillingSystem"

# Restaurant Billing System

A simple C program to manage and generate bills for a restaurant. The program allows users to create, save, display, and search for invoices, handling various billing functionalities.

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
- [Code Structure](#code-structure)
  - [1. Including Standard Libraries](#1-including-standard-libraries)
  - [2. Defining Structures](#2-defining-structures)
  - [3. Functions](#3-functions)
  - [4. Main Function and Program Flow](#4-main-function-and-program-flow)
- [Contributing](#contributing)
- [License](#license)

---

## Overview

This C-based Restaurant Billing System is designed to automate the billing process for restaurants, allowing restaurant staff to generate, view, and save bills in a streamlined way.

## Features

- **Generate Invoice**: Create a new invoice with customer and item details.
- **Display All Invoices**: Show all saved invoices.
- **Search Invoice**: Look up a specific invoice by customer name.
- **Save Invoice**: Save generated invoices to a file.
- **Calculate Discounts and Taxes**: Automatically apply a 10% discount and 9% CGST/SGST to the bill.

## Getting Started

### Prerequisites

- **C Compiler** (e.g., GCC)

### Installation

1. **Clone the repository**:

   ```bash
   git clone https://github.com/alnooristiak/restaurantBillingSystem.git
   cd restaurantBillingSystem
   ```

2. **Compile the program**:

   ```bash
   gcc restaurantBillingSystem.c -o restaurantBillingSystem
   ```

3. **Run the program**:
   ```bash
   ./restaurantBillingSystem
   ```

## Usage

Once the program is running, it will display a menu with the following options:

1. **Generate Invoice**: Enter customer and item details to generate a new bill.
2. **Show all Invoices**: View all previous invoices saved in the file.
3. **Search Invoice**: Search for an invoice by the customer’s name.
4. **Exit**: Exit the program.

Follow the prompts on the screen for each operation.

## Code Structure

### 1. Including Standard Libraries

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
```
