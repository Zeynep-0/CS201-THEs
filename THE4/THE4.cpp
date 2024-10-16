
#include <iostream>
#include <string>
using namespace std;
#include<fstream>
#include <vector>
#include "strutils.h"


struct WeatherData {
	string date;
	double temperature = 0.0;
	double precipitation = 0.0;
};

WeatherData parseLine(const string& line) {
	int ind;
	WeatherData data;
	ind = line.find(",");
	data.date = line.substr(0, ind);
	int ind2;
	ind2 = line.rfind(",");
	data.temperature = atof(line.substr(ind + 2, ind2 - ind - 2));
	data.precipitation = atof(line.substr(ind2 + 2, line.length() - ind2 - 2));
	return data;

}

double averageTemperature(const vector<WeatherData>& data) {
	int count = 0;
	double sum = 0.0;
	for (int i = 0; i < data.size(); i++) {
		sum += data[i].temperature;
		count++;
	}
	if (count == 0) {
		return 0.0;
	}
	double average = sum / count;
	return average;
}
double totalPrecipitation(const vector<WeatherData>& data) {
	double sum = 0.0;
	int cnt = data.size();
	for (int i = 0; i < cnt; i++) {
		sum = sum + data[i].precipitation;
	}
	return sum;
}
WeatherData findExtremesTemperature(const vector<WeatherData>& data, bool findMax) {
	WeatherData maxx, minn;
	double max, min;
	vector<double> datass(data.size());
	for (int i = 0; i < data.size(); i++) {
		datass[i] = data[i].temperature;
	}
	if (findMax == true) {
		max = datass[0];
		for (int i = 0; i < datass.size(); i++) {
			if (max < datass[i]) {
				max = datass[i];
			}
		}
		for (int i = 0; i < datass.size(); i++) {
			if (max == datass[i]) {
				maxx = data[i];
			}
		}
		return maxx;
	}
	else {
		min = datass[0];
		for (int i = 0; i < datass.size(); i++) {
			if (min > datass[i]) {
				min = datass[i];
			}
		}
		for (int i = 0; i < datass.size(); i++) {
			if (min == datass[i]) {
				minn = data[i];
			}
		}
		return minn;
	}
}
WeatherData maxPrecipitation(const vector<WeatherData>& data) {
	WeatherData maxx;
	double max;
	vector<double> datass(data.size());
	for (int i = 0; i < data.size(); i++) {
		datass[i] = data[i].precipitation;
	}
	max = datass[0];
	for (int i = 0; i < datass.size(); i++) {
		if (max < datass[i]) {
			max = datass[i];
		}
	}
	for (int i = 0; i < datass.size(); i++) {
		if (max == datass[i]) {
			maxx = data[i];
		}
	}
	return maxx;

}
int countDryDays(const vector<WeatherData>& data) {
	int cnt = 0;
	vector<double> datass(data.size());
	for (int i = 0; i < data.size(); i++) {
		datass[i] = data[i].precipitation;
	}
	for (int i = 0; i < datass.size(); i++) {
		if (datass[i] == 0.0) {
			cnt++;
		}
	}

	return cnt;
}
string getFormattedDate(const string& date) {
	const string months[] = { "January", "February", "March",
"April", "May", "June", "July", "August", "September",
"October", "November", "December" };
	string year, mon, day, newdat;
	newdat = "";
	int idx = date.find("-");
	year = date.substr(0, idx);
	int idx2 = date.rfind("-");
	mon = date.substr(idx + 1, 2);
	day = date.substr(idx2 + 1, 2);
	int newmon = stoi(mon) - 1;
	newdat = months[newmon];
	newdat += " " + day + ", " + year;
	return newdat;
}
int main() {

	cout << "Welcome to the Weather Data Analysis Program!" << endl;
	cout << "1. Load data file" << endl;
	cout << "2. Display average temperature" << endl;
	cout << "3. Display total precipitation" << endl;
	cout << "4. Display the number of dry days" << endl;
	cout << "5. Display the hottest day" << endl;
	cout << "6. Display the coldest day" << endl;
	cout << "7. Display the day with the highest precipitation" << endl;
	cout << "8. Close the program" << endl << endl;
	cout << "Choose an option: ";
	int opt;
	cin >> opt;
	while (opt != 1 && opt != 8) {
		if (opt < 8 && opt>1) {
			cout << "Please load a data file first." << endl;
			cout << "Choose an option: ";
			cin >> opt;
		}
		else {
			cout << "Invalid option. Please enter a valid option. " << endl;
			cout << "Choose an option: ";
			cin >> opt;
		}
	}
	while (opt != 8) {
		string line;
		string filename;
		cout << "Enter the file name: ";
		cin >> filename;
		ifstream fileimp;
		fileimp.open(filename.c_str());
		if (fileimp.fail()) {
			cout << "Cannot open the file!" << endl;
			cout << "Choose an option: ";
			cin >> opt;
		}
		while (fileimp.fail()) {
			if (opt == 1) {
				cout << "Enter the file name: ";
				cin >> filename;
				fileimp.open(filename.c_str());
				if (fileimp.fail()) {
					cout << "Cannot open the file!" << endl;
					cout << "Choose an option: ";
					cin >> opt;
				}
			}
			while (1 < opt && opt < 8) {
				cout << "Please load a data file first." << endl;
				cout << "Choose an option: ";
				cin >> opt;
			}
			while (opt > 8 || opt < 1) {
				cout << "Invalid option. Please enter a valid option. " << endl;
				cout << "Choose an option: ";
				cin >> opt;
			}
			if (opt == 8) {
				break;
			}

		}
		if (opt == 8) {
			break;
		}
		cout << "Data loaded successfully." << endl;
		vector<WeatherData> data;
		WeatherData a;
		while (getline(fileimp, line)) {
			a = parseLine(line);
			data.push_back(a);
		}
		cout << "Choose an option: ";
		cin >> opt;
		if (opt == 8) {
			break;
		}

		while (opt != 8) {
			if (opt == 2) {
				cout << "Average Temperature: " << averageTemperature(data) << " Celsius";
			}
			else if (opt == 3) {
				cout << "Total Precipitation: " << totalPrecipitation(data) << " mm";
			}
			else if (opt == 4) {
				cout << "Number of Dry Days: " << countDryDays(data);
			}
			else if (opt == 5) {
				WeatherData a;
				a = findExtremesTemperature(data, true);
				double hot;
				string dat;
				dat = getFormattedDate(a.date);
				hot = a.temperature;
				cout << "Hottest Day: " << dat << " with " << hot << " Celsius";
			}
			else if (opt == 6) {
				WeatherData a;
				a = findExtremesTemperature(data, false);
				double hot;
				string dat;
				dat = getFormattedDate(a.date);
				hot = a.temperature;
				cout << "Coldest Day: " << dat << " with " << hot << " Celsius";
			}
			else if (opt == 7) {
				WeatherData a;
				a = maxPrecipitation(data);
				double hot;
				string dat;
				dat = getFormattedDate(a.date);
				hot = a.precipitation;
				cout << "Highest Precipitation Day: " << dat << " with " << hot << " mm";
			}
			else if (opt > 8 || opt < 1)
			{
				cout << "Invalid option. Please enter a valid option. ";
			}
			cout << endl << "Choose an option: ";
			cin >> opt;
		}


		fileimp.close();
	}cout << "Exiting program... ";

	return 0;
}
