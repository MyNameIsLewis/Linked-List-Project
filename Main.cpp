
#include <iostream>
#include <assert.h>
#include <string>
#include <iostream>

using namespace std;

class User
{
public:
	User(string nameParam); //Constructor
	string getName() const { return name; }
	User* getNext() const { return next; }
	void setNext(User* nextParam) { next = nextParam; }
	User* getPrevious() const { return previous; }
	void setPrevious(User* previousParam)
	{
		previous = previousParam;
	}
	void setCurrent(User* currentParam)
	{
		current = currentParam;
	}
private:
	string name;
	User* next;
	User* previous; //Previous user on the list
	User* current; //Current user on the list
};
class Book
{
public:
	Book(string nameParam, string authorParam, double ISBNparam, int takenParam); //Constructor
	int getTaken() const { return taken; }
	void setTaken(int takenParam) { taken = takenParam; }
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
	void setTakenIncrement(Book* toBeIncrementedParam)
	{
		taken++;
	}

	void setTakenDecrement(Book* toBeIncrementedParam)
	{
		taken--;
	}

private:
	string name;
	string author;
	double ISBN;
	int taken;
	Book* next;
	Book* previous; //Previous book on the list
	Book* current; //Current book on the list

};

Book::Book(string nameParam, string authorParam, double ISBNparam, int takenParam)
	:name(nameParam), author(authorParam), ISBN(ISBNparam), taken(takenParam)
{
	next = NULL;
}

User::User(string nameParam):name(nameParam)
{
	next = NULL;
}

void printBookDetails(Book *first)
{
	//Prints the Books details
	Book* nextBook = first;
	while (nextBook != NULL)
	{
		cout << endl;
		cout << "Name : " << nextBook->getName() << endl; //Prints the name
		cout << "Author : " << nextBook->getAuthor() << endl; //Prints the Author
		cout << "ISBN : " << nextBook->getISBN() << endl; //Prints the ISBN
		cout << "Available : " << nextBook->getTaken() << endl << endl; //Prints the amount available

		nextBook = nextBook->getNext();
	}
}
void removeBook(Book* toRemove, Book* previousBook, Book* nextBook)
{
	//Removes a book from a list
	assert(toRemove != NULL);
	previousBook->setNext(toRemove->getNext());
	nextBook->setPrevious(toRemove->getPrevious());
	toRemove->setNext(NULL);
	toRemove->setPrevious(NULL);
	toRemove->setCurrent(NULL);
}
void addInFront(Book* toAdd, Book* inFrontOf)
{
	//Adds a book to a list
	assert(inFrontOf != NULL);
	toAdd->setNext(inFrontOf->getNext());
	inFrontOf->setNext(toAdd);
}

void addBefore(Book* toAdd, Book* before, Book* inFrontOf)
{
	//Adds a book to a list
	assert(inFrontOf != NULL);
	toAdd->setNext(before);
	before->setPrevious(toAdd);
	inFrontOf->setNext(toAdd);
	toAdd->setPrevious(inFrontOf);
}

