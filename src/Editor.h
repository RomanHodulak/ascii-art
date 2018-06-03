#ifndef ASCII_ART_EDITOR_H
#define ASCII_ART_EDITOR_H

#include <ncurses.h>
#include <string>
#include <vector>

using namespace std;

/**
 * ASCII animation player and editor with simple UI. Renders to terminal via ncurses library.
 */
class Editor {
public:

	/**
	 * Runs the editor. Editor keeps running until user quits it (by pressing ESC).
	 *
	 * @tparam Iterator Forward iterator of strings.
	 * @param files File names to load and display in the editor.
	 */
	template <typename Iterator>
	void run(Iterator filesBegin, Iterator filesEnd);

	/**
	 * Releases allocated resources and closes ncurses window.
	 */
	~Editor();
};

#include "Editor.tpp"

#endif //ASCII_ART_EDITOR_H
