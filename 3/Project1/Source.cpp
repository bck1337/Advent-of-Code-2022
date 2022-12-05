#include<string>
#include<fstream>

int main() {
	std::ifstream file = std::ifstream("input.txt");
	std::string line;
	std::string first_string;
	std::string last_string;
	unsigned char prio_test;
	int both = 0;
	if (file.is_open()) {
		std::getline(file,line);
		while (!file.eof()) {
			first_string = line.substr(0,line.length()/2);
			last_string = line.substr(line.length() / 2, line.length() / 2);
			for (int i = 0; i < first_string.length()-1; i++) {
				prio_test = first_string.at(i);
				if (last_string.find(prio_test) != -1) {
					if (prio_test > 96) {
						both += (prio_test - 96);
					}
					else {
						both += (prio_test - 38);
					}
				}
				if () {
					if (first_string.find(prio_test, i + 1) != -1) {
						if (prio_test > 96) {
							both -= (prio_test - 96);
						}
						else {
							both -= (prio_test - 38);
						}
					}
				}
			}
			std::getline(file, line);
		}
		return 0;
	}
	return 1;
}