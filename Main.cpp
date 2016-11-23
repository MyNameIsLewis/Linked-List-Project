#include <iostream>
#include <assert.h>
#include <string>
#include <iostream>

using namespace std;


class Book
{
public:
	Book(string nameParam, string authorParam, double ISBNparam);
	string getName() const { return name; }
	string getAuthor() const { return author; }
	double getISBN() const { return ISBN; }
	Book* getNext() const { return next; }
	void setNext(Book* nextParam) { next = nextParam; }
	Book* getPrevious() const { return previous; }
	void setPrevious(Book* previousParam)
	{
		previous = previousParam;
	}
	void setCurrent(Book* currentParam)
	{
		current = currentParam;
	}

private:
	string name;
	string author;
	double ISBN;
	Book* next;
	Book* previous; //Previous book on the list
	Book* current; //Current book on the list

};

Book::Book(string nameParam, string authorParam, double ISBNparam)
	:name(nameParam), author(authorParam), ISBN (ISBNparam)
{
	next = NULL;
}

void printBookDetails(Book *first)
{
	Book* nextBook = first;
	while (nextBook != NULL)
	{
		cout << "Name : " << nextBook->getName() << endl;
		cout << "Author : " << nextBook->getAuthor() << endl;
		cout << "ISBN : " << nextBook->getISBN() << endl << endl;

		nextBook = nextBook->getNext();
	}
}
void removeBook(Book* toRemove, Book* previousBook, Book* nextBook)
{
	assert(toRemove != NULL);
	previousBook->setNext(toRemove -> getNext());
	nextBook->setPrevious(toRemove -> getPrevious());
	toRemove->setNext(NULL);
	toRemove->setPrevious(NULL);
	toRemove->setCurrent(NULL);
}
void addInFront(Book* toAdd, Book* inFrontOf)
{
	assert(inFrontOf != NULL);
	toAdd->setNext(inFrontOf -> getNext());
	inFrontOf->setNext(toAdd);
}

void addBefore(Book* toAdd, Book* before, Book* inFrontOf)
{
	assert(inFrontOf != NULL);
	toAdd->setNext(before);
	before->setPrevious(toAdd);
	inFrontOf->setNext(toAdd);
	toAdd -> setPrevious(inFrontOf);
}

void printPreviousDetails (Book *last)
	{
		Book* previousBook = last;
		while(previousBook != NULL)
		{
			//Print details
			cout << "ISBN: "<<previousBook-> getISBN() << endl;

			//Get privious customer
			previousBook = previousBook -> getPrevious();
		}
	}
Book* searchForBookByISBN(double isbnNum, Book* first)
{
	Book* nextBook = first;
	while (nextBook != NULL)
	{
		if (isbnNum == nextBook->getISBN())
		{
			return nextBook;
		}
		else
		{
			nextBook = nextBook->getNext();
		}
	}
	return NULL;
}

Book* searchForBookByAuthor(string authorParam, Book* first)
{
	Book* nextBook = first;
	while (nextBook != NULL)
	{
		if (authorParam == nextBook->getAuthor())
		{
			return nextBook;
		}
		else
		{
			nextBook = nextBook->getNext();
		}
	}
	return NULL;
}
Book* searchForBookName(string nameParam, Book* first)
{
	Book* nextBook = first;
	while (nextBook != NULL)
	{
		if (nameParam == nextBook->getName())
		{
			return nextBook;
		}
		else
		{
			nextBook = nextBook->getNext();
		}
	}
	return NULL;
}
/*
	->Search by one letter
	->Return partial book in partial list
	->Match this with full book in completed list
	->Return book(s)
*/
Book* searchPartial(string nameParam, Book* first)
{
	Book* nextBook = first;
	while (nextBook != NULL)
	{
		if (nameParam == nextBook->getName())
		{
			return nextBook;
		}
		else
		{
			nextBook = nextBook->getNext();
		}
	}
	return NULL;
}

int main()
{
	Book *potter = new Book("Potter", "Rowling", 24554864682);
	Book *bfg = new Book("BFG", "Dahl", 4853480421);
	Book *fowl = new Book("A.Fowl", "Colfer", 6623178742);
	Book *cookBook = new Book("A.Harriot's greatest dishes", "Harriot", 45583178742);
	Book *moby = new Book("M.Dick", "Melville", 3674874842);

	Book *potter1 = new Book("P", "R", 2);
	Book *bfg1 = new Book("B", "D", 4);
	Book *fowl1 = new Book("A", "C", 6);
	Book *cookBook1 = new Book("A", "H", 4);
	Book *moby1 = new Book("M", "M", 3);

	potter->setNext(bfg);
	bfg->setNext(fowl);
	fowl->setNext(cookBook);
	cookBook->setNext(moby);

	potter1->setNext(bfg1);
	bfg1->setNext(fowl1);
	fowl1->setNext(cookBook1);
	cookBook1->setNext(moby1);

	string authorInput;
	string nameInput;
	double ISBNInput;
	int chooseInput;
	int password;
	//printBookDetails(potter);

	while (1 < 2)
	{
	cout << "Hello! Please tell me what to do!" << endl << "Press 1 for Book Search" << endl << "Press 2 for book addition (Requires admin login)" << "Press 3 for Book Deletion (Requires admin login)" << endl << "Press 4 for Book rental/return";
	cin >> chooseInput;
	
	if (chooseInput == 1)
	{
	cout << "Please select how you wish to search by: " << endl << "Press 1 for book name" << endl << "Press 2 for Author name" << endl << "Press 3 for ISBN" << endl << "Press 4 to quit"  << endl;
	cin >> chooseInput;
	if (chooseInput == 1)
	{
		cout << "Please type in the name of the book: " << endl;
		cin >> nameInput;
		Book* found = searchForBookName(nameInput, potter);
		if (found != NULL)
		{
			cout << "Found Book: " << found->getName() << endl << endl;
		}
		else
		{
			cout << "Book not found." << endl << endl;
		}
	}
	if (chooseInput == 2)
	{
		cout << "Please type in the name of the Author: " << endl;
		cin >> authorInput;
		Book* found = searchForBookByAuthor(authorInput, potter);
		if (found != NULL)
		{
			cout << "Found Book: " << found->getName() << endl<< endl;
		}
		else
		{
			cout << "Book not found." << endl<< endl;
		}
	}
	if (chooseInput == 3)
	{
		cout << "Please type in the ISBN of the book: " << endl;
		cin >> ISBNInput;
		Book* found = searchForBookByISBN(ISBNInput, potter);
		if (found != NULL)
		{
			cout << "Found book: " << found->getName() << endl << endl;
		}
		else
		{
			cout << "Book not found." << endl << endl;
		}
	}
	
	if (chooseInput == 4)
	{
		return 0;
	}
	}

	if (chooseInput == 2)
	{
		cout << "Please enter password" << endl;
		cin >> password;
		if (password == 12345)
		{
			cout << "Welcome back!" << endl << "Please enter the ID of the book you wish to add, the book before it and the book after it" << endl;
		}
	}
	}
}
