#include "MyString.h"

void MyString::str_cpy(char*& dest, const char* source){
	size_t length = strlen(source);
	dest = new char[16 + length];

	for (size_t j = 0; j < length; j++)
		dest[j] = source[j];
	dest[length] = '\0';
}
void MyString::str_sub(char*& dest, char* substr, size_t subpos, size_t sublen){
	dest = new char[sublen + 1];
	size_t k = subpos;
	size_t i = 0;
	while (i<sublen){
		dest[i] = substr[k];
		k++;
		i++;
	}
	dest[sublen] = '\0';
}


/*
*	Iterator
*/
MyIterator MyString::begin(){
	return MyIterator(this->strData);
}
const MyIterator MyString::begin() const{
	return MyIterator(this->strData);
}

MyIterator MyString::end(){
	return MyIterator(this->strData + this->sizeOfstr);
}
const MyIterator MyString::end() const{
	return MyIterator(this->strData + this->sizeOfstr);
}



reverse_MyIterator MyString::rbegin(){
	return reverse_MyIterator(this->strData + (this->sizeOfstr - 1));
}
const reverse_MyIterator MyString::rbegin() const{
	return reverse_MyIterator(this->strData + (this->sizeOfstr - 1));
}

reverse_MyIterator MyString::rend(){

	return reverse_MyIterator(this->strData - 1);
}
const reverse_MyIterator MyString::rend() const{
	return reverse_MyIterator(this->strData - 1);

}

const_MyIterator MyString::cbegin() const {
	return const_MyIterator(this->strData);
}
const_MyIterator MyString::cend() const {
	return const_MyIterator(this->strData + this->sizeOfstr);
}



const_reverse_MyIterator MyString::crbegin() const{
	return const_reverse_MyIterator(this->strData + (this->sizeOfstr - 1));
}

const_reverse_MyIterator MyString::crend() const{
	return const_reverse_MyIterator(this->strData - 1);
}

/*
*	Initialization
*/
MyString::MyString()
{
	this->sizeOfstr = 0;
	this->cap = 0;
	this->strData = new char[1];
	this->strData[0] = '\0';
}


MyString::MyString(const char* str)
{
	if (str != NULL)
	{
		this->sizeOfstr = strlen(str);
		this->cap = strlen(str) + 16;
		str_cpy(this->strData, str);
	}
	else
	{
		this->cap = 0;
		this->sizeOfstr = 0;
		strData = new char[0];
	}
}


MyString::MyString(size_t size)
{
	if (size >= 0)
	{
		this->sizeOfstr = size;
		this->cap = size + 16;
		this->strData = new char[this->cap];
	}
	else
	{
		this->cap = 0;
		this->sizeOfstr = 0;
		strData = new char[0];
	}
}


MyString::MyString(const MyString& str, size_t pos, size_t len){
	MyString subedStr = str;
	*this = MyString();
	*this = subedStr.substr(pos, len);
}


MyString::MyString(const MyString& s)
{
	this->sizeOfstr = strlen(s.strData);
	this->cap = this->sizeOfstr + 16;
	str_cpy(this->strData, s.strData);
}





MyString& MyString::operator = (const MyString& s){
	this->clear();

	this->sizeOfstr = strlen(s.strData);
	this->cap = this->sizeOfstr + 16;
	str_cpy(this->strData, s.strData);

	return *this;
}

MyString& MyString::operator = (const char* str){
	this->clear();

	this->sizeOfstr = strlen(str);
	this->cap = this->sizeOfstr + 16;
	str_cpy(this->strData, str);
	return *this;
}

MyString& MyString::operator = (char c){
	this->clear();

	this->sizeOfstr = 1;
	this->cap = this->sizeOfstr + 16;
	this->strData = new char[this->cap];
	this->strData[0] = c;
	this->strData[1] = '\0';
	return *this;
}


MyString::MyString(const char* str, size_t n){
	delete[]this->strData;
	this->strData = NULL;
	this->sizeOfstr = 0;

	this->sizeOfstr = n;
	this->cap = this->sizeOfstr + 16;
	str_cpy(this->strData, str);
}

MyString::MyString(size_t n, char c){
	this->sizeOfstr = n;
	this->cap = this->sizeOfstr + 16;
	this->strData = new char[this->cap];
	for (size_t i = 0; i < this->sizeOfstr; i++)
		this->strData[i] = c;

	this->strData[this->sizeOfstr] = '\0';
}

