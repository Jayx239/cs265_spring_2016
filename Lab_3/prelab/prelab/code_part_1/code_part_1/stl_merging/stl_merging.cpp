#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	typedef vector<int> IntVector;
	typedef IntVector::iterator IntVectorIt;

	size_t n,m;

	cout << "Enter the size of the first array for merging" << endl;
	cin >> n;
	cout << endl;
	cout << "Enter the size of the second array for merging" << endl;
	cin >> m;
	cout << endl;

	//Allocate vectors of sizes n, m and n+m
	//Define iterators and their initial and terminal values
	IntVector Vector1(n);
	IntVectorIt start1,end1,it1;
	start1 = Vector1.begin();
	end1 = Vector1.end();

	IntVector Vector2(m);
	IntVectorIt start2,end2,it2;
	start2 = Vector2.begin();
	end2 = Vector2.end();

	IntVector Vector3(n+m);
	IntVectorIt start3,end3,it3;
	start3 = Vector3.begin();
	end3 = Vector3.end();

	//Enter n consecutive even numbers into vector 1
	int i=0;
	for(it1=start1;it1!=end1;it1++)
	{
		*it1=2*i;
		i++;
	}

	//Output numbers stored in vector 1
	cout << "The content of vector 1" << endl;
	for(it1=start1;it1!=end1;it1++)
		cout << *it1 << " ";
	cout << endl;
	
	//Enter m consecutive even numbers into vector 2
	i=0;
	for(it2=start2;it2!=end2;it2++)
	{
		*it2=2*i+1;
		i++;
	}
	
	//Output numbers stored in vector 2
	cout << "The content of vector 2" << endl;
	for(it2=start2;it2!=end2;it2++)
		cout << *it2 << " ";
	cout << endl;

	//Perform merging of vectors 1 and 2 into vector 3
	merge(start1,end1,start2,end2,start3);

	//Print out the result of merging
	cout << "The content of vector 3 after merging" << endl;
	for(it3=start3;it3!=end3;it3++)
		cout << *it3 << " ";
	cout << endl;

	return 0;
}
