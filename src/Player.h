#ifndef ASCII_ART_PLAYER_H
#define ASCII_ART_PLAYER_H

#include <sys/types.h>
#include "ImageSource.h"

/**
 * Determines what frame to render at a certain time. Time is measured in milliseconds.
 */
class Player {
private:

	/** Source of the animation frames. */
	ImageSource & source;

	size_t currentIndexToIndex = 0;

	/** Index of the indices map, pointing to the current frame. */
	size_t currentIndex = 0;

	/** Time elapsed since the current frame in milliseconds. */
	double elapsedTime = 0;

	/** Frames per second. */
	uint fps = 12;

	/** Frames per second multiplier. */
	double speed = 1.0;

	/** TRUE if animation plays, FALSE if paused. */
	bool playing = false;

	/** Maps swapped frames to frames they have been swapped with by index. */
	std::vector<size_t> indices;

	/** Contains indices to indices map, excluding the skipped ones. */
	std::vector<size_t> indicesToIndices;

	/**
	 * Gets duration in milliseconds of the animation, excluding the skipped frames.
	 *
	 * @return Total time in milliseconds.
	 */
	double getTotalTime() const;

	/**
	 * Gets duration of a single frame of the animation.
	 *
	 * @return Time per frame in milliseconds.
	 */
	double getTimePerFrame() const;

public:

	/**
	 * @param source Source to get the image frames from. Source is referenced and can be modified freely outside of
	 * this instance.
	 */
	explicit Player(ImageSource & source);

	/**
	 * Updates the internal timer.
	 *
	 * @param deltaTimeMs Time in milliseconds since the previous update call.
	 */
	void update(double deltaTimeMs);

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
	void setFramesPerSecond(uint fps);

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
	bool plays() const;

	/**
	 * @return TRUE if animation plays in reverse, FALSE if paused.
	 */
	bool playsBackwards() const;

	/**
	 * Skips over to the next frame.
	 */
	void nextFrame();

	/**
	 * Rewinds to previous frame.
	 */
	void prevFrame();

	/**
	 * Sets frame that currently posses given index as skipped. It can still be manually displayed but it is skipped
	 * by the animation playback.
	 *
	 * @param index Index of the frame to skip.
	 */
	void skipFrame(size_t index);

	/**
	 * Reverts the effects of skipping the frame, if it is skipped.
	 *
	 * @param index Index of the frame to un-skip.
	 */
	void unskipFrame(size_t index);

	/**
	 * Swaps the two frames.
	 *
	 * @param first Frame to swap with the second.
	 * @param second Frame to swap with the first.
	 */
	void swapFrames(size_t first, size_t second);

	/**
	 * Gets current frame index.
	 *
	 * @return Current frame index.
	 */
	size_t getCurrentIndex() const;

	/**
	 * Gets total count of frames.
	 *
	 * @return Count of frames in the animation.
	 */
	size_t getFramesCount() const;

	/**
	 * Gets total count of frames, excluding the skipped ones.
	 *
	 * @return Count of frames in the animation displayed by the playback.
	 */
	size_t getPlayableFramesCount() const;

	/**
	 * Checks if current frame is skipped.
	 *
	 * @return TRUE if current frame is skipped, FALSE if not.
	 */
	bool isSkipped() const;

	/**
	 * Checks if a frame is skipped.
	 *
	 * @param index Index of the frame to check.
	 * @return TRUE if current frame is skipped, FALSE if not.
	 */
	bool isSkipped(size_t index) const;

	/**
	 * Gets the speed of playback. Sign of the value is a direction, positive means forwards, negative means backwards.
	 *
	 * @return The playback speed and direction.
	 */
	double getSpeed() const;

	/**
	 * Gets current FPS set.
	 *
	 * @return Frame per second used for playback.
	 */
	uint getFramesPerSecond() const;
};

#endif //ASCII_ART_PLAYER_H
