#ifndef STRING_H
#define STRING_H
class String {
private:
  char *s;
  int length;
  int maxl;

public:
  String();
  String(int length);
  String(char *string);
  ~String();
  String & operator= (const String & other);
  char operator [](int index);
  bool check();
  void push_back(char c);
  char pop_back();
  void insert(char c, int index);
  void erase();
}
#endif