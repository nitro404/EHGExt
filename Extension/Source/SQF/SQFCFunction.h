#ifndef SQF_C_FUNCTION_H
#define SQF_C_FUNCTION_H

#include <QString.h>
#include "Extension.h"
#include "SQF/SQFFunction.h"

class SQFCFunction : public SQFFunction {
public:
	SQFCFunction(QString (*function)(const SQFObject & arguments, int outputSize));
	virtual ~SQFCFunction();

	virtual QString execute(const SQFObject & arguments, int outputSize);

protected:
	QString (*m_function)(const SQFObject & arguments, int outputSize);
};

#endif // SQF_C_FUNCTION_H
