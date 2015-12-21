#ifndef VECTOR3_H
#define VECTOR3_H

#include <math.h>
#include "Utilities/Utilities.h"

class Vector2;
class Vector4;

class Vector3 {
public:
	Vector3              (float a = 0.0f, float b = 0.0f, float c = 0.0f);
	Vector3              (const float v[3]);
	Vector3              (const Vector2 & v);
	Vector3              (const Vector3 & v);
	Vector3              (const Vector4 & v);
	Vector3 & operator = (const Vector2 & v);
	Vector3 & operator = (const Vector3 & v);
	Vector3 & operator = (const Vector4 & v);
	virtual ~Vector3	 ();
	
	Vector3 operator   + (float c)			 const;
	Vector3 operator   + (const Vector2 & v) const;
	Vector3 operator   + (const Vector3 & v) const;
	Vector3 operator   + (const Vector4 & v) const;

	void operator     += (float c);
	void operator     += (const Vector2 & v);
	void operator     += (const Vector3 & v);
	void operator     += (const Vector4 & v);

	Vector3 operator   - ()					 const;

	Vector3 operator   - (float c)			 const;
	Vector3 operator   - (const Vector2 & v) const;
	Vector3 operator   - (const Vector3 & v) const;
	Vector3 operator   - (const Vector4 & v) const;

	void operator     -= (float c);
	void operator     -= (const Vector2 & v);
	void operator     -= (const Vector3 & v);
	void operator     -= (const Vector4 & v);

	Vector3 operator   * (float c)			 const;
	Vector3 operator   * (const Vector2 & v) const;
	Vector3 operator   * (const Vector3 & v) const;
	Vector3 operator   * (const Vector4 & v) const;

	void operator     *= (float c);
	void operator     *= (const Vector2 & v);
	void operator     *= (const Vector3 & v);
	void operator     *= (const Vector4 & v);

	Vector3 operator   / (float c)			 const;
	Vector3 operator   / (const Vector2 & v) const;
	Vector3 operator   / (const Vector3 & v) const;
	Vector3 operator   / (const Vector4 & v) const;

	void operator     /= (float c);
	void operator     /= (const Vector2 & v);
	void operator     /= (const Vector3 & v);
	void operator     /= (const Vector4 & v);

	bool operator     == (const Vector3 & v) const;
	bool operator     != (const Vector3 & v) const;

	float length         ()                  const;
	float dot            (const Vector3 & v) const;
	Vector3 cross        (const Vector3 & v) const;
	void normalize       ();
	Vector3 normalized   ()                  const;

	static Vector3 parseFrom(const char * data, bool * valid = NULL);
#if USE_QT
	static Vector3 parseFrom(const QString & data, bool * valid = NULL);
#endif // USE_QT
#if USE_STL
	static Vector3 parseFrom(const std::string & data, bool * valid = NULL);
#endif // USE_STL
#if USE_QT >= USE_STL
	QString toString() const;
#elif USE_STL
	std::string toString() const;
#endif // USE_QT

public:
	static const Vector3 Zero;
	static const Vector3 One;
	static const Vector3 Forward;
	static const Vector3 Backward;
	static const Vector3 Left;
	static const Vector3 Right;
	static const Vector3 Up;
	static const Vector3 Down;

public:
	union {
		struct {
			float x, y, z;
		};
		float v[3];
	};
};

#endif // VECTOR3_H
