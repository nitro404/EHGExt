#ifndef SQF_FUNCTION_MANAGER_H
#define SQF_FUNCTION_MANAGER_H

#include <QMap.h>
#include <QString.h>
#include <QStringList.h>
#include "Extension.h"
#include "Utilities/Utilities.h"
#include "SQF/SQFFunction.h"
#include "SQF/SQFCFunction.h"
#include "SQF/SQFCPPFunction.h"

class SQFFunctionManager {
public:
	SQFFunctionManager();
	SQFFunctionManager(const SQFFunctionManager & m);
	SQFFunctionManager & operator = (const SQFFunctionManager & m);
	virtual ~SQFFunctionManager();

	int numberOfFunctions() const;
	bool hasFunction(const char * name) const;
	bool hasFunction(const QString & name) const;
	SQFFunction * getFunction(int index) const;
	SQFFunction * getFunction(const char * name) const;
	SQFFunction * getFunction(const QString & name) const;
	bool setFunction(const char * name, SQFFunction * function);
	bool setFunction(const QString & name, SQFFunction * function);
	bool removeFunction(const char * name);
	bool removeFunction(const QString & name);
	void clear();

	QString execute(const char * command, int outputSize);
	
	bool operator == (const SQFFunctionManager & m) const;
	bool operator != (const SQFFunctionManager & m) const;

private:
	QString formatFunctionName(const char * data) const;
	QString formatFunctionName(const QString & data) const;

protected:
	QMap<QString, SQFFunction *> m_functions;
};

#endif // SQF_FUNCTION_MANAGER_H