//template <class InputIterator>
//MyString::MyString(InputIterator first, InputIterator last){
//	size_t j;
//	char tmp[100];
//	for (auto i = first; i != last; i++){
//	tmp[j] = *i;
//	}
//}

MyString::~MyString()
{
	delete[] this->strData;
}

void MyString::set_data(const char* str){
	this->sizeOfstr = strlen(str);
	this->cap = this->sizeOfstr + 16;
	str_cpy(this->strData, str);
}

char* MyString::data(){
	return this->strData;
}


/*
*	Non - member function overloads
*/
MyString operator+ (const MyString& strA, const MyString& strB){
	return MyString(strA) += strB;
}


MyString operator+ (const MyString& strA, const char* str){
	return MyString(strA) += str;
}


MyString operator+  (const MyString& s, const char c){
	MyString reStr;
	reStr.sizeOfstr = strlen(s.strData) + 1;
	reStr.cap = reStr.sizeOfstr + 16;
	reStr.strData = new char[reStr.cap];

	size_t i = 0;
	while (s.strData[i] != '\0'){
		reStr.strData[i] = s.strData[i];
		i++;
	}
	reStr.strData[i] = c;
	reStr.strData[i + 1] = '\0';
	return reStr;
}

ostream& operator<< (ostream& os, const MyString& s){
	if (s.strData == NULL || s.sizeOfstr == 0){
		cout << "";
	}
	else{
		size_t j = 0;
		if (strlen(s.strData) > 0)
		{
			while (s.strData[j] != '\0'){
				os << s.strData[j];
				j++;
			}
		}
		else os << "";
	}

	return os;
}


istream& operator>> (istream& is, MyString& s)
{
	char* strInput = new char[1000];
	is >> strInput;
	s = strInput;
	size_t len = strlen(strInput);
	s.strData[len] = '\0';

	delete[] strInput;
	return is;
}


istream& getline(istream& is, MyString& str){
	char* strInput = new char[1000];
	is >> strInput;
	str = strInput;
	size_t len = strlen(strInput);
	str.strData[len] = '\0';

	delete[] strInput;
	return is;
}


/*
*	Capacity
*/
size_t MyString::size()const {
	return this->sizeOfstr;
}


size_t MyString::length() const{
	return this->sizeOfstr;
}


size_t MyString::max_size() const{
	return this->maxSize;
}


void MyString::resize(size_t n){
	if (n > 0){
		char *tmpStr = NULL;
		str_cpy(tmpStr, this->strData);
		size_t tmpSize = strlen(tmpStr);

		if (n > this->sizeOfstr){
			this->sizeOfstr = n;
			//this->cap = this->sizeOfstr + 16;
			this->strData = new char[this->sizeOfstr + 16];

			for (size_t j = 0; j < tmpSize; j++){
				this->strData[j] = tmpStr[j];
			}
			this->strData[tmpSize] = '\0';
		}
		else{
			this->sizeOfstr = n;
			this->strData = new char[this->sizeOfstr+1];
			size_t i = 0;

			while (i < n){
				this->strData[i] = tmpStr[i];
				i++;
			}
			this->strData[i] = '\0';
		}
		delete[]tmpStr;
	}
	else
		return;

}


void MyString::resize(size_t n, const char c){
	if (n > 0){
		char *tmpStr = NULL;
		str_cpy(tmpStr, this->strData);
		size_t tmpSize = strlen(tmpStr);

		if (n > this->sizeOfstr){
			this->sizeOfstr = n;
			this->cap = this->sizeOfstr + 16;
			this->strData = new char[this->sizeOfstr + 16];
			for (size_t j = 0; j < tmpSize; j++){
				this->strData[j] = tmpStr[j];
			}
			size_t num = 0;
			size_t k = tmpSize;
			while (num < n - tmpSize){
				this->strData[k] = c;
				k++;
				num++;
			}
			this->strData[this->sizeOfstr] = '\0';
		}
		else{
			this->sizeOfstr = n;
			this->cap = this->sizeOfstr + 16;
			this->strData = new char[this->sizeOfstr + 16];
			size_t i = 0;

			while (i < n){
				this->strData[i] = tmpStr[i];
				i++;
			}
			this->strData[i] = '\0';
		}
		delete[]tmpStr;
	}
	else
		return;
}


