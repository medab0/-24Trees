#include <iostream>
#include "tree24.h"

using namespace std;

int main (int argc, char** argv) {
	Tree24* tree = new Tree24();
	
	tree -> insert (13);
	tree -> insert (4);
	tree -> insert (10);
	tree -> insert (24);
	tree -> insert (17);
	tree -> print();
	return 0;
}
