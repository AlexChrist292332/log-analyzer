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
		std::cerr << "Error: cannot open " << argv[1] << "\n";
		return 1;
	}

	std::string line; 
	std::size_t line_count = 0;
	const std::string error_keyword = "ERROR";
	std::size_t error_count = 0;
	while(std::getline(file, line)) {
		++line_count;
		if (line.find(error_keyword) != std::string::npos) {
			std::cout << "Error encountered at the line " << line_count << "\n\t" << line << "\n";
			++error_count;
		}	
	}

	std::cout << "Total lines: " << line_count << "\n";
	std::cout << "Total errors: " << error_count << "\n";
	
	return 0;
}
