template <typename Iterator>
void Editor::run(Iterator filesBegin, Iterator filesEnd) {
	if (!initscr()) {
		return;
	}

	noecho();
	raw();
	printw("Zadávání znaků ukončíte klávesou Enter:\n");

	refresh();
	char ch;
	do {
		ch = (char) getch();
		printw("ch = %c\n", ch);
		refresh();
	} while (ch != '\0' && ch != '\n');
}
