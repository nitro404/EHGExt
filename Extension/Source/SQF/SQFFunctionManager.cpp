#include "SQF/SQFFunctionManager.h"
#include "Logger/Logger.h"

SQFFunctionManager::SQFFunctionManager() {

}

SQFFunctionManager::~SQFFunctionManager() {
	QMapIterator<QString, SQFFunction *> i(m_functions);
	while(i.hasNext()) {
		i.next();
		delete i.value();
	}
}

int SQFFunctionManager::numberOfFunctions() const {
	return m_functions.keys().size();
}

bool SQFFunctionManager::hasFunction(const char * name) const {
	if(name == NULL) { return false; }

	QString formattedName = formatFunctionName(name);
	if(formattedName.isEmpty()) { return false; }

	return m_functions.contains(formattedName);
}

bool SQFFunctionManager::hasFunction(const QString & name) const {
	QString formattedName = formatFunctionName(name);
	if(formattedName.isEmpty()) { return false; }

	return m_functions.contains(formattedName);
}

SQFFunction * SQFFunctionManager::getFunction(int index) const {
	if(index < 0) { return NULL; }

	QList<QString> keys = m_functions.keys();

	if(index >= keys.size()) { return NULL; }

	return m_functions.value(keys[index]);
}

SQFFunction * SQFFunctionManager::getFunction(const char * name) const {
	if(name == NULL) { return NULL; }

	QString formattedName = formatFunctionName(name);
	if(formattedName.isEmpty()) { return NULL; }

	return m_functions.value(formattedName);
}

SQFFunction * SQFFunctionManager::getFunction(const QString & name) const {
	QString formattedName = formatFunctionName(name);
	if(formattedName.isEmpty()) { return NULL; }

	return m_functions.value(formattedName);
}

bool SQFFunctionManager::setFunction(const char * name, SQFFunction * function) {
	QString formattedName = formatFunctionName(name);
	if(formattedName.isEmpty()) { return false; }

	if(m_functions.contains(formattedName)) {
		delete m_functions.value(formattedName);
		m_functions.remove(formattedName);
	}

	m_functions[formattedName] = function;

	return true;
}

bool SQFFunctionManager::setFunction(const QString & name, SQFFunction * function) {
	QString formattedName = formatFunctionName(name);
	if(formattedName.isEmpty()) { return false; }

	if(m_functions.contains(formattedName)) {
		delete m_functions.value(formattedName);
		m_functions.remove(formattedName);
	}

	m_functions[formattedName] = function;

	return true;
}

bool SQFFunctionManager::removeFunction(const char * name) {
	if(name == NULL) { return false; }

	QString formattedName = formatFunctionName(name);
	if(formattedName.isEmpty()) { return false; }

	if(m_functions.contains(formattedName)) {
		delete m_functions.value(formattedName);
		m_functions.remove(formattedName);
		return true;
	}
	return false;
}

bool SQFFunctionManager::removeFunction(const QString & name) {
	QString formattedName = formatFunctionName(name);
	if(formattedName.isEmpty()) { return false; }

	if(m_functions.contains(formattedName)) {
		delete m_functions.value(formattedName);
		m_functions.remove(formattedName);
		return true;
	}
	return false;
}

void SQFFunctionManager::clear() {
	QMapIterator<QString, SQFFunction *> i(m_functions);
	while(i.hasNext()) {
		i.next();
		delete i.value();
	}
	m_functions.clear();
}

QString SQFFunctionManager::formatFunctionName(const char * name) const {
	if(name == NULL) {
		return QString();
	}

	return formatFunctionName(QString(name));
}

QString SQFFunctionManager::formatFunctionName(const QString & name) const {
	if(name.isEmpty()) {
		return name;
	}

	return name.trimmed().toUpper();
}

QString SQFFunctionManager::execute(const char * command, int outputSize) {
	if(command == NULL || Utilities::stringLength(command) == 0 || outputSize <= 0) { return QString(); }

	int separatorIndex = -1;
	for(unsigned int i=0;i<Utilities::stringLength(command);i++) {
		if(command[i] == ' ' || command[i] == '\t') {
			separatorIndex = i;
			break;
		}
	}

	char * functionName = NULL;
	char * data = NULL;

	if(separatorIndex != -1) {
		functionName = Utilities::substring(command, 0, separatorIndex);
		data = Utilities::substring(command, separatorIndex + 1, Utilities::stringLength(command));
	}

	SQFFunction * func = getFunction(functionName == NULL ? command : functionName);
	if(func == NULL) {
		if(functionName != NULL) { delete [] functionName; }
		if(data != NULL) { delete [] data; }

		return QString();
	}

	SQFObject * arguments = NULL;
	
	if(Utilities::stringLength(data) == 0) {
		arguments = new SQFObject();
	}
	else {
		arguments = SQFObject::fromSQF(data);
	}

	QString result;

	if(arguments != NULL) {
		result = func->execute(*arguments, outputSize);
	}
	else {
		Logger::getInstance()->writeLine("Failed to parse function arguments: %s", data);
	}
	
#if LOG_FUNCTION_CALLS
	printf("%s: %s\n", functionName == NULL ? command : functionName, result.toLocal8Bit().data());

	Logger::getInstance()->writeLine("%s: %s", functionName == NULL ? command : functionName, result.toLocal8Bit().data());
#endif // LOG_FUNCTION_CALLS
	
	if(functionName != NULL) { delete [] functionName; }
	if(data != NULL) { delete [] data; }
	if(arguments != NULL) { delete [] arguments; }

	return result;
}

bool SQFFunctionManager::operator == (const SQFFunctionManager & s) const {
	if(m_functions.size() != s.m_functions.size()) { return false; }
	
	QList<QString> keys = m_functions.keys();

	for(int i=0;i<keys.size();i++) {
		if(!s.m_functions.contains(keys[i])) {
			return false;
		}
	}
	return true;
}

bool SQFFunctionManager::operator != (const SQFFunctionManager & s) const {
	return !operator == (s);
}
