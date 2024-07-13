#include <iostream>
#include <unordered_map>
#include "encryption_with_key.hpp"
// Store encrypted passwords
std::unordered_map<std::string, std::string> users;

// Key for encryption
const std::string encryption_key = "my_secret_key";

// Function to register a user
void registerUser(const std::string& username, const std::string& password) {
    std::string encrypted_password = password;
    vix::cryption(encrypted_password, encryption_key);
    users[username] = encrypted_password;
    std::cout << "User registered successfully!" << std::endl;
}

// Function to login a user
bool loginUser(const std::string& username, const std::string& password) {
    auto it = users.find(username);
    if (it != users.end()) {
        std::string encrypted_password = password;
        vix::cryption(encrypted_password, encryption_key);
        if (encrypted_password == it->second) {
            return true;
        }
    }
    return false;
}

int main() {
    int choice;
    std::string username, password;
    std::cout<<"hello"<<std::endl;
    // while (true) {
    //     std::cout << "1. Register\n2. Login\n3. Exit\nChoose an option: ";
    //     std::cin >> choice;

    //     if (choice == 1) {
    //         std::cout << "Enter username: ";
    //         std::cin >> username;
    //         std::cout << "Enter password: ";
    //         std::cin >> password;
    //         registerUser(username, password);
    //     } else if (choice == 2) {
    //         std::cout << "Enter username: ";
    //         std::cin >> username;
    //         std::cout << "Enter password: ";
    //         std::cin >> password;
    //         if (loginUser(username, password)) {
    //             std::cout << "Login successful!" << std::endl;
    //         } else {
    //             std::cout << "Login failed!" << std::endl;
    //         }
    //     } else if (choice == 3) {
    //         break;
    //     } else {
    //         std::cout << "Invalid option. Please try again." << std::endl;
    //     }
    // }

    return 0;
}
