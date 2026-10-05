#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <logfile>\n";
		return 1;
	}
	
	std::ifstream file(argv[1]);
	if (!file) {
		std::cerr << argv[1] << " is not found. Exiting the program...";
		return 1;
	}

	std::string line; 
	std::size_t line_count = 0;
	std::string target = "ERROR";

	while(std::getline(file, line)) {
		line_count++;
		if (line.find(target) != std::string::npos) {
			std:: cout << "Error encountered at the line " << line_count << "\n\t" << line << "\n";
		}	
	}

	std::cout << "Total lines: " << line_count << "\n";
	
	return 0;
}
