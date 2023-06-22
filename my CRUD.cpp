#include <iostream>
#include <vector>
#include <algorithm>

struct Contact {
    std::string name;
    std::string phone;
    std::string email;
};

void createContact(std::vector<Contact>& contacts) {
    Contact newContact;
    std::cout << "Enter name: ";
    std::getline(std::cin, newContact.name);
    std::cout << "Enter phone number: ";
    std::getline(std::cin, newContact.phone);
    std::cout << "Enter email address: ";
    std::getline(std::cin, newContact.email);

    contacts.push_back(newContact);
    std::cout << "Contact created successfully.\n";
}

void readContacts(const std::vector<Contact>& contacts) {
    if (contacts.empty()) {
        std::cout << "No contacts found.\n";
        return;
    }

    std::cout << "Contact List:\n";
    for (const auto& contact : contacts) {
        std::cout << "Name: " << contact.name << std::endl;
        std::cout << "Phone: " << contact.phone << std::endl;
        std::cout << "Email: " << contact.email << std::endl;
        std::cout << std::endl;
    }
}

void updateContact(std::vector<Contact>& contacts) {
    if (contacts.empty()) {
        std::cout << "No contacts found.\n";
        return;
    }

    std::cout << "Enter the name of the contact to update: ";
    std::string name;
    std::getline(std::cin, name);

    bool contactFound = false;
    for (auto& contact : contacts) {
        if (contact.name == name) {
            std::cout << "Enter new phone number: ";
            std::getline(std::cin, contact.phone);
            std::cout << "Enter new email address: ";
            std::getline(std::cin, contact.email);
            contactFound = true;
            std::cout << "Contact updated successfully.\n";
            break;
        }
    }

    if (!contactFound) {
        std::cout << "Contact not found.\n";
    }
}

void deleteContact(std::vector<Contact>& contacts) {
    if (contacts.empty()) {
        std::cout << "No contacts found.\n";
        return;
    }

    std::cout << "Enter the name of the contact to delete: ";
    std::string name;
    std::getline(std::cin, name);

    auto it =std::find_if(contacts.begin(), contacts.end(), [&](const Contact& contact) {
        return contact.name == name;
    });

    if (it != contacts.end()) {
        contacts.erase(it);
        std::cout << "Contact deleted successfully.\n";
    } else {
        std::cout << "Contact not found.\n";
    }
}

int main() {
    std::vector<Contact> contacts;

    while (true) {
        std::cout << "-----------------------------------\n";
        std::cout << "CRUD Application - Contacts\n";
        std::cout << "-----------------------------------\n";
        std::cout << "1. Create contact\n";
        std::cout << "2. Read contacts\n";
        std::cout << "3. Update contact\n";
        std::cout << "4. Delete contact\n";
        std::cout << "5. Exit\n";
        std::cout << "-----------------------------------\n";
        std::cout << "Enter your choice (1-5): ";

        int choice;
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                createContact(contacts);
                break;
            case 2:
                readContacts(contacts);
                break;
            case 3:
                updateContact(contacts);
                break;
            case 4:
                deleteContact(contacts);
                break;
            case 5:
                std::cout << "Exiting program.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }

        std::cout << std::endl;
    }

    return 0;
}
