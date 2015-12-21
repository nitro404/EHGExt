#include "SQF/SQFObject.h"
#include "Logger/Logger.h"

const char * SQFObject::nil = "nil";
const char * SQFObject::objNull = "objNull";
const QRegExp SQFObject::numberRegExp("^-?[0-9]+(\\.[0-9]*)?$");

SQFObject::SQFObject(SQFObjectTypes::SQFObjectType type)
	: m_value()
	, m_type(type)
	, m_elements(NULL) {

}

SQFObject::SQFObject(const QString & value, SQFObjectTypes::SQFObjectType type)
	: m_value(value)
	, m_type(type)
	, m_elements(NULL) {
	
}

SQFObject::SQFObject(const char * value, SQFObjectTypes::SQFObjectType type)
	: m_value(value)
	, m_type(type)
	, m_elements(NULL) {

}

SQFObject::SQFObject(const QStringList & stringList)
	: m_value()
	, m_type(SQFObjectTypes::Array)
	, m_elements(NULL) {
	m_elements = new QVector<SQFObject *>();

	for(int i=0;i<stringList.size();i++) {
		m_elements->append(new SQFObject(stringList[i]));
	}
}

SQFObject::SQFObject(const Vector2 & v)
	: m_value()
	, m_type(SQFObjectTypes::Array)
	, m_elements(NULL) {
	m_elements = new QVector<SQFObject *>();

	for(int i=0;i<2;i++) {
		m_elements->append(new SQFObject(v.v[i]));
	}
}

SQFObject::SQFObject(const Vector3 & v)
	: m_value()
	, m_type(SQFObjectTypes::Array)
	, m_elements(NULL) {
	m_elements = new QVector<SQFObject *>();

	for(int i=0;i<3;i++) {
		m_elements->append(new SQFObject(v.v[i]));
	}
}

SQFObject::SQFObject(const Vector4 & v)
	: m_value()
	, m_type(SQFObjectTypes::Array)
	, m_elements(NULL) {
	m_elements = new QVector<SQFObject *>();

	for(int i=0;i<4;i++) {
		m_elements->append(new SQFObject(v.v[i]));
	}
}

SQFObject::SQFObject(bool value)
	: m_value(value ? "true" : "false")
	, m_type(SQFObjectTypes::Boolean)
	, m_elements(NULL) {

}

SQFObject::SQFObject(int value)
	: m_value(QString::number(value))
	, m_type(SQFObjectTypes::Number)
	, m_elements(NULL) {
	
}

SQFObject::SQFObject(unsigned int value)
	: m_value(QString::number(value))
	, m_type(SQFObjectTypes::Number)
	, m_elements(NULL) {
	
}

SQFObject::SQFObject(long value)
	: m_value(QString::number(value))
	, m_type(SQFObjectTypes::Number)
	, m_elements(NULL) {
	
}

SQFObject::SQFObject(unsigned long value)
	: m_value(QString::number(value))
	, m_type(SQFObjectTypes::Number)
	, m_elements(NULL) {
	
}

SQFObject::SQFObject(long long value)
	: m_value(QString::number(value))
	, m_type(SQFObjectTypes::Number)
	, m_elements(NULL) {
	
}

SQFObject::SQFObject(unsigned long long value)
	: m_value(QString::number(value))
	, m_type(SQFObjectTypes::Number)
	, m_elements(NULL) {
	
}

SQFObject::SQFObject(double value)
	: m_value(QString::number(value))
	, m_type(SQFObjectTypes::Number)
	, m_elements(NULL) {
	
}

SQFObject::SQFObject(const SQFObject & o)
	: m_value(o.m_value)
	, m_type(o.m_type)
	, m_elements(NULL) {
	if(o.m_elements != NULL) {
		m_elements = new QVector<SQFObject *>();

		for(int i=0;i<o.m_elements->size();i++) {
			m_elements->append(new SQFObject(*(*o.m_elements)[i]));
		}
	}
}

SQFObject & SQFObject::operator = (const SQFObject & o) {
	if(m_elements != NULL) {
		for(int i=0;i<m_elements->size();i++) {
			delete (*m_elements)[i];
		}

		delete m_elements;
	}

	m_value = o.m_value;
	m_type = o.m_type;
	
	if(o.m_elements != NULL) {
		m_elements = new QVector<SQFObject *>();

		for(int i=0;i<o.m_elements->size();i++) {
			m_elements->append(new SQFObject(*(*o.m_elements)[i]));
		}
	}

	return *this;
}

