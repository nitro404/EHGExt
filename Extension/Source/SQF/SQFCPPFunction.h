#ifndef SQF_CPP_FUNCTION_H
#define SQF_CPP_FUNCTION_H

#include <functional>
#include <QString.h>
#include "Extension.h"
#include "SQF/SQFFunction.h"

class SQFCPPFunction : public SQFFunction {
public:
	SQFCPPFunction(const std::function<QString(const SQFObject & arguments, int outputSize)> & function);
	virtual ~SQFCPPFunction();

	virtual QString execute(const SQFObject & arguments, int outputSize);

protected:
	  std::function<QString(const SQFObject & arguments, int outputSize)> m_function;
};

#endif // SQF_CPP_FUNCTION_H
