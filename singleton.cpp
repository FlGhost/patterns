#include<iostream>

using namespace std;


class ChocolateBoiler {
 private:
  bool empty;
  bool boiled;
  //singleton
  static ChocolateBoiler* uniqueInstance;
  ChocolateBoiler() {
    empty = true;
    boiled = false;
  }
  //singleton
 public:
  static ChocolateBoiler* getInstance() {
    if (uniqueInstance == nullptr) {
      uniqueInstance = new ChocolateBoiler();
    }
    return uniqueInstance;
  }
void fill() {
    if (isEmpty()) {
        empty = false;
        boiled = false;
        // fill the boiler with a milk/chocolate mixture
        std::cout << "Filled the boiler with milk/chocolate mixture." << std::endl;
        std::cout << "Boiler is empty: " << isEmpty() << std::endl;
        std::cout << "Boiler is boiled: " << isBoiled() << std::endl;
    }
}
  void drain() {
    if (!isEmpty() && isBoiled()) {
      // drain the boiled milk and chocolate
      empty = true;
    }
  }
  void boil() {
    if (!isEmpty() && !isBoiled()) {
      // bring the contents to a boil
      boiled = true;
    }
  }
  bool isEmpty() {
    return empty;
  }
  bool isBoiled() {
    return boiled;
  }
};

//singleton
ChocolateBoiler* ChocolateBoiler::uniqueInstance = nullptr;

int main() {
  // Get the unique instance of the chocolate boiler
  ChocolateBoiler* boiler = ChocolateBoiler::getInstance();

  // Fill the boiler
  boiler->fill();

  // Boil the contents
  boiler->boil();

  // Drain the contents
  boiler->drain();

  // Check if the boiler is empty and boiled(used test)
  bool empty = boiler->isEmpty();
  bool boiled = boiler->isBoiled();
  if (empty && !boiled ) {
    std::cout << "The chocolate boiler is now empty and not boiled." << std::endl;
  } else {
    std::cout << "The chocolate boiler is not in the expected state." << std::endl;
  }
  // Destroy the unique instance of the chocolate boiler
  delete boiler;

  return 0;
}
