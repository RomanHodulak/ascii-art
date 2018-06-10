#include "Editor.h"

Editor::Editor() {
	this->keyMap[KEY_SPACE] = &Editor::commandTogglePlay;
	this->keyMap[KEY_SPACE & CTRL_MASK] = &Editor::commandTogglePlayBackwards;
	this->keyMap['f'] = &Editor::commandFpsInc;
	this->keyMap['f' & CTRL_MASK] = &Editor::commandFpsDec;
	this->keyMap[KEY_ESC] = &Editor::commandExit;
	this->keyMap[KEY_UP] = &Editor::commandUp;
	this->keyMap[KEY_DOWN] = &Editor::commandDown;
	this->keyMap[KEY_LEFT] = &Editor::commandLeft;
	this->keyMap[KEY_RIGHT] = &Editor::commandRight;
	this->keyMap[KEY_DC] = &Editor::commandDelete;
	this->keyMap['x'] = &Editor::commandSkipFrame;
	this->keyMap['s'] = &Editor::commandSwapFrame;
	this->keyMap['a'] = &Editor::commandShowFilterMenu;
	this->keyMap['\r'] = &Editor::commandAccept;
	this->keyMap['\n'] = &Editor::commandAccept;
}

void Editor::commandTogglePlay() {
	this->player->togglePlay();
}

void Editor::commandTogglePlayBackwards() {
	this->player->togglePlayBackwards();
}

void Editor::commandExit() {
	this->running = false;
}

void Editor::commandUp() {
	this->panel->up();
}

void Editor::commandDown() {
	this->panel->down();
}

void Editor::commandLeft() {
	this->player->prevFrame();
}

void Editor::commandRight() {
	this->player->nextFrame();
}

void Editor::commandShowFilterMenu() {
	this->filterMenuVisible = true;
	this->overridenKeyMap[KEY_UP] = &Editor::commandFilterMenuUp;
	this->overridenKeyMap[KEY_DOWN] = &Editor::commandFilterMenuDown;
	this->overridenKeyMap['\r'] = &Editor::commandFilterMenuAccept;
	this->overridenKeyMap['\n'] = &Editor::commandFilterMenuAccept;
	this->overridenKeyMap[KEY_ESC] = &Editor::commandCloseFilterMenu;
	this->overridenKeyMap['a'] = &Editor::commandCloseFilterMenu;
}

void Editor::commandCloseFilterMenu() {
	this->filterMenuVisible = false;
	this->overridenKeyMap.clear();
	this->clearArea(this->filterMenu->getRect());
}

void Editor::commandFilterMenuAccept() {
	this->filterMenu->accept();
	this->commandCloseFilterMenu();
}

void Editor::commandFilterMenuUp() {
	this->filterMenu->up();
}

void Editor::commandFilterMenuDown() {
	this->filterMenu->down();
}

void Editor::clearArea(const Rectangle & rectangle) {
	this->clearRect = new Rectangle(rectangle);
}

void Editor::commandDelete() {
	this->panel->deleteSelected();
}

void Editor::commandAccept() {
	if (this->panel->editSelected()) {
		this->overridenKeyMap[KEY_UP] = &Editor::commandEditFilterUp;
		this->overridenKeyMap[KEY_DOWN] = &Editor::commandEditFilterDown;
		this->overridenKeyMap['\r'] = &Editor::commandLeaveFilterEdit;
		this->overridenKeyMap['\n'] = &Editor::commandLeaveFilterEdit;
	}
}

void Editor::commandEditFilterUp() {
	this->panel->editInc();
}

void Editor::commandEditFilterDown() {
	this->panel->editDec();
}

void Editor::commandLeaveFilterEdit() {
	this->panel->leaveEditMode();
	this->overridenKeyMap.clear();
}

void Editor::commandSkipFrame() {
	this->player->toggleSkippedFrame();
}

void Editor::commandSwapFrame() {
	this->player->swapFrame();
}

void Editor::commandFpsInc() {
	this->player->fpsInc();
}

void Editor::commandFpsDec() {
	this->player->fpsDec();
}

Editor::~Editor() {
	endwin();
	delete this->clearRect;
	delete this->player;
	delete this->panel;
	delete this->filterMenu;
}
