#include"MyString.h"
void run(){
	unsigned key;
	MyString str1, str2, str3, base, name, family, keystr;

	MyString str("Test string");
	MyString rstr("now step live...");

	MyString buyer("money");
	MyString seller("goods");

	MyString firstlevel, secondlevel, scheme, hostname, url, foo, bar;
	size_t found, length;
	do{
		system("cls");
		cout << "======================== All of MyString function ========================" << endl;
		cout << "	0. Exit" << endl;
		cout << "	1. Member functions" << endl;
		cout << "	2. Iterator" << endl;
		cout << "	3. Capacity" << endl;
		cout << "	4. Element access" << endl;
		cout << "	5. Modifiers" << endl;
		cout << "	6. String operations" << endl;
		cout << "	7. Non-member function overloads" << endl;
		cout << "=========================================================================" << endl;
		cout << "Enter the selection number: ";
		do{
			cin >> key;
			if (key <= 7) break;
			cout << "Invalid selection number! Enter again: ";
		} while (key > 7 || key < 0);
		cin.ignore();
		switch (key){

		case 0: return;

		case 1:
			system("cls");

			cout << "created 3 object of MyString: str1, str2, str3" << endl;
			str1 = "Test string: ";   cout << "str1: " << str1 << endl;
			str2 = 'x';				  cout << "str2 <- 'x' " << str2 << endl;
			str3 = str1 + str2;       cout << "str3 <- str1 + str2" << endl;
			cout << "str3 now is: " << str3 << '\n';

			system("pause");
			break;

		case 2:
			system("cls");

			cout << "[Iterator point at the first element of strong]\n";
			for (auto it = str.begin(); it != str.end(); ++it)
				cout << *it;
			cout << "\n\n";

			cout << "[Iterator with reverse case]" << endl;
			cout << "Before reverse: " << rstr << endl;
			cout << "After reverse: " << endl;
			for (auto rit = rstr.rbegin(); rit != rstr.rend(); ++rit)
				cout << *rit;
			cout << "\n\n";

			system("pause");
			break;

		case 3:
			system("cls");

			cout << "str <- \"Test string\"" << endl;
			cout << "size: " << str.size() << "\n";
			cout << "length: " << str.length() << "\n";
			cout << "capacity: " << str.capacity() << "\n";
			cout << "max_size: " << str.max_size() << "\n\n";

			str.reserve(30);
			cout << "After reserve: " << endl;
			cout << "size: " << str.size() << "\n";
			cout << "length: " << str.length() << "\n";
			cout << "capacity: " << str.capacity() << "\n";
			cout << "max_size: " << str.max_size() << "\n\n";

			str.clear();
			cout << "Cleared string" << endl;
			cout << "str: " << str << endl;
			cout << "size: " << str.size() << "\n";
			cout << "length: " << str.length() << "\n";
			cout << "capacity: " << str.capacity() << "\n\n";

			cout << "Test if string is empty or not?" << endl;
			if (str.empty()) cout << "Yes";
			else
				cout << "No";
			cout << "\n\n";

			cout << "Shrink to fit" << endl;
			str = MyString(100, 'x'); cout << "str: " << str << endl;
			cout << "1. capacity of str: " << str.capacity() << '\n';

			str.resize(10);
			cout << "2. capacity of str: " << str.capacity() << '\n';
			str.shrink_to_fit();
			cout << "After shrink" << endl;
			cout << "3. capacity of str: " << str.capacity() << "\n\n";
			system("pause");
			break;

		case 4:
			system("cls");

			cout << "[operator[] and at]" << endl;
			cout << "Print out string one by one element by calling operator[]: ";
			for (unsigned i = 0; i < str.length(); ++i)
				cout << str[i];
			cout << "\n\n";

			cout << "Print out string one by one element by calling using function at(i):\n";
			for (unsigned i = 0; i < str.length(); ++i)
				cout << str.at(i);
			cout << "\n\n";

			cout << "[back and front]" << endl;
			cout << "Access last character of string" << endl;

			str = "hello world."; cout << "str <- \"hello word.\"" << endl;
			str.back() = '!';
			cout << "Assign last character with '!'" << endl;
			cout << str << "\n\n";

			str.front() = 'Y';
			cout << "Assign first character with 'Y'" << endl;
			cout << str << "\n\n";

			system("pause");
			break;
		case 5:
			system("cls");

			cout << "[operator+=]" << endl;
			name = "John";	  cout << "String object called name: " << name << endl;
			family = "Smith"; cout << "String object called family: " << family << endl;
			name += " K. ";
			name += family;
			name += '\n';
			cout << "Added family to name by calling operator += function" << endl;
			cout << "String object name: " << name << "\n\n";

			cout << "[append]" << endl;
			str = MyString();					   cout << "str: " << str << endl;
			str2 = "Writing ";				   cout << "str2: " << str2 << endl;
			str3 = "print 10 and then 5 more"; cout << "str3: " << str3 << endl;

			str.append(str2); cout << "1. append str2 to str " << endl;
			str.append(str3, 6, 3); cout << "2. append str3 at position 6 with lenght 3 to str" << endl;
			str.append("dots are cool", 5); cout << "3. append \"dots are cool\" with lenght 5 start from first character to str" << endl;
			str.append("here: "); cout << "3. append \"here: \" to str" << endl;
			str.append(10u, '.'); cout << "4. append 10 character of '.' to str" << endl;
			//str.append(str3.begin() + 8, str3.end());					//unfix
			cout << "After append str is: " << str << "\n\n";

			cout << "[push back]" << endl;
			str.push_back('!'); cout << "push '!'  to back of str as appending" << endl;
			cout << "str now is: " << str << "\n\n";

			cout << "[assign]" << endl;
			str = MyString();										cout << "str: " << str << endl;
			base = "The quick brown fox jumps over a lazy dog.";	cout << "base: " << base << endl;
			str.assign(base);										cout << "1. Assign str with base" << endl;
			cout << "str: " << str << '\n';

			str.assign(base, 10, 9);								cout << "2. Assign str with base by starting from position at 10 with lenght of 9" << endl;
			cout << "str: " << str << '\n';

			str.assign("pangrams are cool", 7);						cout << "3. Assign str with \"pangrams are cool\" start from first element of str with lenght of 7" << endl;
			cout << "str: " << str << '\n';

			str.assign("c-string");									cout << "4. Assign str with \"c-string\"" << endl;
			cout << "str: " << str << '\n';

			str.assign(10, '*');									cout << "5. Assign str with 10 character of '*' " << endl;
			cout << "str: " << str << '\n';

			//str.assign<int>(10, 0x2D);
			//std::cout << str << '\n';         // "----------"

			//str.assign(base.begin() + 16, base.end() - 12);
			//std::cout << str << '\n';         // "fox jumps over"
			cout << "\n";

			cout << "[insert]" << endl;
			str = "to be question";									cout << "str: " << str << endl;
			str2 = "the ";											cout << "str2: " << str2 << endl;
			str.insert(6, str2);									cout << "Insert str2 to str" << endl;
			cout << "str: " << str << "\n\n";

			cout << "[erase]" << endl;
			str = "This is an example sentence.";
			cout << "str: " << str << '\n';
			str.erase(10, 8);										cout << "After erased start from position at 10 with lenght of 8" << endl;
			cout << "str: " << str << "\n\n";

			cout << "[replace]" << endl;
			base = "this is a test string.";						cout << "base: " << base << endl;
			str1 = "n example";										cout << "str1: " << str1 << endl;
			str2 = "sample phrase";									cout << "str2: " << str2 << endl;
			str3 = "useful.";										cout << "str3: " << str3 << endl;
			str = base;												cout << "1. str <- base" << endl;
			str.replace(9, 5, str1);								cout << "2. replaced str start from position at 9 with lenght of 5 with str2 -> (this is a test string.) " << endl;
			str.replace(19, 6, str2, 7, 6);							cout << "3. replace str( pos = 19, len = 6 ) with str3( pos = 7, len = 6 ) - > (this is an example phrase.)" << endl;
			str.replace(8, 10, "just a");							cout << "4. replace str( pos = 8, len = 10 ) with \"just a\" - > (this is just a phrase.)" << endl;
			str.replace(8, 6, "a shorty", 7);						cout << "3. replace str( pos = 19, len = 6 ) with \"a shorty\"( pos = 0, len = 7 ) - > (this is a short phrase.)" << endl;
			cout << "replaced str: " << str << "\n\n";
			//str.replace(str.begin(), str.end() - 3, str3);                    // "sample phrase!!!"      (1)
			//str.replace(str.begin(), str.begin() + 6, "replace");             // "replace phrase!!!"     (3)
			//str.replace(str.begin() + 8, str.begin() + 14, "is coolness", 7);    // "replace is cool!!!"    (4)
			//str.replace(str.begin() + 12, str.end() - 4, 4, 'o');                // "replace is cooool!!!"  (5)
			//str.replace(str.begin() + 11, str.end(), str4.begin(), str4.end());// "replace is useful."    (6)

			cout << "[swap]" << endl;
			cout << "string called buyer: " << buyer << endl;
			cout << "string called seller: " << seller << endl;
			seller.swap(buyer);

			cout << " After the swap, buyer has " << buyer;
			cout << " and seller has " << seller << "\n\n";

			cout << "[pop_back]" << endl;
			str = "hello world!";
			cout << "str at first: " << str << endl;
			str.pop_back();
			cout << "Poped back str now is: " << str << "\n\n";

			system("pause");
			break;
		case 6:
			system("cls");

			cout << "[c_str]" << endl;
			cout << str.c_str() << endl << endl;

			cout << "[data]" << endl;
			cout << str.data() << "\n\n";

			//	cout << "[get_allocator]" << endl;

			cout << "[copy]" << endl;
			char buffer[20];
			str = ("Test string...");
			length = str.copy(buffer, 6, 5);
			buffer[length] = '\0';
			cout << "buffer contains: " << buffer << "\n\n";

			cout << "[find]" << endl;
			str = ("There are two needles in this haystack with needles.");
			str2 = ("needle");

			found = str.find(str2);
			if (found)
				std::cout << "first 'needle' found at: " << found << "\n\n";

			cout << "[rfind]" << endl;
			str = ("The sixth sick sheik's sixth sheep's sick.");
			cout << "str at first: " << str << endl;
			keystr = ("sixth");

			found = str.rfind(keystr);
			if (found)
				str.replace(found, keystr.length(), "seventh");
			std::cout << str <<"\n\n";

			cout << "[substr]" << endl;

			str = "We think in generalities, but we live in details.";
			str2 = str.substr(3, 5);
			cout << "assign sub string of str(pos = 3, len = 5) to str2" << endl;
			cout << "str2: " << str2 << endl << endl;

			cout << "[compare]" << endl;
			str1 = ("green apple");
			str2 = ("red apple");

			cout << "compare str1 with str2 " << endl;
			if (str1.compare(str2) != 0)
				std::cout << str1 << " is not " << str2 << '\n';

			if (str1.compare(6, 5, "apple") == 0)
				std::cout << "still, " << str1 << " is an apple\n";

			if (str2.compare(str2.size() - 5, 5, "apple") == 0)
				std::cout << "and " << str2 << " is also an apple\n";

			if (str1.compare(6, 5, str2, 4, 5) == 0)
				std::cout << "therefore, both are apples\n";
			cout << "\n";

			system("pause");
			break;
		case 7:
			system("cls");

			cout << "[operator+]" << endl;
			firstlevel = ("com");
			secondlevel = ("cplusplus");
			scheme = ("http://");
			hostname;
			url;

			hostname = "www." + secondlevel + '.' + firstlevel;
			url = scheme + hostname;

			cout << url << "\n\n";

			cout << "[relational operators]" << endl;
			foo = "alpha";
			bar = "beta";

			if (foo == bar) std::cout << "foo and bar are equal\n";
			if (foo != bar) std::cout << "foo and bar are not equal\n";
			if (foo< bar) std::cout << "foo is less than bar\n";
			if (foo> bar) std::cout << "foo is greater than bar\n";
			if (foo <= bar) std::cout << "foo is less than or equal to bar\n";
			if (foo >= bar) std::cout << "foo is greater than or equal to bar\n";
			cout << endl;

			cout << "[swap]" << endl;
			buyer = ("money");
			seller = ("goods");

			std::cout << "Before the swap, buyer has " << buyer;
			std::cout << " and seller has " << seller << '\n';

			swap(buyer, seller);

			std::cout << " After the swap, buyer has " << buyer;
			std::cout << " and seller has " << seller << '\n';
			cout << endl;

			cout << "[operator>> & operator<<]" << endl;
			name.clear();
			cout << "Please, enter your name: ";
			cin >> name;
			cout << "Hello, " << name << "!\n\n";

			cout << "[getline]" << endl;

			cout << "Please, enter your full name: ";
			getline(cin, name);
			cout << "Hello, " << name << "!\n";

			system("pause");
			break;


		}


	} while (1);
}
void main(){
	run();




	//MyString base = "this is a test string.";
	//MyString str1 = "n example";
	//MyString str2 = "sample phrase";
	//MyString str3 = "useful.";
	//MyString str = base;
	//str.replace(9, 5, str1);
	//str.replace(19, 6, str2, 7, 6);
	//str.replace(8, 10, "just a");				
	//str.replace(8, 6, "a shorty", 7);
	//str.replace(22, 1, 3, '!');
}