void printPreviousDetails(Book *last)
{
	//Prints the books details
	Book* previousBook = last;
	while (previousBook != NULL)
	{
		//Print details
		cout << "ISBN: " << previousBook->getISBN() << endl;

		//Get privious customer
		previousBook = previousBook->getPrevious();
	}
}
Book* searchForBookByISBN(double isbnNum, Book* first)
{
	//Searches for books using the ISBN
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
	//Searches for books using the author
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
	//Searches for books using the name
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

User* searchForUserName(string nameParam, User* first)
{
	//Searches for User using the name
	User* nextUser = first;
	while (nextUser != NULL)
	{
		if (nameParam == nextUser->getName())
		{
			return nextUser;
		}
		else
		{
			nextUser = nextUser->getNext();
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
	//Creates a list of book objects
	Book *potter = new Book("Potter", "Rowling", 24554864682, 21);
	Book *bfg = new Book("BFG", "Dahl", 4853480421, 12);
	Book *fowl = new Book("A.Fowl", "Colfer", 6623178742, 10);
	Book *cookBook = new Book("A.Harriot's greatest dishes", "Harriot", 45583178742, 20);
	Book *moby = new Book("M.Dick", "Melville", 3674874842, 17);

	Book *potter1 = new Book("P", "R", 2, 12);
	Book *bfg1 = new Book("B", "D", 4, 13);
	Book *fowl1 = new Book("A", "C", 6, 14);
	Book *cookBook1 = new Book("AA", "H", 4, 12);
	Book *moby1 = new Book("M", "M", 3, 12);

	//Creates a list of Users
	User *dave = new User("Dave");
	User *sarah = new User("Sarah");
	User *paul = new User("Paul");
	User *luke = new User("Luke");
	User *diane = new User("Diane");
	
	//Main book list
	potter->setNext(bfg);
	bfg->setNext(fowl);
	fowl->setNext(cookBook);
	cookBook->setNext(moby);

	//Unavailable Book list
	potter1->setNext(bfg1);
	bfg1->setNext(fowl1);
	fowl1->setNext(cookBook1);
	cookBook1->setNext(moby1);

	//User list
	dave->setNext(sarah);
	sarah->setNext(paul);
	paul->setNext(luke);
	luke->setNext(diane);

	//Variables
	string authorInput;
	string nameInput;
	double ISBNInput;
	int chooseInput;
	char decisionInput;
	string removeInput;
	string frontInput;
	string beforeInput;
	string inFrontInput;
	string userInput;
	int password;


	while (1 < 2)
	{
		cout << "Hello! Welcome to the book shop! Please tell me what to do!" << endl << "Press 1 for Book Search" << endl << "Press 2 for Book addition (Requires admin login)" << endl << "Press 3 for Book Deletion (Requires admin login)" << endl << "Press 4 for Book rental/return"
			<< endl << "Press 5 if you wish to print the details of the books" << endl << "Press 6 to quit" << endl;
		cin >> chooseInput;

		if (chooseInput == 1)
		{
			//Starts the search
			cout << "Please select how you wish to search by: " << endl << "Press 1 for book name" << endl << "Press 2 for Author name" << endl << "Press 3 for ISBN" << endl << "Press 4 to quit" << endl;
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
					cout << "Found Book: " << found->getName() << endl << endl;
				}
				else
				{
					cout << "Book not found." << endl << endl;
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
			//Starts the book addition
			cout << "Please enter password" << endl; //Asks for Admin password
			cin >> password;
			if (password == 12345)
			{
				cout << "Welcome back!" << endl << endl;
				printBookDetails(potter1);
				cout << endl << endl << "Please enter the ID of the book you wish to add, the book before it and the book after it" << endl;
				cin >> removeInput;
				cin >> beforeInput;
				cin >> frontInput;
				Book* remove = searchForBookName(removeInput, potter1);
				Book* before = searchForBookName(beforeInput, potter1);
				Book* front = searchForBookName(frontInput, potter1);
				removeBook(remove, before, front);
				cout << endl << "Great, what book in the list do you want this book to go after?" << endl;
				cin >> inFrontInput;
				Book* inFront = searchForBookName(inFrontInput, potter);
				addInFront(remove, inFront);
				cout << endl << "Book has been added!" << endl;
			}
		}
		if (chooseInput == 3)
		{
			//Starts the book deletion		
			cout << "Please enter password" << endl; //Asks for Admin password
			cin >> password;
			if (password == 12345)
			{
				cout << "Welcome back!" << endl << endl;
				printBookDetails(potter);
				cout << endl << endl << "Please enter the ID of the book you wish to delete, the book before it and the book after it" << endl;
				cin >> removeInput;
				cin >> beforeInput;
				cin >> frontInput;
				Book* remove = searchForBookName(removeInput, potter);
				Book* before = searchForBookName(beforeInput, potter);
				Book* front = searchForBookName(frontInput, potter);
				removeBook(remove, before, front);
				cout << endl << "Book has been removed" << endl;
			}
		}

		if (chooseInput == 4)
		{
			//Searches for users
			cout << "Please enter username" << endl;
			cin >> userInput;
			User* found = searchForUserName(userInput, dave);
			if (found == NULL)
			{
				cout << "User not found, please try again." << endl <<endl;
			}
			else
			{
			//Starts book rental or returning
			cout << "Welcome back!" << endl <<"First, please choose if you are returning or renting a book" << endl << "Press 1 for rental" << endl << "Press 2 for returning";
			cin >> chooseInput;

			if (chooseInput == 1)
			{
				//Rental
				cout << "Please enter the name of the book you wish to rent" << endl;
				cin >> nameInput;
				Book* found = searchForBookName(nameInput, potter);
				int currentTaken = found->getTaken();
				if (found != NULL)
				{
					cout << "Found Book: " << found->getName() << endl << "Do you wish to rent this book?";
					cin >> decisionInput;
					if (decisionInput == 'Y' || 'y')
					{
						found->setTakenDecrement(found); //Takes one away from the number of books 
						cout << "Book has been rented" << endl << endl;
					}
					else if (decisionInput == 'N' || 'n')
					{
						cout << "Please try again." << endl << endl;
					}
					else if (currentTaken == 0)
					{
						cout << "The book is currently unavailable right now, please check back later" << endl << endl;
					}
				}
				else
				{
					cout << "Book not found." << endl << endl;
				}
			}
			if (chooseInput == 2)
			{
				//Starts book returning
				cout << "Please enter the name of the book you are returning" << endl;
				cin >> nameInput;
				Book* found = searchForBookName(nameInput, potter);
				if (found != NULL)
				{
					cout << "Found Book: " << found->getName() << endl << "Do you wish to return this book?";
					cin >> decisionInput;
					if (decisionInput == 'Y' || 'y')
					{
						found->setTakenIncrement(found); //Adds one to the number of books
						cout << "Book has been returned" << endl << endl;
					}
					else if (decisionInput == 'N' || 'n')
					{
						cout << "Please try again." << endl << endl;
					}
				}
				else
				{
					cout << "Book not found." << endl << endl;
				}
			}
		}
		}

		if (chooseInput == 5)
		{
			//Prints Book details
			printBookDetails(potter);
		}
		if (chooseInput == 6)
		{
			return 0; //Quits the program
		}
	}
}
