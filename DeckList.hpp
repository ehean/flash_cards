#include "Deck.hpp"
#ifndef DECKLIST_HPP
#define DECKLIST_HPP
#include <vector>
using namespace std;

class DeckList {
private:
	vector<Deck> deckList;
public:
	void addDeck(Deck &d) { deckList.push_back(d); }
	vector<Deck> getDeckList() { return deckList; }
};

#endif