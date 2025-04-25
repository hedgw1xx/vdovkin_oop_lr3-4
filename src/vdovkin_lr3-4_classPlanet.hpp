#include "vdovkin_def.hpp"

#ifndef VDOVKIN_LR3_4_CLASSPLANET_H
#define VDOVKIN_LR3_4_CLASSPLANET_H

class Planet {
private:
  string name;
  double mass;
  double radius;
  vector<string> researchDates;
  static const double G;

public:
  // Constructors
  Planet();
  Planet(const string &name, double mass, double radius,
         const vector<string> &dates);
  Planet(const Planet &other);
  explicit Planet(const string &name);
  Planet(const string &name, double mass, double radius);

  // Get methods
  string getName() const { return name; }
  double getMass() const { return mass; }
  double getRadius() const { return radius; }
  vector<string> getResearchDates() const { return researchDates; }

  // Set methods
  void setName(const string &name) { this->name = name; }
  void setMass(double mass) { this->mass = mass; }
  void setRadius(double radius) { this->radius = radius; }
  void setResearchDates(const vector<string> &dates) { researchDates = dates; }

  // Method to calculate gravitational acceleration
  double calculateGravity() const;

  // Overloaded operators
  bool operator==(const Planet &other) const;
  bool operator<(const Planet &other) const;
  bool operator>(const Planet &other) const;
  Planet operator+(const Planet &other) const;
  Planet &operator++();
  Planet operator++(int);
  Planet &operator=(const Planet &other);
  friend ostream &operator<<(ostream &os, const Planet &planet);
  friend istream &operator>>(istream &is, Planet &planet);

  // Destructor
  ~Planet() {}
};

#endif // VDOVKIN_LR3_4_CLASSPLANET_H
