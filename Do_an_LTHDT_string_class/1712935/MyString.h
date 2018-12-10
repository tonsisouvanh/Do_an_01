#ifndef CUSTOM_STRING_H
#define CUSTOM_STRING_H

#include <iostream>
#include <iterator>
#include <math.h>
using namespace std;
class  const_reverse_MyIterator : public iterator<input_iterator_tag, char>
{
public:
	typedef const char* pointer;
public:
	const char* p;
	pointer ptr;

	const_reverse_MyIterator(){
		this->p = NULL;
		this->ptr = NULL;
	}
	const_reverse_MyIterator(const char* x) :p(x) {}
	const_reverse_MyIterator(const const_reverse_MyIterator& mit) : p(mit.p) {}
	const_reverse_MyIterator& operator++() {
		--p;
		return *this;
	}
	const_reverse_MyIterator operator++(int) {
		const_reverse_MyIterator tmp(*this);
		operator--();
		return tmp;
	}
	const_reverse_MyIterator& operator--() {
		++p; return *this;
	}
	const_reverse_MyIterator operator--(int) {
		const_reverse_MyIterator tmp(*this);
		operator++();
		return tmp;
	}
	bool operator==(const const_reverse_MyIterator& rhs) const {
		return p == rhs.p;
	}
	bool operator!=(const const_reverse_MyIterator& rhs) const {
		return p != rhs.p;
	}
	const char& operator*() {
		return *p;
	}
	const pointer operator->() {
		return ptr;
	}
};

class const_MyIterator : public iterator<input_iterator_tag, char>
{
public:
	typedef const char* pointer;
public:
	const char* p;
	pointer ptr;

	const_MyIterator(const char* x) :p(x) {}

	const_MyIterator(const const_MyIterator& mit) : p(mit.p) {}

	const_MyIterator& operator++() {
		++p; return *this;
	}

	const_MyIterator operator++(int) {
		const_MyIterator tmp(*this);
		operator++();
		return tmp;
	}

	const_MyIterator& operator--() {
		--p;
		return *this;
	}

	const_MyIterator operator--(int) {
		const_MyIterator tmp(*this);
		operator--();
		return tmp;
	}

	bool operator==(const const_MyIterator& rhs) const { return p == rhs.p; }

	bool operator!=(const const_MyIterator& rhs) const { return p != rhs.p; }

	const char&	  operator* () { return *p; }

	const pointer operator->() { return ptr; }

};


class MyIterator : public iterator<input_iterator_tag, char>
{
public:
	typedef char* pointer;
public:
	char* p;
	pointer ptr;

	MyIterator(){
		this->p = NULL;
		this->ptr = NULL;
	}
	MyIterator(char* x) :p(x) {}
	MyIterator(const MyIterator& mit) : p(mit.p) {}
	MyIterator& operator++() {
		++p;
		return *this;
	}
	MyIterator operator+(int n) {
		MyIterator tmp(*this);
		tmp.p += n;
		return tmp;
	}
	MyIterator operator++(int) {
		MyIterator tmp(*this);
		operator++();
		return tmp;
	}
	MyIterator& operator--() {
		--p; return *this;
	}
	MyIterator operator--(int) {
		MyIterator tmp(*this);
		operator--();
		return tmp;
	}
	bool operator==(const MyIterator& rhs) const {
		return p == rhs.p;
	}
	bool operator!=(const MyIterator& rhs) const {
		return p != rhs.p;
	}
	char& operator*() {
		return *p;
	}
	pointer operator->() {
		return ptr;
	}
};


class  reverse_MyIterator : public iterator<input_iterator_tag, char>
{
public:
	typedef char* pointer;
public:
	char* p;
	pointer ptr;

