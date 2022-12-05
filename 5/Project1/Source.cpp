#include<vector>
#include<fstream>
#include<string>
#include<iostream>

int main() {
	std::ifstream file = std::ifstream("input.txt");
	std::string line = "";
	std::vector<std::vector<char>> ship = {};

	//Stack the crates
	std::vector<char> stack_1 = {'R','N','F','V','L','J','S','M'};
	std::vector<char> stack_2 = {'P','N','D','Z','F','J','W','H'};
	std::vector<char> stack_3 = {'W','R','C','D','G'};
	std::vector<char> stack_4 = {'N','B','S'};
	std::vector<char> stack_5 = {'M','Z','W','P','C','B','F','N'};
	std::vector<char> stack_6 = {'P','R','M','W'};
	std::vector<char> stack_7 = {'R','T','N','G','L','S','W'};
	std::vector<char> stack_8 = {'Q','T','H','F','N','B','V'};
	std::vector<char> stack_9 = {'L','M','H','Z','N','F'};

	//Load the ship
	ship.push_back(stack_1);
	ship.push_back(stack_2);
	ship.push_back(stack_3);
	ship.push_back(stack_4);
	ship.push_back(stack_5);
	ship.push_back(stack_6);
	ship.push_back(stack_7);
	ship.push_back(stack_8);
	ship.push_back(stack_9);

	//Part 1 Crane
	//char crane;
	
	//Part 2 Crane
	std::vector<char> crane = {};
	int count; int from; int to; int tall;
	if (!file.is_open()) return 1;
	//Skip input lines
	if (std::getline(file,line)) for (int i = 0; i < 9; i++) std::getline(file, line);

	while (std::getline(file, line)) {
		count = stoi(line.substr(line.find(' '), (line.find('f') - 1)));
		from = stoi(line.substr((line.find("from") + 5), (line.find("to") - 1))) - 1;
		to = stoi(line.substr((line.find("to") + 3), (line.length() - 1))) - 1;
		tall = ship[from].size();
		// Part 1 Mover
		/*for (int i = 1; i <= count; i++) {
			crane = ship[from][tall - i];
			ship.at(from).pop_back();
			ship.at(to).push_back(crane);
		}*/

		//Part 2 Mover
		for (int i = 1; i <= count; i++) {
			crane.push_back(ship[from][tall - i]);
			ship.at(from).pop_back();
		}
		for (int i = 1; i <= count; i++) {
			ship.at(to).push_back(crane.at(count-i));
			crane.pop_back();
		}
	}
	for (const auto& x : ship) std::cout << x.at(x.size() - 1) << std::endl;
	return 0;
}