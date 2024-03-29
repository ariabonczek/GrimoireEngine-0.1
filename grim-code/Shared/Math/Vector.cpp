#include "Vector.h"
#include "Matrix.h"

#include <cmath>

NS_MATH

Vector2 Vector2::kZero = Vector2(0.0f);
Vector2 Vector2::kOne = Vector2(1.0f);
			 
Vector3 Vector3::kZero = Vector3(0.0f);
Vector3 Vector3::kOne = Vector3(1.0f);
Vector3 Vector3::kRight = Vector3(1.0f, 0.0f, 0.0f);
Vector3 Vector3::kUp = Vector3(0.0f, 1.0f, 0.0f);
Vector3 Vector3::kForward = Vector3(0.0f, 0.0f, 1.0f);

Vector4 Vector4::kZero = Vector4(0.0f);
Vector4 Vector4::kOne = Vector4(1.0f);
Vector4 Vector4::kUnitXAxis = Vector4(1.0f, 0.0f, 0.0f, 0.0f);
Vector4 Vector4::kUnitYAxis = Vector4(0.0f, 1.0f, 0.0f, 0.0f);
Vector4 Vector4::kUnitZAxis = Vector4(0.0f, 0.0f, 1.0f, 0.0f);
Vector4 Vector4::kUnitWAxis = Vector4(0.0f, 0.0f, 0.0f, 1.0f);

/////////////
// Vector2 //
/////////////
Vector2::Vector2() :x(0), y(0){}
Vector2::Vector2(float value) : x(value), y(value){}
Vector2::Vector2(float x, float y) : x(x), y(y){}

float Vector2::Length()const { return sqrtf(x * x + y * y); }
float Vector2::LengthSquared()const { return x * x + y * y; }
// TODO: use fastinvsqrt
Vector2 Vector2::Normalized()const { float val = 1.0f / sqrtf(x * x + y * y); return Vector2(x * val, y * val); }

Vector2 Vector2::operator-(){ return Vector2(-x, -y); }
Vector2 Vector2::operator+(const Vector2& v){ return Vector2(x + v.x, y + v.y); }
void Vector2::operator+=(const Vector2& v){ x = x + v.x; y = y + v.y; }
void Vector2::operator-=(const Vector2& v) { x = x - v.x; y = y - v.y; }
Vector2 Vector2::operator-(const Vector2& v) { return Vector2(x - v.x, y - v.y); }
Vector2 Vector2::operator/(const float& d){ return Vector2(x / d, y / d); }
Vector2 Vector2::operator/(const Vector2& v) { return Vector2(x / v.x, y / v.y); }
bool	Vector2::operator==(const Vector2& v){ return (x == v.x) && (y == v.y); }
bool	Vector2::operator!=(const Vector2& v){ return x != v.x || y != v.y; }
float   Vector2::operator[](const int index){ switch (index){ case 0: return x; case 1: return y; default: throw "Index out of range."; } }
Vector2 Vector2::operator*(const float& s){ return Vector2(x * s, y * s); }
Vector2 operator*(float s, const Vector2& v){ return Vector2(v.x * s, v.y * s); }


Vector2 Vector2::Add(Vector2 v1, Vector2 v2){ return Vector2(v1.x + v2.x, v1.y + v2.y); }
Vector2 Vector2::Clamp(Vector2 v, Vector2 min, Vector2 max)
{
	if (v.x < min.x)
		v.x = min.x;
	else if (v.y > max.x)
		v.x = max.x;
	if (v.y < min.y)
		v.y = min.y;
	else if (v.y > max.y)
		v.y = max.y;

	return v;
}
float   Vector2::Distance(Vector2 v1, Vector2 v2) { Vector2 v = Vector2(v1.x - v2.x, v1.y - v2.y); return sqrtf(v.x*v.x + v.y*v.y); }
float   Vector2::DistanceSquared(Vector2 v1, Vector2 v2) { Vector2 v = Vector2(v1.x - v2.x, v1.y - v2.y); return v.x*v.x + v.y*v.y; }
Vector2 Vector2::Divide(Vector2 v1, Vector2 v2) { return Vector2(v1.x / v2.x, v1.y / v2.y); }
Vector2 Vector2::Divide(Vector2 v, float d) { return Vector2(v.x / d, v.y / d); }
float   Vector2::Dot(Vector2 v1, Vector2 v2) { return v1.x * v2.x + v1.y * v2.y; }
Vector2 Vector2::Max(Vector2 v1, Vector2 v2) { return Vector2(std::max(v1.x, v2.x), std::max(v1.y, v2.y)); }
Vector2 Vector2::Min(Vector2 v1, Vector2 v2) { return Vector2(std::min(v1.x, v2.x), std::min(v1.y, v2.y)); }
Vector2 Vector2::Multiply(Vector2 v1, Vector2 v2) { return Vector2(v1.x * v2.x, v1.y * v2.y); }
Vector2 Vector2::Multiply(Vector2 v, float s) { return Vector2(v.x * s, v.y * s); }
Vector2 Vector2::Negate(Vector2 v) { return Vector2(-v.x, -v.y); }
Vector2 Vector2::Normalized(Vector2 v) { float val = 1.0f / sqrtf(v.x*v.x + v.y*v.y); return Vector2(v.x * val, v.y * val); }
Vector2 Vector2::Reflect(Vector2 v, Vector2 normal)
{
	float val = 2.0f * ((v.x * normal.x) + (v.y * normal.y));
	return Vector2(v.x - (normal.x * val), v.y - (normal.y * val));
}
Vector2 Vector2::Subtract(Vector2 v1, Vector2 v2){ return Vector2(v1.x - v2.x, v1.y - v2.y); }

