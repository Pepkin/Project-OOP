#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

bool inputFromFile() {
	char answer;
	do {
		cout << "Do you want to input data from a file y/n: ";
		cin >> answer;
		cin.ignore();
	} while (answer != 'y' && answer != 'n');

	if (answer == 'y') {
		return true;
	}
	else {
		return false;
	}
}

bool outputToFile() {
	char answer;
	do {
		cout << "Do you want to save your input in a file? y/n ";
		cin >> answer;
		cin.ignore();
	} while (answer != 'y' && answer != 'n');

	if (answer == 'y') {
		return true;
	}
	else {
		return false;
	}
}

float averageCalculator(int *arr, int b) {
	float average = 0.0;
	int *inputArray;
	inputArray = arr;
	int chosenNumber = b;
	int Counter = 0;
	

	for (int i = 0; i < chosenNumber; i++) {
		if (*inputArray % 2 == 0) { 
			average += *inputArray;
			Counter++;
			inputArray++;
		}
		else {
			inputArray++;
		}
	}
	return average / Counter;

}

void saveDataToFile(int *arr, int n, string fileName) {
	int *inputArr;
	inputArr = arr;
	int numbersGiven = n;
	int p = 5;
	int a = 5;
	ofstream import;
	import.open(fileName);
	for (int i = 0; i < numbersGiven; i++) {
		import << *inputArr << " ";
		inputArr++;
		if (i == p) {
			import << "\n";
			for (int j = p; j < (a + 6); j++) {
				p++;
			}
			a = p;
		}
	}
	import.close();
}

void linesWithPositiveIntegersCounter(string fileName) {
	ifstream infile(fileName);
	int a, b, c, d, e, f;
	int lineCount = 0;
	while (infile >> a >> b >> c >> d >> e >> f)
	{
		if (a > 0 && b > 0 && c > 0 && d > 0 && e > 0 && f > 0) {   
			cout << "Line number " << lineCount << " has only positive integers"<< endl;
			
		}
		lineCount++;
	}

	
}

string inputFileName() {
	string name;
	int number;
	cout << "From which file do you want to import the Data? " << endl;
	do {
		cout << "File #1" << endl;
		cout << "File #2" << endl;
		cout << "Option: ";
		cin >> number;
	} while (number != 1 && number != 2);
	
	if (number == 1) {
		name = "File No1.txt";
	}
	else {
		name = "File No2.txt";
	}

	return name;
}


int main() {
	
	int n = 0;
	int fileData[100];
	int inputArr[100];
	float average = 0.0;
	int fileNumbers = 0;
	bool answerForInputFormAFile = inputFromFile();
	
	
	if (answerForInputFormAFile) {
		string inputFile = inputFileName();
		ifstream File;
		File.open(inputFile);
		while (!File.eof())
		{
			File >> fileData[fileNumbers];
			fileNumbers++;
		}
	}
	else {
		cout << "\nEnter the needed amount of data inputs: ";
		cin >> n;
		while (cin.fail() || n <= 0) {
			cin.clear();
			cin.ignore();
			cout << "The input needs to be an integer higher than 0: ";
			cin >> n;
		}
		cout << "\nEnter numbers in the array:" << endl;
		for (int i = 0; i < n; i++) {
			cout << "#" << i + 1 << ":";
			cin >> inputArr[i];
			while (cin.fail()) {
				cin.clear();
				cin.ignore();
			}
		}
		
	}
	cout << "Your numbers are: ";
	if (answerForInputFormAFile) {
		for (int i = 0; i < fileNumbers; i++) {
			cout << fileData[i] << " ";
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			cout << inputArr[i] << " ";
		}
	}
	

	cout << "\nThe average of the even numbers is: ";
	if (answerForInputFormAFile) {
		cout << averageCalculator(fileData, fileNumbers) << endl;
	}
	else {
		cout << averageCalculator(inputArr, n) << endl;
	}
	
	string fileName;
	if (outputToFile()) {
		cout << "Enter the name of the file you want to save the data in: ";
		cin >> fileName;
		fileName = fileName + ".txt";
		if (answerForInputFormAFile) {
			saveDataToFile(fileData, fileNumbers, fileName);
		}
		else {
			saveDataToFile(inputArr, n, fileName);
		}
		
		cout << "Data saved!"<<endl;
	}

	linesWithPositiveIntegersCounter(fileName);

	return 0;
}