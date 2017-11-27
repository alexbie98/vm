#include "util/FileWriter.h"

using namespace std;
namespace util {

void FileWriter::writeLines(const string& file, const vector<string>& lines) {
	ofstream outFile{file};
	for (const string& line: lines){
		outFile << line << endl;
	}		
}

}
