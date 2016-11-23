#include <string.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <stdlib.h>
using namespace std;

class Csv {
	// read and parse comma-separated values
	// sample input: "LU",86.25,"11/4/1998","2:19PM",+4.0625
public:
	Csv(istream& fin = cin, string sep = ",") :
		fin(fin), fieldsep(sep) {}
		
	int getline(string& str);
	string getfield (int n);
	int getnfield() const { return nfield; }
	int getlinedirect(string& str);
	string operator[] (int index);
private:
	istream& fin; // input file pointer
	string line; // input line
	vector<string> field; // field strings
	int nfield; // number of fields
	string fieldsep; // separator characters 
	int split();
	int endofline(char);
	int advplain(const string& s, string& fld, int i);
	int advquoted(const string& s, string& fld, int i);
};

// getline: get one line, grow as needed
int Csv::getline(string& str)
{
	char c;
	for (line = ""; fin.get(c) && !endofline(c); )
		line += c;
	split();
	str = line;
	return !fin.eof();
} 

int Csv::getlinedirect(string& str)
{
	line = str;
	split();
}
// split: split line into fields
int Csv::split()
{
	string fld;
	int i, j;
	nfield = 0;
	if (line.length() == 0)
		return 0;
	i = 0;
	do {
		if (i < line.length() && line[i] == '"')
			j = advquoted(line, fld, ++i); // skip quote
		else
			j = advplain(line, fld, i);
		if (nfield >= field.size())
			field.push_back(fld);
		else
			field[nfield] = fld;
		nfield++;
		i = j + 1;
	} while (j < line.length());
	return nfield;
} 

// advquoted: quoted field; return index of next separator
int Csv::advquoted(const string& s, string& fld, int i)
{
	int j;
	fld = "";
	for (j = i; j < s.length(); j++) {
		if (s[j] == '"' && s[++j] != '"') {
			int k = s.find_first_of(fieldsep, j);
			if (k > s.length()) // no separator found
				k = s.length();
			for (k -= j; k-- > 0; )
				fld += s[j++];
			break;
		}
		fld += s[j];
	}
	return j;
} 

// advplain: unquoted field; return index of next separator
int Csv::advplain(const string& s, string& fld, int i)
{
	int j;
	j = s.find_first_of(fieldsep, i); // look for separator
	if (j > s.length()) // none found
		j = s.length();
	fld = string(s, i, j-i);
	return j;
} 

// getfield: return n-th field
string Csv::getfield (int n)
{
	if (n < 0 || n >= nfield)
		return "";
	else
		return field[n];
}

// endofline: check for and consume \r, \n, \r\n, or EOF
int Csv::endofline(char c)
{
	int eol;
	eol = (c=='\r' || c=='\n');
	if (c == '\r') {
		fin.get(c);
		if (!fin.eof() && c != '\n')
			fin.putback(c); // read too far
	}
	return eol;
} 

string Csv::operator[](int index)
{
	return Csv::getfield(index);
}

// Csvtest main: test Csv class
int main(int argc, char**argv)
{
	clock_t start;
	clock_t end;
	clock_t runtime = 0;
	string line;
	//Csv csv;
	ifstream instream;
	instream.open(argv[1]);	
//	if(argc > 1)
//	{
	//	inStream.open(argv[1]);
	Csv csv;// = new Csv();//instream);
	//csv.setistream(argv[1]);// = new Csv(inStream);
		//csv.setistream(fin);// = new Csv(fin);
//	}
int numLines = 0;	
	while(instream.eof() != 1)
	{	
		string input = "";
		char tempin = instream.get();
		while(instream.good() && (tempin != '\n' && tempin !='\r') && tempin != '\0')
		{
			input+=tempin;
			tempin = instream.get();
		}
		tempin+='\0';
		cout << "line = ‘" << input  <<"’\n";
		start=clock();
		csv.getlinedirect(input);
		end = clock();
		runtime += (end-start);
		numLines++;
		for (int i = 0; i < csv.getnfield(); i++)
                        cout << "field[" << i << "] = `"
                        << csv[i] << "'\n";     //csv.getfield(i) << "'\n"; Replaced with postscript
	}
	long runtimems = runtime/1000.0;
	 cout << "Execution Time: " <<  (runtimems) << " ms"<< endl;
	cout << "Lines: " << numLines << endl;
/*
	while (csv.getline(line) != 0) {
		cout << "line = ‘" << line <<"’\n";
		start=clock();
		for (int i = 0; i < csv.getnfield(); i++)
			cout << "field[" << i << "] = `"
			<< csv[i] << "'\n";	//csv.getfield(i) << "'\n"; Replaced with postscript
		end = clock();
		cout << "Execution Time: " + end-start << endl;
}
*/
	return 0;
}
