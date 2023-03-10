#include <iostream>
#include<iomanip>
#include <string>
#include <fstream>
using namespace std;

class inventory
{
	char name[34];
	int code;
	float cost;
public:
	void readdata();
	void writedata();
};

void inventory::readdata()
{
	cout << "Enter Name : "; cin >> name;
	cout << "Enter Code : "; cin >> code;
	cout << "Enter Cost : "; cin >> cost;
}
void inventory::writedata()
{
	cout << setiosflags(ios::left)
		<< setw(10) << name
		<< setiosflags(ios::right)
		<< setw(10) << code
		<< setprecision(2)
		<< setw(10) << cost
		<< endl;
}
int main()
{
	inventory item[3];
	fstream file;
	file.open("stack.dat", ios::in | ios::out);

	cout << "Enter the details for the three items: \n";
	for (int i = 0; i < 3; i++)
	{
		item[i].readdata();
		file.write((char*)&item[i], sizeof(item[i]));
	}
	file.seekg(0);
	cout << "\n\n Output of the Results\n";
	for (int i = 0; i < 3; i++)
	{
		file.read((char*)&item[i], sizeof(item[i]));
		item[i].writedata();
	}
	file.close();
	return 0;
}