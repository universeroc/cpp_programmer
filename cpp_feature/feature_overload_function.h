#ifndef __FEATURE_OVERLOAD_FUNCTION_H__
#define __FEATURE_OVERLOAD_FUNCTION_H__

class FeatureOverloadFunction {
public:
  void F(int i) {}
  void F(int& i) {}
  void F(const int& i) {}
};

#endif
