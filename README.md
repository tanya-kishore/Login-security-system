Login Security System

Description:

This program implements a simple login security system using C++. Users can register with a username, password, and age, log in using their credentials, and change their passwords if needed.

Features:

    User Registration: Allows users to register with a username, password, and age.
    User Login: Users can log in using their registered credentials.
    Change Password: Provides functionality to change the password after successful login.
    File Storage: User credentials are stored in a text file (file.txt).

Usage:

    Register:
        Select option 1 from the menu.
        Enter a username, password, and age as prompted.
    Login:
        Select option 2 from the menu.
        Enter your username and password.
        Upon successful login, user details are displayed.
    Change Password:
        Select option 3 from the menu.
        Enter your old password and then the new password.
        Confirm the new password to change it.
    End Program:
        Select option 4 from the menu to exit the program.

File Structure:

    main.cpp: Contains the main program logic.
    file.txt: Stores user credentials.

Compilation and Execution:

    Compile the program:

    css

g++ main.cpp -o login_system

Run the program:

bash

    ./login_system

Important Notes:

    Passwords are stored in plain text in the file.txt file for demonstration purposes only. In real applications, passwords should be encrypted.
    This program is for educational purposes and may lack robust security measures for production environments.
    There are two individual file that is designed in a different way but the purpose is same ,that's why they are in the same repository.
Language used:
    C++
