#include "Math/Vector2.h"
#include "Math/Vector3.h"
#include "Math/Vector4.h"

const Vector3 Vector3::Zero	   ( 0.0f,  0.0f,  0.0f);
const Vector3 Vector3::One     ( 1.0f,  1.0f,  1.0f);
const Vector3 Vector3::Forward ( 0.0f,  0.0f, -1.0f);
const Vector3 Vector3::Backward( 0.0f,  0.0f,  1.0f);
const Vector3 Vector3::Left    (-1.0f,  0.0f,  0.0f);
const Vector3 Vector3::Right   ( 1.0f,  0.0f,  0.0f);
const Vector3 Vector3::Up      ( 0.0f,  1.0f,  0.0f);
const Vector3 Vector3::Down    ( 0.0f, -1.0f,  0.0f);

Vector3::Vector3              (float a, float b, float c) : x(a),  y(b),    z(c)    { }
Vector3::Vector3              (const float v[3])		: x(v[0]), y(v[1]), z(v[2]) { }
Vector3::Vector3              (const Vector2 & v)       : x(v.x),  y(v.y),  z(0.0f) { }
Vector3::Vector3              (const Vector3 & v)       : x(v.x),  y(v.y),  z(v.z)  { }
Vector3::Vector3              (const Vector4 & v)       : x(v.x),  y(v.y),  z(v.z)  { }
Vector3 & Vector3::operator = (const Vector2 & v)       { x = v.x; y = v.y; z = 0.0f; return *this; }
Vector3 & Vector3::operator = (const Vector3 & v)       { x = v.x; y = v.y; z = v.z;  return *this; }
Vector3 & Vector3::operator = (const Vector4 & v)       { x = v.x; y = v.y; z = v.z;  return *this; }
Vector3::~Vector3             ()                        { }

Vector3 Vector3::operator   + (float c)			  const { return Vector3(x + c,   y + c,   z + c); }
Vector3 Vector3::operator   + (const Vector2 & v) const { return Vector3(x + v.x, y + v.y, z); }
Vector3 Vector3::operator   + (const Vector3 & v) const { return Vector3(x + v.x, y + v.y, z + v.z); }
Vector3 Vector3::operator   + (const Vector4 & v) const { return Vector3(x + v.x, y + v.y, z + v.z); }

void Vector3::operator     += (float c)					{ x += c;   y += c;   z += c; }
void Vector3::operator     += (const Vector2 & v)       { x += v.x; y += v.y; }
void Vector3::operator     += (const Vector3 & v)       { x += v.x; y += v.y; z += v.z; }
void Vector3::operator     += (const Vector4 & v)       { x += v.x; y += v.y; z += v.z; }

Vector3 Vector3::operator   - ()                  const { return Vector3(-x, -y, -z); }

Vector3 Vector3::operator   - (float c)			  const { return Vector3(x - c,   y - c,   z - c); }
Vector3 Vector3::operator   - (const Vector2 & v) const { return Vector3(x - v.x, y - v.y, z); }
Vector3 Vector3::operator   - (const Vector3 & v) const { return Vector3(x - v.x, y - v.y, z - v.z); }
Vector3 Vector3::operator   - (const Vector4 & v) const { return Vector3(x - v.x, y - v.y, z - v.z); }

void Vector3::operator     -= (float c)					{ x -= c;   y -= c;   z -= c; }
void Vector3::operator     -= (const Vector2 & v)       { x -= v.x; y -= v.y; }
void Vector3::operator     -= (const Vector3 & v)       { x -= v.x; y -= v.y; z -= v.z; }
void Vector3::operator     -= (const Vector4 & v)       { x -= v.x; y -= v.y; z -= v.z; }

Vector3 Vector3::operator   * (float c)			  const { return Vector3(x * c,   y * c,   z * c); }
Vector3 Vector3::operator   * (const Vector2 & v) const { return Vector3(x * v.x, y * v.y, z); }
Vector3 Vector3::operator   * (const Vector3 & v) const { return Vector3(x * v.x, y * v.y, z * v.z); }
Vector3 Vector3::operator   * (const Vector4 & v) const { return Vector3(x * v.x, y * v.y, z * v.z); }

void Vector3::operator     *= (float c)					{ x *= c;   y *= c;   z *= c; }
void Vector3::operator     *= (const Vector2 & v)       { x *= v.x; y *= v.y; }
void Vector3::operator     *= (const Vector3 & v)       { x *= v.x; y *= v.y; z *= v.z; }
void Vector3::operator     *= (const Vector4 & v)       { x *= v.x; y *= v.y; z *= v.z; }

