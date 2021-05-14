
class Vector3
{
public:
	float x, y, z;

	inline Vector3() {
		x = y = z = 0.0f;
	}

	inline Vector3(float X, float Y, float Z) {
		x = X; y = Y; z = Z;
	}

	inline float operator[](int i) const {
		return ((float*)this)[i];
	}

	inline Vector3& operator-=(float v) {
		x -= v; y -= v; z -= v; return *this;
	}

	inline Vector3 operator*(float v) const {
		return Vector3(x * v, y * v, z * v);
	}

	inline Vector3 operator/(float v) const
	{
		return Vector3(x / v, y / v, z / v);
	}

	inline Vector3& operator+=(const Vector3& v) {
		x += v.x; y += v.y; z += v.z; return *this;
	}

	inline Vector3 operator-(const Vector3& v) const {
		return Vector3(x - v.x, y - v.y, z - v.z);
	}

	inline Vector3 operator+(const Vector3& v) const {
		return Vector3(x + v.x, y + v.y, z + v.z);
	}

	inline float Length() {
		return sqrtf(x * x + y * y + z * z);
	}
};

class Vector2 {
public:
	float x, y;

	inline Vector2() {
		x = y = 0.0f;
	}

	inline Vector2 operator/(float v) const {
		return Vector2(x / v, y / v);
	}
	inline Vector2(float X, float Y) {
		x = X; y = Y;
	}

	inline Vector2 operator-(const Vector2& v) const {
		return Vector2(x - v.x, y - v.y);
	}

	inline Vector2 operator+(const Vector2& v) const {
		return Vector2(x + v.x, y + v.y);
	}

	inline Vector2& operator+=(const Vector2& v) {
		x += v.x; y += v.y; return *this;
	}

	inline bool Zero() const {
		return (x > -0.1f && x < 0.1f && y > -0.1f && y < 0.1f);
	}
};

class Vector4 {
public:
	float x, y, z, w;
};

struct Matrix4x4 {
	union {
		struct {
			float        _11, _12, _13, _14;
			float        _21, _22, _23, _24;
			float        _31, _32, _33, _34;
			float        _41, _42, _43, _44;

		}; float m[4][4];
	};
};
//float DegToRad(float deg)
//{
//	return (float)((double)deg * 0.017453292519943295);
//}
//
//bool World2Screen(Vector3 from, Vector3 rot, float fovDegree, Vector3 offset, Vector3 target, Vector3& vector, float width, float height) {
//	if (rot.x < -180.0f) rot.x += 360.0f;
//	if (rot.x > 180.0f)  rot.x -= 360.0f;
//
//	Vector3 newRot = { DegToRad(rot.x), DegToRad(rot.y), DegToRad(rot.z) };
//	float cosX = cos(newRot.x), cosY = cos(newRot.y), cosZ = cos(newRot.z),
//		sinX = sin(newRot.x), sinY = sin(newRot.y), sinZ = sin(newRot.z);
//
//	float array[3][3] = {
//		{ cosZ * cosY - sinZ * sinX * sinY, -cosX * sinZ, cosZ * sinY + cosY * sinZ * sinX },
//		{ cosY * sinZ + cosZ * sinX * sinY,  cosZ * cosX, sinZ * sinY - cosZ * cosY * sinX },
//		{ -cosX * sinY, sinX, cosX * cosY }
//	};
//
//	Vector3 vector3 = { target.x - (from.x + offset.x), target.y - (from.y + offset.y), -target.z - (-from.z + offset.z) };
//	vector3 = {
//		array[0][0] * vector3.x + array[0][1] * vector3.y + array[0][2] * vector3.z,
//		array[1][0] * vector3.x + array[1][1] * vector3.y + array[1][2] * vector3.z,
//		-(array[2][0] * vector3.x + array[2][1] * vector3.y + array[2][2] * vector3.z)
//	};
//
//	bool result = false;
//	vector.x = 0;
//	vector.y = 0;
//
//	if (vector3.z > 0.0f) {
//		float focalLength = (float)((double)(height / 2.0f) / tan((double)(DegToRad(fovDegree) / 2.0f)));
//		vector.x = focalLength * vector3.x / vector3.z + width / 2.0f;
//		vector.y = focalLength * -vector3.y / vector3.z + height / 2.0f;
//		result = true;
//	}
//
//	return result;
//}
//
//float Get3dDistance(Vector3 c1, Vector3 c2)
//{
//	//(Dx*Dx+Dy*Dy+Dz*Dz)^.5 
//	float dx = c2.x - c1.x;
//	float dy = c2.y - c1.y;
//	float dz = c2.z - c1.z;
//
//	return sqrt((float)(dx * dx + dy * dy + dz * dz));
//}
namespace Math
{
#define M_PI 3.14159265358979323846f
#define M_RADPI	57.295779513082f
#define M_PI_F ((float)(M_PI))
#define RAD2DEG(x) ((float)(x) * (float)(180.f / M_PI_F))
#define DEG2RAD(x) ((float)(x) * (float)(M_PI_F / 180.f))
#define atan2(a, b) ((float)atan2((double)(a), (double)(b)))
	static volatile const double Infinity = INFINITY;
	typedef struct { double d0, d1; } double2;


