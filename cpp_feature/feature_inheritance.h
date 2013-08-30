#ifndef __FEATURE_INHERITANCE__
#define __FEATURE_INHERITANCE__

#include <iostream>

class Inheritance {
public:
  Inheritance() { ii_ = 'I'; }
  const char& getII() const { return ii_; }
  char ii_;
};

class Inheritance1 : public Inheritance {
public:
  void display() {
    std::cout<<"As I am inherited class Inheritance, "
               "so I also has class member variable ii_: "
             <<ii_<<std::endl;
  }
};



#endif