Vector3 Vector3::operator   / (float c)			  const { return Vector3(  c == 0.0f ? 0.0f : x / c,     c == 0.0f ? 0.0f : y / c,	   c == 0.0f ? 0.0f : z / c); }
Vector3 Vector3::operator   / (const Vector2 & v) const { return Vector3(v.x == 0.0f ? 0.0f : x / v.x, v.y == 0.0f ? 0.0f : y / v.y,					  z); }
Vector3 Vector3::operator   / (const Vector3 & v) const { return Vector3(v.x == 0.0f ? 0.0f : x / v.x, v.y == 0.0f ? 0.0f : y / v.y, v.z == 0.0f ? 0.0f : z / v.z); }
Vector3 Vector3::operator   / (const Vector4 & v) const { return Vector3(v.x == 0.0f ? 0.0f : x / v.x, v.y == 0.0f ? 0.0f : y / v.y, v.z == 0.0f ? 0.0f : z / v.z); }

void Vector3::operator     /= (float c)					{ x =   c == 0.0f ? 0.0f : x / c;   y =   c == 0.0f ? 0.0f : y / c;   z =   c == 0.0f ? 0.0f : z / c; }
void Vector3::operator     /= (const Vector2 & v)       { x = v.x == 0.0f ? 0.0f : x / v.x; y = v.y == 0.0f ? 0.0f : y / v.y; }
void Vector3::operator     /= (const Vector3 & v)       { x = v.x == 0.0f ? 0.0f : x / v.x; y = v.y == 0.0f ? 0.0f : y / v.y; z = v.z == 0.0f ? 0.0f : z / v.z; }
void Vector3::operator     /= (const Vector4 & v)       { x = v.x == 0.0f ? 0.0f : x / v.x; y = v.y == 0.0f ? 0.0f : y / v.y; z = v.z == 0.0f ? 0.0f : z / v.z; }

bool Vector3::operator     == (const Vector3 & v) const { return x == v.x && y == v.y && z == v.z; }
bool Vector3::operator     != (const Vector3 & v) const { return x != v.x || y != v.y || z != v.z; }

float Vector3::length		  ()				  const { return sqrt((x * x) + (y * y) + (z * z)); }
float Vector3::dot            (const Vector3 & v) const { return (x * v.x) + (y * v.y) + (z * v.z); }
Vector3 Vector3::cross        (const Vector3 & v) const { return Vector3((y * v.z) - (z * v.y), (z * v.x) - (x * v.z), (x * v.y) - (y * v.x)); }
void Vector3::normalize		  ()						{ float l = length(); if(l == 0.0f) { x = y = z = 0.0f; } else { x /= l; y /= l; z /= l; } }
Vector3 Vector3::normalized   ()				  const { float l = length(); if(l == 0.0f) { return Zero; } else { return Vector3(x / l, y / l, z / l); } }

Vector3 Vector3::parseFrom(const char * data, bool * valid) {
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
Vector3 Vector3::parseFrom(const QString & data, bool * valid) {
	static const QRegExp     nonFloatRegExp("[^-0-9.]+");
	static const QRegExp nonFloatTrimRegExp("(^[^-0-9.]+)|([^-0-9.]+$)");

	if(data.isEmpty()) {
		if(valid != NULL) { *valid = false; }
		return Zero;
	}

	QStringList parts = QString(data).replace(nonFloatTrimRegExp, "").split(nonFloatRegExp, QString::SkipEmptyParts);
	if(parts.size() != 3) {
		if(valid != NULL) { *valid = false; }
		return Zero;
	}

	Vector3 newVector;

	bool success = false;
	for(int i=0;i<3;i++) {
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
Vector3 Vector3::parseFrom(const std::string & data, bool * valid) {
	static const std::regex     nonFloatRegExp("[^-0-9.]+");
	static const std::regex nonFloatTrimRegExp("(^[^-0-9.]+)|([^-0-9.]+$)");

	std::string trimmedData;
	std::regex_replace(std::back_inserter(trimmedData), data.begin(), data.end(), nonFloatTrimRegExp, "");

	std::string formattedData;
	std::regex_replace(std::back_inserter(formattedData), trimmedData.begin(), trimmedData.end(), nonFloatRegExp, " ");

	int index = 0, start = -1, end = -1;
	std::string part;
	bool success = false;
	Vector3 newVector;
	for(int i=0;i<static_cast<int>(formattedData.length());i++) {
		if(formattedData[i] == ' ' || i == static_cast<int>(formattedData.length()) - 1) {
			if(index > 2) {
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

	if(index != 3) {
		if(valid != NULL) { *valid = false; }
		return Zero;
	}

	if(valid != NULL) { *valid = true; }
	return newVector;
}
#endif // USE_STL

#if USE_QT >= USE_STL
QString Vector3::toString() const {
	return QString("%1, %2, %3").arg(x).arg(y).arg(z);
}
#elif USE_STL
std::string Vector3::toString() const {
	return std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z);
}
#endif // USE_QT
