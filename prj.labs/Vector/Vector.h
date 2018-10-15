#pragma once

class Vector
{
public:
	Vector() = default;
	 Vector(const int s);
	Vector(const Vector& vector);
		//Конструктор копирования
	~Vector();
	int& operator[](const int index);
	int GetSize()const;

private:
	int* data_{ nullptr };
	int size_{ 0 };
};