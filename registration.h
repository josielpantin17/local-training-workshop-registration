#ifndef REGISTRATION_H_INCLUDED
#define REGISTRATION_H_INCLUDED
#include "participant.h"
#include <array>
using namespace std;

class RegistrationSystem {
private:
    array<Participant, 100> people;
    int count, nextId;
    int getNumber(int, int);
    string getText(string);
    string getPhone();
    void searchParticipant(int) const;
    void searchParticipant(string) const;
public:
    RegistrationSystem();
    void run();
    void registerParticipant();
    void showParticipants() const;
    void searchMenu();
    void showSummary() const;
};
#endif
