# File Management System

This is a simple file management system implemented in C++. It allows you to perform basic file operations such as creating, reading, writing, and deleting text files.

## Features

- Create a new text file
- Read the contents of a text file
- Write or edit the contents of a text file
- Delete a text file

## Usage

1. Select an option from the menu by entering the corresponding number.

2. Follow the prompts to perform the desired file operation:

- **Create:** Choose this option to create a new text file. Enter the name of the file when prompted. If a file with the same name already exists, an error message will be displayed.

- **Read:** Select this option to read the contents of a text file. The program will display a list of available text files in the "textfiles" directory. Enter the number corresponding to the file you want to read. The contents of the file will be displayed on the screen.

- **Write:** Use this option to edit the contents of a text file. The program will display a list of available text files in the "textfiles" directory. Enter the number corresponding to the file you want to edit. The current content of the file will be displayed, and you can enter new content to replace the existing one.

- **Delete:** Choose this option to delete a text file. The program will display a list of available text files in the "textfiles" directory. Enter the number corresponding to the file you want to delete. The selected file will be permanently deleted.

3. After performing the selected operation, you can continue using the program by selecting another option from the menu.

## Additional Information

- The program includes a loading animation while performing certain operations to provide visual feedback to the user.

- To handle input issues, the code includes the lines `std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');` and `std::cin.clear();`. These lines are used to clear the input buffer and reset any error flags that might be set, ensuring that subsequent input operations work correctly. This is important to prevent unexpected behavior and ensure smooth execution of the program.

## Challenges Faced

While implementing this file management system, one challenge I faced was handling input-related issues, such as newline characters or invalid input. This led to unexpected behavior, incorrect output, or the program getting stuck in an infinite loop. To overcome this, I researched and found the solution of using `std::cin.ignore()` and `std::cin.clear()` to clear the input buffer and reset the error flags.

## Bonus Parameters

I have not attempted the bonus parameters for this file management system. (I just tried to implement the option to change names but in the end it did not implement it)

