#ifndef ASCII_ART_BRIGHTNESSFILTER_H
#define ASCII_ART_BRIGHTNESSFILTER_H

#include "Filter.h"

/**
 * Increases or decreases pixel brightness.
 */
class BrightnessFilter : public Filter {
private:

	/** Multiplies each channel. */
	double brightness = 1.0;

public:

	BrightnessFilter() = default;

	explicit BrightnessFilter(double brightness);

	/**
	 * Applies brightness multiplier to given pixel and prints it out.
	 *
	 * @param pixel Pixel to modify the brightness of.
	 * @return Pixel with increased or decreased brightness.
	 */
	Pixel apply(const Pixel & pixel) const override;

	/**
	 * Adjusts brightness applied.
	 *
	 * @param brightness Brightness value.
	 */
	void setBrightness(double brightness);

	/**
	 * Gets brightness set.
	 *
	 * @return Brightness.
	 */
	double getBrightness();

	std::string getName() const override;

	Filter * clone() const override;
};

#endif //ASCII_ART_BRIGHTNESSFILTER_H
