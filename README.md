# Branch Sales Management System

## Description
This C program manages sales data for multiple branches of a company. It allows users to input sales data, analyze it through various functionalities, and display results for better business decision-making. The program is designed to handle data for 12 months and provides tools for total sales calculation, percentage share, sorting, and peak month analysis.

## Features
1. **Data Input**:
   - Input branch details: name, manager ID, and monthly sales data for 12 months.

2. **Sales Analysis**:
   - Calculate total sales for the entire company.
   - Determine the percentage sales contribution of each branch.
   - Identify the month with peak sales.

3. **Sorting**:
   - Sort branches by sales for a specified month.
   - Sort months by sales for a specific branch.

4. **User-Friendly Menu**:
   - Interactive menu allows users to navigate and perform various operations.

## How It Works
1. **Data Entry**:
   - Users specify the number of branches and input the data for each branch, including branch name, manager ID, and sales for 12 months.

2. **Functionalities**:
   - Total sales are calculated by summing the sales of all branches across all months.
   - The percentage share of each branch in the total sales is computed.
   - The month with the highest sales is determined by aggregating sales across all branches.
   - Sorting operations allow users to analyze sales by branch or by month.

3. **Menu Navigation**:
   - Users interact with the program through a menu and choose specific operations to perform.

## Requirements
- **Programming Language**: C
- **Compiler**: GCC or any other C compiler
- **Operating System**: Cross-platform

## How to Run
1. Clone or download the program to your local machine.
2. Compile the program using a C compiler:
   ```bash
   gcc -o sales_management sales_management.c

