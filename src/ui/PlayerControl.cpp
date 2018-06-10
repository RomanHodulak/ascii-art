#include "PlayerControl.h"

PlayerControl::PlayerControl(
	const Rectangle & rect,
	ImageSource & images,
	const AsciiPrinter & printer,
	const Filter & filter
) : Control(rect), player(images), printer(printer), filter(filter) {
}

void PlayerControl::nextFrame() {
	this->player.nextFrame();
}

void PlayerControl::prevFrame() {
	this->player.prevFrame();
}

void PlayerControl::togglePlay() {
	this->player.togglePlay();
}

void PlayerControl::toggleSkippedFrame() {

}

void PlayerControl::swapFrame() {
}

Control * PlayerControl::clone() const {
	return new PlayerControl(* this);
}

std::ostream & PlayerControl::print(std::ostream & out) {
	out << ' ' << (this->player.plays() ? "▶" : "\u23F8")
		<< "   Frame: " << this->player.getCurrentIndex() << '/' << this->player.getFramesCount()
		<< (this->player.isSkipped() ? " (skipped)" : "          ")
		<< std::endl;

	for (int i = this->rect.x; i < this->rect.width; ++i) {
		out << "═";
	}
	out << std::endl;

	return this->player.getFrame().print(out, this->printer, this->filter);
}

void PlayerControl::update(double deltaTime) {
	this->player.update(deltaTime);
}
