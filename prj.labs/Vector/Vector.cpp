#include "vector.h" 

	Vector::Vector(const int s)
		:size_(s)
		, data_(new int[size_])
	{
	}

	Vector::Vector(const Vector& vector)
		//Конструктор копирования
		:Vector(vector.size_)
	{
		for (int i = 0; i < size_; i++)
		{
			data_[i] = vector.data_[i];
		}
	}

	Vector::~Vector()
	{
		delete[] data_;
		data_ = nullptr;
	}

	int& Vector::operator[](const int index)
	{
		if ((index < 0) || (index >= size_)) throw "error";
		return data_[index];
	};
	int Vector::GetSize()const
	{
		return size_;
	}