SQFObject::~SQFObject() {
	if(m_elements != NULL) {
		for(int i=0;i<m_elements->size();i++) {
			delete (*m_elements)[i];
		}

		delete m_elements;
	}
}

const QString & SQFObject::getValue() const {
	return m_value;
}

bool SQFObject::getValueAsBoolean(bool * valid) const {
	if(m_value.isEmpty()) {
		if(valid != NULL) { *valid = false; }

		return false;
	}

	if(Utilities::compareStringsIgnoreCase(m_value, "true") == 0) {
		if(valid != NULL) { *valid = true; }

		return true;
	}
	else if(Utilities::compareStringsIgnoreCase(m_value, "false") == 0) {
		if(valid != NULL) { *valid = true; }

		return false;
	}

	if(valid != NULL) { *valid = false; }

	return false;
}

int SQFObject::getValueAsInteger(bool * valid) const {
	if(m_value.isEmpty()) { return false; }
	
	return m_value.toInt(valid);
}

unsigned int SQFObject::getValueAsUnsignedInteger(bool * valid) const {
	if(m_value.isEmpty()) { return false; }
	
	return m_value.toUInt(valid);
}

long SQFObject::getValueAsLong(bool * valid) const {
	if(m_value.isEmpty()) { return false; }
	
	return m_value.toLong(valid);
}

unsigned long SQFObject::getValueAsUnsignedLong(bool * valid) const {
	if(m_value.isEmpty()) { return false; }
	
	return m_value.toULong(valid);
}

long long SQFObject::getValueAsLongLong(bool * valid) const {
	if(m_value.isEmpty()) { return false; }
	
	return m_value.toLongLong(valid);
}

float SQFObject::getValueAsFloat(bool * valid) const {
	if(m_value.isEmpty()) { return false; }
	
	return m_value.toFloat(valid);
}

double SQFObject::getValueAsDouble(bool * valid) const {
	if(m_value.isEmpty()) { return false; }

	return m_value.toDouble(valid);
}

bool SQFObject::setValue(const char * value) {
	if(m_type == SQFObjectTypes::Array) { return false; }
	
	if(value == NULL) {
		m_value = QString();
	}
	else {
		m_value = QString(value);
	}
	
	if(!SQFObjectTypes::isValid(m_type)) {
		m_type = SQFObjectTypes::String;
	}
	
	return true;
}

bool SQFObject::setValue(const QString & value) {
	if(m_type == SQFObjectTypes::Array) { return false; }
		
	m_value = value;
	
	if(!SQFObjectTypes::isValid(m_type)) {
		m_type = SQFObjectTypes::String;
	}
	
	return true;
}

SQFObjectTypes::SQFObjectType SQFObject::getType() const {
	return m_type;
}

bool SQFObject::isBoolean() const {
	return m_type == SQFObjectTypes::Boolean;
}

bool SQFObject::isNumber() const {
	return m_type == SQFObjectTypes::Number;
}

bool SQFObject::isString() const {
	return m_type == SQFObjectTypes::String;
}

bool SQFObject::isArray() const {
	return m_type == SQFObjectTypes::Array;
}

bool SQFObject::hasElements() const {
	return m_elements != NULL && m_elements->size() > 0;
}

int SQFObject::numberOfElements() const {
	return m_elements == NULL ? 0 : m_elements->size();
}

bool SQFObject::hasElement(const SQFObject & object) const {
	if(m_elements == NULL) { return false; }
	
	for(int i=0;i<m_elements->size();i++) {
		if(*(*m_elements)[i] == object) {
			return true;
		}
	}
	return false;
}

int SQFObject::indexOfElement(const SQFObject & object) const {
	if(m_elements == NULL) { return -1; }
	
	for(int i=0;i<m_elements->size();i++) {
		if(*(*m_elements)[i] == object) {
			return i;
		}
	}
	return -1;
}

SQFObject * SQFObject::getElement(int index) const {
	if(m_elements == NULL || index < 0 || index >= m_elements->size()) { return false; }

	return (*m_elements)[index];
}

