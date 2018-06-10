#ifndef ASCII_ART_PLAYERCONTROL_H
#define ASCII_ART_PLAYERCONTROL_H

#include "Control.h"
#include "../ImageSource.h"
#include "../Player.h"

class PlayerControl : public Control {
private:

	Player player;
	const AsciiPrinter & printer;
	const Filter & filter;
	size_t swapped = 0;
	bool swapping = false;

public:

	explicit PlayerControl(
		const Rectangle & rect,
		ImageSource & images,
		const AsciiPrinter & printer,
		const Filter & filter
	);

	void update(double deltaTimeMs);

	void nextFrame();

	void prevFrame();

	void togglePlay();

	void toggleSkippedFrame();

	void swapFrame();

	Control * clone() const override;

	std::ostream & print(std::ostream & out) override;

	void togglePlayBackwards();

	void fpsInc();

	void fpsDec();
};

#endif //ASCII_ART_PLAYERCONTROL_H
