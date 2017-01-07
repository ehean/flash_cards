#include "ProgramInterface.hpp"
#include <iostream>
#include <fstream>
#include <direct.h>
#include <Windows.h>
using namespace std;

void ProgramInterface::displayMenu() {
	int input;

	cout << "MENU" << endl;
	cout << "1. Create a new deck" << endl;
	cout << "2. Open a deck and practice (TBA)" << endl;
	cout << "3. Edit an existing deck (TBA)" << endl;

	cin >> input;
	validateOption(input);
}

void ProgramInterface::validateOption(int input) {
	if (input == 1) 
		CreateDeck();
	else if (input == 2) 
		openDeck();
	else if (input == 3) { }
		// editDeck open;
	else {
		cout << "\nPlease enter a valid menu option.\n";
		cin >> input;
		validateOption(input);
	}
}

void ProgramInterface::CreateDeck() {

	Deck newDeck;
	DeckList newDeckList;
	newDeckList.addDeck(newDeck);
	string input;
	bool isFront = true;

	cout << "Deck Name: ";
	cin.ignore();
	getline(cin, input);
	newDeck.setDeckName(input);

	createCard(newDeck, newDeckList);
}

void ProgramInterface::createCard(Deck d, DeckList dl) {
	string input;
	bool isFront = true;
	int cardNumber = 1;

	do {
		if (isFront)
			cout << "Input Card " << cardNumber << " front:\n";
		else {
			cout << "Input Card " << cardNumber << " back:\n";
			cardNumber++;
		}
		getline(cin, input);
		isFront = !isFront;
	} while (inputResponse(input, !isFront, d, dl, cardNumber) == CONTINUE);
}

cmd ProgramInterface::inputResponse(string input, bool isFront, Deck &d, DeckList &dl, int cn) {

	if (input == "quit") {
		saveAndQuit(d, dl);
		return SAVE_AND_QUIT;
	}
	if (input == "menu") {
		saveAndQuit(d, dl);
		displayMenu();
		return RETURN_TO_MENU;
	}
	if (input == "edit") {
		if (isFront) {
			d.addBlankCard();
			d.getDeck()[cn - 2].setFront(input);
		}
		else
			d.getDeck()[cn - 2].setBack(input);
		return CONTINUE;
	}
	else {
		if (isFront) {
			Card newCard;
			newCard.setFront(input);
			newCard.setNumber(cn);
			d.addCard(newCard);
		}
		else {
			d.setBack(cn - 2, input);
		}
		return CONTINUE;
	}
}


void ProgramInterface::saveAndQuit(Deck &d, DeckList &dl) {
	fstream outputFile;
	_mkdir("Decks");
	outputFile.open("Decks/" + d.getDeckName() + ".txt", ios::app);

	vector<Card> deck = d.getDeck();
	for (size_t i = 0; i < deck.size(); ++i) {
		outputFile << deck[i].getFront() << TAB;
		outputFile << deck[i].getBack() << NEWLINE;
	}
	outputFile.close();

	fstream deckListFile;
	deckListFile.open("deckList.txt", ios::app);

	vector<Deck> deckList = dl.getDeckList();
	if (deckListFile) {
			deckListFile << d.getDeckName();
	}
	else
		cout << "ERROR: Cannot open the deckList.txt file.\n" << endl;
}

void ProgramInterface::openDeck() {

	char ENTER;
	ifstream openDeckFile;
	int deckNum = 1;
	int input;
	string front, back;
	vector<string> deckNames;

	HANDLE hFind;
	WIN32_FIND_DATA data;
	SetCurrentDirectory("Decks\\");
	hFind = FindFirstFile("*.txt", &data);
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			cout << deckNum << ". ";
			cout << data.cFileName << endl;
			deckNum++;
			deckNames.push_back(data.cFileName);
		} while (FindNextFile(hFind, &data));
		FindClose(hFind);
	}
	
	cin.ignore();
	cout << "Type in the number of the deck you wish to play, or type 0 to return to the menu.\n";
	cin >> input;
	if (input == 0) {
		SetCurrentDirectory("..");
		displayMenu();
	}
	else {
		openDeckFile.open(deckNames[input - 1]);
		while (openDeckFile) {
			getline(openDeckFile, front, '\t');
			cout << "Front:\n" << front << endl;
			cin.ignore();
			cin.get();
			getline(openDeckFile, back);
			cout << "Back:\n" << back << endl;
			cin.get();
		}
		SetCurrentDirectory("..");
		displayMenu();
	}
}

void playDeck(ifstream deck) {
	;
	//ifstream openDeck;
	//string cardText, front, back;
	//Deck playDeck;
	//playDeck.setDeckName(deck);

	//openDeck.open(name + ".txt");

	///*while (getline(openDeck, cardText)) {
	//	cout 
	//}*/
}