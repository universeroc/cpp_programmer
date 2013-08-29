// cpp_feature.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#ifdef TEST_OVERLOAD_FUNCTION
#include "feature_overload_function.h"
#endif

int _tmain(int argc, _TCHAR* argv[])
{

#ifdef TEST_OVERLOAD_FUNCTION
  FeatureOverloadFunction fof;
  int t = 2013;
  fof.F(t);
#endif

	return 0;
}

