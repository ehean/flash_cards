#include "Card.hpp"
#ifndef DECK_HPP
#define DECK_HPP
#include <vector>
#include <string>
using namespace std;

const string EMPTY = "EMPTY";

class Deck {
private:
	vector<Card> deck;
	string deckName;
	Card BLANK;
public:
	vector<Card> getDeck()			{	return deck;	 }
	string getDeckName()			{	return deckName; }
	void setDeckName(string d)		{	deckName = d;	}
	void addCard(Card &c)			{	deck.push_back(c);	}
	void addBlankCard()				{	deck.push_back(BLANK);	}
	void setBack(int cardIndex, string backName) { deck[cardIndex].setBack(backName); }
	void randomizeDeck()			{}
};
#endif // !DECK_HPP
