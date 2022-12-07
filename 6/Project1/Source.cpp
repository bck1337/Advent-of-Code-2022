#include<fstream>
#include<string>

int main() {
	std::ifstream file = std::ifstream("input.txt");
	std::string line = "";
	std::string buffer = "";
	bool unique = false;
	//Part 1
	//int finder = 3;
	
	//Part 2
	int finder = 13;
	if (!file.is_open()) {
		return 1;
	}
	std::getline(file, line);
	while (finder < line.length()) {
		//Part 1
		//buffer = line.substr((finder - 3), 4);
		
		//Part 2
		buffer = line.substr((finder - 13), 14);
		for (const auto& marker : buffer) {
			if (buffer.find(marker) == buffer.find_last_of(marker)) {
				unique = true;
			}
			else {
				unique = false;
				break;
			}
		}
		if (unique) return (finder + 1);
		finder++;
	}
	return 0;
}