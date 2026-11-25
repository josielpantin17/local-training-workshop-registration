#include <string>
using namespace std;

class Participant {
private:
    int id;
    string name, phone, workshop;
public:
    void setData(int, string, string, string);
    int getId() const;
    string getName() const;
    string getPhone() const;
    string getWorkshop() const;
    void display() const;
};
