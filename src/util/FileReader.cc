#include "util/FileReader.h"
using namespace std;

namespace util {
	
vector<string> FileReader::readLines(const std::string& file){
	
	vector<string> lines;
	string line;
	
	ifstream myFile{file};
	while (getline(myFile, line)){
		lines.push_back(line);
	}
	return lines;
}

}