	static inline double2 Add212RightSmaller(double2 a, double b)
	{
		double
			c0 = a.d0 + b,
			c1 = a.d0 - c0 + b + a.d1,
			d0 = c0 + c1,
			d1 = c0 - d0 + c1;
		return double2{ d0, d1 };
	}

	static inline double Add221RightSmaller(double2 a, double2 b)
	{
		double
			c0 = a.d0 + b.d0,
			c1 = a.d0 - c0 + b.d0 + b.d1 + a.d1,
			d0 = c0 + c1;
		return d0;
	}

	//float abs(float a) {
	//	if (a < 0.f) return -a;
	//	else return a;
	//}

	//float asin(float x) {
	//	float negate = float(x < 0);
	//	x = abs(x);
	//	float ret = -0.0187293;
	//	ret *= x;
	//	ret += 0.0742610;
	//	ret *= x;
	//	ret -= 0.2121144;
	//	ret *= x;
	//	ret += 1.5707288;
	//	ret = 3.14159265358979 * 0.5 - sqrt(1.0 - x) * ret;
	//	return ret - 2 * negate * ret;
	//}

	__forceinline float Dot(const Vector3& Vec1, const Vector3& Vec2) {
		return Vec1[0] * Vec2[0] + Vec1[1] * Vec2[1] + Vec1[2] * Vec2[2];
	}

	__forceinline float Calc3D_Dist(const Vector3& Src, const Vector3& Dst) {
		return sqrtf(pow((Src.x - Dst.x), 2) + pow((Src.y - Dst.y), 2) + pow((Src.z - Dst.z), 2));
	}

	__forceinline float Calc2D_Dist(const Vector2& Src, const Vector2& Dst) {
		return sqrt(powf(Src.x - Dst.x, 2) + powf(Src.y - Dst.y, 2));
	}

	__forceinline Vector2 CalcAngle(const Vector3& Src, const Vector3& Dst) {
		Vector3 dir = Src - Dst;
		return Vector2{ RAD2DEG(asin(dir.y / dir.Length())), RAD2DEG(-atan2(dir.x, -dir.z)) };
	}


}

