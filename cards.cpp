#include "cards.h"
#include <cstdlib>
#include <iostream>
#include <vector>

/*
You might or might not need these two extra libraries
#include <iomanip>
#include <algorithm>
*/


/* *************************************************
Card class
************************************************* */

/*
Default constructor for the Card class.
It could give repeated cards. This is OK.
Most variations of Blackjack are played with
several decks of cards at the same time.
*/
Card::Card() {
	int r = 1 + rand() % 4;
	switch (r) {
	case 1: suit = Oros; break;
	case 2: suit = COPAS; break;
	case 3: suit = ESPADAS; break;
	case 4: suit = BASTOS; break;
	default: break;
	}

	r = 1 + rand() % 10;
	switch (r) {
	case  1: rank = AS; break;
	case  2: rank = DOS; break;
	case  3: rank = TRES; break;
	case  4: rank = CUATRO; break;
	case  5: rank = CINCO; break;
	case  6: rank = SEIS; break;
	case  7: rank = SIETE; break;
	case  8: rank = SOTA; break;
	case  9: rank = CABALLO; break;
	case 10: rank = REY; break;
	default: break;
	}
}

// Accessor: returns a string with the suit of the card in Spanish 
string Card::get_spanish_suit() const {
	string suitName;
	switch (suit) {
	case Oros:
		suitName = "Oros";
		break;
	case COPAS:
		suitName = "copas";
		break;
	case ESPADAS:
		suitName = "espadas";
		break;
	case BASTOS:
		suitName = "bastos";
		break;
	default: break;
	}
	return suitName;
}

// Accessor: returns a string with the rank of the card in Spanish 
string Card::get_spanish_rank() const {
	string rankName;
	switch (rank) {
	case AS:
		rankName = "As";
		break;
	case DOS:
		rankName = "Dos";
		break;
	case TRES:
		rankName = "Tres";
		break;
	case CUATRO:
		rankName = "Cuatro";
		break;
	case CINCO:
		rankName = "Cinco";
		break;
	case SEIS:
		rankName = "Seis";
		break;
	case SIETE:
		rankName = "Siete";
		break;
	case SOTA:
		rankName = "Sota";
		break;
	case CABALLO:
		rankName = "Caballo";
		break;
	case REY:
		rankName = "Rey";
		break;
	default: break;
	}
	return rankName;
}



// Accessor: returns a string with the suit of the card in English 
// This is just a stub! Modify it to your liking.
string Card::get_english_suit() const {
	string suitName;
	switch (suit) {
	case Oros:
		suitName = "Diamonds";
		break;
	case COPAS:
		suitName = "Hearts";
		break;
	case ESPADAS:
		suitName = "Spades";
		break;
	case BASTOS:
		suitName = "Clubs";
		break;
	default: break;
	}
	return suitName;
}

// Accessor: returns a string with the rank of the card in English 
// This is just a stub! Modify it to your liking.
string Card::get_english_rank() const {
	string rankName;
	switch (rank) {
	case AS:
		rankName = "Ace";
		break;
	case DOS:
		rankName = "Two";
		break;
	case TRES:
		rankName = "Three";
		break;
	case CUATRO:
		rankName = "Four";
		break;
	case CINCO:
		rankName = "Five";
		break;
	case SEIS:
		rankName = "Six";
		break;
	case SIETE:
		rankName = "Seven";
		break;
	case SOTA:
		rankName = "Jack";
		break;
	case CABALLO:
		rankName = "Queen";
		break;
	case REY:
		rankName = "King";
		break;
	default: break;
	}
	return rankName;
}

double Card::get_value() const
{
	double value = 0.0;
	switch (rank)
	{
		case AS:
			value = 1.0;
			break;
		case DOS:
			value = 2.0;
			break;
		case TRES:
			value = 3.0;
			break;
		case CUATRO:
			value = 4.0;
			break;
		case CINCO:
			value = 5.0;
			break;
		case SEIS:
			value = 6.0;
			break;
		case SIETE:
			value = 7.0;
			break;
		case SOTA:
			value = 0.5;
			break;
		case CABALLO:
			value = 0.5;
			break;
		case REY:
			value = 0.5;
			break;
		default: break;
	}
	return value;
}



// Assigns a numerical value to card based on rank.
// AS=1, DOS=2, ..., SIETE=7, SOTA=10, CABALLO=11, REY=12
int Card::get_rank() const {
	return static_cast<int>(rank) + 1;
}

// Comparison operator for cards
// Returns TRUE if card1 < card2
bool Card::operator < (Card card2) const {
	return rank < card2.rank;
}



/* *************************************************
Hand class
************************************************* */
// Implemente the member functions of the Hand class here.
Hand::Hand()
{

	hand.push_back(new Card());
	num_cards = 1;
}
string Hand::get_cards() const
{
	string cards;
	for (auto i = 0; i < num_cards; i++)
	{
		cards += hand[i]->get_english_rank();
		cards += " of ";
		cards += hand[i]->get_english_suit();
		if (i != num_cards - 1)
			cards += ", ";
		else
			cards += ".\n";
	}
	return cards;
}
void Hand::add_card()
{
	hand.push_back(new Card());
	num_cards++;
}
int Hand::get_num_cards() const
{
	return num_cards;
}
double Hand::hand_value() const
{
	double value = 0.0;
	for (auto i = 0; i < num_cards; i++)
		value += hand[i]->get_value();
	return value;
}


/* *************************************************
Player class
************************************************* */
// Implemente the member functions of the Player class here.