bool SQFObject::addElement(SQFObject * object) {
	if(m_type != SQFObjectTypes::Array) { return false; }

	if(m_elements == NULL) {
		m_elements = new QVector<SQFObject *>();
	}

	m_elements->append(object);

	return true;
}

bool SQFObject::addElement(const SQFObject & object) {
	if(m_type != SQFObjectTypes::Array) { return false; }

	if(m_elements == NULL) {
		m_elements = new QVector<SQFObject *>();
	}

	m_elements->append(new SQFObject(object));

	return true;
}

bool SQFObject::replaceElement(int index, SQFObject * object) {
	if(m_type != SQFObjectTypes::Array) { return false; }

	if(m_elements == NULL) {
		if(index < 0 || index >= m_elements->size()) { return false; }
		
		if(index == 0) {
			m_elements = new QVector<SQFObject *>();
			
			m_elements->append(object);
			
			return true;
		}
		else {
			return false;
		}
	}
	
	delete (*m_elements)[index];
	m_elements->replace(index, object);
	
	return true;
}

bool SQFObject::replaceElement(int index, const SQFObject & object) {
	if(m_type != SQFObjectTypes::Array) { return false; }

	if(m_elements == NULL) {
		if(index < 0 || index >= m_elements->size()) { return false; }
		
		if(index == 0) {
			m_elements = new QVector<SQFObject *>();
			
			m_elements->append(new SQFObject(object));
			
			return true;
		}
		else {
			return false;
		}
	}
	
	delete (*m_elements)[index];
	m_elements->replace(index, new SQFObject(object));
	
	return true;
}

bool SQFObject::removeElement(int index) {
	if(m_elements == NULL || index < 0 || index >= m_elements->size()) { return false; }
	
	delete (*m_elements)[index];
	m_elements->remove(index);

	return true;
}

bool SQFObject::removeElement(const SQFObject & object) {
	if(m_elements == NULL) { return false; }
	
	for(int i=0;i<m_elements->size();i++) {
		if(*(*m_elements)[i] == object) {
			delete (*m_elements)[i];
			m_elements->remove(i);

			return true;
		}
	}
	return false;
}

void SQFObject::clearElements() {
	if(m_elements == NULL) { return; }

	for(int i=0;i<m_elements->size();i++) {
		delete (*m_elements)[i];
	}
	m_elements->clear();
}

SQFObject * SQFObject::fromSQF(const QString & data) {
	if(data.isNull()) { return NULL; }

	QByteArray bytes = data.toLocal8Bit();

	return fromSQF(bytes.data());
}

