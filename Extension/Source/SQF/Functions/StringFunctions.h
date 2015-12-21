#ifndef STRING_FUNCTIONS_H
#define STRING_FUNCTIONS_H

#include <QString.h>
#include "Extension.h"
#include "SQF/SQFObject.h"

namespace StringFunctions {

	QString stringLength(const SQFObject & arguments, int outputSize);
	QString compareStrings(const SQFObject & arguments, int outputSize);
	QString compareStringsIgnoreCase(const SQFObject & arguments, int outputSize);
	QString matchString(const SQFObject & arguments, int outputSize);
	QString toLowerCase(const SQFObject & arguments, int outputSize);
	QString toUpperCase(const SQFObject & arguments, int outputSize);
	QString trimString(const SQFObject & arguments, int outputSize);
	QString substring(const SQFObject & arguments, int outputSize);
	QString splitString(const SQFObject & arguments, int outputSize);
	QString replaceString(const SQFObject & arguments, int outputSize);

}

#endif // STRING_FUNCTIONS_H
