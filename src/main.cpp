#include "Editor.h"

int main(int argc, char * argv []) {
	setlocale(LC_ALL, "");
	Editor editor;
	vector<string> files;

	for (int i = 1; i < argc; ++i) {
		files.emplace_back(argv[i]);
	}

	editor.run(files.begin(), files.end());
}
