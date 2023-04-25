#include <iostream>
using namespace std;

class FindTheBoss {
public:
    void operation1() {
        cout << "The boss is here\n";
    }
};

class KillTheBoss {
public:
    void operation2() {
        cout << "Charge!!!\n";
    }
};

class Facade {
public:
    Facade() {
        command1 = new FindTheBoss;
        command2 = new KillTheBoss;
    }
    void operation() {
        command1->operation1();
        command2->operation2();
    }
private:
    FindTheBoss* command1;
    KillTheBoss* command2;
};

int main() {
    Facade* facade = new Facade();
    facade->operation();
    return 0;
}
