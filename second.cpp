#include <iostream>
#include <fstream>
#include <string>
using namespace std;


bool userExists(const string& username) {
    ifstream file(username + ".txt");
    return file.good();
}

void registerUser() {
    string username, password;
    cout << "Enter new username: ";
    cin >> username;

    if (userExists(username)) {
        cout << "Username already exists. Try logging in.\n";
        return;
    }

    cout << "Enter new password: ";
    cin >> password;

    ofstream file(username + ".txt");
    file << username << "\n" << password;
    file.close();

    cout << "Registration successful!\n";
}


bool loginUser() {
    string username, password, fileUsername, filePassword;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (!userExists(username)) {
        cout << "User not found.\n";
        return false;
    }

    ifstream file(username + ".txt");
    getline(file, fileUsername);
    getline(file, filePassword);

    if (username == fileUsername && password == filePassword) {
        cout << "Login successful!\n";
        return true;
    } else {
        cout << "Incorrect credentials.\n";
        return false;
    }
}


int main() {
    int choice;
    cout << "1. Register\n2. Login\nChoose option: ";
    cin >> choice;

    if (choice == 1) {
        registerUser();
    } else if (choice == 2) {
        loginUser();
    } else {
        cout << "Invalid choice.\n";
    }

    return 0;
}
