
#include <iostream>
#include <iomanip>
using namespace std;

void getTripDetails(string& startCity, string& destinationCity, float&
	distance, float& gasPrice, int& passengers, int& daysInAdvance, bool&
	isWeekend) {
	string weekend;
	cout << "Enter the starting city: ";
	cin >> startCity;
	cout << "Enter the destination city: ";
	cin >> destinationCity;
	cout << "Enter the trip distance in kilometers: ";
	cin >> distance;
	cout << "Enter the price of gasoline per liter: ";
	cin >> gasPrice;
	cout << "Enter the number of passengers: ";
	cin >> passengers;
	cout << "Enter days booked in advance: ";
	cin >> daysInAdvance;
	cout << "Is the trip on a weekend? (yes/no): ";
	cin >> weekend;
	if (weekend == "no") {
		isWeekend = 0;
	}
	else {
		isWeekend = 1;
	}

}

float calculateEnvironmentalFee(float distance, float
	average_fuel_consumption_per_100km) {
	if (average_fuel_consumption_per_100km > 8) {
		return distance * 0.002;
	}
	else {
		return distance * 0.001;
	}
}

float calculateCarCost(const float distance, const float gasPrice,
	const float average_fuel_consumption_per_100km, const float
	envImpactFee) {
	float fuelcost;
	fuelcost = (distance / 100) * average_fuel_consumption_per_100km * gasPrice;
	if (fuelcost > 2700) {
		fuelcost = fuelcost / 2;
	}
	return fuelcost + envImpactFee * distance;
}

float calculateTieredDistanceRate(float basePrice, float distance,
	string type) {
	if (type == "Bus") {
		if (distance <= 100) {
			return basePrice;
		}
		else if (distance <= 200) {
			return basePrice * 1.05;
		}
		else if (distance <= 300) {
			return basePrice * 1.1;
		}
		else {
			return basePrice * 1.15;
		}
	}
	if (type == "Train") {
		if (distance <= 100) {
			return basePrice;
		}
		else if (distance <= 200) {
			return basePrice * 1.1;
		}
		else if (distance <= 300) {
			return basePrice * 1.15;
		}
		else {
			return basePrice * 1.30;
		}
	}
	else {
		return 0;
	}
}


float applyEarlyBookingDiscount(float cost, int daysInAdvance) {
	if (daysInAdvance >= 30) {
		return cost * 0.9;
	}
	else {
		return cost;
	}
}


float applyDayOfWeekPricing(float cost, bool isWeekend) {
	if (isWeekend) {
		return cost * 1.1;
	}
	else {
		return cost;
	}
}

float calculateBusTrainCost(const float basePrice, const float
	distance, const int passengers, const int daysInAdvance, const bool
	isWeekend, string type) {
	return applyDayOfWeekPricing(applyEarlyBookingDiscount(calculateTieredDistanceRate(basePrice, distance, type) * passengers, daysInAdvance), isWeekend);

}

float findMin(float a, float b, float c, float d) {
	if (a < b) {
		if (a < c) {
			if (a < d) {
				return a;
			}
			else {
				return d;
			}
		}
		else if (c < d) {
			return c;
		}
		else {
			return d;
		}
	}
	else if (b < c) {
		if (b < d) {
			return b;
		}
		else {
			return d;
		}
	}
	else if (c < d) {
		return c;
	}
	else {
		return d;
	}

}

int main() {
	cout << fixed << setprecision(2);
	string startCity;
	string destinationCity;
	float distance;
	float gasPrice;
	int passengers;
	int daysInAdvance;
	bool isWeekend;
	float a, b, c, d;
	float retur;
	getTripDetails(startCity, destinationCity, distance, gasPrice, passengers, daysInAdvance, isWeekend);
	a = calculateCarCost(distance, gasPrice, 7.9, calculateEnvironmentalFee(distance, 7.9));
	cout << "Cost for Car 1: " << a << " TL" << endl;
	b = calculateCarCost(distance, gasPrice, 8.2, calculateEnvironmentalFee(distance, 8.2));
	cout << "Cost for Car 2: " << b << " TL" << endl;
	c = calculateBusTrainCost(510, distance, passengers, daysInAdvance, isWeekend, "Bus");
	cout << "Cost for Bus: " << c << " TL" << endl;
	d = calculateBusTrainCost(470, distance, passengers, daysInAdvance, isWeekend, "Train");
	cout << "Cost for Train: " << d << " TL" << endl;
	retur = findMin(a, b, c, d);
	if (retur == a) {
		cout << "The most cost-effective transportation option to travel from " << startCity
			<< " to " << destinationCity << ": Car 1 with a cost of " << a << " TL";
	}
	if (retur == b) {
		cout << "The most cost-effective transportation option to travel from " << startCity
			<< " to " << destinationCity << ": Car 2 with a cost of " << b << " TL";
	}
	if (retur == c) {
		cout << "The most cost-effective transportation option to travel from " << startCity
			<< " to " << destinationCity << ": Bus with a cost of " << c << " TL";
	}
	if (retur == d) {
		cout << "The most cost-effective transportation option to travel from " << startCity
			<< " to " << destinationCity << ": Train with a cost of " << d << " TL";
	}

}