SQFObject * SQFObject::fromSQF(const char * data) {
	if(data == NULL) { return NULL; }

	QString trimmedData = QString(data).trimmed();
	
	if(trimmedData.length() == 0) {
		return new SQFObject();
	}
	
	if(trimmedData.length() >= 2) {
		char firstChar = trimmedData[0].toLatin1();
		char lastChar = trimmedData[trimmedData.length() - 1].toLatin1();
		
		if(firstChar == '[') {
			if(lastChar == ']') {
				SQFObject * array = new SQFObject(SQFObjectTypes::Array);
				QString innerData = Utilities::substring(trimmedData, 1, trimmedData.length() - 1).trimmed();
				
				char c;
				char closingCharacter = '\0';
				bool isSingleQuoteString = false;
				bool isDoubleQuoteString = false;
				int depth = 0;
				QString buffer("");

				for(int i=0;i<innerData.length();i++) {
					c = innerData[i].toLatin1();
					
					if(c == '\'') {
						if(!isDoubleQuoteString) {
							isSingleQuoteString = !isSingleQuoteString;
						}
					}
					else if(c == '"') {
						if(!isSingleQuoteString) {
							isDoubleQuoteString = !isDoubleQuoteString;
						}
					}
					else if(c == '[') {
						if(!isSingleQuoteString && !isDoubleQuoteString) {
							depth++;
						}
					}
					else if(c == ']') {
						if(!isSingleQuoteString && !isDoubleQuoteString) {
							depth--;
						}
					}
					
					if(closingCharacter == '\0') {
						if(c == '[') {
							closingCharacter = ']';
						}
						else if(c == '\'' || c == '\"') {
							closingCharacter = c;
						}
						else if(c == ',') {
							if(depth == 0 && !isSingleQuoteString && !isDoubleQuoteString) {
								QString value = QString(buffer).trimmed();
								if(value.length() > 0 && value[0].toLatin1() == ',') {
									value = Utilities::substring(value, 1, value.length());
								}
								
								if(value.length() > 0) {
									array->addElement(fromSQF(value));
								}
								
								buffer = "";
							}
						}
					}
					else if(closingCharacter == c) {
						if(depth == 0) {
							closingCharacter = '\0';
						}
					}
					
					buffer += c;
				}
				
				QString value = QString(buffer).trimmed();
				if(value.length() > 0 && value[0].toLatin1() == ',') {
					value = Utilities::substring(value, 1, value.length());
				}
				if(value.length() > 0) {
					array->addElement(fromSQF(value));
				}
				
				return array;
			}
			else {
				Logger::getInstance()->writeLine("Malformed array: %s", trimmedData.toLocal8Bit().data());
				return NULL;
			}
		}
		else if(firstChar == '\'') {
			if(lastChar == '\'') {
				return new SQFObject(Utilities::substring(trimmedData, 1, trimmedData.length() - 1).replace("''",  "'"), SQFObjectTypes::String);
			}
			else {
				Logger::getInstance()->writeLine("Malformed string: %s", trimmedData.toLocal8Bit().data());
				return NULL;
			}
		}
		else if(firstChar == '"') {
			if(lastChar == '"') {
				return new SQFObject(Utilities::substring(trimmedData, 1, trimmedData.length() - 1).replace("\"\"",  "\""), SQFObjectTypes::String);
			}
			else {
				Logger::getInstance()->writeLine("Malformed string: %s", trimmedData.toLocal8Bit().data());
				return NULL;
			}
		}
	}
	
	if(Utilities::compareStringsIgnoreCase(trimmedData, nil) == 0 || Utilities::compareStringsIgnoreCase(trimmedData, objNull) == 0) {
		return new SQFObject();
	}
	else if(Utilities::compareStringsIgnoreCase(trimmedData, "true") == 0 || Utilities::compareStringsIgnoreCase(trimmedData, "false") == 0) {
		return new SQFObject(trimmedData.toLower(), SQFObjectTypes::Boolean);
	}
	else if(trimmedData.contains(numberRegExp)) {
		return new SQFObject(trimmedData, SQFObjectTypes::Number);
	}
	else {
		Logger::getInstance()->writeLine("Invalid or unknown type for value: %s", trimmedData.toLocal8Bit().data());
		return new SQFObject(trimmedData, SQFObjectTypes::Unknown);
	}
}

QString SQFObject::toSQF() const {
	QString sqf("");
	
	if(m_type == SQFObjectTypes::Array) {
		sqf += '[';
	}
	
	if(m_type == SQFObjectTypes::Array) {
		if(m_elements != NULL) {
			for(int i=0;i<m_elements->size();i++) {
				sqf += (*m_elements)[i]->toSQF();
				
				if(i < m_elements->size() - 1) {
					sqf += ", ";
				}
			}
		}
	}
	else {
		if(m_value.isNull()) {
			sqf += nil;
		}
		else {
			if(m_type == SQFObjectTypes::String) {
				sqf += '"';
				sqf += QString(m_value).replace("\"", "\"\"", Qt::CaseSensitive);
				sqf += '"';
			}
			else {
				sqf += m_value;
			}
		}
	}
	
	if(m_type == SQFObjectTypes::Array) {
		sqf += ']';
	}
	
	return sqf;
}

bool SQFObject::operator == (const SQFObject & o) const {
	if(m_type != o.m_type) { return false; }
	
	if(m_type == SQFObjectTypes::Array) {
		if(m_elements == NULL && o.m_elements != NULL || 
		   m_elements != NULL && o.m_elements == NULL) { return false; }
		
		if(m_elements != NULL && o.m_elements != NULL) {
			if(m_elements->size() != o.m_elements->size()) { return false; }
			
			for(int i=0;i<m_elements->size();i++) {
				if(*(*m_elements)[i] != *(*o.m_elements)[i]) {
					return false;
				}
			}
			return true;
		}
		else {
			return true;
		}
	}
	else {
		return Utilities::compareStrings(m_value, o.m_value) == 0;
	}
}

bool SQFObject::operator != (const SQFObject & o) const {
	return !operator == (o);
}
