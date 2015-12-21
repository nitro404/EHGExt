#include "Math/Vector2.h"
#include "Math/Vector3.h"
#include "Math/Vector4.h"

const Vector2 Vector2::Zero	  ( 0.0f,  0.0f);
const Vector2 Vector2::One	  ( 1.0f,  1.0f);
const Vector2 Vector2::Left	  (-1.0f,  0.0f);
const Vector2 Vector2::Right  ( 1.0f,  0.0f);
const Vector2 Vector2::Up	  ( 0.0f,  1.0f);
const Vector2 Vector2::Down	  ( 0.0f, -1.0f);

Vector2::Vector2              (float a, float b)        : x(a),    y(b)    { }
Vector2::Vector2              (const float v[2])		: x(v[0]), y(v[1]) { }
Vector2::Vector2              (const Vector2 & v)       : x(v.x),  y(v.y)  { }
Vector2::Vector2              (const Vector3 & v)       : x(v.x),  y(v.y)  { }
Vector2::Vector2              (const Vector4 & v)       : x(v.x),  y(v.y)  { }
Vector2 & Vector2::operator = (const Vector2 & v)       { x = v.x; y = v.y; return *this; }
Vector2 & Vector2::operator = (const Vector3 & v)       { x = v.x; y = v.y; return *this; }
Vector2 & Vector2::operator = (const Vector4 & v)       { x = v.x; y = v.y; return *this; }
Vector2::~Vector2             ()                        { }

Vector2 Vector2::operator   + (float c)			  const { return Vector2(x + c,   y + c); }
Vector2 Vector2::operator   + (const Vector2 & v) const { return Vector2(x + v.x, y + v.y); }
Vector2 Vector2::operator   + (const Vector3 & v) const { return Vector2(x + v.x, y + v.y); }
Vector2 Vector2::operator   + (const Vector4 & v) const { return Vector2(x + v.x, y + v.y); }

void Vector2::operator     += (float c)					{ x += c;   y += c; }
void Vector2::operator     += (const Vector2 & v)       { x += v.x; y += v.y; }
void Vector2::operator     += (const Vector3 & v)       { x += v.x; y += v.y; }
void Vector2::operator     += (const Vector4 & v)       { x += v.x; y += v.y; }

Vector2 Vector2::operator   - ()                  const { return Vector2(-x, -y); }

Vector2 Vector2::operator   - (float c)			  const { return Vector2(x - c,   y - c); }
Vector2 Vector2::operator   - (const Vector2 & v) const { return Vector2(x - v.x, y - v.y); }
Vector2 Vector2::operator   - (const Vector3 & v) const { return Vector2(x - v.x, y - v.y); }
Vector2 Vector2::operator   - (const Vector4 & v) const { return Vector2(x - v.x, y - v.y); }

void Vector2::operator     -= (float c)					{ x -= c;   y -= c; }
void Vector2::operator     -= (const Vector2 & v)       { x -= v.x; y -= v.y; }
void Vector2::operator     -= (const Vector3 & v)       { x -= v.x; y -= v.y; }
void Vector2::operator     -= (const Vector4 & v)       { x -= v.x; y -= v.y; }

Vector2 Vector2::operator   * (float c)			  const { return Vector2(x * c,   y * c); }
Vector2 Vector2::operator   * (const Vector2 & v) const { return Vector2(x * v.x, y * v.y); }
Vector2 Vector2::operator   * (const Vector3 & v) const { return Vector2(x * v.x, y * v.y); }
Vector2 Vector2::operator   * (const Vector4 & v) const { return Vector2(x * v.x, y * v.y); }

void Vector2::operator     *= (float c)					{ x *= c;   y *= c; }
void Vector2::operator     *= (const Vector2 & v)       { x *= v.x; y *= v.y; }
void Vector2::operator     *= (const Vector3 & v)       { x *= v.x; y *= v.y; }
void Vector2::operator     *= (const Vector4 & v)       { x *= v.x; y *= v.y; }

Vector2 Vector2::operator   / (float c)			  const { return Vector2(  c == 0.0f ? 0.0f : x / c,     c == 0.0f ? 0.0f : y / c); }
Vector2 Vector2::operator   / (const Vector2 & v) const { return Vector2(v.x == 0.0f ? 0.0f : x / v.x, v.y == 0.0f ? 0.0f : y / v.y); }
Vector2 Vector2::operator   / (const Vector3 & v) const { return Vector2(v.x == 0.0f ? 0.0f : x / v.x, v.y == 0.0f ? 0.0f : y / v.y); }
Vector2 Vector2::operator   / (const Vector4 & v) const { return Vector2(v.x == 0.0f ? 0.0f : x / v.x, v.y == 0.0f ? 0.0f : y / v.y); }

