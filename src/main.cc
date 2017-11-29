#include <iostream>
#include <string>
#include <vector>
#include "Editor.h"

using namespace std;

int main(int argc, char* argv[]) {

	vector<string> args(argv+1,argv+argc);

	vm::Editor editor(args);
	int exitStatus = editor.run();
	return exitStatus;
}
