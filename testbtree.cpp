//#pragma warning(disable:4996)
//tstbtree.cc
//#include "btnode.h"

#include <iostream>
#include <cstring>
#include "btree.h"
using namespace std;
/*
final tree depth 3 ( root - 1-2-3) but in code depth 2
in result b-tree inserting V == height 2
b-tree always balanced
수요일까지...! 그리고 다음주 목요일이 마지막 클래스 hash!!!


correct insertion!! 
deletion 내맘대로...!!
btree - remove
leaf node / non leaf node
non leaf node- separator, append to root


leaf node?? redistribute merge


	int InOrdertraversal(); !!! sorted result?
			10
		/		\
	5				20
				/		\
			15				30
5-10-15-20-30 순서로
left - itself - right 출력

level ordering?? root - child - child ... - leaf 이용
queue 사용 
root - c1 - c2
root - c1 - c2 (pop) - c11 -c12 -c21 -c22
...



until! 
s
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