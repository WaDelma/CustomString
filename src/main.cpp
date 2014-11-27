#include "String.hpp"
#include <iostream>
#include <iterator>

using namespace std;
int main(){
  String s;
  s.push_back('a');
  s.push_back('b');
  s.push_back('c');
  for(iterator it = s.start(); it < s.end(); ++it){
    cout << it << '\n';
  }
  return 0;
}
