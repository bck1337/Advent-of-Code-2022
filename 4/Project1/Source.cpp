#include<algorithm>
#include<vector>
#include<string>
#include<fstream>

int main() {
	std::ifstream file = std:: ifstream("input.txt");
	std::string line = "";
	int first = 0;
	int second = 0;
	int third = 0;
	int fourth = 0;
	int count = 0;
	if (!file.is_open()) {
		return 1;
	}
	while (std::getline(file, line)) {
		first = std::stoi(line.substr(0, line.find("-")));
		second = std::stoi(line.substr((line.find("-") + 1), line.find(",")));
		third = std::stoi(line.substr((line.find(",") + 1), line.find_last_of("-")));
		fourth = std::stoi(line.substr((line.find_last_of("-") + 1), line.length() - 1));
		//Part One
		//if ((first >= third && second <= fourth)||(third >= first && fourth <= second))count++;
		
		//Part Two
		if (((first <= fourth && first >= third) || (second <= fourth && second >= third)) || ((first >= third && second <= fourth) || (third >= first && fourth <= second)))count++;
	}
	return count;
}