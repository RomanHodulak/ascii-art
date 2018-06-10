#include <iostream>
#include "Editor.h"

int main(int argc, char * argv []) {
	if (argc < 3) {
		std::cout << "Usage: " << argv[0] << " <map> <image> [more_images...]" << std::endl;

		return EXIT_SUCCESS;
	}

	setlocale(LC_ALL, "");
	vector<string> files;

	for (int i = 2; i < argc; ++i) {
		files.emplace_back(argv[i]);
	}

	try {
		Editor editor;
		editor.run(argv[1], files.begin(), files.end());

		return EXIT_SUCCESS;
	}
	catch (const InvalidFileException & e) {
		std::cout << e.what() << std::endl;

		return EXIT_FAILURE;
	}
}
