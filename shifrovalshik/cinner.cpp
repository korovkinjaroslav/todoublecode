#include "cinner.h"
#include <iostream>
#include <string>
std::string cin_all() {
	std::string a, b;
	int lenght;
	getline(std::cin, b);
	lenght = b.size();
	while ((lenght <3)or(b[lenght - 3] != 'E') or (b[lenght - 2] != 'N') or (b[lenght - 1] != 'D')) {
		a.append(b);
		a.append("\n");
		getline(std::cin, b);
		lenght = b.size();
	}
	return a;
}