	reverse_MyIterator(){
		this->p = NULL;
		this->ptr = NULL;
	}
	reverse_MyIterator(char* x) :p(x) {}
	reverse_MyIterator(const reverse_MyIterator& mit) : p(mit.p) {}
	reverse_MyIterator& operator++() {
		--p;
		return *this;
	}
	reverse_MyIterator operator++(int) {
		reverse_MyIterator tmp(*this);
		operator--();
		return tmp;
	}
	reverse_MyIterator& operator--() {
		++p; return *this;
	}
	reverse_MyIterator operator--(int) {
		reverse_MyIterator tmp(*this);
		operator++();
		return tmp;
	}
	bool operator==(const reverse_MyIterator& rhs) const {
		return p == rhs.p;
	}
	bool operator!=(const reverse_MyIterator& rhs) const {
		return p != rhs.p;
	}
	char& operator*() {
		return *p;
	}
	pointer operator->() {
		return ptr;
	}
};

template <class T> class allocator{

};


class MyString
{
private:
	char*	 strData;
	size_t	 cap;
	size_t   sizeOfstr;
	const size_t maxSize = _Pow_int(2, 32) - 1;
	static const size_t npos = -1;
private:
	void str_sub(char*&, char*, size_t, size_t);
	void str_cpy(char*&, const char*);
public:

	/*
	*	Initialization								1 function left
	*/
	MyString();
	MyString(const char* str);
	MyString(const char* str, size_t n);
	MyString(const MyString& str, size_t pos, size_t len);
	MyString(size_t);
	MyString(const MyString& s);
	MyString(size_t n, char c);

	//template <class InputIterator>
	//MyString(InputIterator first, InputIterator last);

	~MyString();
	MyString& operator = (const MyString& s);
	MyString& operator = (const char* str);
	MyString& operator = (char c);
	void  set_data(const char* str);

	/*
	*	Iterator														//DONE
	*/
	MyIterator begin();
	const MyIterator begin() const;

	MyIterator end();
	const MyIterator end()   const;

	reverse_MyIterator rbegin();
	const reverse_MyIterator rbegin() const;

	reverse_MyIterator rend();
	const reverse_MyIterator rend()   const;

	const_MyIterator cbegin() const;
	const_MyIterator cend() const;

	const_reverse_MyIterator  crbegin() const;
	const_reverse_MyIterator  crend()   const;
	/*
	*	Non-member function overloads											//DONE
	*/
	friend MyString operator+  (const MyString&, const char);
	friend MyString operator+  (const MyString&, const MyString&);
	friend MyString operator+  (const MyString&, const char*);
	void   swap(MyString& str);
	friend ostream& operator<< (ostream& so, const MyString& s);
	friend istream& operator>> (istream& so, MyString& s);
	friend istream& getline(istream& is, MyString& str);

	/*
	*	Capacity																//Done
	*/
	size_t	  size() const;
	size_t    length() const;
	size_t	  max_size() const;
	void	  resize(size_t);
	void	  resize(size_t, const char);
	size_t	  capacity() const;
	void	  reserve(size_t n);
	void	  clear();
	bool	  empty() const;
	void	  shrink_to_fit();

	/*
	*	Element access                          Done
	*/
	char&		operator[] (size_t pos);
	const char& operator[] (size_t pos) const;
	char at(size_t pos);
	const char& at(size_t pos) const;
	char&		back();
	const char& back() const;
	char&	    front();
	const char& front() const;


	/*
	*	Modifiers
	*/
	MyString& operator+= (const MyString&);
	MyString& operator+= (const char* str);
	MyString& operator+= (const char c);

	MyString& append(const MyString& str);
	MyString& append(const MyString& str, size_t subpos, size_t sublen);
	MyString& append(const char* str);
	MyString& append(const char* str, size_t n);
	MyString& append(size_t n, char c);
	/*template			 <class InputIterator>
	MyString& append	 (InputIterator first, InputIterator last);	*/				//no code

	void      push_back(char c);

	MyString& assign(const MyString& str);
	MyString& assign(const MyString& str, size_t subpos, size_t sublen);
	MyString& assign(const char*);
	MyString& assign(const char* s, size_t n);									
	MyString& assign(size_t n, char c);										
	/*template			 <class InputIterator>
	MyString& assign	 (InputIterator first, InputIterator last);*/					//no code

