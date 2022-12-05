#include<fstream>
#include<string>

int main() {
	//Open file
	std::ifstream file = std::ifstream("input.txt");
	if (file.is_open()) {
		//Get the first line
		std::string line;
		std::getline(file, line);

		//Create scoring variables
		int round = 0;
		int total = 0;
		unsigned char oppmove;
		unsigned char yourmove;

		while (!file.eof()) {
			//Define played moves
			oppmove = line.at(0);
			yourmove = line.at(2);

			//To score, each set of moves will be divided, as each possible non-draw permutation produces a unique value.
			//Before division, each value is adjusted to its score. This also makes the division values easier to use.
			oppmove -= 64;
			yourmove -= 87;

			//Part 1 Switch
			/*
			round = int((float(oppmove) / float(yourmove) * 6));
			switch (round) {
				//Draw, any pair divides to 1, then is multiplied by 6 to convert all results to integers.
				case 6:
					round = yourmove + 3;
					break;
				//Win 1, Rock/Paper*6 -> 1/2*6 = 3  
				case 3:
					round = yourmove + 6;
					break;
				//Win 2, Paper/Scissors*6 -> 2/3*6 = 4
				case 4:
					round = yourmove + 6;
					break;
				//Win 3, Scissors/Rock*6 -> 3/1*6 = 18
				case 18:
					round = yourmove + 6;
					break;
				default:
					round = yourmove;
					break;
			}
			*/

			//Part 2 Switch
			switch (yourmove) {
				//Loss, the losing choice is 2 away from the opponents choice.
				case 1:
					yourmove = (oppmove + 2) % 3;
					if (yourmove == 0) yourmove = 3;
					round = 0 + yourmove;
					break;
				case 2:
				//Draw, just add 3 to the opponents choice to find the score.
					round = 3 + oppmove;
					break;
				default:
				//Win, the winning choice is 1 away from the opponents choice.
					yourmove = (oppmove + 1) % 3;
					if (yourmove == 0) yourmove = 3;
					round = 6 + yourmove;
					break;
			}
			//Add each round score to the total score
			total += round;

			//Get next line
			std::getline(file, line);
		}
		return total;
	}
	return 1;
}