//class Vector3
//{
//public:
//	float x, y, z;
//
//	inline Vector3() {
//		x = y = z = 0.0f;
//	}
//
//	inline Vector3(float X, float Y, float Z) {
//		x = X; y = Y; z = Z;
//	}
//
//	inline float operator[](int i) const {
//		return ((float*)this)[i];
//	}
//
//	inline Vector3& operator-=(float v) {
//		x -= v; y -= v; z -= v; return *this;
//	}
//
//	inline Vector3 operator*(float v) const {
//		return Vector3(x * v, y * v, z * v);
//	}
//
//	inline Vector3 operator/(float v) const
//	{
//		return Vector3(x / v, y / v, z / v);
//	}
//
//	inline Vector3& operator+=(const Vector3& v) {
//		x += v.x; y += v.y; z += v.z; return *this;
//	}
//
//	inline Vector3 operator-(const Vector3& v) const {
//		return Vector3(x - v.x, y - v.y, z - v.z);
//	}
//
//	inline Vector3 operator+(const Vector3& v) const {
//		return Vector3(x + v.x, y + v.y, z + v.z);
//	}
//
//	inline float Length() {
//		return sqrtf(x * x + y * y + z * z);
//	}
//};
//
//class Vector2 {
//public:
//	float x, y;
//
//	inline Vector2() {
//		x = y = 0.0f;
//	}
//
//	inline Vector2 operator/(float v) const {
//		return Vector2(x / v, y / v);
//	}
//	inline Vector2(float X, float Y) {
//		x = X; y = Y;
//	}
//
//	inline Vector2 operator-(const Vector2& v) const {
//		return Vector2(x - v.x, y - v.y);
//	}
//
//	inline Vector2 operator+(const Vector2& v) const {
//		return Vector2(x + v.x, y + v.y);
//	}
//
//	inline Vector2& operator+=(const Vector2& v) {
//		x += v.x; y += v.y; return *this;
//	}
//
//	inline bool Zero() const {
//		return (x > -0.1f && x < 0.1f && y > -0.1f && y < 0.1f);
//	}
//};
//
//class Vector4 {
//public:
//	float x, y, z, w;
//};
//
//struct Matrix4x4 {
//	union {
//		struct {
//			float        _11, _12, _13, _14;
//			float        _21, _22, _23, _24;
//			float        _31, _32, _33, _34;
//			float        _41, _42, _43, _44;
//
//		}; float m[4][4];
//	};
//};
//
//namespace Math
//{
//#define M_PI 3.14159265358979323846f
//#define M_RADPI	57.295779513082f
//#define M_PI_F ((float)(M_PI))
//#define RAD2DEG(x) ((float)(x) * (float)(180.f / M_PI_F))
//#define DEG2RAD(x) ((float)(x) * (float)(M_PI_F / 180.f))
//#define atan2(a, b) ((float)atan2((double)(a), (double)(b)))
//	static volatile const double Infinity = INFINITY;
//	typedef struct { double d0, d1; } double2;
//
//
//	static inline double2 Add212RightSmaller(double2 a, double b)
//	{
//		double
//			c0 = a.d0 + b,
//			c1 = a.d0 - c0 + b + a.d1,
//			d0 = c0 + c1,
//			d1 = c0 - d0 + c1;
//		return double2{ d0, d1 };
//	}
//
//	static inline double Add221RightSmaller(double2 a, double2 b)
//	{
//		double
//			c0 = a.d0 + b.d0,
//			c1 = a.d0 - c0 + b.d0 + b.d1 + a.d1,
//			d0 = c0 + c1;
//		return d0;
//	}
//
//	float abs(float a) {
//		if (a < 0.f) return -a;
//		else return a;
//	}
//
//	float asin(float x) {
//		float negate = float(x < 0);
//		x = abs(x);
//		float ret = -0.0187293;
//		ret *= x;
//		ret += 0.0742610;
//		ret *= x;
//		ret -= 0.2121144;
//		ret *= x;
//		ret += 1.5707288;
//		ret = 3.14159265358979 * 0.5 - sqrt(1.0 - x) * ret;
//		return ret - 2 * negate * ret;
//	}
//
//	__forceinline float Dot(const Vector3& Vec1, const Vector3& Vec2) {
//		return Vec1[0] * Vec2[0] + Vec1[1] * Vec2[1] + Vec1[2] * Vec2[2];
//	}
//
//	__forceinline float Calc3D_Dist(const Vector3& Src, const Vector3& Dst) {
//		return sqrtf(pow((Src.x - Dst.x), 2) + pow((Src.y - Dst.y), 2) + pow((Src.z - Dst.z), 2));
//	}
//
//	__forceinline float Calc2D_Dist(const Vector2& Src, const Vector2& Dst) {
//		return sqrt(powf(Src.x - Dst.x, 2) + powf(Src.y - Dst.y, 2));
//	}
//
//	__forceinline Vector2 CalcAngle(const Vector3& Src, const Vector3& Dst) {
//		Vector3 dir = Src - Dst;
//		return Vector2{ RAD2DEG(asin(dir.y / dir.Length())), RAD2DEG(-atan2(dir.x, -dir.z)) };
//	}
//
//
//}