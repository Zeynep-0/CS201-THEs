
#include <iostream>
#include <string>
using namespace std;

int decodeNumber(const string& PositionWord) {
	int sum = 0;
	for (int i = 0; i < PositionWord.length(); i++) {
		if (isdigit(PositionWord[i])) {
			char digitChar = PositionWord[i];
			sum += atoi(&digitChar);
		}
	}
	return sum;


}
string reverseWord(const string& word) {
	string newword = "";
	for (int i = 1; i < word.length() + 1; i++) {
		newword = newword + word[word.length() - i];
	}
	return newword;

}
string reverseLettersDecode(const string& message) {
	int space = message.find(" ");
	string neww;
	string a = message.substr(0, space);
	neww = reverseWord(a);
	a = message.substr(space + 1, message.length() - space);
	int space2 = a.find(" ");
	while (space2 != string::npos) {
		neww += " " + reverseWord(a.substr(0, space2));
		a = a.substr(space2 + 1, a.length() - space2);
		space2 = a.find(" ");
	}
	neww += " " + reverseWord(a);
	return neww;
}
string caesarCipherShiftDecode(const string& message, int shift) {
	string decodedstring = "";
	for (int i = 0; i < message.length(); i++) {
		char mess = message[i];
		if (isalpha(mess) != 0) {
			if (islower(mess)) {
				int ind = (mess - 'a' - shift + 26) % 26;
				char newch = 'a' + ind;
				decodedstring += newch;
			}
			else {
				int ind = (mess - 'A' - shift + 26) % 26;
				char newch = 'A' + ind;
				decodedstring += newch;
			}
		}
		else {
			decodedstring = decodedstring + mess;
		}
	}
	return decodedstring;
}
string findKey(const string& decodedMessage, int position) {
	string key = "";
	int counter = 1;
	int index = 0;
	if (counter == position) {
		return key = decodedMessage.substr(0, decodedMessage.find(" "));
	}
	while (counter != position) {
		if (decodedMessage.find(" ", index + 1) != 0) {
			index = decodedMessage.find(" ", index + 1);
			counter++;
		}
		else {
			return key = decodedMessage.substr(index, decodedMessage.length() - index);
		}
	}
	string subst = decodedMessage.substr(index + 1, decodedMessage.length() - index);
	key = decodedMessage.substr(index + 1, subst.find(" "));
	return key;


}
string removeLastPunctuation(string key) {
	string punctuationMarks = ".,;:!?";
	if (punctuationMarks.find(key[key.length() - 1]) != string::npos) {
		return key.substr(0, key.length() - 1);
	}
	else {
		return key;
	}
}




int main() {
	string message;
	cout << "Enter your encoded message: ";
	getline(cin, message);
	cout << "Choose your decoding strategy:" << endl;
	cout << "1. Reverse Letters" << endl;
	cout << "2. Caesar Cipher Shift" << endl;
	int choice;
	cout << "Enter choice (1 or 2): ";
	cin >> choice;
	while (choice != 1 && choice != 2) {
		cout << "Invalid choice. Enter choice (1 or 2): ";
		cin >> choice;
	}
	if (choice == 2) {
		int shift;
		cout << "Enter Caesar Cipher Shift amount: ";
		cin >> shift;
		cout << "Enter the word to find the position of the key word: ";
		string PositionWord;
		cin >> PositionWord;
		cout << "Decoded Message: ";
		string decodedMessage = caesarCipherShiftDecode(message, shift);
		cout << decodedMessage << endl;
		cout << "Secret Key: ";
		cout << removeLastPunctuation(findKey(decodedMessage, decodeNumber(PositionWord)));
	}
	else {
		cout << "Enter the word to find the position of the key word: ";
		string PositionWord;
		cin >> PositionWord;
		cout << "Decoded Message: ";
		string decodedMessage = reverseLettersDecode(message);
		cout << decodedMessage << endl;
		cout << "Secret Key: ";
		cout << removeLastPunctuation(findKey(decodedMessage, decodeNumber(PositionWord)));

	}



}