size_t MyString::capacity() const{
	return this->cap;
}
void MyString::reserve(size_t n){
	if (n > this->cap){
		char* str = NULL;
		str_cpy(str, this->strData);
		*this = MyString();
		this->cap += (n + 16);
		this->strData = new char[this->cap];

		size_t n = strlen(str);
		for (size_t i = 0; i < n; i++)
			this->strData[i] = str[i];
		this->strData[n] = '\0';
		this->sizeOfstr = n;

		delete[] str;
	}
	else{
		return;
	}
}
void MyString::clear(){
	this->sizeOfstr = 0;
	this->cap = 0;
	delete[] this->strData;
	this->strData = NULL;
}

bool MyString::empty() const{
	if (this->strData == NULL && this->sizeOfstr == 0)
		return 1;
	else return 0;
}


void MyString::shrink_to_fit(){
	char *tmpStr = NULL;
	str_cpy(tmpStr, this->strData);
	this->clear();
	this->strData = new char[strlen(tmpStr) + 1];
	this->sizeOfstr = strlen(tmpStr);
	this->cap = this->sizeOfstr+1;

	for (size_t i = 0; i < this->sizeOfstr; i++){
		this->strData[i] = tmpStr[i];
	}
	this->strData[this->sizeOfstr] = '\0';
	delete[] tmpStr;
}


/*
*	Element access:							Done
*/
char& MyString::operator [] (size_t pos){
	return this->strData[pos];
}

const char& MyString::operator[] (size_t pos) const{
	return this->strData[pos];
}

char  MyString::at(size_t pos){
	return this->strData[pos];
}

const char& MyString::at(size_t pos) const{
	return this->strData[pos];
}

char& MyString::back(){
	return this->strData[this->sizeOfstr - 1];
}

const char& MyString::back() const{
	return this->strData[this->sizeOfstr - 1];
}

char& MyString::front(){
	return this->strData[0];
}

const char& MyString::front() const{
	return this->strData[0];
}


/*
*	Modifiers
*/
MyString& MyString::operator += (const char* str){
	char *tmpStr = NULL;
	str_cpy(tmpStr, this->strData);
	this->sizeOfstr += strlen(str);
	this->cap = this->sizeOfstr + 16;
	this->strData = new char[this->cap];

	unsigned i = 0;
	while (tmpStr[i] != '\0'){
		this->strData[i] = tmpStr[i];
		i++;
	}

	unsigned j = i, e = 0;
	while (str[e] != '\0'){
		this->strData[j] = str[e];
		j++;
		e++;
	}
	this->strData[j] = '\0';

	delete[]tmpStr;
	return *this;
}


MyString& MyString::operator += (const MyString& s){
	size_t oriSize = s.sizeOfstr;
	char *tmpStr = NULL;
	str_cpy(tmpStr, this->strData);
	int n = this->sizeOfstr + s.sizeOfstr;
	this->sizeOfstr = n;
	this->cap = this->sizeOfstr + 16;
	this->strData = new char[this->cap];

	size_t i = 0;
	while (tmpStr[i] != '\0'){
		this->strData[i] = tmpStr[i];
		i++;
	}
	size_t j = i, e = 0;
	while (e < oriSize){
		this->strData[j] = s.strData[e];
		j++;
		e++;
	}

	this->strData[j] = '\0';

	delete[]tmpStr;
	return *this;

}


MyString& MyString::operator += (const char c){
	char *tmpStr = NULL;
	str_cpy(tmpStr, this->strData);
	this->sizeOfstr = strlen(tmpStr) + 1;
	this->cap = this->sizeOfstr + 16;
	this->strData = new char[this->cap];

	size_t i = 0;
	while (tmpStr[i] != '\0'){
		this->strData[i] = tmpStr[i];
		i++;
	}
	this->strData[i] = c;
	this->strData[i + 1] = '\0';

	delete[]tmpStr;
	return *this;
}


MyString& MyString::append(const MyString& str){
	*this = *this + str;
	return *this;
}

MyString& MyString::append(const MyString& str, size_t subpos, size_t sublen){
	char *tmpStr = NULL;

	str_sub(tmpStr, str.strData, subpos, sublen);

	*this = *this + tmpStr;

	delete[] tmpStr;
	return *this;
}