void Vector2::operator     /= (float c)					{ x =   c == 0.0f ? 0.0f : x / c;   y =   c == 0.0f ? 0.0f : y / c; }
void Vector2::operator     /= (const Vector2 & v)       { x = v.x == 0.0f ? 0.0f : x / v.x; y = v.y == 0.0f ? 0.0f : y / v.y; }
void Vector2::operator     /= (const Vector3 & v)       { x = v.x == 0.0f ? 0.0f : x / v.x; y = v.y == 0.0f ? 0.0f : y / v.y; }
void Vector2::operator     /= (const Vector4 & v)       { x = v.x == 0.0f ? 0.0f : x / v.x; y = v.y == 0.0f ? 0.0f : y / v.y; }

bool Vector2::operator     == (const Vector2 & v) const { return x == v.x && y == v.y; }
bool Vector2::operator     != (const Vector2 & v) const { return x != v.x || y != v.y; }

float Vector2::length		  ()				  const { return sqrt((x * x) + (y * y)); }
float Vector2::dot            (const Vector2 & v) const { return (x * v.x) + (y * v.y); }
void Vector2::normalize		  ()						{ float l = length(); if(l == 0.0f) { x = y = 0.0f; } else { x /= l; y /= l; } }
Vector2 Vector2::normalized   ()				  const { float l = length(); if(l == 0.0f) { return Zero; } else { return Vector2(x / l, y / l); } }

Vector2 Vector2::parseFrom(const char * data, bool * valid) {
	if(data == NULL || Utilities::stringLength(data) == 0) {
		if(valid != NULL) { *valid = false; }
		return Zero;
	}

#if USE_QT >= USE_STL
	return parseFrom(QString(data), valid);
#elif USE_STL
	return parseFrom(std::string(data), valid);
#endif // USE_QT
}

#if USE_QT
Vector2 Vector2::parseFrom(const QString & data, bool * valid) {
	static const QRegExp     nonFloatRegExp("[^-0-9.]+");
	static const QRegExp nonFloatTrimRegExp("(^[^-0-9.]+)|([^-0-9.]+$)");

	if(data.isEmpty()) {
		if(valid != NULL) { *valid = false; }
		return Zero;
	}

	QStringList parts = QString(data).replace(nonFloatTrimRegExp, "").split(nonFloatRegExp, QString::SkipEmptyParts);
	if(parts.size() != 2) {
		if(valid != NULL) { *valid = false; }
		return Zero;
	}

	Vector2 newVector;

	bool success = false;
	for(int i=0;i<2;i++) {
		newVector.v[i] = Utilities::parseFloat(parts[i], &success);

		if(!success) {
			if(valid != NULL) { *valid = false; }
			return Zero;
		}
	}

	if(valid != NULL) { *valid = true; }
	return newVector;
}
#endif // USE_QT

#if USE_STL
Vector2 Vector2::parseFrom(const std::string & data, bool * valid) {
	static const std::regex     nonFloatRegExp("[^-0-9.]+");
	static const std::regex nonFloatTrimRegExp("(^[^-0-9.]+)|([^-0-9.]+$)");

	std::string trimmedData;
	std::regex_replace(std::back_inserter(trimmedData), data.begin(), data.end(), nonFloatTrimRegExp, "");

	std::string formattedData;
	std::regex_replace(std::back_inserter(formattedData), trimmedData.begin(), trimmedData.end(), nonFloatRegExp, " ");

	int index = 0, start = -1, end = -1;
	std::string part;
	bool success = false;
	Vector2 newVector;
	for(int i=0;i<static_cast<int>(formattedData.length());i++) {
		if(formattedData[i] == ' ' || i == static_cast<int>(formattedData.length()) - 1) {
			if(index > 1) {
				if(valid != NULL) { *valid = false; }
				return Zero;
			}

			start = end + 1;
			end = i == static_cast<int>(formattedData.length()) - 1 ? i + 1 : i;

			part = Utilities::substring(formattedData, start, end);

			newVector.v[index++] = Utilities::parseFloat(part, &success);

			if(!success) {
				if(valid != NULL) { *valid = false; }
				return Zero;
			}
		}
	}

	if(index != 2) {
		if(valid != NULL) { *valid = false; }
		return Zero;
	}

	if(valid != NULL) { *valid = true; }
	return newVector;
}
#endif // USE_STL

#if USE_QT >= USE_STL
QString Vector2::toString() const {
	return QString("%1, %2").arg(x).arg(y);
}
#elif USE_STL
std::string Vector2::toString() const {
	return std::to_string(x) + ", " + std::to_string(y);
}
#endif // USE_QT
