#include <iostream>
using namespace std;

#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include "Queue.h"
#include "DynamicArray.h"

struct customer
{
  int aTime;
  int sTime;
  char ID;
};

// requires cmath and cstdlib
int getRandomNumberOfArrivals(double averageArrivalRate)
{
  int arrivals = 0;
  double probOfnArrivals = exp(-averageArrivalRate);
  for (double randomValue = (double)rand() / RAND_MAX;
    (randomValue -= probOfnArrivals) > 0.0;
    probOfnArrivals *= averageArrivalRate / (double)++arrivals);
  return arrivals;
}

//Simulates the use of queue for a supermarket registers
int main()
{
  srand(time(NULL));
  int CAPACITY;
  float RATE;
  int maxQ;
  int minT;
  int maxT;
  int TIME;

  // read the input values from a text file, one per line, in the order specified above.
  ifstream fin;
    fin.open("simulation.txt");
  if (!fin.good())
    throw "I/O error";

  fin >> CAPACITY >> RATE >> maxQ
    >> minT >> maxT >> TIME;

  cout << "number of servers    : " << CAPACITY << endl;
  cout << "customer arrival rate: " << RATE << " per minute, for " << TIME << " minutes" << endl;
  cout << "maximum queue length : " << maxQ << endl;
  cout << "minimum service time : " << minT << endl;
  cout << "maximum service time : " << maxT << endl;

  // declare and create and assign arrays and queues to be used in the solution
  int n = 0;
  Queue<customer> wQueue;
  DynamicArray<customer> nowServing(CAPACITY);
  DynamicArray<bool> server(CAPACITY);

  for (int i = 0; i <CAPACITY; i++)
    server[i]=false;
  
  // the clock time loop
  for (int time = 0;; time++)
  {
    //handle all services scheduled to complete at this clock time
    for (int i = 0; i <CAPACITY; i++)
    {
      if(server[i]) 
      {
        if(nowServing[i].sTime == time)
          server[i] = false;
      }
    }
     
    // handle new arrivals -- can be turned away if all queues are at maximum length!
    if (time < TIME) 
    {
      //get the #of of arrivals from the Poisson process (a whole number >= 0) 
      int arrival = getRandomNumberOfArrivals(RATE);

      for (int i = 0; i < arrival; i++) //for each new arrival
      {
        if (wQueue.size() < maxQ) // if the wait queue is not full
        {
         
          //create a new customer object with the arrival time equal to the current time
          customer nCustomer;
          nCustomer.aTime = time;
          nCustomer.ID = (char)('A' + (n++ % 26));
          // copy the new customer to the wait queue
          wQueue.push(nCustomer);
        }
      }
    }
    
    // for idle servers, move customer from wait queue and begin service
    for (int i = 0; i < CAPACITY; i++) //for each server
    {
      if (server[i] == false && !wQueue.empty()) //if (server is idle AND the wait queue is not empty)
      {
        //remove top customer from wait queue
        nowServing[i] = wQueue.front();
        wQueue.pop();
        server[i] = true;
    
        //set the customer's service time to the current time + random service interval
        nowServing[i].sTime = time + minT + rand() % (maxT - minT + 1);
      }
    }
    
      //output the current time
      cout << endl << "Time: " << time << endl;
      //output a heading for the visual prepresentation of the servers and the wait queue
      cout << "------------------------------------------" << endl;
      cout << "  Line      Now Serving      Waiting Queue   " << endl;
      cout << "------------------------------------------" << endl;

      for (int i = 0; i < CAPACITY; i++) //for each server
      {
        cout << "   " << i << "             "; //output the server's index number (zero-based)

        //show the ID of the customer being served by that server (blank if idle)
        if (server[i])
          cout << nowServing[i].ID;
        else
          cout << " ";
        cout << "           ";

        //show the IDs of customers in the wait queue
        if (i == 0) //for server 0 only, show the IDs of customers in the wait queue
        {
          Queue<customer> tempQ;
          tempQ = wQueue;
          while (!tempQ.empty())
          {
            cout << tempQ.front().ID << " ";
            tempQ.pop();
          }
          cout << endl;
        }
        else
          cout << endl;
      }

      if (time > TIME && wQueue.empty())
      {
        int ctr = 0;
        for (int i = 0; i < CAPACITY; i++)
        {
          if (!server[i])
            ctr++;
        }
        if(ctr==CAPACITY)
         break;
        else
        {
          cout << "Press ENTER to continue...";
          cin.ignore();
          continue;
        }
      }
      else 
      {
        cout << "Press ENTER to continue...";
        cin.ignore();
        continue;
      }
     
  }
  cout << "Done!" << endl;

  return 0;
}
