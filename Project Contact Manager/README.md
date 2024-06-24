# Contact Management System
This project is a simple Contact Management System implemented in C++. It allows users to manage contacts by adding, deleting, searching, displaying, and saving contacts to a file.

## Features
- Add Contact: Add a new contact with name, phone number, and email.
- Delete Contact: Remove a contact by name.
- Search Contact: Find a contact by name.
- Display Contacts: Show all contacts in a formatted table.
- Save to File: Save contacts to a text file (contacts.txt).

## Compilation
To compile the project using make, navigate to the project directory and run:

```bash
make
```

This will compile the source files, create object files in the `obj/` directory, and generate the executable (`contact_manager`) in the `build/` directory.

## Execution
Run the executable from the build/ directory:

```bash
./build/contact_manager
```

## Cleaning Up
To clean up object files and the executable, run:

```bash
make clean
```

## Usage
Upon running the executable, you will be presented with a menu-driven interface to interact with the Contact Management System:

- Add a contact: Enter contact details to add a new contact.
- Delete a contact: Remove a contact by providing the name.
- Search for a contact: Find and display contact details by name.
- Display all contacts: Show all contacts in a formatted table.
- Save contacts to file: Save the current contacts to a text file (contacts.txt).
- Exit: Quit the program.

## Example

```bash
===== Contact Management System =====
1. Add a contact
2. Delete a contact
3. Search for a contact
4. Display all contacts
5. Save contacts to file
6. Exit
Enter your choice: 1
Enter name: Jim 
Enter phone number: 1234567890
Enter email: jim@email.com
Contact added successfully.
===== Contact Management System =====
1. Add a contact
2. Delete a contact
3. Search for a contact
4. Display all contacts
5. Save contacts to file
6. Exit
Enter your choice: 4
---------------------------------------Contacts---------------------------------------
| Name                      | Phone                     | Email                      |
--------------------------------------------------------------------------------------
| Jim                       | 1234567890                | jim@email.com              |
--------------------------------------------------------------------------------------
```

## Contributing
Contributions to improve and extend this Contact Management System are welcome. If you have suggestions, enhancements, or bug fixes, feel free to submit a pull request.