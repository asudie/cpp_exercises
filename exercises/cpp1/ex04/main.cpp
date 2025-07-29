#include <string>
#include <iostream>
#include <fstream>

std::string replaceAll(std::string line, const std::string& s1, const std::string& s2){
	if(s1.empty()) return line;
	size_t pos = 0;
	while((pos = line.find(s1, pos)) != std::string::npos){
		line = line.substr(0, pos) + s2 + line.substr(pos + s1.length()); 
		pos += s2.length();
	}
	return line;
}

int main(int argc, char** argv)
{
	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::ifstream inputFile(filename.c_str());
	if (!inputFile) {
		std::cerr << "Error opening input file." << std::endl;
		return 1;
	}
	std::ofstream outputFile((filename + ".replace").c_str());
	if (!outputFile) {
		std::cerr << "Error creating output file." << std::endl;
		return 1;
	}
	std::string line;
	while(std::getline(inputFile, line)) {
		outputFile << replaceAll(line, s1, s2) << '\n';
	}
	inputFile.close();
	outputFile.close();

	std::cout << "File copied successfully to " << filename + ".replace" << std::endl;

	return 0;

}