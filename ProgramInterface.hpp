#include "DeckList.hpp"
#ifndef PROGRAMINTERFACE_HPP
#define PROGRAMINTERFACE_HPP
#include <iostream>
using namespace std;

enum cmd { CONTINUE, SAVE_AND_QUIT, EDIT_PREVIOUS, RETURN_TO_MENU };

const char TAB = '\t';
const char NEWLINE = '\n';


class ProgramInterface {
public:
	void displayMenu();
	void validateOption(int option);
	void CreateDeck();
	void createCard(Deck d, DeckList dl);
	cmd inputResponse(string input, bool isFront, Deck &d, DeckList &dl, int cn);
	void saveAndQuit(Deck &d, DeckList &dl);
	void openDeck();
	void playDeck(ifstream deck);
};

#endif