MyString& MyString::append(const char* str, size_t n){
	char* tmpStr = NULL;
	tmpStr = new char[n + 1];

	for (size_t i = 0; i < n; i++)
		tmpStr[i] = str[i];

	tmpStr[n] = '\0';
	*this = *this + tmpStr;
	delete[] tmpStr;
	return *this;
}


MyString& MyString::append(const char* str){
	*this += str;
	return *this;
}


MyString& MyString::append(size_t n, char c){
	char* tmpStr = NULL;
	tmpStr = new char[n + 1];

	for (size_t i = 0; i < n; i++)
		tmpStr[i] = c;

	tmpStr[n] = '\0';

	*this = *this + tmpStr;
	delete[] tmpStr;
	return *this;
}

void MyString::push_back(char c){
	*this = *this + c;
}


MyString& MyString::assign(const MyString& str){
	return *this = MyString(str);
}


MyString& MyString::assign(const MyString& substr, size_t subpos, size_t sublen){

	char* tmpStr = NULL;
	str_sub(tmpStr, substr.strData, subpos, sublen);

	*this = MyString(tmpStr);

	delete[] tmpStr;
	return *this;
}


MyString& MyString::assign(const char* str){
	*this = MyString(str);
	return *this;
}


MyString& MyString::assign(const char* str,size_t n){
	char* tmp = NULL, *strCpy = NULL;
	str_cpy(strCpy, str);
	str_sub(tmp, strCpy, 0, n);

	*this = MyString();
	*this = tmp;

	delete[] tmp;
	delete[] strCpy;
	return *this;
}


MyString& MyString::assign(size_t n, char c){
	MyString tmp;
	tmp.append(n, c);
	*this = MyString();
	*this = tmp;
	return *this;
}


MyString& MyString::insert(size_t pos, const MyString& str){
	if (pos < 0 || pos > this->sizeOfstr) return *this;
	size_t   size_insertStr = strlen(str.strData);
	char *tempStr = NULL;

	str_cpy(tempStr, this->strData);

	*this = MyString();
	this->sizeOfstr = size_insertStr + strlen(tempStr);
	this->cap = this->sizeOfstr + 16;
	this->strData = new char[this->cap];

	size_t i = 0, k = 0;
	size_t sizeStr = strlen(str.strData);
	while (i < this->sizeOfstr){
		if (i == pos){
			for (size_t j = 0; j < sizeStr; j++){
				this->strData[i] = str.strData[j];
				i++;
			}
			continue;
		}
		else{
			this->strData[i] = tempStr[k];
			k++;
		}
		i++;
	}
	this->strData[i] = '\0';

	delete[] tempStr;
	return *this;
}


MyString& MyString::erase(size_t pos, size_t len){
	if (pos < 0 || pos > this->sizeOfstr - 1){
		cout << "out of range!" << endl;
		return *this;
	}

	char* erasedStr = NULL;
	str_cpy(erasedStr, this->strData);
	size_t i = pos, marker = 0;
	for (size_t j = ((pos - 1) + len) + 1; j < this->sizeOfstr; j++){
		erasedStr[i] = erasedStr[j];
		i++;
		marker++;
	}
	erasedStr[pos + marker] = '\0';
	*this = MyString();
	this->sizeOfstr = strlen(erasedStr);
	this->cap = this->sizeOfstr + 16;
	this->strData = new char[this->cap];
	*this = erasedStr;
	delete[]erasedStr;
	return *this;
}

