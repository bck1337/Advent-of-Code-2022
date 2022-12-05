#include<fstream>
#include<string>
#include<iostream>
int main() {
	std::ifstream file = std::ifstream("input1.txt");
	if (file.is_open()) {
		std::string line;
		std::getline(file, line);
		int bag = 0;
		int max = 0;
		int second = 0;
		int third = 0;
		while (!file.eof()){
			if (line != "") {
				bag += std::stoi(line);
				if (bag > max) {
					max = bag;
				}
				else if (bag > second) {
					second = bag;
				}
				else if (bag > third) {
					third = bag;
				}
			}
			else {
				bag = 0;
			}
			std::getline(file, line);
		}	
		return (max+second+third);
	}
	file.close();
	return 1;
}