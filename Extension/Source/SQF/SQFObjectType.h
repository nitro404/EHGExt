#ifndef SQF_OBJECT_TYPE_H
#define SQF_OBJECT_TYPE_H

#include "Extension.h"
#include "Utilities/Utilities.h"

namespace SQFObjectTypes {
	enum SQFObjectType {
		Invalid = -1,
		Unknown,
		Boolean,
		Number,
		String,
		Array,
		NumberOfSQFObjectTypes
	};
	
	extern const char * objectTypeStrings[];
	
	bool isValid(SQFObjectType type);
	bool isValid(int type);
	const char * toString(SQFObjectType type);
	const char * toString(int type);
	SQFObjectType parseFrom(const char * data);
	SQFObjectType parseFrom(const QString & data);
}

#endif // SQF_OBJECT_TYPE_H
