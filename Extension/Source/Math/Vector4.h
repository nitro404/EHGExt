#ifndef VECTOR4_H
#define VECTOR4_H

#include <math.h>
#include "Utilities/Utilities.h"

class Vector2;
class Vector3;

class Vector4 {
public:
	Vector4				 (float a = 0.0f, float b = 0.0f, float c = 0.0f, float d = 0.0f);
	Vector4              (const float v[4]);
	Vector4				 (const Vector2 & v);
	Vector4				 (const Vector3 & v);
	Vector4				 (const Vector4 & v);
	Vector4 & operator = (const Vector2 & v);
	Vector4 & operator = (const Vector3 & v);
	Vector4 & operator = (const Vector4 & v);
	virtual ~Vector4	 ();
	
	Vector4 operator   + (float c)			 const;
	Vector4 operator   + (const Vector2 & v) const;
	Vector4 operator   + (const Vector3 & v) const;
	Vector4 operator   + (const Vector4 & v) const;

	void operator     += (float c);
	void operator     += (const Vector2 & v);
	void operator     += (const Vector3 & v);
	void operator     += (const Vector4 & v);

	Vector4 operator   - ()					 const;

	Vector4 operator   - (float c)			 const;
	Vector4 operator   - (const Vector2 & v) const;
	Vector4 operator   - (const Vector3 & v) const;
	Vector4 operator   - (const Vector4 & v) const;

	void operator     -= (float c);
	void operator     -= (const Vector2 & v);
	void operator     -= (const Vector3 & v);
	void operator     -= (const Vector4 & v);

	Vector4 operator   * (float c)			 const;
	Vector4 operator   * (const Vector2 & v) const;
	Vector4 operator   * (const Vector3 & v) const;
	Vector4 operator   * (const Vector4 & v) const;

	void operator     *= (float c);
	void operator     *= (const Vector2 & v);
	void operator     *= (const Vector3 & v);
	void operator     *= (const Vector4 & v);

	Vector4 operator   / (float c)			 const;
	Vector4 operator   / (const Vector2 & v) const;
	Vector4 operator   / (const Vector3 & v) const;
	Vector4 operator   / (const Vector4 & v) const;

	void operator     /= (float c);
	void operator     /= (const Vector2 & v);
	void operator     /= (const Vector3 & v);
	void operator     /= (const Vector4 & v);

	bool operator     == (const Vector4 & v) const;
	bool operator     != (const Vector4 & v) const;

	float length         ()                  const;
	float dot            (const Vector4 & v) const;
	void normalize       ();
	Vector4 normalized   ()                  const;

	static Vector4 parseFrom(const char * data, bool * valid = NULL);
#if USE_QT
	static Vector4 parseFrom(const QString & data, bool * valid = NULL);
#endif // USE_QT
#if USE_STL
	static Vector4 parseFrom(const std::string & data, bool * valid = NULL);
#endif // USE_STL
#if USE_QT >= USE_STL
	QString toString() const;
#elif USE_STL
	std::string toString() const;
#endif // USE_QT

public:
	static const Vector4 Zero;
	static const Vector4 One;
	static const Vector4 Forward;
	static const Vector4 Backward;
	static const Vector4 Left;
	static const Vector4 Right;
	static const Vector4 Up;
	static const Vector4 Down;

public:
	union {
		struct {
			float x, y, z, w;
		};
		float v[4];
	};
};

#endif // VECTOR4_H
