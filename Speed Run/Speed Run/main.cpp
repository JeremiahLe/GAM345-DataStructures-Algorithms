// basic file operations
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Convert a string to a number
int convertToNumber(string s)
{
	// Convert the string into a character array
	const char* charArray = s.c_str();
	// Convert the char array into a number
	int number = atoi(charArray);
	return number;
}

int main() {
	string line;
	ifstream myfile("Numbers.txt");
	if (!myfile.is_open())
	{
		cout << "Unable to open Numbers.txt";
		return 0;
	}
	// Read how many numbers there are
	getline(myfile, line);
	int numberCount = convertToNumber(line);

	// Reserve the space in the vector
	std::vector<int> numbers;
	numbers.reserve(numberCount);

	// Read the numbers into the vector
	getline(myfile, line); // Read the whole line
	stringstream ss(line);
	while (getline(ss, line, ' ')) {
		// Add the number to the vector
		numbers.push_back(convertToNumber(line));
	}

	// Finally, read the value to search for
	getline(myfile, line);
	int numberToFind = convertToNumber(line);

	// Close the file
	myfile.close();

	// See if the numberToFind is in the set of numbers
	std::vector<int>::iterator itr = std::find(numbers.begin(), numbers.end(), numberToFind);
	cout << (itr == numbers.end() ? "False" : "True") << endl;

	// Sort the vector
	std::sort(numbers.begin(), numbers.end());
	for (int i = 0; i < numbers.size()-1; i++)
	{
		if (numbers[i] == numbers[i + 1])
		{
			cout << "True" << endl;
			return 0;
		}
	}

	cout << "False" << endl;
	
	return 0;
}