#include <iomanip>
#include <iostream>
#include <algorithm>

#include "scheme.h"

using namespace std;

bool scheme::empty(string & line, const char *delim)
{
  string del(delim);
  del.append("\"");
  return line.find_first_not_of(del) == string::npos;
} // End of 'scheme::empty' function

svec scheme::split(string & line, const char *delim)
{
  svec res;

  while (!empty(line, delim))
  {
    auto off = line.find_first_not_of(delim);
    line.erase(line.begin(), line.begin() + off);
    off = line.find_first_of(delim);

    if (line[0] == '"')
    {
      line.erase(line.begin(), line.begin() + 1);
      off = line.find_first_of("\"");
    }
    string param = line.substr(0, off);
    line.erase(line.begin(), line.begin() + off);
    res.push_back(param);
  }

  return res;
} // End of 'scheme::split' function

void scheme::relax(int s, int v, int u)
{
  if (len[v] > len[u] + weights[u][v])
    len[v] = len[u] + weights[u][v], pred[v] = u;
} // End of 'scheme::relax' function

scheme::scheme(std::ifstream & file)
{
  if (!file.is_open())
    return;

  int i = 0;

  // vertices correction, adding adjacent list 
  while (!file.eof())
  {
    string line;
    getline(file, line);
    svec params = split(line.append("\n"), " \t\n\r");

    // skip empty lines
    if (params.empty())
      continue;

    // forward initialization
    if (params[0] == "N")
    {
      num = stoi(params[1]);
      weights = new int*[num];
      for (int i = 0; i < num; i++)
        weights[i] = new int[num];

      len = new int[num];
      fill_n(len, num, INF);
      pred = new int[num];
      fill_n(pred, num, 0);

      continue;
    }

    for (int j = 0; j < num; j++)
      weights[i][j] = stoi(params[j]);
    i++;
  }
} // End of constructor

void scheme::buildTable(int central)
{
  int s = central - 1;
  len[s] = 0;                // source
  pred[s] = -1;
  vector<pair<int, int>> v;  // array of pairs [vertex, length to s]

  // init
  for (int i = 0; i < num; i++)
    v.push_back(pair<int, int>(i, len[i]));

  auto cmp = [](const pair<int, int> & a, const pair<int, int> & b){return a.second < b.second;};
  vector<pair<int, int>>::iterator it;

  while (!v.empty())
  {
    sort(v.begin(), v.end(), cmp);    // getting vertex with
    int u = v[0].first;               // least length
    v.erase(v.begin());

    if (len[u] == INF)
      return;
    for (int i = 0; i < num; i++)
      if (weights[i][u] == 0)   // i isnt adjacent
        continue;
      else if ((it = find(v.begin(), v.end(), pair<int, int>(i, len[i]))) != v.end())  // i is inside v
      {
        relax(s, i, u);
        *it = pair<int, int>(i, len[i]);
      }
  }
} // End of 'scheme::buildTable' function

void scheme::print()
{
  cout << "nodes:  |";
  for (int i = 0; i < num; i++)
    cout << setw(3) << i + 1 << " | ";
  cout << endl;
  cout << "---------";
  for (int i = 0; i < num - 1; i++)
    cout << "-------";
  cout << endl;
  cout << "length: |";
  for (int i = 0; i < num; i++)
    cout << setw(3) << len[i] << " | ";
  cout << endl;
  cout << "---------";
  for (int i = 0; i < num - 1; i++)
    cout << "-------";
  cout << endl;
  cout << "ways:   |";
  for (int i = 0; i < num; i++)
    cout << setw(3) << pred[i] + 1 << " | ";
  cout << endl;
} // End of 'scheme::print' function

scheme::~scheme()
{
  for (int i = 0; i < num; i++)
    delete [] weights[i];
  delete [] weights;
  delete [] pred;
  delete [] len;
} // End of destructor

