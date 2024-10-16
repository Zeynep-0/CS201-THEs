#include <iostream>
#include <iomanip>
using namespace std;

int main() {

	cout << "Welcome to the Hogwarts Potion Brewing Challenge!" << endl << "Which potion are you brewing? " << endl;
	cout << "1. Potion of Invisibility" << endl;
	cout << "2. Calming Draught" << endl;
	cout << "3. Strengthening Solution" << endl;
	cout << "Enter choice (1-3): ";
	int choice;
	cin >> choice;
	int pearl, venom, demiguise;
	int lavender, crocodile, peppermint;
	int blood, claw;
	float boilp, invol, evo, boilt, boilpf;
	cout << fixed << setprecision(2);
	switch (choice) {
	case 1:
		cout << "Enter the amount of Pearl Dust (in grams): ";
		cin >> pearl;
		cout << "Enter the amount of Acromantula Venom (in ml): ";
		cin >> venom;
		cout << "Enter the amount of Tincture of Demiguise (drops):" << endl;
		cin >> demiguise;
		boilp = 100 + pearl + 4 * demiguise - 3 * venom;
		boilpf = (boilp * 9 / 5) + 32;
		invol = 500 + pearl + venom + demiguise;
		evo = invol - 300;
		boilt = evo / (40 * (100 / boilp));
		cout << "For your potion: " << endl;
		cout << "Adjusted Boiling Point: " << boilp << " C (" << boilpf << " F)" << endl;
		cout << "Total Initial Volume: " << invol << " ml" << endl;
		cout << "Evaporated Volume: " << evo << " ml" << endl;
		cout << "Boiling Time Required: " << boilt << " minutes" << endl;
		cout << "Ensure your potion is brewed at this precise volume and time for perfect results!";

		break;
	case 2:
		cout << "Enter the amount of Lavender (in grams): ";
		cin >> lavender;
		cout << "Enter the number of Crocodile Hearts: ";
		cin >> crocodile;
		cout << "Enter the amount of Peppermint (in leaves, 1 leaf = 1ml):" << endl;
		cin >> peppermint;
		boilp = 100 - 0.2 * lavender + 5 * crocodile - peppermint;
		boilpf = (boilp * 9 / 5) + 32;
		invol = 500 + lavender + peppermint + (crocodile * 5);
		evo = invol - 300;
		boilt = evo / (40 * (100 / boilp));
		cout << "For your potion: " << endl;
		cout << "Adjusted Boiling Point: " << boilp << " C (" << boilpf << " F)" << endl;
		cout << "Total Initial Volume: " << invol << " ml" << endl;
		cout << "Evaporated Volume: " << evo << " ml" << endl;
		cout << "Boiling Time Required: " << boilt << " minutes" << endl;
		cout << "Ensure your potion is brewed at this precise volume and time for perfect results!";
		break;
	case 3:
		cout << "Enter the amount of Salamander Blood (in ml): ";
		cin >> blood;
		cout << "Enter the amount of Powdered Griffin Claw (in grams):" << endl;
		cin >> claw;
		boilp = 100 - 2 * blood + 3 * claw;
		boilpf = (boilp * 9 / 5) + 32;
		invol = 500 + blood + claw;
		evo = invol - 300;
		boilt = evo / (40 * (100 / boilp));
		cout << "For your potion: " << endl;
		cout << "Adjusted Boiling Point: " << boilp << " C (" << boilpf << " F)" << endl;
		cout << "Total Initial Volume: " << invol << " ml" << endl;
		cout << "Evaporated Volume: " << evo << " ml" << endl;
		cout << "Boiling Time Required: " << boilt << " minutes" << endl;
		cout << "Ensure your potion is brewed at this precise volume and time for perfect results!";
		break;
	default:
		cout << "Invalid choice. Please restart the program and select a valid potion.";
		break;
	}
}