MyString& MyString::replace(size_t pos, size_t len, const MyString& str){

	if (pos < 0 || pos > this->sizeOfstr) return *this;

	size_t  size_replaceStr = strlen(str.strData);
	char *tempStr = NULL;
	str_cpy(tempStr, this->strData);

	*this = MyString();
	this->sizeOfstr = size_replaceStr + strlen(tempStr);
	this->cap = this->sizeOfstr + 16;
	this->strData = new char[this->cap];

	size_t i = 0, k = 0;
	while (i < this->sizeOfstr){
		if (i == pos){
			for (size_t j = 0; j < size_replaceStr; j++){
				this->strData[i] = str.strData[j];
				i++;
			}
			k = pos + len;
			continue;
		}
		else{
			this->strData[i] = tempStr[k];
			k++;
		}
		i++;
	}
	this->strData[i] = '\0';

	delete[] tempStr;
	return *this;
}
MyString& MyString::replace(size_t pos, size_t len, const char* str){

	if (pos < 0 || pos > this->sizeOfstr) return *this;

	size_t  size_replaceStr = strlen(str);
	char *tempStr = NULL;
	str_cpy(tempStr, this->strData);

	*this = MyString();
	this->sizeOfstr = size_replaceStr + strlen(tempStr);
	this->cap = this->sizeOfstr + 16;
	this->strData = new char[this->cap];

	size_t i = 0, k = 0;
	while (i < this->sizeOfstr){
		if (i == pos){
			for (size_t j = 0; j < size_replaceStr; j++){
				this->strData[i] = str[j];
				i++;
			}
			k = pos + len;
			continue;
		}
		else{
			this->strData[i] = tempStr[k];
			k++;
		}
		i++;
	}
	this->strData[i] = '\0';

	delete[] tempStr;
	return *this;
}

MyString& MyString::replace(size_t pos, size_t len, const MyString& str,
	size_t subpos, size_t sublen){

	if ((pos < 0 || pos >= this->sizeOfstr) || (subpos < 0 || subpos >= str.sizeOfstr))
		return *this;

	char* subedStr = NULL;
	str_sub(subedStr, str.strData, subpos, sublen);
	this->replace(pos, len, subedStr);

	delete[]subedStr;
	return *this;
}

MyString& MyString::replace(size_t pos, size_t len, const char* str, size_t n){
	if (pos < 0 || pos > this->sizeOfstr) return *this;
	char *strCpy = NULL, *mids = NULL;
	str_cpy(strCpy, str);
	str_sub(mids, strCpy, 0, n);

	MyString lhs, rhs;
	rhs = this->substr(pos + len, pos + len);
	lhs = this->substr(0, pos);

	*this = MyString();
	*this = lhs + mids;
	*this += rhs;


	delete[] strCpy;
	delete[] mids;
	return *this;
}
MyString& MyString::replace(size_t pos, size_t len, size_t n, char c){
	if (pos < 0 || pos > this->sizeOfstr){
		return *this;
	}
	MyString tmpStr;
	tmpStr = *this;
	this->clear();
	size_t new_size = (tmpStr.sizeOfstr - len) + n;
	this->sizeOfstr = new_size;
	this->cap = this->sizeOfstr + 16;
	this->strData = new char[new_size + 16];

	if (len > n || len == n){
		size_t i = 0, k = 0;
		while (i < tmpStr.sizeOfstr){
			if (i == pos){
				for (size_t j = 0; j < n; j++){
					this->strData[i] = c;
					i++;
				}
				k = pos + len;
				continue;
			}
			else{
				this->strData[i] = tmpStr[k];
				k++;
			}
			i++;
		}
		this->strData[i] = '\0';
	}
	else{
		char* subedStr = NULL;
		size_t subpos = pos + len;
		str_sub(subedStr, tmpStr.strData, subpos, tmpStr.sizeOfstr - subpos);

		size_t i = 0, k = 0;
		while (i < pos + len){
			if (i == pos){
				for (size_t j = 0; j < n; j++){
					this->strData[i] = c;
					i++;
				}
				k = pos + len;
				continue;
			}
			else{
				this->strData[i] = tmpStr[k];
				k++;
			}
			i++;
		}
		this->strData[i] = '\0';
		*this += subedStr;
		delete[]subedStr;
	}
	return *this;
}
void MyString::swap(MyString& s){
	MyString tmpStr;

	tmpStr = *this;
	this->clear();
	*this = s;
	s.clear();
	s = tmpStr;
}
void MyString::swap(MyString& x, MyString& y){
	MyString tmp;
	tmp = x;
	x = y;
	y = tmp;
}

void MyString::pop_back(){
	char *tmpStr = NULL;
	str_cpy(tmpStr, this->strData);
	this->clear();
	this->sizeOfstr = strlen(tmpStr) - 1;
	this->cap = this->sizeOfstr + 16;
	this->strData = new char[this->cap];

	for (size_t i = 0; i < this->sizeOfstr; i++)
		this->strData[i] = tmpStr[i];

	this->strData[this->sizeOfstr] = '\0';
	delete[] tmpStr;
}


