#include "Player.h"
#include <cstdlib>
#include <numeric>
#include <algorithm>

using namespace std;

Player::Player(ImageSource & source) : source(source), indices(source.getFramesCount()), indicesToIndices(source.getFramesCount()) {
	iota(indices.begin(), indices.end(), 0);
	iota(indicesToIndices.begin(), indicesToIndices.end(), 0);
}

void Player::update(double deltaTimeMs) {
	if (!this->plays()) return;

	this->elapsedTime += deltaTimeMs;
	auto timePerFrame = this->getTimePerFrame();

	if (this->elapsedTime >= timePerFrame) {
		this->currentIndexToIndex += this->elapsedTime / timePerFrame;
		this->currentIndexToIndex %= this->getPlayableFramesCount();
		this->currentIndex = this->indicesToIndices[this->currentIndexToIndex];
		this->elapsedTime -= (this->elapsedTime / timePerFrame) * timePerFrame;
	}
}

const Frame & Player::getFrame() {
	return this->source.getFrame(this->indices.at(this->currentIndex));
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

bool Player::plays() const {
	return this->playing;
}

double Player::getTotalTime() const {
	return (this->getPlayableFramesCount()) * this->getTimePerFrame();
}

double Player::getTimePerFrame() const {
	return (1000.0 / (this->fps * this->speed));
}

void Player::nextFrame() {
	++this->currentIndex;
	this->currentIndex %= this->indices.size();

	auto it = lower_bound(this->indicesToIndices.begin(), this->indicesToIndices.end(), this->currentIndex);
	this->currentIndexToIndex = (size_t) (it - this->indicesToIndices.begin());
}

void Player::prevFrame() {
	if (this->currentIndex-- == 0) {
		this->currentIndex = this->indices.size() - 1;
	}

	auto it = lower_bound(this->indicesToIndices.begin(), this->indicesToIndices.end(), this->currentIndex);
	this->currentIndexToIndex = (size_t) (it - this->indicesToIndices.begin());
}

void Player::skipFrame(size_t index) {
	if (index >= this->source.getFramesCount()) {
		throw exception();
	}

	if (!this->isSkipped(index)) {
		auto it = lower_bound(this->indicesToIndices.begin(), this->indicesToIndices.end(), index);
		this->indicesToIndices.erase(it);
	}
}

void Player::unskipFrame(size_t index) {
	if (index >= this->source.getFramesCount()) {
		throw exception();
	}

	if (this->isSkipped(index)) {
		this->indicesToIndices.emplace(
			lower_bound(this->indicesToIndices.begin(), this->indicesToIndices.end(), index),
			index
		);
	}
}

void Player::swapFrames(size_t first, size_t second) {
	if (max(first, second) >= this->indices.size()) {
		throw exception();
	}
	if (first == second) {
		return;
	}

	auto tmp = this->indices[first];
	this->indices[first] = this->indices[second];
	this->indices[second] = tmp;
}

size_t Player::getCurrentIndex() const {
	return this->currentIndex;
}

size_t Player::getFramesCount() const {
	return this->indices.size();
}

size_t Player::getPlayableFramesCount() const {
	return this->indicesToIndices.size();
}

bool Player::isSkipped() const {
	return this->isSkipped(this->getCurrentIndex());
}

bool Player::isSkipped(size_t index) const {
	if (index >= this->source.getFramesCount()) {
		throw exception();
	}

	return !binary_search(this->indicesToIndices.begin(), this->indicesToIndices.end(), index);
}
