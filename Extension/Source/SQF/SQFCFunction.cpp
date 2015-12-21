#include "SQF/SQFCFunction.h"

SQFCFunction::SQFCFunction(QString (*function)(const SQFObject & arguments, int outputSize)) {
	m_function = function;
}

SQFCFunction::~SQFCFunction() {

}

QString SQFCFunction::execute(const SQFObject & arguments, int outputSize) {
	if(m_function == NULL) { return QString(); }

	return (*m_function)(arguments, outputSize);
}
