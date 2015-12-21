#include <QFile.h>
#include "Logger/Logger.h"
#include "Settings Manager/SettingsManager.h"

Logger::Logger()
	: m_initialized(false)
	, m_log(NULL) {

}

Logger::~Logger() {
	if(m_log != NULL) {
		if(m_log->isOpen()) {
			m_log->close();
		}

		delete m_log;
	}
}

bool Logger::init(bool openLog) {
	if(m_initialized) { return true; }

	if(openLog) {
		open();
	}

	m_initialized = true;

	return true;
}

bool Logger::isInitialized() const {
	return m_initialized;
}

bool Logger::open() {
	m_log = new QFile(SettingsManager::getInstance()->logFileName);
	if(!m_log->open(QIODevice::Append)) { return false; }

	return true;
}

void Logger::close() {
	if(m_log == NULL || !m_log->isOpen()) { return; }

	m_log->close();
	m_log = NULL;
}

bool Logger::isOpen() const {
	return m_log != NULL && m_log->isOpen();
}

bool Logger::writeLine(bool value) {
	return writeLine(value ? "true" : "false");
}

bool Logger::writeLine(int value) {
	return writeLine(QString::number(value));
}

bool Logger::writeLine(double value) {
	return writeLine(QString::number(value));
}

bool Logger::writeLine(const char * format, ...) {
	if(format == NULL) { return false; }
	
	static char text[256];
	va_list args;
	va_start(args, format);
		vsprintf_s(text, 256, format, args);
	va_end(args);

	return writeLine(QString(text));
}

bool Logger::writeLine(const QString & text) {
	if(m_log == NULL || !m_log->isOpen()) { return false; }

	m_log->write(text.toLocal8Bit());
	m_log->write(Utilities::newLine);

	return true;
}

QString Logger::log(const SQFObject & arguments, int outputSize) {
	writeLine(arguments.toSQF());

	return QString();
}
