#include <iostream>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <sstream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <stdio.h>
#include <utility>
#include <iomanip>
#include <set>
#include <map>
#include <fstream>
#include <limits.h>

#define                size(A)					    ((int)A.size())
#define                 All(A)					 A.begin(), A.end()
#define		  For(i, v, Limit)		for (int i = v; i < Limit; i++)
#define      DFor(i, Limit, v)     for (int i = Limit; i >= v; i--)
#define                    MAX									 31

typedef          long long int   						   LongInt;
typedef unsigned long long int 						      ULongInt;
typedef            long double							LongDouble;

using namespace std;

template <class _Ty>
class Queue: public queue <_Ty> {
	public:
		_Ty Dequeue() {
			_Ty tmp = queue <_Ty>::front();
			queue <_Ty>::pop();
			return tmp;
		}
};

vector <int> divisors;
int number, lowest, cube[3];

bool prime(int n) 
{
	if (n <= 1) 
		return false;
	for (int i = 2; i*i <= n; i++)
		if (!(n % i))
			return false;
	return true;
}

void BF(int index = 0) 
{
	if (index == 3) 
	{
		if (cube[0] * cube[1] * cube[2] != number) return;
		lowest = min(lowest, 2 * ((cube[0] * cube[1]) + (cube[0] * cube[2]) + (cube[1] * cube[2])));
	}
	else for (int i = 0; i < size(divisors); i++) 
	{
		cube[index] = divisors[i];
		BF(index + 1);
	}
}

int main() 
{
	int cases;
	scanf("%d", &cases);
	while (cases--) 
	{
		lowest = INT_MAX;
		scanf("%d", &number);
		if (prime(number))
			divisors.push_back(1);
		else for (int i = 1; i <= number / 2; i++)
			if (!(number % i)) divisors.push_back(i);
		divisors.push_back(number);
		BF();
		printf("%d\n", lowest);
		divisors.clear();
	}
	return 0;
}