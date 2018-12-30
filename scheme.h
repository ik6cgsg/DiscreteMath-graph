#ifndef _SCHEME_H__
#define _SCHEME_H__
#pragma once

#include <climits>
#include <fstream>
#include <string>
#include <vector>

const int INF = INT_MAX;

using svec = std::vector<std::string>;

class scheme
{
private:
  int **weights;
  int num;
  int *len, *pred;

  bool empty(std::string & line, const char *delim);
  svec split(std::string & line, const char *delim);
  void relax(int s, int v, int u);
public:
  scheme(std::ifstream & file);

  void buildTable(int central);
  void print();

  ~scheme();
}; // end of 'scheme' class

#endif // _SCHEME_H__
