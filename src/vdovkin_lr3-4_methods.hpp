#ifndef VDOVKIN_LR3_4_METHODS_H
#define VDOVKIN_LR3_4_METHODS_H

#include "vdovkin_lr3-4_classPlanet.hpp"

inline vector<Planet> planets;

inline bool isValidMass(double mass) { return mass > 0; }

inline bool isValidRadius(double radius) { return radius > 0; }

inline void inputPlanet(Planet &planet) {
  string name;
  double mass, radius;
  vector<string> dates;

  cout << "Enter name: ";
  cin >> name;
  planet.setName(name);

  do {
    cout << "Enter mass (>0): ";
    cin >> mass;
  } while (!isValidMass(mass));
  planet.setMass(mass);

  do {
    cout << "Enter radius (>0): ";
    cin >> radius;
  } while (!isValidRadius(radius));
  planet.setRadius(radius);

  int numDates;
  cout << "Enter number of research dates: ";
  cin >> numDates;
  for (int i = 0; i < numDates; ++i) {
    string date;
    cout << "Enter date " << i + 1 << ": ";
    cin >> date;
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

#endif // VDOVKIN_LR3_4_METHODS_H
