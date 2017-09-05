#ifndef TOY_H_
#define TOY_H_

#include "Picture.h"
#include <iostream>

class Toy
{
public:
  enum ToyType {
    BASIC_TOY,
    ALIEN
   };
  Toy();
  Toy(ToyType type, std::string const &name, std::string const &picture);
  virtual ~Toy();
  int  getType() const;
  std::string const & getName() const;
  std::string const & getAscii() const;
  void setName(std::string const &name);
  void setAscii(std::string const &picture);
protected:
  ToyType _type;
  std::string _name;
  Picture _picture;
};

#endif
