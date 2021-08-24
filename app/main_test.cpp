#include <iostream>
#include <cstdlib>
#include <cmath>
#include "SimplexNoise.h"

int main(int argc, char **argv) {
	float scale     = 400.f;
	float offset_x  = 5.9f;
	float offset_y  = 5.1f;
	float offset_z  = 0.05f;
	float lacunarity    = 1.99f;
	float persistance   = 0.5f;
	const SimplexNoise noise(0.1f/scale, 0.5f, lacunarity, persistance); // Amplitude of 0.5 for the 1st octave : sum ~1.0f
	float_t min = 1.0,
			max = -1.0;
	for (size_t i = 0, len = std::atoi(argv[1]); i < len; i++) {
		for (; i % 10 < 9 && i < len; i++) {
			float_t val = noise.noise(i * 0.01f);
			val = (val + 1.0) / 2.0;
			if (min > val) min = val;
			if (max < val) max = val;
			std::cout << val << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << "Min \t" << min << std::endl;
	std::cout << "Max \t" << max << std::endl;
}
