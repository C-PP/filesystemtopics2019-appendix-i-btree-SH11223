//#pragma warning(disable:4996)
//tstbtree.cc
//#include "btnode.h"

#include <iostream>
#include <cstring>
#include "btree.h"
using namespace std;
/*

*/
const char * keys = "CSDTAMPIBWN GURKEHOLJYQZFXV";

const int BTreeSize = 3;

int main(int argc, char * argv) {
	int result, i;
	BTree <char> bt(BTreeSize);
	cout << "input data = " << keys << endl;
	result = bt.Create("btree.dat", ios::in | ios::out);
	if (!result) { 
		cout << "Please delete testbt.dat" << endl; 
		system("pause");
		return 0; 
	}
	for (i = 0; i<26; i++)
	{
		cout << "Inserting " << keys[i] << endl;
		result = bt.Insert(keys[i], i);
		bt.Print(cout);
	}
//	bt.Search('A'); //after searching the value, print word file 22page !!!
	bt.InOrdertraversal(cout);

	for (i = 0; i < 26; i++) {
		cout << "Remove Key" << keys[i] << endl;
		bt.Remove(keys[i]);
		bt.Print(cout);
	}
	system("pause");
	return 1;
}