#include "SQF/Functions/StringFunctions.h"
#include "Utilities/Utilities.h"

namespace StringFunctions {

	QString stringLength(const SQFObject & arguments, int outputSize) {
		QString result(QString::number(arguments.getValue().length()));

		return result;
	}
	
	QString compareStrings(const SQFObject & arguments, int outputSize) {
		if(!arguments.isArray()) {
			return QString();
		}
		if(arguments.numberOfElements() < 2 || arguments.numberOfElements() > 3) {
			return QString();
		}

		const QString & a = arguments.getElement(0)->getValue();
		const QString & b = arguments.getElement(1)->getValue();

		bool caseSensitive = true;
		bool valid = true;

		if(arguments.numberOfElements() == 3) {
			caseSensitive = arguments.getElement(2)->getValueAsBoolean(&valid);

			if(!valid) {
				return QString();
			}
		}

		QString result(QString::number(Utilities::compareStrings(a, b, caseSensitive)));

		return result;
	}

	QString compareStringsIgnoreCase(const SQFObject & arguments, int outputSize) {
		if(!arguments.isArray()) {
			return QString();
		}
		if(arguments.numberOfElements() != 2) {
			return QString();
		}

		const QString & a = arguments.getElement(0)->getValue();
		const QString & b = arguments.getElement(1)->getValue();

		QString result(QString::number(Utilities::compareStringsIgnoreCase(a, b)));

		return result;
	}

	QString matchString(const SQFObject & arguments, int outputSize) {
		if(!arguments.isArray()) {
			return QString();
		}
		if(arguments.numberOfElements() != 2) {
			return QString();
		}

		const QString & string = arguments.getElement(0)->getValue();
		const QRegExp regExp(arguments.getElement(1)->getValue());

		QString result(string.contains(regExp) ? "true" : "false");

		return result;
	}
	
	QString toLowerCase(const SQFObject & arguments, int outputSize) {
		QString result(SQFObject(arguments.getValue().toLower()).toSQF());

		return result;
	}
	
	QString toUpperCase(const SQFObject & arguments, int outputSize) {
		QString result(SQFObject(arguments.getValue().toUpper()).toSQF());

		return result;
	}

	QString trimString(const SQFObject & arguments, int outputSize) {
		QString result(SQFObject(arguments.getValue().trimmed()).toSQF());

		return result;
	}
	
	QString substring(const SQFObject & arguments, int outputSize) {
		if(!arguments.isArray()) {
			return QString();
		}
		if(arguments.numberOfElements() != 3) {
			return QString();
		}

		bool valid = true;

		const QString & string = arguments.getElement(0)->getValue();

		int start = arguments.getElement(1)->getValueAsInteger(&valid);
		if(!valid) {
			return QString();
		}

		int end = arguments.getElement(2)->getValueAsInteger(&valid);
		if(!valid) {
			return QString();
		}

		QString result(SQFObject(Utilities::substring(string, start, end)).toSQF());

		return result;
	}

	QString splitString(const SQFObject & arguments, int outputSize) {
		if(!arguments.isArray()) {
			return QString();
		}
		if(arguments.numberOfElements() != 2) {
			return QString();
		}

		const QString & string = arguments.getElement(0)->getValue();
		const QRegExp regExp(arguments.getElement(1)->getValue());

		QString result(SQFObject(string.split(regExp, QString::SkipEmptyParts)).toSQF());

		return result;
	}

	QString replaceString(const SQFObject & arguments, int outputSize) {
		if(!arguments.isArray()) {
			return QString();
		}
		if(arguments.numberOfElements() != 3) {
			return QString();
		}

		const QString & string = arguments.getElement(0)->getValue();
		const QRegExp regExp(arguments.getElement(1)->getValue());
		const QString & replacement = arguments.getElement(2)->getValue();

		QString result(SQFObject(QString(string).replace(regExp, replacement)).toSQF());

		return result;
	}

}
