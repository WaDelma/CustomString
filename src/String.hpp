#ifndef String_HPP
#define String_HPP
#include <iostream>
class String {
	typedef unsigned int index;
private:
	char *s;
	index length;
	index maxl;
	void ensure(index add);
	index next2power(index i);
public:
	String();
	explicit String(index length);
	String(char *c);
	~String();
	String& operator+= (char c);
	String& operator+= (const String &str); 
	String& operator= (const String &str);
	index operator== (const String &str) const;
	char& operator[] (index i) const;
	bool check() const;
	void push_back(char c);
	void push_back(const String &str);
	char pop_back();
	void insert(char c, index i);
	char& erase(index i);
	void swap(String& str);
	index size() const;
	template<typename ch>
	class string_iterator {
		typedef string_iterator<ch> this_t;
	private:
		ch *buf;
		index pos;
	public:
		string_iterator(ch *b, index p) : buf(b), pos(p) {}
		ch& operator*() {
			return buf[pos];
		}
		ch* operator->() {
			return &(operator*());
		}
		this_t& operator++() {
			++pos;
			return *this;
		}
		this_t operator++(int) {
			this_t tmp(*this);
			++(*this);
			return tmp;
		}
		this_t operator+(index n) {
			this_t tmp(*this);
			tmp.pos += n;
			return tmp;
		}
		this_t& operator+=(index n) {
			pos += n;
			return *this;
		}
		bool operator!=(this_t other){
			if(other.pos != pos){
				return true;
			}
			return other.buf != buf;
		}
		friend std::ostream& operator<<(std::ostream &st, const this_t &it){
			st << it.buf[it.pos];
			return st;
		}
	};
	typedef string_iterator<char> iterator;
	typedef string_iterator<const char> citerator; 
	iterator begin() {
		return iterator(s, 0);
	}
	iterator end() {
		return iterator(s, length);
	}
	citerator begin() const{
		return citerator(s, 0);
	}
	citerator end() const{
		return citerator(s, length);
	}
	friend std::ostream& operator<<(std::ostream &st, const String &s){
		for(auto it = s.begin(); it != s.end(); ++it){
			st << it;
		}
		return st;
	}
	//TODO:
	friend std::istream& operator>>(std::istream &st, String &s){
		char c;
		while(c = st.get() && (c != '\n' || c != '\r')){
			s += c;
		}
		return st;
	}
};
#endif
