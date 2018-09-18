#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>


using namespace std;

//****PROJECT*******
//Author of the Application: Lucia Pinilla 
//Submitted to: Houria Houmel
//Current Date: Wednesday, June 20th 2018
//VERSION: 3 with Vectors

//Struct of Book
struct Book
{
	int isbn;
	string title;
	string author;
	double price;
	int year;
	string subject;
	string language;

	Book()
	{

	}
	Book(int isbn, string title, string author, double price, int year, string subject, string language)
	{
		isbn = isbn;
		title = title;
		author = author;
		price = price;
		year = year;
		subject = subject;
		language = language;

	}
	// create string to concatenate title and author
	string getAuthourAndTitle() 
	{
		return title + ", " + author;
	}

	
};
struct PriceComparator
{
	int operator ()(Book b1, Book b2)
	{
		return b1.price < b2.price;
	}
};
struct Title_AuhorComparator
{
	int operator () (Book b1, Book b2)
	{
		return b1.getAuthourAndTitle() < b1.getAuthourAndTitle();
	}
};

//Prototypes by POINTER AND REFERENCE
void display_menu2(int & flag);
void add_book(vector <Book> * books, int nmb);
void input_searchId(int * isbn_search);
void input_searchTitle(string * title_search);
void search_book(int id, vector<Book> * books);
void search_book(string title, vector<Book> * books);
void display_books(vector<Book> * books);
void load_oldest(vector<Book> * old_books, vector<Book> * books);
void display_old_books(vector<Book> * old_books);


void main()
{

	int numBooks = 0;
	int isbn_search;
	string title_search;
	int flag = 0;

	cout << "Please enter the number of Books that you want to add at the library: ";
	cin >> numBooks;

	 
	vector <Book> * books = new vector <Book>();
	vector <Book> * old_books = new vector <Book>();

	
		do
		{
			display_menu2(flag);
			switch (flag)
			{
			case 1:
				add_book(books, numBooks);
				break;
			case 2:
				input_searchId(&isbn_search);
				search_book(isbn_search, books);
				break;
			case 3:
				input_searchTitle(&title_search);
				search_book(title_search, books);
				break;
			case 4:
				display_books(books);
				break;
			case 5:
				cout << "\n\nHi....We are sorting the array by title and author .... \n";
				sort(books->begin(), books->end(), Title_AuhorComparator());
				display_books(books);
				break;
			case 6:
				cout << "\n\nHi....We are sorting the array by price .... \n";
				sort(books->begin(), books->end(), PriceComparator());
				display_books(books);
				
				break;
			case 7:
				load_oldest(old_books, books);

				break;
			case 8:
				display_old_books(old_books);
				break;
			case 9:
				break;
			}
		} while (flag < 9);
	
	system("pause");
}
//FUNCTIONS IMPLEMENTATION


//for displaying main menu
void display_menu2(int & flag)
{
	system("cls");
	cout << "***************************************\n";
	cout << "		     Main Menu		    		\n";
	cout << "***************************************\n";
	cout << "Please select one option:";
	cout << "\n1. Add a new book";
	cout << "\n2. Search for a book by isbn";
	cout << "\n3. Search for a book by title";
	cout << "\n4. Show all books from the library";
	cout << "\n5. Sort books by title and author(in descending order)";
	cout << "\n6. Sort books by price";
	cout << "\n7. Copy the oldest books in another room(another array for oldest books, year 2014 and less)";
	cout << "\n8. Show old books";
	cout << "\n9. Exit the application\n";
	cin >> flag;

}
//for overload operator cin  
istream & operator >> (istream & in_stream, Book & a_book)
{
	cout << "\nPlease enter the following information about the book: ";
	cout << "\nInternational Standard Book Number: ";
	in_stream >> a_book.isbn;
	in_stream.ignore();

	cout << "\nTitle: ";
	getline(in_stream, a_book.title);

	cout << "\nAuthor: ";
	getline(in_stream, a_book.author);

	cout << "\nPrice: ";
	in_stream >> a_book.price;

	cout << "\nYear: ";
	in_stream >> a_book.year;
	in_stream.ignore();

	cout << "\nSubject: ";
	getline(in_stream, a_book.subject);

	cout << "\nLenguage: ";
	getline(in_stream, a_book.language);

	return in_stream;
}
istream & operator >> (istream & in_stream, Book * a_book)
{
	cout << "\nPlease enter the following information about the book: ";
	cout << "\nInternational Standard Book Number: ";
	in_stream >> a_book->isbn;
	in_stream.ignore();

	cout << "\nTitle: ";
	getline(in_stream, a_book->title);

	cout << "\nAuthor: ";
	getline(in_stream, a_book->author);

	cout << "\nPrice: ";
	in_stream >> a_book->price;

	cout << "\nYear: ";
	in_stream >> a_book->year;
	in_stream.ignore();

	cout << "\nSubject: ";
	getline(in_stream, a_book->subject);

	cout << "\nLenguage: ";
	getline(in_stream, a_book->language);

	return in_stream;
}
//for overload operator cout
ostream & operator << (ostream & out_stream, Book * a_book)
{
	out_stream << "International Standard Book Number: " << a_book->isbn <<
		"\nTitle: " << a_book->title <<
		"\nAuthor: " << a_book->author <<
		"\nPrice: " << a_book->price <<
		"\nYear: " << a_book->year <<
		"\nSubject: " << a_book->subject <<
		"\nLanguage: " << a_book->language;

	return out_stream;
}
ostream & operator << (ostream & out_stream, Book & a_book)
{
	out_stream << "International Standard Book Number: " << a_book.isbn <<
		"\nTitle: " << a_book.title <<
		"\nAuthor: " << a_book.author <<
		"\nPrice: " << a_book.price <<
		"\nYear: " << a_book.year <<
		"\nSubject: " << a_book.subject <<
		"\nLanguage: " << a_book.language;

	return out_stream;
}
ostream & operator << (ostream & out_stream, Book a_book)
{
	out_stream << "International Standard Book Number: " << a_book.isbn <<
		"\nTitle: " << a_book.title <<
		"\nAuthor: " << a_book.author <<
		"\nPrice: " << a_book.price <<
		"\nYear: " << a_book.year <<
		"\nSubject: " << a_book.subject <<
		"\nLanguage: " << a_book.language;

	return out_stream;
}

