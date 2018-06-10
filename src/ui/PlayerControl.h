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
};

#endif //ASCII_ART_PLAYERCONTROL_H
