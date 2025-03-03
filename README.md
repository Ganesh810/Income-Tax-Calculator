# Income Tax Calculator

## Overview

This project is a **C-based Income Tax Calculator** that allows users to:

- Add new tax records
- View all records
- Search for a specific record
- Edit an existing record
- Delete a record

The program utilizes **file handling** to store tax records persistently, making it a simple yet effective tax management tool.

## Features

1. **Add New Record**: Users can enter taxpayer details, and the tax is automatically calculated based on predefined tax brackets.
2. **List All Records**: Displays all tax records along with the calculated tax.
3. **Search Record**: Allows users to find tax records by name.
4. **Edit Record**: Users can modify an existing record.
5. **Delete Record**: Removes a record from the file.
6. **Exit**: Terminates the program.

## Tax Calculation Logic

The tax is computed based on the following slabs:

- **Income ≤ 250,000**: No tax
- **Income 250,001 - 500,000**: 5% tax on income exceeding 250,000
- **Income 500,001 - 1,000,000**: 20% tax on income exceeding 500,000 + 12,500
- **Income > 1,000,000**: 30% tax on income exceeding 1,000,000 + 112,500

## File Handling

- The program uses a binary file (`tax_records.txt`) to store data persistently.
- Each record is saved using a `struct` in C.
- Users can modify, search, and delete records efficiently.

## Compilation & Execution

### **To Compile:**

```sh
gcc c_project.cpp -o tax_calculator
```

### **To Run:**

```sh
./tax_calculator
```

## Example Usage

```sh
Tax Calculator
1. Add new record
2. List all records
3. Search record
4. Edit record
5. Delete record
0. Exit
Enter choice: 1
Enter name: John
Enter age: 30
Enter income: 600000
Record added successfully.
```

## Potential Improvements

- Input validation to ensure correct data entry.
- Sorting records by income or name for better accessibility.
- Implementing a GUI-based version for better user experience.

