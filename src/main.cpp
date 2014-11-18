#include "String.hpp"
#include <iostream>

int main(){
  String s = new String("lol");
  for(int i = s.iterator().start(); i < s.iterator().end(); i++){
    cout << i;
  }
  return 0;
}
