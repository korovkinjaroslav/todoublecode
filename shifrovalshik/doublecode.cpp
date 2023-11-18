#include "doublecode.h"
#include <string>
#include <deque>
#include <cmath>
std::string to_binar_code(int ascii_ind, int znaki) {
	std::deque<char>prosto_dek;
	ascii_ind = abs(ascii_ind);
	int a = ascii_ind, count = 0;
	char b;
	std::string bincode;
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
	while (prosto_dek.size() != znaki) {
		prosto_dek.push_front('0');
	}
	for (int i = 0; i < prosto_dek.size(); i++) {
		bincode.push_back(prosto_dek[i]);
	}
	return bincode;
}
std::string shifr_text(std::string text, int znaki) {
	int len = text.size();
	std::string codetext;
	for (int i = 0; i < len; i++) {
		codetext.append(to_binar_code(int(unsigned char(text[i])), znaki));
	}
	return codetext;
}
std::string rasshifr_text(std::string text, int shag) {
	int text_len;
	text_len = text.size();
	while ((text[text_len - 1] != '0') and (text[text_len-1] != '1')) {
		text.pop_back();
		text_len -= 1;
	}
	int i = 0;
	int ascii_ind;
	int len;
	std::string normal_text;
	std::deque<char>simbol;
	while (i < text_len - shag) {
		ascii_ind = 0;
		for (int j = i; j < i + shag; j++) {
			simbol.push_back(text[j]);
		}
		while (simbol.front() == '0') {
			simbol.pop_front();
		}
		len = simbol.size();
		for (int m = 0; m < len;m++) {
			ascii_ind += (int(simbol[m]) - 48) * int(pow(2, len-m-1));
		}
		normal_text.push_back(char(ascii_ind));
		simbol.clear();
		i += shag;
	}
	return normal_text;
}