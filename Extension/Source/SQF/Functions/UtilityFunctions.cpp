#include <time.h>
#include "SQF/Functions/UtilityFunctions.h"
#include "Utilities/Utilities.h"

namespace UtilityFunctions {

	QString systemTime(const SQFObject & arguments, int outputSize) {
		time_t now;
		time(&now);
		
		return QString::number(now);
	}

	QString randomInteger(const SQFObject & arguments, int outputSize) {
		if(!arguments.isArray()) {
			return QString();
		}
		if(arguments.numberOfElements() != 2) {
			return QString();
		}

		bool valid = true;
		
		int min = arguments.getElement(0)->getValueAsInteger(&valid);
		if(!valid) {
			return QString();
		}

		int max = arguments.getElement(1)->getValueAsInteger(&valid);
		if(!valid) {
			return QString();
		}

		QString result(QString::number(Utilities::randomInteger(min, max)));

		return result;
	}
	
	QString randomFloat(const SQFObject & arguments, int outputSize) {
		if(!arguments.isArray()) { return QString(); }
		if(arguments.numberOfElements() != 2) { return QString(); }

		bool valid = true;
		
		int min = arguments.getElement(0)->getValueAsFloat(&valid);
		if(!valid) { return QString(); }

		int max = arguments.getElement(1)->getValueAsFloat(&valid);
		if(!valid) { return QString(); }

		QString result(QString::number(Utilities::randomFloat(min, max)));

		return result;
	}

}