/*
*	String operations
*/
char* MyString::c_str()const{
	char  *cstr = this->strData;
	return cstr;
}
size_t MyString::copy(char* str, size_t len, size_t pos){
	if (pos < 0 || pos >= this->sizeOfstr)
		return -1;

	size_t k = 0;
	for (size_t i = pos; i < (pos)+len; i++){
		str[k] = this->strData[i];
		k++;
	}
	return len;
}


size_t MyString::find(const MyString& str){
	size_t pos = -1;
	for (size_t i = 0; i < this->sizeOfstr; i++){
		if (str.strData[0] == this->strData[i]){
			pos = i;
			break;
		}
	}
	if (pos < 0) return -1;
	size_t k = pos, frag = 0;
	for (size_t j = 0; j < strlen(str.strData); j++){
		if (str.strData[j] == this->strData[k])
			frag = 1;
		else{
			return str.sizeOfstr;
		}
		k++;
	}
	return pos;
}


size_t MyString::rfind(const MyString& str){
	size_t pos = find(str);
	return pos;
}

size_t MyString::find_first_of(const MyString& str, size_t pos){
	if (pos < 0 || pos > this->sizeOfstr){
		cout << "out of range" << endl;
		return -1;
	}
	size_t i = pos;
	for (size_t i = pos; i < this->sizeOfstr; i++){
		for (size_t j = 0; j < strlen(str.strData); j++){
			if (this->strData[i] == str.strData[j])
				return i;
		}
	}
	return -1;
}
size_t MyString::find_first_of(const char* str, size_t pos){
	if (pos < 0 || pos > this->sizeOfstr){
		cout << "out of range" << endl;
		return -1;
	}
	size_t i = pos;
	for (size_t i = pos; i < this->sizeOfstr; i++){
		for (size_t j = 0; j < strlen(str); j++){
			if (this->strData[i] == str[j])
				return i;
		}
	}
	return -1;
}

size_t MyString::find_last_of(const MyString& str){
	for (size_t i = this->sizeOfstr - 1; i >= 0; i--){
		for (size_t j = 0; j < strlen(str.strData); j++){
			if (this->strData[i] == str.strData[j])
				return i;
		}
	}
	return -1;
}
size_t MyString::find_last_of(const MyString& str, size_t pos){
	if (pos < 0 || pos > this->sizeOfstr) return -1;
	for (size_t i = pos; i >= 0; i--){
		for (size_t j = 0; j < strlen(str.strData); j++){
			if (this->strData[i] == str.strData[j])
				return i;
		}
	}
	return -1;
}


size_t MyString::find_first_not_of(const MyString& str, size_t pos){
	size_t found;
	if (pos < 0 || pos > this->sizeOfstr) return -1;

	for (size_t i = pos; i < this->sizeOfstr; i++){
		found = 1;
		for (size_t j = 0; j < strlen(str.strData); j++){
			if (this->strData[i] == str.strData[j]){
				found = 0;
				break;
			}
		}
		if (found == 1) return i;

	}
	return -1;
}


size_t MyString::find_last_not_of(const MyString& str, size_t pos){
	size_t found;
	if (pos < 0 || pos > this->sizeOfstr) return -1;

	for (size_t i = pos; i >= 0; i--){
		found = 1;
		for (size_t j = strlen(str.strData); j >= 0; j--){
			if (this->strData[i] == str.strData[j]){
				found = 0;
				break;
			}
		}
		if (found == 1) return i;

	}
	return -1;
}


MyString MyString::substr(size_t pos, size_t len)const{
	MyString subedStr;
	subedStr.cap = len + 16;
	subedStr.sizeOfstr = len;
	subedStr.strData = new char[len + 16];

	if (pos == this->sizeOfstr - 1){
		char c = this->strData[this->sizeOfstr - 1];
		subedStr[0] = c;
		subedStr[1] = '\0';
	}
	if (pos > this->sizeOfstr - 1 || pos < 0){
		cout << "out of range" << endl;
		subedStr[0] = '\0';
		return subedStr;
	}

	size_t i = 0, k = pos;
	while (i < len){
		subedStr.strData[i] = this->strData[k];
		i++;
		k++;
	}
	subedStr.strData[len] = '\0';
	return subedStr;
}


