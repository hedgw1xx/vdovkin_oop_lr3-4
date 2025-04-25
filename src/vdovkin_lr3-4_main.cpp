#include "vdovkin_lr3-4_classPlanet.hpp"
#include "vdovkin_lr3-4_methods.hpp"

int main(int argc, char *argv[]) {
  struct MenuItem {
    string title;
    function<void()> action;
  };

  map<int, MenuItem> menu = {
      {1, {"Default Constructor", demoDefaultConstructor}},
      {2, {"Parameterized Constructor", demoParameterizedConstructor}},
      {3, {"Copy Constructor", demoCopyConstructor}},
      {4, {"Conversion Constructor", demoConversionConstructor}},
      {5, {"Gravity Calculation", demoGravityCalculation}},
      {6,
       {"Add Planet",
        []() {
          Planet p;
          inputPlanet(p);
          planets.push_back(p);
          cout << "Planet added: " << p << endl;
        }}},
      {7, {"Display All Planets", displayAllPlanets}},
      {8, {"Sort Planets by Mass", []() {
             auto sorted = getSortedPlanetsByMass();
             cout << "Planets sorted by mass:" << endl;
             for (const auto &p : sorted) {
               cout << p << endl;
             }
           }}}};

  int choice = 0;

  while (true) {

    cout << "Menu:" << endl;
    for (const auto &item : menu) {
      cout << "• " << item.first << ". " << item.second.title << endl;
    }
    cout << "• 0. Exit" << endl;

    EnterInt(cin, choice, "Enter your choice: ")();

    if (choice == 0) {
      cout << "© 2025 Eugene Vdovkin" << endl;
      break;
    }

    cout << endl;

    if (menu.find(choice) != menu.end()) {
      clearTerminal();
      menu[choice].action();
    } else {
      clearTerminal();
      cout << "Invalid choice" << endl;
    }

    cout << endl << endl;
  }

  return 0;
}
