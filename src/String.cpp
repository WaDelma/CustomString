#include "String.hpp"
#include "assert.hpp"
#include <iostream>

typedef unsigned int index;
String::String(){
	s = new char[8];
	length = 0;
	maxl = 8;
}

String::String(index length){
	length = next2power(length);
	s = new char[length];
	this->length = length;
	maxl = length;
}

String::String(const char *string){
	length = 0;
    while(string[length++]);
    --length;
    maxl = next2power(length);
    s = new char[maxl];
    for(index i = 0; i < length; i++){
		s[i] = string[i];
	}
}

String& String::operator=(const String &other){
	delete s;
	length = other.length;
	maxl = other.maxl;
	s = new char[maxl];
	for(index n = 0; n < other.length; n++){
		s[n] = other.s[n];
	}
	return *this;
}

String& String::operator+= (char c){
	push_back(c);
}

String& String::operator+= (const String &str){
	push_back(str);
}

index String::size() const{
	return length;
}

bool String::operator== (const String &str) const{
	if(size() != str.size()){
		return false;
	}
	int i = 0;
	while(i < size() && s[i] == str.s[i]){
		++i;
	}
	return i == size();
}

char& String::operator[](index i) const{
	assert(i >= 0);
	assert(i < length);
	//if(!s) throw  stupid exception
	return s[i];
}

// Adds character to the end of string
// If there is not enough space left it grows backing array
void String::push_back(char c){
	ensure(1);
	s[length++] = c;
}

void String::push_back(const String &c){
	ensure(c.size());
	for(index i = 0; i < c.size(); i++){
		s[length++] = c[i];
	}
}

char String::pop_back(){
	assert(s);
	assert(length > 0);
	return s[--length];
}
 
void String::insert(char c, index i){
	assert(i >= 0);
	assert(i < length);
	ensure(1);
	++length;
	for(char last = c; i < length; ++i){
		char temp = s[i];
		s[i] = last;
		last = temp;
	}
}

char& String::erase(index i){
	assert(i >= 0);
	assert(i < length);
	char& result = s[i];
	++i;
	for(; i < length; ++i){
		s[i - 1] = s[i];
	}
	--length;
	return result;
}

void String::swap(String& str){
	char *tempS = str.s;
	index tempLength = str.length;
	index tempMaxl = str.maxl;
	str.s = s;
	str.length = length;
	str.maxl = maxl;
	s = tempS;
	length = tempLength;
	maxl = tempMaxl;
}

void String::ensure(index add){
	index newl = length + add;
	if(newl < maxl){
		return;
	}
	newl = next2power(newl);
	char *n = new char[newl];
	for(index i = 0; i < length; ++i){
		n[i] = s[i];
	}
	s = n;
	maxl = newl;
}

index String::next2power(index i){
	i--;
	i |= i >> 1;
	i |= i >> 2;
	i |= i >> 4;
	i |= i >> 8;
	i |= i >> 16;
	i++;
}

String::~String(){
	delete[] s;
}
