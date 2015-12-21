#ifndef SETTINGS_MANAGER_H
#define SETTINGS_MANAGER_H

#include "Utilities/Utilities.h"
#include "Variable System/VariableCollection.h"
#include "Singleton/Singleton.h"

class SettingsManager : public Singleton<SettingsManager> {
friend class Singleton<SettingsManager>;
public:
	SettingsManager();
	SettingsManager(const SettingsManager & s);
	SettingsManager & operator = (const SettingsManager & s);
	virtual ~SettingsManager();
	
	void reset();
	
	bool load();
	bool save() const;
	bool loadFrom(const char * fileName);
	bool loadFrom(const QString & fileName);
	bool saveTo(const char * fileName) const;
	bool saveTo(const QString & fileName) const;

public:
	const static char * defaultSettingsFileName;
	const static char * defaultLogFileName;
	
	char * logFileName;

private:
	VariableCollection * m_variables;
};

#endif // SETTINGS_MANAGER_H
