#ifndef ASCII_ART_PLAYER_H
#define ASCII_ART_PLAYER_H

#include <cstdlib>
#include "ImageSource.h"

/**
 * Determines what frame to render at a certain time.
 */
class Player {
private:

	ImageSource & source;
	unsigned long currentTime = 0;
	unsigned int fps = 30;
	double speed = 1.0;
	bool playing = false;

public:

	/**
	 * @param source Source to get the image frames from. Source is referenced and can be modified freely outside of
	 * this instance.
	 */
	explicit Player(ImageSource & source);

	/**
	 * Updates the internal timer.
	 *
	 * @param timestamp Current timestamp.
	 */
	void update(unsigned long timestamp);

	/**
	 * Gets current frame.
	 *
	 * @return Current frame.
	 */
	const Frame & getFrame();

	/**
	 * Changes the animation source and resets the animation.
	 *
	 * @param source Source to change.
	 */
	void changeSource(ImageSource & source);

	/**
	 * Sets number of frame switches per second.
	 *
	 * @param fps FPS to set.
	 */
	void setFramesPerSecond(unsigned int fps);

	/**
	 * Sets play speed, which is effectively an FPS multiplier. Set negative value to play backwards, or zero to freeze.
	 *
	 * @param speed Speed to set.
	 */
	void setSpeed(double speed);

	/**
	 * Pauses if animation is playing, resumes if paused.
	 */
	void togglePlay();

	/**
	 * @return TRUE if animation plays, FALSE if paused.
	 */
	bool plays();
};

#endif //ASCII_ART_PLAYER_H
