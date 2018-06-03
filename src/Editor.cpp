#include "Editor.h"

Editor::~Editor() {
	printw("Obnovuji nastavení terminálu\n");
	refresh();
	endwin();
}
