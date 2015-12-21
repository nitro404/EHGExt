#include <math.h>
#include "Math/ExtendedMath.h"

namespace Math {
	
	const float PI        = 3.14159265358979323846f;
	const float HalfPI    = 1.57079632679489661923f;
	const float QuarterPI = 0.78539816339744830962f;
	const float TwoPI     = 6.28318530717958647693f;
	const float E         = 2.71828182845904523536f;
	const float Log10E    = 6.25907521676639521102f;
	const float Log2E     = 1.8841693853637201099f;
	
	float min(float a, float b) {
		return a < b ? a : b;
	}

	float max(float a, float b) {
		return a > b ? a : b;
	}

	float clamp(float value, float min, float max) {
		return value < min ? min : value > max ? max : value;
	}

	float abs(float v) {
		return v < 0.0f ? 0.0f - v : v;
	}

	float distance(float a, float b) {
		return abs(b - a);
	}

	float radiansToDegrees(float r) {
		return r * (180.0f / PI);
	}

	float degreesToRadians(float d) {
		return d * (PI / 180.0f);
	}

	int compareAngles(float a, float b) {
		if(a == b) { return 0; }
		
		float c = fmod(a, 360.0f);
		float d = fmod(b, 360.0f);
		if(c < 0.0f) { c += 360.0f; }
		if(d < 0.0f) { d += 360.0f; }
		if(c == d) { return 0; }

		double angleComparison = cos(degreesToRadians(a - b) + (PI / 2.0f));
		return angleComparison < 0.0 ? -1 : angleComparison > 0.0 ? 1 : 0;
	}

	float lerp(float a, float b, float amount) {
			 if(amount == 0.0f) { return a; }
		else if(amount == 1.0f) { return b; }

		return a + (b - a) * amount;
	}

	float normalize(float value, float min, float max) {
		return (value - min) / (max - min);
	}

}
