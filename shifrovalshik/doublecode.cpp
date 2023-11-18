#include "doublecode.h"
#include <string>
#include <deque>
std::string to_binar_code(int ascii_ind) {
	std::deque<char>prosto_dek;
	ascii_ind = abs(ascii_ind);
	int a = ascii_ind, count = 0;
	char b;
	std::string bincode;
	if (a == 0) {
		return "00000000";
	}
	while (a != 0) {
		count++;
		a /= 10;
	}
	a = ascii_ind;
	while (a != 0) {
		b = char(a % 2 + 48);
		prosto_dek.push_front(b);
		a /= 2;
	}
	while (prosto_dek.size() != 8) {
		prosto_dek.push_front('0');
	}
	for (int i = 0; i < prosto_dek.size(); i++) {
		bincode.push_back(prosto_dek[i]);
	}
	while (prosto_dek.size() != 8) {
		prosto_dek.push_front('0');
	}
	return bincode;
}
std::string shifr_text(std::string text) {
	int len = text.size();
	std::string codetext;
	for (int i = 0; i < len; i++) {
		codetext.append(to_binar_code(int(unsigned char(text[i]))));
	}
	return codetext;
}