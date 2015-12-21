#include "Settings Manager/SettingsManager.h"

const char * SettingsManager::defaultSettingsFileName = "EHGExt.ini";
const char * SettingsManager::defaultLogFileName = "EHGExt.log";

SettingsManager::SettingsManager()
	: m_variables(new VariableCollection())
	, logFileName(NULL) {
	reset();
}

SettingsManager::SettingsManager(const SettingsManager & s)
	: m_variables(new VariableCollection(*s.m_variables))
	, logFileName(NULL) {
	logFileName = Utilities::copyString(s.logFileName);
}

SettingsManager & SettingsManager::operator = (const SettingsManager & s) {
	if(logFileName != NULL) { delete [] logFileName; }

	delete m_variables;

	m_variables = new VariableCollection(*s.m_variables);

	logFileName = Utilities::copyString(s.logFileName);

	return *this;
}

SettingsManager::~SettingsManager() {
	if(logFileName != NULL)	{ delete [] logFileName; }

	delete m_variables;
}

void SettingsManager::reset() {
	if(logFileName != NULL) { delete [] logFileName; }

	logFileName = Utilities::copyString(defaultLogFileName);
}

bool SettingsManager::load() {
	return loadFrom(defaultSettingsFileName);
}

bool SettingsManager::save() const {
	return saveTo(defaultSettingsFileName);
}

bool SettingsManager::loadFrom(const QString & fileName) {
	QByteArray fileNameBytes = fileName.toLocal8Bit();

	return loadFrom(fileNameBytes.data());
}

bool SettingsManager::loadFrom(const char * fileName) {
	VariableCollection * newVariables = VariableCollection::readFrom(fileName);
	if(newVariables == NULL) { return false; }

	delete m_variables;
	m_variables = newVariables;

	const char * data = NULL;

	data = m_variables->getValue("Log File Name", "Paths");
	if(data != NULL) {
		if(logFileName != NULL) { delete [] logFileName; }
		logFileName = Utilities::copyString(data);
	}
	
	return true;
}

bool SettingsManager::saveTo(const QString & fileName) const {
	QByteArray fileNameBytes = fileName.toLocal8Bit();

	return saveTo(fileNameBytes.data());
}

bool SettingsManager::saveTo(const char * fileName) const {
	m_variables->setValue("Log File Name", logFileName, "Paths");

	// group the variables by categories
	m_variables->sortVariables();

	// update the settings file with the changes
	return m_variables->writeTo(fileName);
}