/////////////
// Vector3 //
/////////////
Vector3::Vector3() : x(0), y(0), z(0){}
Vector3::Vector3(float value) : x(value), y(value), z(value){}
Vector3::Vector3(Vector2 v2, float z) : x(v2.x), y(v2.y), z(z){}
Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z){}

float Vector3::Length()const { return sqrtf(x*x + y*y + z*z); }
float Vector3::LengthSquared()const { return x*x + y*y + z*z; }
Vector3 Vector3::Normalized()const { float val = 1.0f / sqrtf(x*x + y*y + z*z); return Vector3(x * val, y * val, z * val); }

Vector3 Vector3::operator-(){ return Vector3(-x, -y, -z); }
Vector3 Vector3::operator-(const Vector3& v){ return Vector3(x - v.x, y - v.y, z - v.z); }
Vector3 Vector3::operator+(const Vector3& v) { return Vector3(x + v.x, y + v.y, z + v.z); }
void Vector3::operator+=(const Vector3& v) { x = x + v.x; y = y + v.y; z = z + v.z; }
void Vector3::operator-=(const Vector3& v) { x = x - v.x; y = y - v.y; z = z - v.z; }
Vector3 Vector3::operator/(const float& d){ return Vector3(x / d, y / d, z / d); }
Vector3 Vector3::operator/(const Vector3& v) { return Vector3(x / v.x, y / v.y, z / v.z); }
bool	Vector3::operator==(const Vector3& v){ return (x == v.x) && (y == v.y) && (z == v.z); }
bool	Vector3::operator!=(const Vector3& v){ return x != v.x || y != v.y || z != v.z; }
float   Vector3::operator[](const int index){ switch (index){ case 0: return x; case 1: return y; case 2: return z; default: throw "Index out of range."; } }
Vector3 operator*(const Vector3& v, float s){ return Vector3(v.x * s, v.y * s, v.z * s); }
Vector3 operator*(float s, const Vector3& v){ return Vector3(v.x * s, v.y * s, v.z * s); }
Vector3 operator*(const Vector3& v1, const Vector3 v2) { return Vector3(v1.x*v2.x, v1.y*v2.y, v1.z*v2.z); }

Vector3 Vector3::Add(Vector3 v1, Vector3 v2){ return Vector3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z); }
Vector3 Vector3::Clamp(Vector3 v, Vector3 min, Vector3 max)
{
	if (v.x < min.x)
		v.x = min.x;
	else if (v.y > max.x)
		v.x = max.x;
	if (v.y < min.y)
		v.y = min.y;
	else if (v.y > max.y)
		v.y = max.y;
	if (v.z < min.z)
		v.z = min.z;
	else if (v.z > max.z)
		v.z = max.z;

	return v;
}