vector<Book>& operator >> (vector<Book> & books, Book & aBook)
{
	cin >> aBook;
	books.push_back(aBook);
	return books;

}
vector<Book>*& operator >> (vector<Book>*&  books, Book aBook)
{
	cin >> aBook;
	books->push_back(aBook);
	return books;

}

vector<Book>& operator >> (vector<Book> *  books, Book & aBook)
{
	cin >> aBook;
	books->push_back(aBook);
	return *books;

}

//to add books 
void add_book(vector <Book> * books , int nmb)
{
	system("cls");

	Book * tmpBook = new Book();
	for (int i = 0; i < nmb; i++)
	{
		*books >> *tmpBook;
	}
}
//for prompt the search isbn from user
void input_searchId(int * isbn_search)
{
	cout << "\nPlease enter the Book's isbn: ";
	cin >> *isbn_search;
}

//for prompt the search title from user
void input_searchTitle(string * title_search)
{
	cout << "\nPlease enter the Book's title: ";
	cin >> *title_search;

}
//for search a book by its isbn
void search_book(int id, vector<Book> * books)
{
	
	vector <Book>::iterator iter;
	bool bookFound = false;

	system("cls");
	
	for (iter = books->begin(); iter != books->end(); ++iter)
	{
		if (iter->isbn == id)
		{
			bookFound = true;
			break;
		}
	}
	if (bookFound == true)
	{
		cout << "Book ISBN: " << iter->isbn << "\nTitle: " << iter->title << "\nAuthor: " << iter->author << "\nPrice: " << iter->price << "\nYear: " << iter->year << "\nSubject: " << iter->subject << "\nLanguage: " << iter->language << endl;
	}
	else
	{
		cout << "Record NOT FOUND, please try with another isbn" << endl;
	}

	system("pause");
}
//for search a book by its title
void search_book(string title, vector<Book> * books)
{
	vector <Book>::iterator iter;
	bool bookFound = false;

	system("cls");

	for (iter = books->begin(); iter != books->end(); ++iter)
	{
		if (title == iter->title)
		{
			bookFound = true;
			break;
		}
	}
	if (bookFound == true)
	{
		
		cout << "Book ISBN: " << iter->isbn << "\nTitle: " << iter->title << "\nAuthor: " << iter->author << "\nPrice: " << iter->price << "\nYear: " << iter->year << "\nSubject: " << iter->subject << "\nLanguage: " << iter->language << endl;

	}
	else
	{
		cout << "Title NOT FOUND, please try with another one" << endl;
	}
	system("pause");
}
//To display all books
void display_books(vector<Book> * books)
{
	vector <Book>::iterator iter;

	system("cls");

	for (iter = books->begin(); iter != books->end(); iter++)
	{
		cout << "Book ISBN: " << iter->isbn << "\nTitle: " << iter->title << "\nAuthor: " << iter->author << "\nPrice: " << iter->price << "\nYear: " << iter->year << "\nSubject: " << iter->subject << "\nLanguage: " << iter->language << endl;

	}

	system("pause");

}
//to add old book using the overloading operator cin
void load_oldest(vector<Book> * old_books, vector<Book> * books)
{
	vector <Book>::iterator  iter;

	for (iter = books->begin(); iter != books->end(); iter++)
	{
		if (iter->year < 2015)
		{
			old_books->push_back(*iter);
		}
	}

	cout << "\n The new room has been created" << endl;
}

//for displaying oldest books
void display_old_books(vector<Book> * old_books)
{
	vector <Book>::iterator iter;

	for (iter = old_books->begin();iter < old_books->end(); iter++)
	{
		cout << "Book ISBN: " << iter->isbn << "\nTitle: " << iter->title << "\nAuthor: " << iter->author << "\nPrice: " << iter->price << "\nYear: " << iter->year << "\nSubject: " << iter->subject << "\nLanguage: " << iter->language << endl;
	}

	system("pause");

}
