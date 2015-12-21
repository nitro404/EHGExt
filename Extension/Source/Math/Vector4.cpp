#include "Math/Vector2.h"
#include "Math/Vector3.h"
#include "Math/Vector4.h"

const Vector4 Vector4::Zero	   ( 0.0f,  0.0f,  0.0f,  0.0f);
const Vector4 Vector4::One	   ( 1.0f,  1.0f,  1.0f,  1.0f);
const Vector4 Vector4::Forward ( 0.0f,  0.0f, -1.0f,  0.0f);
const Vector4 Vector4::Backward( 0.0f,  0.0f,  1.0f,  0.0f);
const Vector4 Vector4::Left    (-1.0f,  0.0f,  0.0f,  0.0f);
const Vector4 Vector4::Right   ( 1.0f,  0.0f,  0.0f,  0.0f);
const Vector4 Vector4::Up      ( 0.0f,  1.0f,  0.0f,  0.0f);
const Vector4 Vector4::Down    ( 0.0f, -1.0f,  0.0f,  0.0f);

Vector4::Vector4              (float a, float b, float c, float d) : x(a), y(b), z(c), w(d)  { }
Vector4::Vector4              (const float v[4])		: x(v[0]), y(v[1]), z(v[2]), w(v[3]) { }
Vector4::Vector4              (const Vector2 & v)       : x(v.x),  y(v.y),  z(0.0f), w(0.0f) { }
Vector4::Vector4              (const Vector3 & v)       : x(v.x),  y(v.y),  z(v.z),  w(0.0f) { }
Vector4::Vector4              (const Vector4 & v)       : x(v.x),  y(v.y),  z(v.z),  w(v.w)  { }
Vector4 & Vector4::operator = (const Vector2 & v)       { x = v.x; y = v.y; z = 0.0f; w = 0.0f; return *this; }
Vector4 & Vector4::operator = (const Vector3 & v)       { x = v.x; y = v.y; z = v.z;  w = 0.0f; return *this; }
Vector4 & Vector4::operator = (const Vector4 & v)       { x = v.x; y = v.y; z = v.z;  w = v.w;  return *this; }
Vector4::~Vector4             ()                        { }

Vector4 Vector4::operator   + (float c)			  const { return Vector4(x + c,   y + c,   z + c,   w + c); }
Vector4 Vector4::operator   + (const Vector2 & v) const { return Vector4(x + v.x, y + v.y, z,       w); }
Vector4 Vector4::operator   + (const Vector3 & v) const { return Vector4(x + v.x, y + v.y, z + v.z, w); }
Vector4 Vector4::operator   + (const Vector4 & v) const { return Vector4(x + v.x, y + v.y, z + v.z, w + v.w); }

void Vector4::operator     += (float c)					{ x += c;   y += c;   z += c;   w += c; }
void Vector4::operator     += (const Vector2 & v)       { x += v.x; y += v.y; }
void Vector4::operator     += (const Vector3 & v)       { x += v.x; y += v.y; z += v.z; }
void Vector4::operator     += (const Vector4 & v)       { x += v.x; y += v.y; z += v.z; w += v.w; }

Vector4 Vector4::operator   - ()                  const { return Vector4(-x, -y, -z, -w); }

Vector4 Vector4::operator   - (float c)			  const { return Vector4(x - c,   y - c,   z - c,   w - c); }
Vector4 Vector4::operator   - (const Vector2 & v) const { return Vector4(x - v.x, y - v.y, z,       w); }
Vector4 Vector4::operator   - (const Vector3 & v) const { return Vector4(x - v.x, y - v.y, z - v.z, w); }
Vector4 Vector4::operator   - (const Vector4 & v) const { return Vector4(x - v.x, y - v.y, z - v.z, w - v.w); }

void Vector4::operator     -= (float c)					{ x -= c;   y -= c;   z -= c;   w -= c; }
void Vector4::operator     -= (const Vector2 & v)       { x -= v.x; y -= v.y; }
void Vector4::operator     -= (const Vector3 & v)       { x -= v.x; y -= v.y; z -= v.z; }
void Vector4::operator     -= (const Vector4 & v)       { x -= v.x; y -= v.y; z -= v.z; w -= v.w; }

Vector4 Vector4::operator   * (float c)			  const { return Vector4(x * c,   y * c,   z * c,   w * c); }
Vector4 Vector4::operator   * (const Vector2 & v) const { return Vector4(x * v.x, y * v.y, z,       w); }
Vector4 Vector4::operator   * (const Vector3 & v) const { return Vector4(x * v.x, y * v.y, z * v.z, w); }
Vector4 Vector4::operator   * (const Vector4 & v) const { return Vector4(x * v.x, y * v.y, z * v.z, w * v.w); }

void Vector4::operator     *= (float c)					{ x *= c;   y *= c;   z *= c;   w *= c; }
void Vector4::operator     *= (const Vector2 & v)       { x *= v.x; y *= v.y; }
void Vector4::operator     *= (const Vector3 & v)       { x *= v.x; y *= v.y; z *= v.z; }
void Vector4::operator     *= (const Vector4 & v)       { x *= v.x; y *= v.y; z *= v.z; w *= v.w; }

