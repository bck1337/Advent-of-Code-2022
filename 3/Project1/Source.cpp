#include<string>
#include<fstream>
#include<algorithm>
#include<vector>

int main() {
	std::ifstream file = std::ifstream("input.txt");
	std::string line;
	std::string intersection = "";
	std::string badge = "";
	std::vector<std::string> part_2 = {};
	unsigned char prio_test;
	int both = 0;
	int elf = 0;
	if (!file.is_open()) {
		return 1;
	}
	while (std::getline(file, line)) {
		std::sort(line.begin(), line.end());
		auto last = std::unique(line.begin(), line.end());
		line.erase(last, line.end());
		part_2.push_back(line);
		elf++;
		if (elf == 3) {
			std::set_intersection(part_2[0].begin(), part_2[0].end(), part_2[1].begin(), part_2[1].end(), std::back_inserter(intersection));
			std::set_intersection(intersection.begin(), intersection.end(), part_2[2].begin(), part_2[2].end(), std::back_inserter(badge));
			for (int i = 0; i < badge.length(); i++) {
				prio_test = badge.at(i);
				if (prio_test > 96) {
					both += (prio_test - 96);
				}
				else {
					both += (prio_test - 38);
				}
			}
			intersection = "";
			badge = "";
			part_2.clear();
			elf = 0;
		}
	}		return both;
}