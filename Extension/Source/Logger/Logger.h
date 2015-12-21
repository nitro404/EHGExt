#ifndef LOGGER_H
#define LOGGER_H

#include <QString.h>
#include "Extension.h"
#include "Singleton/Singleton.h"
#include "SQF/SQFObject.h"

class Logger : public Singleton<Logger> {
friend class Singleton<Logger>;
public:
	Logger();
	virtual ~Logger();

	bool init(bool openLog = true);
	bool isInitialized() const;

	bool open();
	void close();
	bool isOpen() const;
	
	bool writeLine(bool value);
	bool writeLine(int value);
	bool writeLine(double value);
	bool writeLine(const char * format, ...);
	bool writeLine(const QString & text);

	QString log(const SQFObject & arguments, int outputSize);

private:
	void writeLineHelper(const char * text);

protected:
	bool m_initialized;
	QFile * m_log;
};

#endif // LOGGER_H
