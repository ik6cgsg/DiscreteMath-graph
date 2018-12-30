#include <cstdio>

#include "scheme.h"

using namespace std;

int main()
{
  ifstream in;
  in.open("tests\\s1.test");
  scheme s(in);
  in.close();

  s.buildTable(5);
  s.print();

  getchar();

  return 0;
}
