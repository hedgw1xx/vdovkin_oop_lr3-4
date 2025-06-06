#ifndef VDOVKIN_LR3_4_METHODS_H
#define VDOVKIN_LR3_4_METHODS_H

#include "vdovkin_def.hpp"
#include "vdovkin_lr3-4_classPlanet.hpp"

inline vector<Planet> planets;

inline void inputPlanet(Planet &planet) {
  string name;
  double mass, radius;
  vector<string> dates;

  Enter(cin, name, "Enter name: ")();
  planet.setName(name);

  Enter(cin, mass, "Enter mass: ")();
  planet.setMass(mass);

  Enter(cin, radius, "Enter radius: ")();
  planet.setRadius(radius);

  int numDates;
  Enter(cin, numDates, "Enter number of research dates: ")();
  for (int i = 0; i < numDates; ++i) {
    string date;
    Enter(cin, date, "Enter date: ")();
    dates.push_back(date);
  }
  planet.setResearchDates(dates);
}

inline void displayAllPlanets() {
  for (const auto &planet : planets) {
    cout << planet << endl;
  }
}

inline void demoDefaultConstructor() {
  Planet p;
  cout << "Default constructor: " << p << endl;
}

inline void demoParameterizedConstructor() {
  vector<string> dates = {"2020", "2021"};
  Planet p("Earth", 5.972e24, 6371e3, dates);
  cout << "Parameterized constructor: " << p << endl;
}

inline void demoCopyConstructor() {
  vector<string> dates = {"2020"};
  Planet p1("Mars", 6.417e23, 3390e3, dates);
  Planet p2(p1);
  cout << "Copy constructor: " << p2 << endl;
}

inline void demoConversionConstructor() {
  Planet p("Jupiter");
  cout << "Conversion constructor: " << p << endl;
}

inline void demoGravityCalculation() {
  vector<string> dates = {"2023"};
  Planet p("Venus", 4.867e24, 6052e3, dates);
  cout << "Gravity on " << p.getName() << ": " << p.calculateGravity()
       << " m/s^2" << endl;
}

inline vector<Planet> getSortedPlanetsByMass() {
  vector<Planet> sortedPlanets = planets;
  sort(sortedPlanets.begin(), sortedPlanets.end(),
       [](const Planet &a, const Planet &b) {
         return a.getMass() < b.getMass();
       });
  return sortedPlanets;
}

inline void demoPrefixIncrement() {
  int index = 0;
  Enter(cin, index, "enter planet index: ")();
  Planet p = planets[index - 1];
  cout << "Original: " << p << endl;
  cout << "Prefix increment: " << ++p << endl;
  planets.push_back(p);
}

inline void demoPostfixIncrement() {
  int index = 0;
  Enter(cin, index, "enter planet index: ")();
  Planet p = planets[index - 1];
  cout << "Original: " << p << endl;
  cout << "Postfix increment: " << p++ << endl;
  cout << "After increment" << p << endl;
  planets.push_back(p);
}

// idk
inline void demoAddition() {
  int i1, i2 = 0;
  Enter(cin, i1, "Enter first planet: ")();
  Enter(cin, i2, "Enter second planet: ")();

  Planet p1(planets[i1 - 1]);
  Planet p2(planets[i2 - 1]);
  Planet p3 = p1 + p2;
  planets.push_back(p3);

  cout << "Original " << p1 << endl;
  cout << "Original " << p2 << endl;
  cout << "Addition: " << p3 << endl;
}

// TODO: realisation on added planets
#endif // VDOVKIN_LR3_4_METHODS_H
