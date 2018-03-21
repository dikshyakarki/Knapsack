/**
 * a framework for exhaustive-search discrete knapsack 
 * @author Dikshya Karki
 * @version date March 7, 2017
 */
#include <climits>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

typedef unsigned int uint;

/**
 * raise an unsigned integer to an unsigned power
 * C++ has pow, but it accepts and returns floating point values
 * @param base the base to be raised to a power
 * @param exp the exponent to which to reaise the base
 * @return base ^ exp
 */
uint ipow(uint base, uint exp)
{
  if( base == 0 )
    return 1;
  uint result = 1;
  while( exp > 0 )
  {
    if( (exp & 1) == 1 )
      result *= base;
    exp >>= 1;
    base *= base;
  }
  return result;
}

void knapsack(vector<uint> weights, vector<uint> values, uint capacity)
{
  uint totalInputs = values.size();
  uint total = ipow(2, totalInputs);

  uint operations = 0;

  for (uint count = 0 ; count < total ; count++)
  {
    string pairs = "{ ";
    uint sum_weight = 0;
    uint sum_value = 0;

    for (uint i = 0 ; i < totalInputs ; i++)
    {
      if ((( count >> i ) & 1 ) == 1)
      {
        sum_weight = sum_weight + weights.at(i);
        sum_value = sum_value + values.at(i);

        ostringstream oss;
        oss << i;
        pairs = pairs + oss.str() + " ";
        
      }
      operations++;
    }
    pairs = pairs + "} " ;
    operations++;
    if (capacity < sum_weight)
    { 
      cout.setf( ios::left );
      cout.width(15);
      cout << pairs ;
      cout.width(15);
      cout << sum_weight;
      cout.width(15);
      cout << "NF" << endl;
      operations++;
    }
    else
    {
      cout.setf( ios::left );
      cout.width(15);
      cout << pairs ;
      cout.width(15);
      cout << sum_weight;
      cout.width(15);
      cout << sum_value << endl;
      operations++;
    }
  }
  
 cerr << totalInputs << " " << operations;
}

/*
 * standard input must be of the form
 * capacity
 * weight value
 * weight value
 * ...
 */
int main()
{
  uint capacity;
  cin >> capacity;
  
  vector<uint> weights;
  vector<uint> values;

  while( !cin.eof() )
  {
    uint weight;
    uint value;
    cin >> weight >> value;
    if( !cin.eof() )
    {
      weights.push_back( weight );
      values.push_back( value );
    }
  }
  knapsack(weights, values, capacity);
   



      