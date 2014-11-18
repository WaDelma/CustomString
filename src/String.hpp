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
  char operator[] (int index);
  bool check();
  void push_back(char c);
  char pop_back();
  void insert(char c, int index);
  void erase();

  class iterator: public std::iterator<random_access_iterator_tag, int, ptrdiff_t,  const int*, const int&> {
  private:
    char *p;
  public:
    iterator & operator*()     { return *this; }
    iterator & operator++()    { ++p; return *this; }
    iterator & operator++(int) { p++; return *this; }
  };
};
#endif
