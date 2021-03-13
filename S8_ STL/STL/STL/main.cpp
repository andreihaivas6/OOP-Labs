
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <utility>

using namespace std;

ifstream f("propozitie.txt");

class Compare
{
public:
	Compare() {}
	bool operator() (pair<int, string> p1, pair <int, string> p2)
	{
		if (p1.first != p2.first)
			return p1.first < p2.first;
		else
			return p1.second > p2.second;
	}
};

int main()
{
	string prop;
	getline(f, prop);
	map <string, int> cuvinte;
	string separator = " .,?!";
	string cuvant;
	for (string::iterator i = prop.begin(); i != prop.end(); i++)
	{
		if (separator.find(*i) != string::npos)
		{
			if (!cuvant.empty())
			{
				cout << cuvant << " ";
				for (string::iterator j = cuvant.begin(); j != cuvant.end(); j++)
					if (isupper(*j))
						*j = tolower(*j);
				cuvinte[cuvant]++;
				cuvant.erase();
			}
		}
		else
			cuvant += *i;
	}

	priority_queue <pair <int, string>, vector <pair <int, string>>, Compare > cuv;
	for (map <string, int>::iterator i = cuvinte.begin(); i != cuvinte.end(); i++)
		cuv.push(pair <int, string>(i->second, i->first));
	cout << "\n";
	while (!cuv.empty())
	{
		cout << cuv.top().second << " " << cuv.top().first << "\n";
		cuv.pop();
	}
	
	return 0;
}


/*const char separator[] = " .,?!";
int vf = -1;
int found = prop.find_first_of(separator);
while (found != string::npos)
{
	string cuvant;
	cuvant = prop.substr(vf + 1, found - vf - 1);
	if (cuvant.size() > 0)
		cout << cuvant << "\n";
	vf = found;
	found = prop.find_first_of(separator, found + 1);
}
cout << prop.substr(vf + 1); */