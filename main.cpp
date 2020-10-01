#include <iostream>
#include <memory>
#include <fstream>
#include "intData.h"
#include "node.h"

#include <unistd.h>

using namespace std;
using namespace HeterogeneousTree::DataTypes;
using namespace HeterogeneousTree;

#define _add_child(parentPtr, Type, value) parentPtr->addChild(make_shared<Node>(make_shared<Type>(value)))
#define _create_head(Type, value) make_shared<Node>(make_shared<Type>(value))
#define _create_empty_head() make_shared<Node>()

void TestSimple() {
	auto head = _create_head(IntData, 8);
	auto bar = _add_child(head, StringData, "bar");
	auto int2015 = _add_child(bar, IntData, 2015);
	auto nine = _add_child(int2015, IntData, 9);
	auto float2015 = _add_child(bar, DoubleData, 2.015);
	auto str2015 = _add_child(bar, StringData, "2015");
	auto baz = _add_child(head, StringData, "baz");
	auto foo = _add_child(baz, StringData, "foo");
	auto complicatedFloat = _add_child(foo, DoubleData, 6.28318);
	auto hello = _add_child(complicatedFloat, StringData, "hello");
	auto hello2 = _add_child(complicatedFloat, StringData, "hello");

	ofstream ofs("bina", ios_base::binary);
	head->serialize(ofs);
	ofs.close();

	ifstream ifs("bina", ios_base::binary);
	NodePtr head_des = make_shared<Node>();
	head_des->deserialize(ifs);
	head_des->print(cout);
	ifs.close();
}


int main(int argc, char ** argv) {
	int rez=0;

	auto head = _create_empty_head();
	bool file_deserialized = false;

//	opterr=0;
	while ( (rez = getopt(argc, argv, "i:o:")) != -1){
		if (static_cast<char>(rez) == 'i') {
			file_deserialized = true;
			ifstream in(optarg, ios_base::binary);
			head->deserialize(in);
			head->print(cout);
		}
		else if (static_cast<char>(rez) == 'o') {
			if (file_deserialized) {
				ofstream out(optarg, ios_base::binary);
				head->serialize(out);
			}
			else {
				cout << "no tree to serialize\n";
				break;
			}
		}
	}

	return 0;
}
