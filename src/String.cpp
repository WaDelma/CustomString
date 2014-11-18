#include "String.hpp"
#include <assert.h>

String::String(){
  s = 0;
  length = 0;
  maxl = 0;
}

String::String(int length){
  s = 0;
  this->length = length;
  maxl = length;
}

String::String(char *string){
  s = string;
  this->length = 0;
  while(s[length++]);
  maxl = length;
}

String & String::operator=(const String &other){
  
}

char String::operator[](int index){
  assert(index >= 0);
  assert(index < length);
  if(s) return s[index];
  return 0;
}

void String::push_back(char c){
  if(++length >= maxl){
    char *n = new char[length];
    char *t = n;
    while(*n++ = *s++);
    s = t;
    maxl = length;
  }
  s[length - 1] = c;
}

char String::pop_back(){
  assert(length > 0);
  if(s) return s[--length];
  return 0;
}
 
void String::insert(char c, int index){
   assert(index >= 0);
   assert(index < length);
   if(++length >= maxl){
    char *n = new char[length];
    char *t = n;
	int i = 0;
    do{
	  if(i == index) ++n;
	} while(*n++ = *s++);
    s = t;
    maxl = length;
  }
  s[index] = c;
}

String::~String(){
  if(s) delete s;
}
