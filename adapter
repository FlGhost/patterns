#include <iostream>
using namespace std;
// Adaptee Interface
class Adaptee
{
public:
    virtual void print(string str) = 0;
};

// Adaptee Implementation
class idkwtn : public Adaptee
{
public:
    void print(string str) override
    {
        cout << "Open the door " << str << endl;
    }
};

// Target Interface
class Client
{
public:
    virtual void print(string str) = 0;
};

// Adapter Implementation
class Adapter : public Client
{
private:
    Adaptee* printer;

public:
    Adapter(Adaptee* adaptee) : printer(adaptee) {}

    void print(string str) override
    {
        printer->print(str);
    }
};

// Client Code
int main()
{
    Adaptee* adaptee = new idkwtn();
    Client* newPrinter = new Adapter(adaptee);

    newPrinter->print("please");
    return 0;
}
