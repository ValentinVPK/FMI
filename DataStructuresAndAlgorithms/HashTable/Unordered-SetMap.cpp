#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


int main()
{

	unordered_set <int> us;

	us.insert(6);
	us.insert(3);
	us.insert(15);
	us.insert(2);
	us.insert(65);
	us.insert(6);
	us.insert(6);



	if (!us.count(4))
		cout << 4 << " not found" << endl;
	else
		cout << "Found " << 4 << endl << endl;


	for (auto itr = us.begin(); itr != us.end(); itr++)
		cout << (*itr) << endl;

	us.erase(3);


	unordered_map <int, char> um;
	um[2] = 'f';
	um[2] = 'f';
	um[2] = 'c';
	um[5] = 'f';
	um[3] = 'b';
	um[4] = 'a';
	um[1] = 's';


	for (auto x : um)
		cout << x.first << " " << x.second << endl;
}
