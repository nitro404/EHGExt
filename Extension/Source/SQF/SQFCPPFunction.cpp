#include "SQF/SQFCPPFunction.h"

SQFCPPFunction::SQFCPPFunction(const std::function<QString(const SQFObject & arguments, int outputSize)> & function)
	: m_function(function) {

}

SQFCPPFunction::~SQFCPPFunction() {

}

QString SQFCPPFunction::execute(const SQFObject & arguments, int outputSize) {
	return m_function(arguments, outputSize);
}
