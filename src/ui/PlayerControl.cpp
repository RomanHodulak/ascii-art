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

	if (this->player.getSpeed() < 0) {
		this->player.setSpeed(-this->player.getSpeed());
	}
}

void PlayerControl::togglePlayBackwards() {
	this->player.togglePlay();

	if (this->player.getSpeed() > 0) {
		this->player.setSpeed(-this->player.getSpeed());
	}
}

void PlayerControl::toggleSkippedFrame() {
	if (this->player.isSkipped()) {
		this->player.unskipFrame(this->player.getCurrentIndex());
	}
	else if (this->player.getPlayableFramesCount() > 1) {
		this->player.skipFrame(this->player.getCurrentIndex());
	}
}

void PlayerControl::swapFrame() {
	if (this->swapping) {
		this->player.swapFrames(this->swapped, this->player.getCurrentIndex());
		this->swapping = false;
	}
	else {
		this->swapped = this->player.getCurrentIndex();
		this->swapping = true;
	}
}

Control * PlayerControl::clone() const {
	return new PlayerControl(* this);
}

std::ostream & PlayerControl::print(std::ostream & out) {
	if (this->player.playsBackwards()) {
		out << "◀";
	}
	else if (this->player.plays()) {
		out << "▶";
	}
	else {
		out << "\u23F8";
	}

	out << "  FPS: " << this->player.getFramesPerSecond()
		<< "  Frame: " << (this->player.getCurrentIndex() + 1) << '/' << this->player.getFramesCount()
		<< (this->player.isSkipped()
			? " (skipped)"
	 		: "          ")
		<< (this->swapping
			? " (swapping frame " + std::to_string(this->swapped) + ", select other frame)"
	 		: "                                            ")
		<< std::endl;

	for (int i = 0; i < this->rect.width; ++i) {
		out << "═";
	}
	out << std::endl;

	return this->player.getFrame().print(out, this->printer, this->filter);
}

void PlayerControl::update(double deltaTime) {
	this->player.update(deltaTime);
}

void PlayerControl::fpsInc() {
	this->player.setFramesPerSecond(this->player.getFramesPerSecond() + 1);
}

void PlayerControl::fpsDec() {
	if (this->player.getFramesPerSecond() > 0) {
		this->player.setFramesPerSecond(this->player.getFramesPerSecond() - 1);
	}
}
