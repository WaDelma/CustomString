#include "String.hpp"
#include "assert.hpp"
#include <iostream>
#include <functional>

using namespace std;
void testEmpty(){
	String s;
	assert(s.size() == 0);
}

void testNonEmpty(){
	String s = "a";
	assert(s.size() == 1);
	assert(s == "a");
}

void testPushing(){
	String s;
	s.push_back('a');
	assert(s.size() == 1);
	assert(s == "a");
}

void testPushingOperator(){
	String s;
	s += 'a';
	assert(s.size() == 1);
	assert(s == "a");
	s += "b";
	assert(s.size() == 2);
	assert(s == "ab");
}

void testInsert(){
	String s = "ac";
	s.insert('b', 1);
	assert(s.size() == 3);
	assert(s == "abc");
}

void testPop(){
	String s = "ab";
	char c = s.pop_back();
	assert(s.size() == 1);
	assert(c == 'b');
	assert(s == "a");
}

void testSwap(){
	String s = "a";
	String ss = "b";
	s.swap(ss);
	assert(s == "b");
	assert(ss == "a");
}

void testRead(){
	String sss;
	cin >> sss;
	cout << sss;
}

void test(function<void()> f){
	try{
		f();
	}catch(logic_error e){
		cout << "  " << e.what() << endl;
	}
}

int main(){
	test(testEmpty);
	test(testNonEmpty);
	test(testPushing);
	test(testPushingOperator);
	test(testInsert);
	test(testPop);
	test(testSwap);
	test(testRead);
	return 0;
}
