
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
	typedef vector<int> IntVector;
	typedef IntVector::iterator IntVectorIt;
	size_t n = atoi(argv[1]);

	//Seed the random-number generator with current time so that
	//the numbers will be different every time we run.
	srand((unsigned)time(NULL));

	IntVector NumbersVector(n);
	IntVectorIt startv,endv,itv;
	startv = NumbersVector.begin();
	endv = NumbersVector.end();

	//Enter random numbers into NumbersVector
	for(itv=startv;itv!=endv;itv++)
	*itv=rand()%n;

	//Start timing sorting procedure
	clock_t start=clock();
	sort(startv,endv);
	//Stop timing sorting procedure
	clock_t stop=clock();

	//Print out elapsed time in miliseconds
	cout << "STL Sort: \n\tThe elapsed time: ";
	cout << 1000*(stop-start) /CLOCKS_PER_SEC << endl;

	return 0;
}

