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
	const std::string warn_keyword = "WARN";
	const std::string info_keyword = "INFO";

	std::size_t error_count = 0;
	std::size_t warn_count = 0;
	std::size_t info_count = 0;

	while(std::getline(file, line)) {
		++line_count;
		if (line.find(error_keyword) != std::string::npos) {
			std::cout << "Error encountered at the line " << line_count << "\n\t" << line << "\n";
			++error_count;
		} else if (line.find(warn_keyword) != std::string::npos) {
			std::cout << "Warning encountered at the line " << line_count << "\n\t" << line << "\n";
			++warn_count;
		} else if (line.find(info_keyword) != std::string::npos) {
			++info_count;
		}	
	}

	std::cout << "Total errors: " << error_count << "\n";
	std::cout << "Total warnings: " << warn_count << "\n";
	std::cout << "Total info lines: " << info_count << "\n";
	std::cout << "Total lines: " << line_count << "\n";
	return 0;
}
