#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{	
	//An input stream is declared.
	ifstream is;

	//The user is prompted for a name of an input file.
	string filename;
	cout << "Enter the name of file which will serve as input: ";
	cin >> filename;

	//The program opens the file for reading and assigns it
	//to the input stream is. It also checks whether opening
	//operation was successful.
	is.open(filename.c_str());
	bool reading_failed = is.fail();
	if(reading_failed)
		cout << "Input failed!!!" << endl; 

	//The execution is stopped if the reading fails.
	bool available_for_reading=!reading_failed;
	assert(available_for_reading);

	//An output stream os is declared and a file output.txt
	//is assigned to it.
	ofstream os ("output.txt");

	int num=0; //counts the number of flights
	string line; //serves for reading successive lines of input


	clock_t start=clock();

	while(getline(is,line))
	{	
	    if(line.substr(0,3)=="ACM")
		{	os << line << endl;
				num++;
		}
	}

	clock_t stop=clock();

	cout << "It took ";
	cout << 1000*(stop-start)/CLOCKS_PER_SEC;
	cout << " milliseconds to read file ";
	cout << filename << "." << endl;

	cout << "File " << filename;
	cout << " contained measurements of ";
	cout << num << " flights." << endl;

	return 0;
}
