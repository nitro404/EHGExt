#ifndef UTILITY_FUNCTIONS_H
#define UTILITY_FUNCTIONS_H

#include <QString.h>
#include "Extension.h"
#include "SQF/SQFObject.h"

namespace UtilityFunctions {

	QString systemTime(const SQFObject & arguments, int outputSize);
	QString randomInteger(const SQFObject & arguments, int outputSize);
	QString randomFloat(const SQFObject & arguments, int outputSize);

}

#endif // UTILITY_FUNCTIONS_H
