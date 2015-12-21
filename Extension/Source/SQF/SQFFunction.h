#ifndef SQF_FUNCTION_H
#define SQF_FUNCTION_H

#include <QString.h>
#include "Extension.h"
#include "SQF/SQFObject.h"

class SQFFunction {
public:
	virtual ~SQFFunction() { }

	virtual QString execute(const SQFObject & arguments, int outputSize) = 0;
};

#endif // SQF_FUNCTION_H
