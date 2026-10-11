#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void registerUser() {
    string username, password, confirm;
    cout << "\n--- Register ---\n";
    cin.ignore();
    cout << "Username : "; getline(cin, username);
    cout << "Password : "; cin >> password;
    cout << "Confirm  : "; cin >> confirm;

    if (password != confirm) {
        cout << "Passwords do not match!\n";
        return;
    }

    // Check if username already exists
    string u, p;
    ifstream fin("users.txt");
    while (getline(fin,u)){
        getline(fin, p);
        if (u == username) { 
            cout << "Username already taken!\n";
            fin.close();
            return;
        }
    }
    fin.close();

    ofstream fout("users.txt", ios::app);
    fout << username << "\n" << password << "\n";
    fout.close();
    cout << "Registered Successfully!\n";
}

void loginUser() {
    string username, password, u, p;
    cout << "\n--- Login ---\n";
    cin.ignore();
    cout << "Username : "; getline(cin, username);
    cout << "Password : "; cin >> password;

    ifstream fin("users.txt");
    while (getline(fin, u)) {
        getline(fin, p);
        if (u == username && p == password) {
            cout << "Welcome, " << username << "!\n";
            fin.close();
            return;
        }
    }
    fin.close();
    cout << "Invalid username or password!\n";
}

int main() {
    int choice;
    cout << "=== Login & Registration System ===\n";
    do {
        cout << "\n1. Register\n2. Login\n0. Exit\nChoice: ";
        cin >> choice;
        if (cin.fail()) { 
            cin.clear();         
            cin.ignore(100, '\n');
            choice = -1;
        }
        switch (choice) { 
            case 1: registerUser(); break;
            case 2: loginUser();    break;
            case 0: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 0);
    return 0;
}