int MyString::compare(const MyString &s) const{
	if (this->sizeOfstr > s.sizeOfstr)
		return 1;
	else if (this->sizeOfstr < s.sizeOfstr)
		return -1;
	else{
		for (size_t i = 0; i < this->sizeOfstr; i++){
			if (this->strData[i] != s.strData[i]) return 1;
		}
		return 0;
	}
}


int MyString::compare(size_t pos, size_t len, const MyString& str)const {
	MyString cpyStr = *this;
	MyString subedStr = cpyStr.substr(pos, len);
	if (str == subedStr) return 0;
	else{
		if (str.sizeOfstr < subedStr.sizeOfstr || str < subedStr) return -1;
		else return 1;
	}
}


int	MyString::compare(size_t pos, size_t len, const MyString& str,
	size_t subpos, size_t sublen)const{
	MyString strSrc;
	MyString strCmp;
	strSrc.assign(*this, pos, len);
	strCmp.assign(str, subpos, sublen);
	if (strSrc == strCmp) return 0;
	else{
		if (strCmp.sizeOfstr < strSrc.sizeOfstr || strCmp < strSrc) return -1;
		else return 1;
	}
}


int	MyString::compare(const char* s) {
	if (this->sizeOfstr > strlen(s))
		return 1;
	else if (this->sizeOfstr < strlen(s))
		return -1;
	else{
		for (size_t i = 0; i < this->sizeOfstr; i++){
			if (this->strData[i] != s[i]) return 1;
		}
		return 0;
	}
}
int MyString::compare(size_t pos, size_t len, char* s) {
	char *subedStr = NULL;
	str_sub(subedStr, s, pos, len);
	if (this->strData == subedStr) return 0;
	else{
		if (strlen(subedStr) < this->sizeOfstr || strlen(subedStr) < this->sizeOfstr) return -1;
		else return 1;
	}
	return 1;
}
/*
*	relational operators
*/

bool operator== (const MyString& lhs, const MyString& rhs){
	if (lhs.sizeOfstr != rhs.sizeOfstr) return false;

	size_t cap = lhs.sizeOfstr;
	size_t   n = 0;

	while ((n < cap) && (lhs.strData[n] == rhs.strData[n])) n++;
	return (n == cap);
}


bool operator== (const MyString& lhs, char rhs){
	return (lhs == MyString(rhs));
}


bool operator== (char lhs, const MyString& rhs){
	return (MyString(lhs) == rhs);
}


bool operator!= (const MyString& lhs, const MyString& rhs){
	return !(lhs == rhs);
}


bool operator!= (const MyString& lhs, char rhs){
	return !(lhs == rhs);
}


bool operator!= (char lhs, const MyString& rhs){
	return !(lhs == rhs);
}


bool operator> (const MyString& lhs, const MyString& rhs){
	size_t sumLhs = 0;
	size_t sumRhs = 0;
	for (size_t i = 0; i < lhs.sizeOfstr; i++){
		sumLhs += (size_t)lhs[i];
	}

	for (size_t i = 0; i < rhs.sizeOfstr; i++){
		sumRhs += (size_t)rhs[i];
	}
	return sumLhs > sumRhs;
}

bool operator>(const char* lhs, const MyString& rhs){
	return (MyString(lhs) > rhs);
}

bool operator> (const MyString& lhs, const char* rhs){
	return (lhs > MyString(rhs));
}




bool operator< (const MyString& lhs, const MyString& rhs){
	return !(lhs == rhs) && !(lhs > rhs);
}

bool operator< (const MyString& lhs, const char* rhs){
	return !(lhs == rhs) && !(lhs > rhs);
}

bool operator< (const char* lhs, const MyString& rhs){
	return !(lhs == rhs) && !(lhs > rhs);
}


bool operator<= (const MyString& lhs, const MyString& rhs){
	return !(lhs > rhs);
}

bool operator<= (const MyString& lhs, const char* rhs){
	return !(lhs > rhs);
}

bool operator<= (const char* lhs, const MyString& rhs){
	return !(lhs > rhs);
}


bool operator>= (const MyString& lhs, const MyString& rhs){
	return (lhs == rhs) || (lhs > rhs);
}

bool operator>= (const MyString& lhs, const char* rhs){
	return (lhs == rhs) || (lhs > rhs);
}

bool operator>= (const char* lhs, const MyString& rhs){
	return (lhs == rhs) || (lhs > rhs);
}


