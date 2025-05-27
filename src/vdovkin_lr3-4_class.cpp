#include "vdovkin_lr3-4_classPlanet.hpp"
#include <iostream>

const double Planet::G = 6.67430e-11;

Planet::Planet() : name("Unknown"), mass(0.0), radius(0.0) {}

Planet::Planet(const string &name, double mass, double radius,
               const vector<string> &dates)
    : name(name), mass(mass), radius(radius), researchDates(dates) {}

Planet::Planet(const Planet &other)
    : name(other.name), mass(other.mass), radius(other.radius),
      researchDates(other.researchDates) {}

Planet::Planet(const string &name) : name(name), mass(0.0), radius(0.0) {}

Planet::Planet(const string &name, double mass, double radius)
    : Planet(name, mass, radius, {}) {}

double Planet::calculateGravity() const {
  if (radius == 0)
    return 0.0;
  return G * mass / (radius * radius);
}

bool Planet::operator==(const Planet &other) const {
  return mass == other.mass;
}

bool Planet::operator<(const Planet &other) const { return mass < other.mass; }

bool Planet::operator>(const Planet &other) const { return mass > other.mass; }

Planet Planet::operator+(const Planet &other) const {
  string newName = name + " + " + other.name;
  double newMass = mass + other.mass;
  double newRadius = (radius + other.radius) / 2.0;
  vector<string> newDates = researchDates;
  newDates.insert(newDates.end(), other.researchDates.begin(),
                  other.researchDates.end());
  return Planet(newName, newMass, newRadius, newDates);
}

Planet &Planet::operator++() {
  mass += 4.8e24;
  return *this;
}

Planet Planet::operator++(int) {
  radius += 10e5;
  return *this;
}

Planet &Planet::operator=(const Planet &other) {
  if (this != &other) {
    name = other.name;
    mass = other.mass;
    radius = other.radius;
    researchDates = other.researchDates;
  }
  return *this;
}

ostream &operator<<(ostream &os, const Planet &planet) {
  os << "Planet: " << planet.name << ", Mass: " << planet.mass
     << ", Radius: " << planet.radius << ", Research Dates: ";
  for (const auto &date : planet.researchDates) {
    os << date << " ";
  }
  return os;
}

istream &operator>>(istream &is, Planet &planet) {
  Enter(is, planet.name, "Enter name: ")();
  Enter(is, planet.mass, "Enter mass: ")();
  Enter(is, planet.radius, "Enter radius: ")();
  int numDates;
  Enter(is, numDates, "Enter number of research dates: ")();
  planet.researchDates.clear();
  for (int i = 0; i < numDates; ++i) {
    string date;
    Enter(is, date, "Enter date " + to_string(i + 1) + ": ")();
    planet.researchDates.push_back(date);
  }
  return is;
}
