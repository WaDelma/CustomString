#ifndef STRING_HPP
#define STRING_HPP
#include <iostream>
class String {
	typedef unsigned int index;
private:
	char *s;
	index length;
	index maxl;
	void ensure(index);
	index next2power(index);
public:
	String();
	explicit String(index);
	String(const char*);
	~String();
	String& operator+= (char);
	String& operator+= (const String&); 
	String& operator= (const String&);
	bool operator== (const String&) const;
	char& operator[] (index) const;
	bool check() const;
	void push_back(char);
	void push_back(const String&);
	char pop_back();
	void insert(char, index);
	char& erase(index);
	void swap(String&);
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
	
	friend std::istream& operator>>(std::istream &st, String &s){
		char c;
		while(st.get(c)){
			if(c == ' ' || c == '\n' || c == '\r') break;
			s += c;
		}
		return st;
	}
};
#endif
