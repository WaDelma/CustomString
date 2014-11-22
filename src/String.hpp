#ifndef String_HPP
#define String_HPP
class String {
private:
  char *s;
  int length;
  int maxl;

public:
  String();
  String(int length);
  String(char *String);
  ~String();
  String & operator= (const String & other);
  char operator[] (int index);
  bool check();
  void push_back(char c);
  char pop_back();
  void insert(char c, int index);
  void erase();

  class iterator{
  public:
    char *cur;
    iterator& operator++(){
      ++cur;
      return *this;
    }
  };
  class const_iterator{

  };
//  struct iteratorBase;
//  struct constIteratorBase {
//    typedef const char& reference;
//    typedef const char* pointer;
//    typedef const String string;
//  };
//  struct iteratorBase {
//    typedef char& reference;
//    typedef char* pointer;
//    typedef String string;
//  };

//  template<typename base>
//  class commonIterator : public base {
//  protected:
//    typedef typename base::reference reference;
//    typedef typename base::pointer pointer;
//    typedef typename base::string string;
//    typedef typename base::constIterator constIterator;
//    typedef typename base::iterator iterator;
//    string* s;
//    int pos;
//  public:
//    typedef commonIterator<base> self;
//    friend constIterator;

//    commonIterator(string* s, int pos) : s(s), pos(pos) { }
//    commonIterator(const iterator& copy) : s(copy.s), pos(copy.pos) { }

//    reference operator*() const { return s->at(pos); }
//    pointer operator->() const { return &s->at(pos); }

//    self& operator++(){ ++pos; return *this; }
//    self& operator--(){ --pos; return *this; }
//    self& operator+=(int amt){ pos += amt; return *this; }
//    bool operator==(const self &x) const { return (x.s == s) && (x.pos == pos); }
//    int operator-(const self &x) const { assert(x.s == s); return pos - x.pos; }
//    bool is_valid() const { return pos < s->size(); }

//    self operator++(int) {
//        self tmp = *this;
//        ++*this;
//        return tmp;
//    }
//    self operator--(int){
//        self tmp = *this;
//        --*this;
//        return tmp;
//    }
//    self& operator-=(int amt) {
//        return *this += -amt;
//    }
//    bool operator!=(const self& x) const {
//        return !(*this == x);
//    }
//    bool operator>(const self& x) const {
//        return *this - x > 0;
//    }
//    bool operator>=(const self& x) const {
//        return *this - x >= 0;
//    }
//    bool operator<(const self& x) const {
//        return *this - x < 0;
//    }
//    bool operator<=(const self& x) const {
//        return *this - x <= 0;
//    }
//    self operator+(int amt) const {
//        self tmp = *this;
//        return tmp += amt;
//    }
//    self operator-(int amt) const {
//        self tmp = *this;
//        return tmp -= amt;
//    }
//    reference operator[](int index) const {
//        self tmp = *this;
//        tmp += index;
//        return *tmp;
//    }
//  };

//  typedef commonIterator<constIteratorBase> const_iterator;
//  typedef commonIterator<iteratorBase> iterator;
};
#endif
