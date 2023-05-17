#pragma once
/// <summary>
/// Big thanks to AcidLeaf on GitHub: https://gist.github.com/acidleaf/8957147
/// </summary>
class Vec2
{
public:
	Vec2() : x(0), y(0) {};
	Vec2(float x, float y) : x(x), y(y) {};
	Vec2(const Vec2& v) : x(v.x), y(v.y) {};
	Vec2& operator=(const Vec2& v) 
	{
		x = v.x;
		y = v.y;
		return *this;
	}
	Vec2 operator+(const Vec2& v)
	{
		return Vec2(x + v.x, y + v.y);
	}

	Vec2 operator-(const Vec2& v)
	{
		return Vec2(x - v.x, y - v.y);
	}

	Vec2& operator +=(Vec2& v)
	{
		x += v.x;
		y += v.y;
		return *this;
	}

	Vec2& operator -=(Vec2& v)
	{
		x -= v.x;
		y -= v.y;
		return *this;
	}

	Vec2 operator+(double s)
	{
		return Vec2(x + s, y + s);
	}

	Vec2 operator-(double s)
	{
		return Vec2(x - s, y - s);
	}

	Vec2 operator*(double s)
	{
		return Vec2(x * s, y * s);
	}

	Vec2 operator/(double s)
	{
		return Vec2(x / s, y / s);
	}

	Vec2& operator +=(double s)
	{
		x += s;
		y += s;
		return *this;
	}

	Vec2& operator -=(double s)
	{
		x -= s;
		y -= s;
		return *this;
	}

	Vec2& operator *=(double s)
	{
		x *= s;
		y *= s;
		return *this;
	}

	Vec2& operator /=(double s)
	{
		x /= s;
		y /= s;
		return *this;
	}



	
	~Vec2() {};


	float x;
	float y;
};