Vector3 Vector3::Cross(Vector3 v1, Vector3 v2) { float x = v1.y * v2.z - v1.z * v2.y; float y = v1.z * v2.x - v1.x * v2.z; float z = v1.x * v2.y - v1.y * v2.x; return Vector3(x, y, z); }
float   Vector3::Distance(Vector3 v1, Vector3 v2) { Vector3 v = Vector3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z); return sqrtf(v.x*v.x + v.y*v.y + v.z*v.z); }
float   Vector3::DistanceSquared(Vector3 v1, Vector3 v2) { Vector3 v = Vector3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z); return v.x*v.x + v.y*v.y + v.z*v.z; }
Vector3 Vector3::Divide(Vector3 v1, Vector3 v2) { return Vector3(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z); }
Vector3 Vector3::Divide(Vector3 v, float d) { return Vector3(v.x / d, v.y / d, v.z / d); }
float   Vector3::Dot(Vector3 v1, Vector3 v2) { return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z; }
Vector3 Vector3::Lerp(Vector3 v1, Vector3 v2, float t) { return Vector3(lerp(v1.x, v2.x, t), lerp(v1.y, v2.y, t), lerp(v1.z, v2.z, t)); }
Vector3 Vector3::Max(Vector3 v1, Vector3 v2) { return Vector3(std::max(v1.x, v2.x), std::max(v1.y, v2.y), std::max(v1.z, v2.z)); }
Vector3 Vector3::Min(Vector3 v1, Vector3 v2) { return Vector3(std::min(v1.x, v2.x), std::min(v1.y, v2.y), std::min(v1.z, v2.z)); }
Vector3 Vector3::Multiply(Vector3 v1, Vector3 v2) { return Vector3(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z); }
Vector3 Vector3::Multiply(Vector3 v, float s) { return Vector3(v.x * s, v.y * s, v.z * s); }
Vector3 Vector3::Negate(Vector3 v) { return Vector3(-v.x, -v.y, -v.z); }
Vector3 Vector3::Normalize(Vector3 v) { float val = 1.0f / sqrtf(v.x*v.x + v.y*v.y + v.z*v.z); return Vector3(v.x * val, v.y * val, v.z * val); }
Vector3 Vector3::Reflect(Vector3 v, Vector3 normal)
{
	float val = 2.0f * ((v.x * normal.x) + (v.y * normal.y) + (v.z * normal.z));
	return Vector3(v.x - (normal.x * val), v.y - (normal.y * val), v.z - (normal.z * val));
}
Vector3 Vector3::Subtract(Vector3 v1, Vector3 v2){ return Vector3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z); }

/////////////
// Vector4 //
/////////////
Vector4::Vector4() : x(0), y(0), z(0), w(0){}
Vector4::Vector4(float value) : x(value), y(value), z(value), w(value){}
Vector4::Vector4(Vector3 v3, float w) : x(v3.x), y(v3.y), z(v3.z), w(w){}
Vector4::Vector4(Vector2 v2, float z, float w) : x(v2.x), y(v2.y), z(z), w(w){}
Vector4::Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w){}

float Vector4::Length()const { return sqrtf(x*x + y*y + z*z + w*w); }
float Vector4::LengthSquared()const { return x*x + y*y + z*z + w*w; }
Vector4 Vector4::Normalized() const { float val = 1.0f / sqrtf(x*x + y*y + z*z + w*w); return Vector4(x * val, y * val, z * val, w * val); }
Vector3 Vector4::AsVector3() const { return Vector3(x, y, z); }

Vector4 Vector4::operator-()const { return Vector4(-x, -y, -z, -w); }
Vector4 Vector4::operator-(const Vector4& v)const { return Vector4(x - v.x, y - v.y, z - v.z, w - v.w); }
Vector4 Vector4::operator/(const float& d)const { return Vector4(x / d, y / d, z / d, w / d); }
Vector4 Vector4::operator/(const Vector4& v) const { return Vector4(x / v.x, y / v.y, z / v.z, w / v.w); }
bool	Vector4::operator==(const Vector4& v)const { return (x == v.x) && (y == v.y) && (z == v.z) && (w == v.z); }
bool	Vector4::operator!=(const Vector4& v)const { return x != v.x || y != v.y || z != v.z || w != v.w; }
float   Vector4::operator[](const int index)const { switch (index){ case 0: return x; case 1: return y; case 2: return z; case 3: return w; default: throw "Index out of range."; } }
Vector4 operator*(const Vector4& v, float s){ return Vector4(v.x * s, v.y * s, v.z * s, v.w * s); }
Vector4 operator*(float s, const Vector4& v){ return Vector4(v.x * s, v.y * s, v.z * s, v.w * s); }

