#include <iostream>
#include <vector>
#include <string>

struct Contact {
    std::string name;
    std::string phoneNumber;
};

class Phonebook {
private:
    std::vector<Contact> contacts;

public:
    void addContact(const Contact &contact) {
        contacts.push_back(contact);
    }

    void displayContacts() {
        for (const auto &contact : contacts) {
            std::cout << "Name: " << contact.name << ", Phone: " << contact.phoneNumber << std::endl;
        }
    }

    bool removeContact(const std::string &name) {
        for (auto it = contacts.begin(); it != contacts.end(); ++it) {
            if (it->name == name) {
                contacts.erase(it);
                return true;
            }
        }
        return false;
    }

    Contact* searchContact(const std::string &name) {
        for (auto &contact : contacts) {
            if (contact.name == name) {
                return &contact;
            }
        }
        return nullptr;
    }
};

int main() {
    Phonebook phonebook;
    int choice;
    do {
        std::cout << "Phonebook Menu:\n";
        std::cout << "1. Add Contact\n";
        std::cout << "2. Display All Contacts\n";
        std::cout << "3. Search Contact\n";
        std::cout << "4. Remove Contact\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string name, phone;
                std::cout << "Enter name: ";
                std::cin.ignore(); // clear the buffer
                getline(std::cin, name);
                std::cout << "Enter phone number: ";
                getline(std::cin, phone);
                phonebook.addContact({name, phone});
                break;
            }
            case 2: {
                phonebook.displayContacts();
                break;
            }
            case 3: {
                std::string name;
                std::cout << "Enter name: ";
                std::cin.ignore(); // clear the buffer
                getline(std::cin, name);
                Contact* contact = phonebook.searchContact(name);
                if (contact) {
                    std::cout << "Name: " << contact->name << ", Phone: " << contact->phoneNumber << std::endl;
                } else {
                    std::cout << "Contact not found.\n";
                }
                break;
            }
            case 4: {
                std::string name;
                std::cout << "Enter name: ";
                std::cin.ignore(); // clear the buffer
                getline(std::cin, name);
                if (phonebook.removeContact(name)) {
                    std::cout << "Contact removed successfully.\n";
                } else {
                    std::cout << "Contact not found.\n";
                }
                break;
            }
            case 5:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
