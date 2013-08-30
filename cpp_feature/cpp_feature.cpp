// cpp_feature.cpp : Defines the entry point for the console application.
//

#include "tchar.h"
#include <iostream>

//#define TEST_INHERITANCE
#define TEST_STRING_EXAMPLE

#ifdef TEST_OVERLOAD_FUNCTION
#include "feature_overload_function.h"
#endif

#ifdef TEST_INHERITANCE
#include "feature_inheritance.h"
#endif

#ifdef TEST_STRING_EXAMPLE
#include "feature_string_example.h"
#endif

int _tmain(int argc, _TCHAR* argv[])
{

#ifdef TEST_OVERLOAD_FUNCTION
  FeatureOverloadFunction fof;
  int t = 2013;
  fof.F(t);
#endif

#ifdef TEST_INHERITANCE
  Inheritance inheritance;
  std::cout<<"i from Inheritance: "<<inheritance.getII()<<std::endl;

  Inheritance1 inheritance1;
  std::cout<<"i from Inheritance1: "<<inheritance1.getII()<<std::endl;

  std::cout<<"i get from Inheritance1 display fun: "<<std::endl;
  inheritance1.display();
#endif

#ifdef TEST_STRING_EXAMPLE
  String s;
  std::cout<<s.c_str()<<s.length()<<std::endl;
  
  s += "ddd";
  std::cout<<s.c_str()<<s.length()<<std::endl;

  String r = s + s;
  std::cout<<r.c_str()<<r.length()<<std::endl;


#endif

	return 0;
}

