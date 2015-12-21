#include "SQF/Functions/MathFunctions.h"
#include "Utilities/Utilities.h"
#include "Math/ExtendedMath.h"
#include "Math/Vector2.h"
#include "Math/Vector3.h"
#include "Math/Vector4.h"

namespace MathFunctions {
	
	QString clampNumber(const SQFObject & arguments, int outputSize) {
		if(!arguments.isArray()) {
			return QString();
		}
		if(arguments.numberOfElements() != 3) {
			return QString();
		}
		
		bool valid = true;
		float * numbers = new float[3];

		for(int i=0;i<arguments.numberOfElements();i++) {
			numbers[i] = arguments.getElement(i)->getValueAsFloat(&valid);

			if(!valid) {
				delete [] numbers;

				return QString();
			}
		}

		QString result(SQFObject(Math::clamp(numbers[0], numbers[1], numbers[2])).toSQF());

		delete [] numbers;

		return result;
	}

	QString distance(const SQFObject & arguments, int outputSize) {
		if(!arguments.isArray()) {
			return QString();
		}
		if(arguments.numberOfElements() != 2) {
			return QString();
		}
		
		bool valid = true;
		float * numbers = new float[2];

		for(int i=0;i<arguments.numberOfElements();i++) {
			numbers[i] = arguments.getElement(i)->getValueAsFloat(&valid);

			if(!valid) {
				delete [] numbers;

				return QString();
			}
		}

		QString result(SQFObject(Math::distance(numbers[0], numbers[1])).toSQF());

		delete [] numbers;

		return result;
	}

	QString radiansToDegrees(const SQFObject & arguments, int outputSize) {
		if(!arguments.isArray()) {
			return QString();
		}
		if(arguments.numberOfElements() != 1) {
			return QString();
		}
		
		bool valid = true;
		float angle = arguments.getElement(0)->getValueAsFloat(&valid);

		if(!valid) {
			return QString();
		}

		QString result(SQFObject(Math::radiansToDegrees(angle)).toSQF());

		return result;
	}

	QString degreesToRadians(const SQFObject & arguments, int outputSize) {
		if(!arguments.isArray()) {
			return QString();
		}
		if(arguments.numberOfElements() != 1) {
			return QString();
		}
		
		bool valid = true;
		float angle = arguments.getElement(0)->getValueAsFloat(&valid);

		if(!valid) {
			return QString();
		}

		QString result(SQFObject(Math::degreesToRadians(angle)).toSQF());

		return result;
	}

	QString compareAngles(const SQFObject & arguments, int outputSize) {
		if(!arguments.isArray()) {
			return QString();
		}
		if(arguments.numberOfElements() != 2) {
			return QString();
		}
		
		bool valid = true;
		float * numbers = new float[2];

		for(int i=0;i<arguments.numberOfElements();i++) {
			numbers[i] = arguments.getElement(i)->getValueAsFloat(&valid);

			if(!valid) {
				delete [] numbers;

				return QString();
			}
		}

		QString result(SQFObject(Math::compareAngles(numbers[0], numbers[1])).toSQF());

		delete [] numbers;

		return result;
	}

	QString lerp(const SQFObject & arguments, int outputSize) {
		if(!arguments.isArray()) {
			return QString();
		}
		if(arguments.numberOfElements() != 3) {
			return QString();
		}
		
		bool valid = true;
		float * numbers = new float[3];

		for(int i=0;i<arguments.numberOfElements();i++) {
			numbers[i] = arguments.getElement(i)->getValueAsFloat(&valid);

			if(!valid) {
				delete [] numbers;

				return QString();
			}
		}

		QString result(SQFObject(Math::lerp(numbers[0], numbers[1], numbers[2])).toSQF());

		delete [] numbers;

		return result;
	}

	QString normalizeNumber(const SQFObject & arguments, int outputSize) {
		if(!arguments.isArray()) {
			return QString();
		}
		if(arguments.numberOfElements() != 3) {
			return QString();
		}
		
		bool valid = true;
		float * numbers = new float[3];

		for(int i=0;i<arguments.numberOfElements();i++) {
			numbers[i] = arguments.getElement(i)->getValueAsFloat(&valid);

			if(!valid) {
				delete [] numbers;

				return QString();
			}
		}

		QString result(SQFObject(Math::normalize(numbers[0], numbers[1], numbers[2])).toSQF());

		delete [] numbers;

		return result;
	}

	QString normalizeVector(const SQFObject & arguments, int outputSize) {
		if(!arguments.isArray()) {
			return QString();
		}
		if(arguments.numberOfElements() < 2 || arguments.numberOfElements() > 4) {
			return QString();
		}
		
		bool valid = true;
		float * vectorData = new float[arguments.numberOfElements()];

		for(int i=0;i<arguments.numberOfElements();i++) {
			vectorData[i] = arguments.getElement(i)->getValueAsFloat(&valid);

			if(!valid) {
				delete [] vectorData;

				return QString();
			}
		}

		QString result;

		if(arguments.numberOfElements() == 2) {
			result = QString(SQFObject(Vector2(vectorData).normalized()).toSQF());
		}
		else if(arguments.numberOfElements() == 3) {
			result = QString(SQFObject(Vector3(vectorData).normalized()).toSQF());
		}
		else if(arguments.numberOfElements() == 4) {
			result = QString(SQFObject(Vector4(vectorData).normalized()).toSQF());
		}

		delete [] vectorData;

		return result;
	}

}
