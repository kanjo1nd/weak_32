#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Directory {
	string name;
	string owner;
	string number;
	string address;
	string activity;
public:
	Directory(const string& n, const string& o, const string& num, const string& addr, const string& act) : name(n), owner(o), number(num), address(addr), activity(act){}

	void SearchName(const string& n) {
		if (n == name) {
			cout << "Found: " << name << endl;
		}
		else {
			cout << "Not Found" << endl;
		}
	}
	void SearchNumber(const string& o) {
		if (o == owner) {
			cout << "Found: " << owner << endl;
		}
		else {
			cout << "Not Found" << endl;
		}
	}
	void SearchNumber(const string& num) const {
		if (num == number) {
			cout << "Found: " << number << endl;
		}
		else {
			cout << "Not Found" << endl;
		}
	}
	void SearchActivity(const string& act) {
		if (act == activity) {
			cout << "Found: " << activity << endl;
		}
		else {
			cout << "Not Found" << endl;
		}
	}
	void print() {
		cout << "Name: " << name << endl;
		cout << "Owner: " << owner << endl;
		cout << "Number: " << number << endl;
		cout << "Address: " << address << endl;
		cout << "Activity: " << activity << endl;
	}

	void SaveRecordToFile(ofstream& file) const {
		file << "Name: " << name << "\n"
			<< "Owner: " << owner << "\n"
			<< "Number: " << number << "\n"
			<< "Address: " << address << "\n"
			<< "Activity: " << activity << "\n"
			<< "---------------------------\n";
	}
};

int main() {
	Directory directory1("Company1", "Owner1", "123456789", "Address1", "Activity1");
	Directory directory2("Company2", "Owner2", "987654321", "Address2", "Activity2");

	directory1.print();
	directory2.print();

	ofstream file("directory.txt");
	if (!file) {
		cerr << "Error opening file for writing!" << endl;
		return 1;
	}

	directory1.SaveRecordToFile(file);
	directory2.SaveRecordToFile(file);

	file.close();
}