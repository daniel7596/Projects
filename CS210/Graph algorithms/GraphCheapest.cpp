#include <iostream>
#include <fstream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

#include <cstdlib>

struct Vertex
{
  string name;

  bool isVisited;
  list<pair<int, double> > adjacentVertices;
  int prev;
  double cost;
};

struct struct1
{
  int vertex;
  int prev;
  double cost;

  bool operator<(const struct1& a) const
  {
    return cost > a.cost;
  }
};

pair<stack<int>, double> getShortestRoute(int iStart, int iEnd, vector<Vertex>& database)
{
  pair<stack<int>, double> result;
  list<pair<int, double> >::iterator it; // to iterate over adjacentVertices

  for (int z = 0; z < database.size(); z++)
  {
    database[z].isVisited = false;
    database[z].prev = -1;
    database[z].cost = 0;
  }

  priority_queue<struct1> Cont;
  struct1 s;
  s.vertex = iStart;
  s.prev = -1;
  s.cost = 0;
  Cont.push(s);
  while (!Cont.empty())
  {
    struct1 y = Cont.top();
    Cont.pop();

    if (database[y.vertex].isVisited == true) continue;
    database[y.vertex].isVisited = true;
    database[y.vertex].cost = y.cost;
    database[y.vertex].prev = y.prev;
    if (y.vertex == iEnd) break;
    for (it = database[y.vertex].adjacentVertices.begin(); it != database[y.vertex].adjacentVertices.end(); it++)
    {
      if (database[(*it).first].isVisited == false)
      {
        struct1 neighbor;
        neighbor.cost = (*it).second + y.cost;
        neighbor.prev = y.vertex;
        neighbor.vertex = (*it).first;
        Cont.push(neighbor);
      }
    }
  }

  result.second = database[iEnd].cost;
  for (int vertex = iEnd; vertex >= 0; vertex = database[vertex].prev)
    result.first.push(vertex);
  return result;
}

int main()
{
  ifstream fin;
  fin.open("cities.txt");
  if (!fin.good()) throw "I/O error";

  // process the input file
  vector<Vertex> database;
  while (fin.good()) // EOF loop
  {
    string fromCity, toCity, cost;

    // read one edge
    getline(fin, fromCity);
    getline(fin, toCity);
    getline(fin, cost);
    fin.ignore(1000, 10); // skip the separator

    // add vertices for new cities included in the edge
    int iToVertex = -1, iFromVertex = -1, i;
    for (i = 0; i < database.size(); i++) // seek "destination" city
      if (database[i].name == fromCity)
        break;

    if (i == database.size()) // not in database yet
    {
      // store the vertex if it is new
      Vertex fromVertex;
      fromVertex.name = fromCity;
      database.push_back(fromVertex);
    }
    iFromVertex = i;

    for (i = 0; i < database.size(); i++) // seek "from" city
      if (database[i].name == toCity)
        break;
    if (i == database.size()) // not in vector yet
    {
      // store the vertex if it is new
      Vertex toVertex;
      toVertex.name = toCity;
      database.push_back(toVertex);
    }
    iToVertex = i;

    // store bi-directional edges
    double edgeCost = atof(cost.c_str());
    database[iFromVertex].adjacentVertices.push_back(pair<int, double>(iToVertex, edgeCost));
    database[iToVertex].adjacentVertices.push_back(pair<int, double>(iFromVertex, edgeCost));
  }
  fin.close();
  cout << "Input file processed\n\n";

  while (true)
  {
    string fromCity, toCity;
    cout << "\nEnter the source city [blank to exit]: ";
    getline(cin, fromCity);
    if (fromCity.length() == 0) break;

    // find the from city
    int iFrom;
    for (iFrom = 0; iFrom < database.size(); iFrom++)
      if (database[iFrom].name == fromCity)
        break;

    cout << "Enter the destination city [blank to exit]: ";
    getline(cin, toCity);
    if (toCity.length() == 0) break;

    // find the destination city
    int iTo;
    for (iTo = 0; iTo < database.size(); iTo++)
      if (database[iTo].name == toCity)
        break;

    pair<stack<int>, double> result = getShortestRoute(iFrom, iTo, database);
    cout << "Total miles: " << result.second;
    while (!result.first.empty()) { cout << '-' << database[result.first.top()].name; result.first.pop(); }
    cout << endl;
  }
}
