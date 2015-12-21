#include "SQF/SQFObjectType.h"

const char * SQFObjectTypes::objectTypeStrings[] = { "Unknown", "Boolean", "Number", "String", "Array" };

bool SQFObjectTypes::isValid(SQFObjectType type) {
	return type > Invalid && type < NumberOfSQFObjectTypes;
}

bool SQFObjectTypes::isValid(int type) {
	return type > static_cast<int>(Invalid) && type < static_cast<int>(NumberOfSQFObjectTypes);
}

const char * SQFObjectTypes::toString(SQFObjectType type) {
	return toString(static_cast<int>(type));
}

const char * SQFObjectTypes::toString(int type) {
	if(!isValid(type)) { return "Invalid"; }

	return objectTypeStrings[type];
}

SQFObjectTypes::SQFObjectType SQFObjectTypes::parseFrom(const char * data) {
	if(data == NULL) { return Invalid; }

	SQFObjectType type = Invalid;

	char * typeString = Utilities::trimCopyString(data);

	for(int i=0;i<static_cast<int>(NumberOfSQFObjectTypes);i++) {
		if(Utilities::compareStringsIgnoreCase(typeString, objectTypeStrings[i]) == 0) {
			type = static_cast<SQFObjectType>(i);
			break;
		}
	}

	delete [] typeString;

	return type;
}

SQFObjectTypes::SQFObjectType SQFObjectTypes::parseFrom(const QString & data) {
	QByteArray dataBytes = data.toLocal8Bit();
	return parseFrom(dataBytes.data());
}
