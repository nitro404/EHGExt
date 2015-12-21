#ifndef EXTENSION_MANAGER_H
#define EXTENSION_MANAGER_H

#include "Extension.h"
#include "Singleton/Singleton.h"
#include "SQF/SQFFunctionManager.h"

class ExtensionManager : public Singleton<ExtensionManager> {
friend class Singleton<ExtensionManager>;
public:
	ExtensionManager();
	virtual ~ExtensionManager();

	bool init();
	bool isInitialized() const;

	bool execute(const char * function, char * output, int outputSize);

	QString version(const SQFObject & arguments, int outputSize);

public:
	static const char * VERSION;

protected:
	bool m_initialized;
	SQFFunctionManager * m_functionManager;
};

#endif // EXTENSION_MANAGER_H
