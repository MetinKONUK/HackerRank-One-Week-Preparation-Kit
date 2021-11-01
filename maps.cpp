#include <iostream>
#include<map>
using namespace std;
int main()
{
	//STRUCTURE OF A MAP
	map<char, int> mp = {
		{'T', 7},
		{'S', 8},
		{'a', 4}
	};
	//ACCESSING MEMBER OF A MAP
	//cout << mp['S'] << endl;
	/*
		mp['b'] will return 0 (default value of integer)
	*/

	//INSERT ELEMENT TO MAP
	mp['u'] = 9;
	mp.insert(pair<char, int>('j', 5));
	//cout << mp['j'] << endl;

	pair<char, int> p1('z', 10);
	mp.insert(p1);
	//cout << p1.first << " " << p1.second << endl;

	//ERASE ELEMENT
	mp.erase('z');

	//CLEAR ALL MAP
	//mp.clear();

	//CHECK IF MAP IS EMPTY
	mp.empty(); // 1 if empyt 0 if not

	//SIZE OF THE MAP
	//cout << mp.size() << endl;

	//INITIALIZE AN ELEMENT
	if (mp.find('a') == mp.end()) { //letter does not exist
		mp['a'] = 0;
	}
	mp['a'] += 10;

	//ITERATE THROUGH THE MAP (NO ORDER)
	for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
		cout << itr->first << "," << itr->second << endl;
	}
	return 0;
}