Vector4 Vector4::operator   / (float c)			  const { return Vector4(  c == 0.0f ? 0.0f : x / c,     c == 0.0f ? 0.0f : y / c,     c == 0.0f ? 0.0f : z / c,     c == 0.0f ? 0.0f : w / c); }
Vector4 Vector4::operator   / (const Vector2 & v) const { return Vector4(v.x == 0.0f ? 0.0f : x / v.x, v.y == 0.0f ? 0.0f : y / v.y,                      z,                            w); }
Vector4 Vector4::operator   / (const Vector3 & v) const { return Vector4(v.x == 0.0f ? 0.0f : x / v.x, v.y == 0.0f ? 0.0f : y / v.y, v.z == 0.0f ? 0.0f : z / v.z,                      w); }
Vector4 Vector4::operator   / (const Vector4 & v) const { return Vector4(v.x == 0.0f ? 0.0f : x / v.x, v.y == 0.0f ? 0.0f : y / v.y, v.z == 0.0f ? 0.0f : z / v.z, v.w == 0.0f ? 0.0f : w / v.w); }

void Vector4::operator     /= (float c)					{ x =   c == 0.0f ? 0.0f : x / c;   y =   c == 0.0f ? 0.0f : y / c;   z =   c == 0.0f ? 0.0f : z / c;   w =   c == 0.0f ? 0.0f : w / c; }
void Vector4::operator     /= (const Vector2 & v)       { x = v.x == 0.0f ? 0.0f : x / v.x; y = v.y == 0.0f ? 0.0f : y / v.y; }
void Vector4::operator     /= (const Vector3 & v)       { x = v.x == 0.0f ? 0.0f : x / v.x; y = v.y == 0.0f ? 0.0f : y / v.y; z = v.z == 0.0f ? 0.0f : z / v.z; }
void Vector4::operator     /= (const Vector4 & v)       { x = v.x == 0.0f ? 0.0f : x / v.x; y = v.y == 0.0f ? 0.0f : y / v.y; z = v.z == 0.0f ? 0.0f : z / v.z; w = v.w == 0.0f ? 0.0f : w / v.w; }

bool Vector4::operator     == (const Vector4 & v) const { return x == v.x && y == v.y && z == v.z && w == v.w; }
bool Vector4::operator     != (const Vector4 & v) const { return x != v.x || y != v.y || z != v.z || w != v.w; }

float Vector4::length		  ()				  const { return sqrt((x * x) + (y * y) + (z * z) + (w * w)); }
float Vector4::dot            (const Vector4 & v) const { return (x * v.x) + (y * v.y) + (z * v.z) + (w * v.w); }
void Vector4::normalize		  ()						{ float l = length(); if(l == 0.0f) { x = y = z = w = 0.0f; } else { x /= l; y /= l; z /= l; w /= l; } }
Vector4 Vector4::normalized   ()				  const { float l = length(); if(l == 0.0f) { return Zero; } else { return Vector4(x / l, y / l, z / l, w / l); } }

Vector4 Vector4::parseFrom(const char * data, bool * valid) {
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
Vector4 Vector4::parseFrom(const QString & data, bool * valid) {
	static const QRegExp     nonFloatRegExp("[^-0-9.]+");
	static const QRegExp nonFloatTrimRegExp("(^[^-0-9.]+)|([^-0-9.]+$)");

	if(data.isEmpty()) {
		if(valid != NULL) { *valid = false; }
		return Zero;
	}

	QStringList parts = QString(data).replace(nonFloatTrimRegExp, "").split(nonFloatRegExp, QString::SkipEmptyParts);
	if(parts.size() != 4) {
		if(valid != NULL) { *valid = false; }
		return Zero;
	}

	Vector4 newVector;

	bool success = false;
	for(int i=0;i<4;i++) {
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
Vector4 Vector4::parseFrom(const std::string & data, bool * valid) {
	static const std::regex     nonFloatRegExp("[^-0-9.]+");
	static const std::regex nonFloatTrimRegExp("(^[^-0-9.]+)|([^-0-9.]+$)");

	std::string trimmedData;
	std::regex_replace(std::back_inserter(trimmedData), data.begin(), data.end(), nonFloatTrimRegExp, "");

	std::string formattedData;
	std::regex_replace(std::back_inserter(formattedData), trimmedData.begin(), trimmedData.end(), nonFloatRegExp, " ");

	int index = 0, start = -1, end = -1;
	std::string part;
	bool success = false;
	Vector4 newVector;
	for(int i=0;i<static_cast<int>(formattedData.length());i++) {
		if(formattedData[i] == ' ' || i == static_cast<int>(formattedData.length()) - 1) {
			if(index > 3) {
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

	if(index != 4) {
		if(valid != NULL) { *valid = false; }
		return Zero;
	}

	if(valid != NULL) { *valid = true; }
	return newVector;
}
#endif // USE_STL

#if USE_QT >= USE_STL
QString Vector4::toString() const {
	return QString("%1, %2, %3, %4").arg(x).arg(y).arg(z).arg(w);
}
#elif USE_STL
std::string Vector4::toString() const {
	return std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ", " + std::to_string(w);
}
#endif // USE_QT
