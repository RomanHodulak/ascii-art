#include "Editor.h"

int main(int argc, char * argv []) {
	setlocale(LC_ALL, "");
	Editor editor;
	vector<string> files;

	editor.run(files.begin(), files.end());
}
