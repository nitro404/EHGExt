#ifndef MATH_FUNCTIONS_H
#define MATH_FUNCTIONS_H

#include <QString.h>
#include "Extension.h"
#include "SQF/SQFObject.h"

namespace MathFunctions {
	
	QString clampNumber(const SQFObject & arguments, int outputSize);
	QString distance(const SQFObject & arguments, int outputSize);
	QString radiansToDegrees(const SQFObject & arguments, int outputSize);
	QString degreesToRadians(const SQFObject & arguments, int outputSize);
	QString compareAngles(const SQFObject & arguments, int outputSize);
	QString lerp(const SQFObject & arguments, int outputSize);
	QString normalizeNumber(const SQFObject & arguments, int outputSize);
	QString normalizeVector(const SQFObject & arguments, int outputSize);

}

#endif // MATH_FUNCTIONS_H
