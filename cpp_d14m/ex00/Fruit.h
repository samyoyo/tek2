#ifndef FRUIT_H_
#define FRUIT_H_

#include <iostream>

class Fruit {
public:
  Fruit(std::string const &name, int vitamins);
  virtual ~Fruit();
  virtual std::string const &getName() const;
  int getVitamins() const;
  Fruit&  operator=(Fruit const& fruit);
  bool  operator==(Fruit const &fruit);
protected:
  std::string _name;
  int _vitamins;
};

#endif
