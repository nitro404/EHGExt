#include <functional>
#include "Logger/Logger.h"
#include "Extension Manager/ExtensionManager.h"
#include "SQF/Functions/UtilityFunctions.h"
#include "SQF/Functions/MathFunctions.h"
#include "SQF/Functions/StringFunctions.h"

const char * ExtensionManager::VERSION = "1.0";

ExtensionManager::ExtensionManager()
	: Singleton()
	, m_initialized(false)
	
	, m_functionManager(NULL) {
	m_functionManager = new SQFFunctionManager();
}

ExtensionManager::~ExtensionManager() {
	delete m_functionManager;
}

bool ExtensionManager::init() {
	if(m_initialized) { return true; }
	
	m_functionManager->setFunction("version", new SQFCPPFunction(std::bind(&ExtensionManager::version, this, std::placeholders::_1, std::placeholders::_2)));

	m_functionManager->setFunction("log", new SQFCPPFunction(std::bind(&Logger::log, Logger::getInstance(), std::placeholders::_1, std::placeholders::_2)));

	m_functionManager->setFunction("time", new SQFCFunction(&UtilityFunctions::systemTime));
	m_functionManager->setFunction("randomInteger", new SQFCFunction(&UtilityFunctions::randomInteger));
	m_functionManager->setFunction("randomFloat", new SQFCFunction(&UtilityFunctions::randomFloat));
	
	m_functionManager->setFunction("clampNumber", new SQFCFunction(&MathFunctions::clampNumber));
	m_functionManager->setFunction("distance", new SQFCFunction(&MathFunctions::distance));
	m_functionManager->setFunction("radiansToDegrees", new SQFCFunction(&MathFunctions::radiansToDegrees));
	m_functionManager->setFunction("degreesToRadians", new SQFCFunction(&MathFunctions::degreesToRadians));
	m_functionManager->setFunction("compareAngles", new SQFCFunction(&MathFunctions::compareAngles));
	m_functionManager->setFunction("lerp", new SQFCFunction(&MathFunctions::lerp));
	m_functionManager->setFunction("normalizeNumber", new SQFCFunction(&MathFunctions::normalizeNumber));
	m_functionManager->setFunction("normalizeVector", new SQFCFunction(&MathFunctions::normalizeVector));

	m_functionManager->setFunction("stringLength", new SQFCFunction(&StringFunctions::stringLength));
	m_functionManager->setFunction("compareStrings", new SQFCFunction(&StringFunctions::compareStrings));
	m_functionManager->setFunction("compareStringsIgnoreCase", new SQFCFunction(&StringFunctions::compareStringsIgnoreCase));
	m_functionManager->setFunction("matchString", new SQFCFunction(&StringFunctions::matchString));
	m_functionManager->setFunction("toLowerCase", new SQFCFunction(&StringFunctions::toLowerCase));
	m_functionManager->setFunction("toUpperCase", new SQFCFunction(&StringFunctions::toUpperCase));
	m_functionManager->setFunction("trimString", new SQFCFunction(&StringFunctions::trimString));
	m_functionManager->setFunction("substring", new SQFCFunction(&StringFunctions::substring));
	m_functionManager->setFunction("splitString", new SQFCFunction(&StringFunctions::splitString));
	m_functionManager->setFunction("replaceString", new SQFCFunction(&StringFunctions::replaceString));
	
	m_initialized = true;

	return true;
}

bool ExtensionManager::isInitialized() const {
	return m_initialized;
}

bool ExtensionManager::execute(const char * function, char * output, int outputSize) {
	if(!m_initialized || function == NULL || output == NULL || outputSize <= 0) { return false; }

	strncpy_s(output, outputSize, m_functionManager->execute(function, outputSize).toLocal8Bit().data(), _TRUNCATE);

	return true;
}

QString ExtensionManager::version(const SQFObject & arguments, int outputSize) {
	return QString(SQFObject(VERSION).toSQF());
}
