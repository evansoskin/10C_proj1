#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"
using namespace std;

// Global constants (if any)


// Non member functions declarations (if any)


// Non member functions implementations (if any)


// Stub for main
int main()
{
	
	Card* c = new Card();
	cout << c->get_english_rank() << " of " << c->get_english_suit() << endl;
	cout << c->get_spanish_rank() << " of " << c->get_spanish_suit() << endl;

	Hand h;
	cout << h.get_cards();
	h.add_card();
	cout << h.get_cards();
	cout << h.hand_value() << endl;

	system("PAUSE");
	return 0;
}