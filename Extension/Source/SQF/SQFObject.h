#ifndef SQF_OBJECT_H
#define SQF_OBJECT_H

#include <QString.h>
#include <QRegExp.h>
#include <QVector.h>
#include "Extension.h"
#include "SQF/SQFObjectType.h"
#include "Utilities/Utilities.h"
#include "Math/Vector2.h"
#include "Math/Vector3.h"
#include "Math/Vector4.h"

class SQFObject {
public:
	SQFObject(SQFObjectTypes::SQFObjectType type = SQFObjectTypes::Unknown);
	SQFObject(const char * value, SQFObjectTypes::SQFObjectType type = SQFObjectTypes::String);
	SQFObject(const QString & value, SQFObjectTypes::SQFObjectType type = SQFObjectTypes::String);
	SQFObject(const QStringList & stringList);
	SQFObject(const Vector2 & v);
	SQFObject(const Vector3 & v);
	SQFObject(const Vector4 & v);
	SQFObject(bool value);
	SQFObject(int value);
	SQFObject(unsigned int value);
	SQFObject(long value);
	SQFObject(unsigned long value);
	SQFObject(long long value);
	SQFObject(unsigned long long value);
	SQFObject(double value);
	SQFObject(const SQFObject & o);
	SQFObject & operator = (const SQFObject & o);
	virtual ~SQFObject();

	const QString & getValue() const;
	bool getValueAsBoolean(bool * valid = NULL) const;
	int getValueAsInteger(bool * valid = NULL) const;
	unsigned int getValueAsUnsignedInteger(bool * valid = NULL) const;
	long getValueAsLong(bool * valid = NULL) const;
	unsigned long getValueAsUnsignedLong(bool * valid = NULL) const;
	long long getValueAsLongLong(bool * valid = NULL) const;
	float getValueAsFloat(bool * valid = NULL) const;
	double getValueAsDouble(bool * valid = NULL) const;
	bool setValue(const char * value);
	bool setValue(const QString & value);

	SQFObjectTypes::SQFObjectType getType() const;
	bool isBoolean() const;
	bool isNumber() const;
	bool isString() const;
	bool isArray() const;

	bool hasElements() const;
	int numberOfElements() const;
	bool hasElement(const SQFObject & object) const;
	int indexOfElement(const SQFObject & object) const;
	SQFObject * getElement(int index) const;
	bool addElement(SQFObject * object);
	bool addElement(const SQFObject & object);
	bool replaceElement(int index, SQFObject * object);
	bool replaceElement(int index, const SQFObject & object);
	bool removeElement(int index);
	bool removeElement(const SQFObject & object);
	void clearElements();

	static SQFObject * fromSQF(const QString & data);
	static SQFObject * fromSQF(const char * data);
	QString toSQF() const;

	bool operator == (const SQFObject & o) const;
	bool operator != (const SQFObject & o) const;

public:
	static const char * nil;
	static const char * objNull;
	static const QRegExp numberRegExp;

protected:
	QString m_value;
	SQFObjectTypes::SQFObjectType m_type;
	QVector<SQFObject *> * m_elements;
};

#endif // SQF_OBJECT_H
