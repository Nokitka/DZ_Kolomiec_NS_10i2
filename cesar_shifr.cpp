#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "RUSSIAN");

	string smallChar = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
	string bigChar = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";

	string text;
	string shifr = "";

	int k, nums, numb;
	char sym;

	cout << "Enter text: ";
	getline(cin, text);
	cout << "Enter ROT: ";
	cin >> k;

	for (int i = 0; i < text.size(); i++) {

		sym = text[i];
		nums = smallChar.find(sym);
		numb = bigChar.find(sym);

		if (nums == -1 && numb == -1) {
			shifr.push_back(text[i]);
		}
		else {
			if (nums + k <= 32 and nums != -1){
				shifr.push_back(smallChar[nums + k]);
			}
			else if (numb + k <= 32 and numb != -1) {
				shifr.push_back(bigChar[numb + k]);
			}
			else if (nums + k > 32 and nums != -1) {
				shifr.push_back(smallChar[nums + k - 33]);
			}
			else if (numb + k > 32 and numb != -1) {
				shifr.push_back(bigChar[numb + k - 33]);
			}

		}
	}

	cout << shifr;

	return 0;
}

