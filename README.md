# Student-Database

## Overview
This project is a **Student-Database** implemented in C using **Linked Lists**. The program allows users to perform various operations such as adding, deleting, modifying, sorting, and displaying student records.

## Features
- **Add** a new student record
- **Delete** a specific student record by roll number or name
- **Modify** an existing student record
- **Sort** student records by roll number
- **Reverse** the linked list of student records
- **Show** all student records
- **Delete all** student records
- **Save** student records to a file for persistence
- **Exit** the program with or without saving

## Compilation & Execution
### Compile:
```bash
gcc student_record.c -o student_record
```

### Run:
```bash
./student_record
```

## Menu Options
Once executed, the program provides the following menu options:
```
-----------------------------
****STUDENT RECORD MENU**** |
-----------------------------
| a/A : Add new record      |
| d/D : Delete a record     |
| s/S : Show the list       |
| m/M : Modify a record     |
| v/V : Save                |
| e/E : Exit                |
| t/T : Sort the list       |
| l/L : Delete all records  |
| r/R : Reverse the list    |
-----------------------------
```

## File Storage
The records are stored in a file named **hello.txt** when saved. The format used is:
```
<Roll Number> <Name> <Marks>
```
Example:
```
1 John 85.50
2 Alice 92.75
```

## Functions
The following functions are implemented:
- `add_end(ST **ptr)`: Adds a student record at the end
- `delete(ST **ptr)`: Deletes a student record by roll number or name
- `modify(ST **ptr)`: Modifies an existing student record
- `sort(ST *ptr)`: Sorts the records by roll number
- `show(ST *ptr, ST **p)`: Displays all student records
- `rev_link(ST **ptr)`: Reverses the linked list
- `deleteall(ST **ptr)`: Deletes all student records
- `save(ST *ptr)`: Saves student records to a file

## Future Improvements
- Implement a graphical user interface (GUI)
- Add search functionality
- Implement database integration instead of file storage

## License
This project is open-source and available under the MIT License.

## Author
[Your Name]

