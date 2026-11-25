#include "registration.h"
#include <iostream>
#include <cctype>
using namespace std;

const string workshops[4] = {"Computer Basics", "Microsoft Office Training",
                             "Digital Marketing", "Basic Computer Programming"};

RegistrationSystem::RegistrationSystem() { count = 0; nextId = 1001; }

int RegistrationSystem::getNumber(int low, int high) {
    int n;
    while (!(cin >> n) || n < low || n > high) {
        cout << "Enter a number from " << low << " to " << high << ": ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    cin.ignore(1000, '\n');
    return n;
}

string RegistrationSystem::getText(string message) {
    string text;
    do {
        cout << message;
        getline(cin, text);
        if (text.empty()) cout << "This field cannot be empty.\n";
    } while (text.empty());
    return text;
}

string RegistrationSystem::getPhone() {
    string phone;
    bool valid;
    do {
        phone = getText("Phone (7 to 15 digits): ");
        valid = phone.length() >= 7 && phone.length() <= 15;
        int length = phone.length();
        for (int i = 0; i < length; i++)
            if (!isdigit(static_cast<unsigned char>(phone[i]))) valid = false;
        if (!valid) cout << "Use only 7 to 15 digits.\n";
    } while (!valid);
    return phone;
}

void RegistrationSystem::registerParticipant() {
    if (count == 100) { cout << "Registration is full.\n"; return; }
    string name = getText("Name: ");
    string phone = getPhone();
    cout << "\nChoose a workshop:\n";
    for (int i = 0; i < 4; i++) cout << i + 1 << ". " << workshops[i] << endl;
    int choice = getNumber(1, 4);
    people[count].setData(nextId, name, phone, workshops[choice - 1]);
    cout << "Registered! ID: " << nextId << endl;
    count++;
    nextId++;
}

void RegistrationSystem::showParticipants() const {
    if (count == 0) { cout << "No registrations yet.\n"; return; }
    for (int i = 0; i < count; i++) { cout << "\n"; people[i].display(); }
}

void RegistrationSystem::searchParticipant(int id) const {
    for (int i = 0; i < count; i++)
        if (people[i].getId() == id) { people[i].display(); return; }
    cout << "Participant not found.\n";
}

void RegistrationSystem::searchParticipant(string name) const {
    bool found = false;
    for (int i = 0; i < count; i++)
        if (people[i].getName().find(name) != string::npos) {
            people[i].display(); found = true;
        }
    if (!found) cout << "Participant not found.\n";
}

void RegistrationSystem::searchMenu() {
    if (count == 0) { cout << "No participants to search.\n"; return; }
    int choice;
    cout << "1. Search by ID\n2. Search by name\nChoice: ";
    choice = getNumber(1, 2);
    if (choice == 1) {
        cout << "Enter ID: ";
        searchParticipant(getNumber(1001, 1100));
    } else searchParticipant(getText("Enter name: "));
}

void RegistrationSystem::showSummary() const {
    int totals[4] = {0, 0, 0, 0};
    for (int i = 0; i < count; i++)
        for (int j = 0; j < 4; j++)
            if (people[i].getWorkshop() == workshops[j]) totals[j]++;
    cout << "Total participants: " << count << "\nSpaces left: " << 100 - count << endl;
    for (int j = 0; j < 4; j++) cout << workshops[j] << ": " << totals[j] << endl;
}

void RegistrationSystem::run() {
    int choice;
    do {
        cout << "\n--- WORKSHOP REGISTRATION ---\n"
             << "1. Register\n2. Show participants\n3. Search\n4. Summary\n5. Exit\nChoice: ";
        choice = getNumber(1, 5);
        switch (choice) {
            case 1: registerParticipant(); break;
            case 2: showParticipants(); break;
            case 3: searchMenu(); break;
            case 4: showSummary(); break;
            case 5: cout << "Thank you!\n"; break;
        }
    } while (choice != 5);
}
