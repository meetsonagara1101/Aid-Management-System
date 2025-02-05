# Aid Management System

## Overview
The Aid Management System is a console-based inventory management application designed for managing humanitarian aid items. The system allows users to track, update, and manage various aid items including both perishable and non-perishable goods.

## Features

### 1. Main Menu Options
The system provides the following functionalities:
1. List Items
2. Add Item
3. Remove Item
4. Update Quantity
5. Sort
6. Ship Items
7. New/Open Aid Database
0. Exit

### 2. Database Management
- Ability to create new or open existing aid databases
- File operations with .dat extension support
- Automatic loading and saving of records

### 3. Item Display Format
Items are displayed in a structured table format showing:
```
ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry
----+-------+-------------------------------------+------+------+---------+-----------
```

### 4. Item Details
Each item record contains:
- SKU (Stock Keeping Unit)
- Description
- Quantity Available (Have)
- Quantity Needed (Need)
- Unit Price
- Expiry Date (for perishable items)
- Special Instructions (where applicable)

### 5. Item Categories
Supports different types of items:
- Perishable items (with expiry dates)
- Non-perishable items
- Items with special handling instructions

### 6. Detailed Item View
When selecting an item, displays comprehensive information including:
- Item identification (SKU and Description)
- Quantity statistics
- Financial information (Unit Price and Required Purchase Fund)
- Expiry information (for perishable items)

## Technical Details

### Memory Management
- Efficient heap memory usage
- Zero memory leaks (verified by Valgrind)
- Clean memory deallocation on program exit

### Data File Structure
The system uses a text-based database with tab-separated values:
```
SKU Description Have Need Price Instructions ExpiryDate
```

### System Requirements
- Console-based interface
- File system access for data storage
- Memory management capabilities

## Usage Examples

### Viewing Item List
1. Select option 1 from main menu
2. View tabulated list of all items
3. Enter row number for detailed item view
4. Press ENTER to return to main menu

### Database Operations
1. Select option 7 for database operations
2. Enter filename (e.g., "data.dat")
3. System loads and displays record count

## Error Handling
- Input validation
- File operation error handling
- Memory allocation verification

## Data Safety Features
- Automatic data persistence
- Clean program exit
- Data integrity checks

## Performance
- Efficient memory usage
- Quick data access and modification
- Optimized for large datasets

## Note
This system is designed for humanitarian aid inventory management and includes features specific to tracking and managing aid supplies. The implementation focuses on reliability and efficient resource usage.