Vector4 Vector4::Add(Vector4 v1, Vector4 v2){ return Vector4(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w); }
Vector4 Vector4::Clamp(Vector4 v, Vector4 min, Vector4 max)
{
	if (v.x < min.x)
		v.x = min.x;
	else if (v.y > max.x)
		v.x = max.x;
	if (v.y < min.y)
		v.y = min.y;
	else if (v.y > max.y)
		v.y = max.y;
	if (v.z < min.z)
		v.z = min.z;
	else if (v.z > max.z)
		v.z = max.z;
	if (v.w < min.w)
		v.w = min.w;
	else if (v.w > max.w)
		v.w = max.w;

	return v;
}
float   Vector4::Distance(Vector4 v1, Vector4 v2) { Vector4 v = Vector4(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w); return sqrtf(v.x*v.x + v.y*v.y + v.z*v.z + v.w*v.w); }
float   Vector4::DistanceSquared(Vector4 v1, Vector4 v2) { Vector4 v = Vector4(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w); return v.x*v.x + v.y*v.y + v.z*v.z + v.w*v.w; }
Vector4 Vector4::Divide(Vector4 v1, Vector4 v2) { return Vector4(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z, v1.w / v2.w); }
Vector4 Vector4::Divide(Vector4 v, float d) { return Vector4(v.x / d, v.y / d, v.z / d, v.w / d); }
float   Vector4::Dot(Vector4 v1, Vector4 v2) { return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w; }
Vector4 Vector4::Max(Vector4 v1, Vector4 v2) { return Vector4(std::max(v1.x, v2.x), std::max(v1.y, v2.y), std::max(v1.z, v2.z), std::max(v1.w, v2.w)); }
Vector4 Vector4::Min(Vector4 v1, Vector4 v2) { return Vector4(std::min(v1.x, v2.x), std::min(v1.y, v2.y), std::min(v1.z, v2.z), std::min(v1.w, v2.w)); }
Vector4 Vector4::Multiply(Vector4 v1, Vector4 v2) { return Vector4(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z, v1.w * v2.w); }
Vector4 Vector4::Multiply(Vector4 v, float s) { return Vector4(v.x * s, v.y * s, v.z * s, v.w * s); }
Vector4 Vector4::Negate(Vector4 v) { return Vector4(-v.x, -v.y, -v.z, -v.w); }
Vector4 Vector4::Normalized(Vector4 v) { float val = 1.0f / sqrtf(v.x*v.x + v.y*v.y + v.z*v.z + v.w*v.w); return Vector4(v.x * val, v.y * val, v.z * val, v.w * val); }
Vector4 Vector4::Reflect(Vector4 v, Vector4 normal)
{
	float val = 2.0f * ((v.x * normal.x) + (v.y * normal.y) + (v.z * normal.z) + (v.w * normal.w));
	return Vector4(v.x - (normal.x * val), v.y - (normal.y * val), v.z - (normal.z * val), v.w - (normal.w * val));
}
Vector4 Vector4::Subtract(Vector4 v1, Vector4 v2){ return Vector4(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w); }

Vector3 operator+(const Vector3& l, const Vector3& r)
{
	return Vector3(l.x + r.x, l.y + r.y, l.z + r.z);
}

Vector3 operator*(const Vector3& l, const Vector3& r)
{
	return Vector3(l.x * r.x, l.y * r.y, l.z * r.z);
}

Vector3 Vector3::operator*(const Matrix& m)
{
	return Vector3(x * m.row[0].x + y * m.row[1].x + z * m.row[2].x + m.row[3].x,
		x * m.row[0].y + y * m.row[1].y + z * m.row[2].y + m.row[3].y,
		x * m.row[0].z + y * m.row[1].z + z * m.row[2].z + m.row[3].z);
}

Vector3 operator*(const Vector3& l, const Matrix& r)
{
	return Vector3(l.x * r.row[0].x + l.y * r.row[1].x + l.z * r.row[2].x,
		l.x * r.row[0].y + l.y * r.row[1].y + l.z * r.row[2].y,
		l.x * r.row[0].z + l.y * r.row[1].z + l.z * r.row[2].z);
}

Vector4 operator+(const Vector4& l, const Vector4& r)
{
	return Vector4(l.x + r.x, l.y + r.y, l.z + r.z, l.w + r.w);
}

Vector4 operator*(const Vector4& l, const Vector4& r)
{
	return Vector4(l.x * r.x, l.y * r.y, l.z * r.z, l.w * r.w);
}

Vector4 Vector4::operator*(const Matrix& m)
{
	return Vector4(
		x * m.row[0].x + y * m.row[1].x + z * m.row[2].x + w * m.row[3].x,
		x * m.row[0].y + y * m.row[1].y + z * m.row[2].y + w * m.row[3].y,
		x * m.row[0].z + y * m.row[1].z + z * m.row[2].z + w * m.row[3].z,
		x * m.row[0].w + y * m.row[1].w + z * m.row[2].w + w * m.row[3].w);
}

Vector4 operator*(const Vector4& l, const Matrix& r)
{
	return Vector4(
		l.x * r.row[0].x + l.y * r.row[1].x + l.z * r.row[2].x + l.w * r.row[3].x,
		l.x * r.row[0].y + l.y * r.row[1].y + l.z * r.row[2].y + l.w * r.row[3].y,
		l.x * r.row[0].z + l.y * r.row[1].z + l.z * r.row[2].z + l.w * r.row[3].z,
		l.x * r.row[0].w + l.y * r.row[1].w + l.z * r.row[2].w + l.w * r.row[3].w);
}

NS_MATH_END