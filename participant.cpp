#include "participant.h"
#include <iostream>
using namespace std;

void Participant::setData(int i, string n, string p, string w) {
    id = i; name = n; phone = p; workshop = w;
}
int Participant::getId() const { return id; }
string Participant::getName() const { return name; }
string Participant::getPhone() const { return phone; }
string Participant::getWorkshop() const { return workshop; }
void Participant::display() const {
    cout << "ID: " << id << "\nName: " << name
         << "\nPhone: " << phone << "\nWorkshop: " << workshop << endl;
}
