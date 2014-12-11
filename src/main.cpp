#include "String.hpp"
#include <iostream>
#include <assert.h>

using namespace std;
int main(){
  String s;
  assert(s.size() == 0);
  
  s.push_back('a');
  s.push_back('c');
  assert(s.size() == 2);
  
  s.insert('b', 1);
  cout << '[';
  for(auto it = s.begin(); it != s.end(); ++it){
    cout << it << ", ";
  }
  cout << ']';
  cout << endl;
  assert(s.size() == 3);
  assert(s == "abc");
  
  char lastc = s.pop_back();
  cout << lastc << ' ' << s << endl;
  assert(lastc == 'c');
  assert(s == "ab");
  
  String ss = "xD";
  cout << ss << ' ' << ss[1] << endl;
  assert(ss.size() == 2);

  ss += "b";
  ss += 'g';
  cout << ss << endl;
  assert(ss.size() == 4);
  assert(ss == "xDbg");
  
  s.swap(ss);
  cout << s << " " << ss << endl;
  assert(s == "xDbg");
  assert(s.size() == 4);
  assert(ss == "an");
  assert(ss.size() == 2);
  
  String sss;
  cin >> sss;
  cout << sss;
  return 0;
}
