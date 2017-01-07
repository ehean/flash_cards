#ifndef CARD_HPP
#define CARD_HPP
#include <string>
using namespace std;

class Card {
private:
	string front;
	string back;
	int cardNumber;
public:
	//Card();
	//Card(string f, string b) {
	//	front = f;
	//	back = b;
	//}
	void setFront(string f) {	front = f;	}
	void setBack(string b)	{	back = b;	}
	void setNumber(int cn)  {   cardNumber = cn;	}
	string getFront()		{	return front;	}
	string getBack()		{	return back;	}	
	int getNumber()			{   return cardNumber;	}	
};
#endif