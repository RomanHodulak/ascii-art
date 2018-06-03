#include "Player.h"

Player::Player(ImageSource & source) : source(source) {
}

void Player::update(unsigned long timestamp) {
	if (!this->playing) return;

	this->currentTime += timestamp;
}

const Frame & Player::getFrame() {
	double timePerFrame = (1000.0 / fps * speed);
	double totalTime = this->source.getFramesCount() * timePerFrame;
	this->currentTime %= (size_t) totalTime;
	size_t index = (size_t) (this->currentTime / timePerFrame);

	return this->source.getFrame(index);
}

void Player::changeSource(ImageSource & source) {
	this->source = source;
}

void Player::setFramesPerSecond(unsigned int fps) {
	this->fps = fps;
}

void Player::setSpeed(double speed) {
	this->speed = speed;
}

void Player::togglePlay() {
	this->playing = !this->playing;
}

bool Player::plays() {
	return this->playing;
}
