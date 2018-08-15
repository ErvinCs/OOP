#include <iostream>

#include "Tests.h"
#include "UI.h"
#include "UserUI.h"
#include "AdminUI.h"
#include "Database.h"
#include "TextFileDatabase.h"
#include "HtmlFileDatabase.h"
#include "Controller.h"

//Deprecated
void setUp(Database<Dog>& db)
{
	db.add(Dog("Dog", "Dog1", 1, "https://www.petfinder.com/dog/twotoes-41351433/ak/fairbanks/homeward-bound-pet-rescue-and-referral-ak29/"));
	db.add(Dog("Dog", "Dog2", 2, "https://www.petfinder.com/dog/koda-41405326/ak/fairbanks/fairbanks-north-star-borough-animal-control-ak12/"));
	db.add(Dog("Rat", "Dog3", 7, "https://www.petfinder.com/small-furry/laura-41350455/ak/fairbanks/fairbanks-north-star-borough-animal-control-ak12/"));
	db.add(Dog("Underdog", "Dog4", 4, "https://www.petfinder.com/dog/rascal-40920804/ak/fairbanks/homeward-bound-pet-rescue-and-referral-ak29/"));
	db.add(Dog("Dog", "Dog5", 9, "https://www.petfinder.com/dog/johnny-37944012/ak/fairbanks/homeward-bound-pet-rescue-and-referral-ak29/"));
	db.add(Dog("Underdog", "Dog6", 6, "https://www.petfinder.com/dog/breeze-41370250/ak/fairbanks/fairbanks-north-star-borough-animal-control-ak12/"));
	db.add(Dog("Horse", "Amazing horse, i mean dog", 3, "https://bestfriends.org/adopt/adopt-our-sanctuary/12677461/sally"));
	db.add(Dog("Pig", "Timmy the Dog", 2, "https://bestfriends.org/adopt/adopt-our-sanctuary/12155513/timmy"));
	db.add(Dog("Cat", "Myron", 3, "https://bestfriends.org/adopt/adopt-our-sanctuary/12802404/myron"));
	db.add(Dog("Pig", "Definitely a dog", 2, "https://bestfriends.org/adopt/adopt-our-sanctuary/11615857/daisy"));
}

void printMenu()
{
	std::cout << "\t0. Exit\n";
	std::cout << "\t1. Admin Mode\n";
	std::cout << "\t2. User Mode\n";
}

void printPersistenceMenu()
{
	std::cout << "\t0. Exit\n";
	std::cout << "\t1. Persistence: .txt\n";
	std::cout << "\t2. Persistence: .html\n";
}

int choosePersistence()
{
	bool running = true;
	while (running)
	{
		int mode;
		printPersistenceMenu();
		std::cout << "Choose persistence file: ";
		std::cin >> mode;

		if (mode >= 0 && mode <= 2)
			return mode;
		else
			std::cout << "Invalid input!\n";
	}
	return -1;
}

int main()
{
	int persistence = choosePersistence();

	Tests test = Tests();
	test.testAll();
	
	std::string txtPath = "C:\\Users\\asus\\source\\repos\\Lab8-9\\dogs.txt";
	std::string htmlPath = "C:\\Users\\asus\\source\\repos\\Lab8-9\\dogs.html";

	Database<Dog>* dogDb = nullptr;
	if (persistence == 1)
		dogDb = new TextFileDatabase<Dog>(txtPath);
	else if (persistence == 2)
		dogDb = new HtmlFileDatabase<Dog>(htmlPath);
	else
	{
		delete dogDb;
		return 0;
	}

	FileController<Dog> con = FileController<Dog>(dogDb);

	AdminUI adminUI = AdminUI(con);
	UserUI userUI = UserUI(con);

	bool running = true;
	while (running)
	{
		int mode;
		printMenu();
		std::cout << "Choose mode: ";
		std::cin >> mode;
		if (mode == 1)
			adminUI.run();
		else if (mode == 2)
			userUI.run();
		else if (mode == 0)
			running = false;
		else
			std::cout << "Invalid input!\n";
	}

	return 0;
}