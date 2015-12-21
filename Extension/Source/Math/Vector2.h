#ifndef VECTOR2_H
#define VECTOR2_H

#include <math.h>
#include "Utilities/Utilities.h"

class Vector3;
class Vector4;

class Vector2 {
public:
	Vector2              (float a = 0.0f, float b = 0.0f);
	Vector2              (const float v[2]);
	Vector2              (const Vector2 & v);
	Vector2              (const Vector3 & v);
	Vector2              (const Vector4 & v);
	Vector2 & operator = (const Vector2 & v);
	Vector2 & operator = (const Vector3 & v);
	Vector2 & operator = (const Vector4 & v);
	virtual ~Vector2	 ();

	Vector2 operator   + (float c)			 const;
	Vector2 operator   + (const Vector2 & v) const;
	Vector2 operator   + (const Vector3 & v) const;
	Vector2 operator   + (const Vector4 & v) const;

	void operator     += (float c);
	void operator     += (const Vector2 & v);
	void operator     += (const Vector3 & v);
	void operator     += (const Vector4 & v);

	Vector2 operator   - ()					 const;

	Vector2 operator   - (float c)			 const;
	Vector2 operator   - (const Vector2 & v) const;
	Vector2 operator   - (const Vector3 & v) const;
	Vector2 operator   - (const Vector4 & v) const;

	void operator     -= (float c);
	void operator     -= (const Vector2 & v);
	void operator     -= (const Vector3 & v);
	void operator     -= (const Vector4 & v);

	Vector2 operator   * (float c)			 const;
	Vector2 operator   * (const Vector2 & v) const;
	Vector2 operator   * (const Vector3 & v) const;
	Vector2 operator   * (const Vector4 & v) const;

	void operator     *= (float c);
	void operator     *= (const Vector2 & v);
	void operator     *= (const Vector3 & v);
	void operator     *= (const Vector4 & v);

	Vector2 operator   / (float c)			 const;
	Vector2 operator   / (const Vector2 & v) const;
	Vector2 operator   / (const Vector3 & v) const;
	Vector2 operator   / (const Vector4 & v) const;

	void operator     /= (float c);
	void operator     /= (const Vector2 & v);
	void operator     /= (const Vector3 & v);
	void operator     /= (const Vector4 & v);

	bool operator     == (const Vector2 & v) const;
	bool operator     != (const Vector2 & v) const;

	float length         ()                  const;
	float dot            (const Vector2 & v) const;
	void normalize       ();
	Vector2 normalized   ()                  const;

	static Vector2 parseFrom(const char * data, bool * valid = NULL);
#if USE_QT
	static Vector2 parseFrom(const QString & data, bool * valid = NULL);
#endif // USE_QT
#if USE_STL
	static Vector2 parseFrom(const std::string & data, bool * valid = NULL);
#endif // USE_STL
#if USE_QT >= USE_STL
	QString toString() const;
#elif USE_STL
	std::string toString() const;
#endif // USE_QT

public:
	static const Vector2 Zero;
	static const Vector2 One;
	static const Vector2 Left;
	static const Vector2 Right;
	static const Vector2 Up;
	static const Vector2 Down;

public:
	union {
		struct {
			float x, y;
		};
		float v[2];
	};
};

#endif // VECTOR2_H
