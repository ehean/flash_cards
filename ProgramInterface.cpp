#include "ProgramInterface.hpp"
#include <iostream>
#include <fstream>
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
	outputFile.open(d.getDeckName() + ".txt", ios::app);

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
	string deckName;
	ifstream getDecks;
	ifstream openDeck;
	int deckNum = 1;
	vector<int> deckNums;
	vector<string> deckNames;
	string input;
	getDecks.open("deckList.txt");

	cout << "Here's a list of all of your card decks.\n";
	if (getDecks) {
		while (getline(getDecks, deckName)) {
			deckNums.push_back(deckNum);
			deckNames.push_back(deckName);
			cout << deckNum++ << ". " << deckName << endl;
		}
	}
	else {
		cout << "ERROR: Cannot open the deckList.txt file.\n";
	}
	
	cin.ignore();
	cout << "Type in the name of the deck you wish to play, or type 0 to return to the menu.\n";
	getline(cin, input);

	if (input == "0") {
		displayMenu();
	}
	else {
		openDeck.open(input + ".txt");
		if (openDeck)
			;
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