	MyString& insert(size_t pos, const MyString& str);				
	MyString& insert(size_t pos, const MyString& str, size_t subpos, size_t sublen);		//no code
	MyString& insert(size_t pos, const char* s);											//no code
	MyString& insert(size_t pos, const char* s, size_t n);									//no code
	MyString& insert(size_t pos, size_t n, char c);										//no code
	//template			 <class InputIterator>
	//void	  insert	 (iterator p, size_t n, char c);										//no code
	//template			 <class InputIterator>	
	//iterator  insert	 (iterator p, char c);													//no code
	//template			 <class InputIterator>
	//void	  insert	 (iterator p, InputIterator first, InputIterator last);					//no code


	MyString& erase(size_t pos, size_t len);
	//template			 <class InputIterator>
	//iterator  erase		 (iterator p);
	//template			 <class InputIterator>
	//iterator  erase		 (iterator first, iterator last);


	MyString& replace(size_t pos, size_t len, const MyString& str);
	/*	template <class InputIterator>
	MyString& replace	 (iterator i1, iterator i2, const MyString& str);*/
	MyString& replace(size_t pos, size_t len, const MyString& str, size_t subpos, size_t sublen);
	MyString& replace(size_t pos, size_t len, const char* str);
	/*	template <class InputIterator>
	MyString& replace	 (iterator i1, iterator i2, const char* s);*/
	MyString& replace(size_t pos, size_t len, const char* str, size_t n);
	/*template <class InputIterator>
	MyString& replace	 (iterator i1, iterator i2, const char* s, size_t n);*/
	MyString& replace(size_t pos, size_t len, size_t n, char c);
	/*template <class InputIterator>
	MyString& replace	 (iterator i1, iterator i2, size_t n, char c);*/
	/*template <class InputIterator>
	MyString& replace	 (iterator i1, iterator i2,InputIterator first, InputIterator last);*/

	void	  pop_back();																			//checked

	/*
	*	String operations										1left
	*/
	char*    c_str()const;
	char*    data();
	//get allocator                                            no code
	size_t	 copy(char* str, size_t len, size_t pos);			

	size_t   find(const MyString& str, size_t pos);
	size_t   find(const MyString& str);

	size_t   rfind(const MyString& str, size_t pos);
	size_t   rfind(const MyString& str);

	size_t   find_first_of(const MyString& str, size_t);
	size_t	 find_first_of(const char* s, size_t pos);

	size_t   find_last_of(const MyString& str, size_t);
	size_t   find_last_of(const MyString& str);
	size_t   find_first_not_of(const MyString& str, size_t pos);
	size_t   find_last_not_of(const MyString& str, size_t pos);

	MyString substr(size_t pos, size_t len) const;

	int		 compare(const MyString &str) const;
	int		 compare(size_t pos, size_t len, const MyString& str)const;
	int		 compare(size_t pos, size_t len, const MyString& str,
		size_t subpos, size_t sublen)const;
	int		 compare(const char* s);
	int		 compare(size_t pos, size_t len, char* s);
	int		 compare(size_t pos, size_t len, const char* s, size_t n) const;

	/*
	*	relational operators
	*/
	friend bool operator== (const MyString& lhs, const MyString& rhs);
	friend bool operator== (const MyString& lhs, char            rhs);
	friend bool operator== (char            lhs, const MyString& rhs);

	friend bool operator!= (const MyString& lhs, const MyString& rhs);
	friend bool operator!= (const char*     lhs, const MyString& rhs);
	friend bool operator!= (const MyString& lhs, const char*     rhs);

	friend bool operator>  (const MyString& lhs, const MyString& rhs);
	friend bool operator>  (const char*     lhs, const MyString& rhs);
	friend bool operator>  (const MyString& lhs, const char*     rhs);

	friend bool operator<  (const MyString& lhs, const MyString& rhs);
	friend bool operator<  (const char*     lhs, const MyString& rhs);
	friend bool operator<  (const MyString& lhs, const char*     rhs);

	friend bool operator<= (const MyString& lhs, const MyString& rhs);
	friend bool operator<= (const char*     lhs, const MyString& rhs);
	friend bool operator<= (const MyString& lhs, const char*     rhs);

	friend bool operator>= (const MyString&	lhs, const MyString& rhs);
	friend bool operator>= (const char*		lhs, const MyString& rhs);
	friend bool operator>= (const MyString&	lhs, const char*	 rhs);
	void swap(MyString& x, MyString& y);
};

#endif