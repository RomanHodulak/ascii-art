#ifndef ASCII_ART_PLAYERCONTROL_H
#define ASCII_ART_PLAYERCONTROL_H

#include "Control.h"
#include "../ImageSource.h"
#include "../Player.h"

/**
 * Plays and renders animation, along with controls to modify the playback.
 */
class PlayerControl : public Control {
private:

	/** Handles playback logic. */
	Player player;

	/** Prints the frames. */
	const AsciiPrinter & printer;

	/** Reference to filter in use for rendering. */
	const Filter & filter;

	/** Index of the first swapped frame in the current swapping session. */
	size_t swapped = 0;

	/** Indicates if swapping session is active. TRUE indicates control awaits for user to pick second swapped frame. */
	bool swapping = false;

public:

	explicit PlayerControl(
		const Rectangle & rect,
		ImageSource & images,
		const AsciiPrinter & printer,
		const Filter & filter
	);

	/**
	 * Updates the player so it can display correct frame.
	 *
	 * @param deltaTimeMs Time since the previous update call in milliseconds.
	 */
	void update(double deltaTimeMs);

	/**
	 * Manually display following frame.
	 */
	void nextFrame();

	/**
	 * Manually display previous frame.
	 */
	void prevFrame();

	/**
	 * Toggle play/pause.
	 */
	void togglePlay();

	/**
	 * Toggle current frame as skipped/not skipped.
	 */
	void toggleSkippedFrame();

	/**
	 * Marks current frame as swapped. First call marks the first frame, second call the second frame to swap the first
	 * with.
	 */
	void swapFrame();

	Control * clone() const override;

	std::ostream & print(std::ostream & out) override;

	/**
	 * Toggle play/pause. When playing, play backwards.
	 */
	void togglePlayBackwards();

	/**
	 * Increments FPS by one.
	 */
	void fpsInc();

	/**
	 * Decrements FPS by one.
	 */
	void fpsDec();
};

#endif //ASCII_ART_PLAYERCONTROL_H
