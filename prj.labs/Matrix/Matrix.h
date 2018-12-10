#ifndef MATRIX_HPP
#define MATRIX_HPP
class Matrix
{
public:
	Matrix() = default;
	Matrix(int sizeRows, int sizeColums);
	Matrix( Matrix& matrix);
	int& GetElement(const int rows, const int colums) const;
	~Matrix();
	int GetCountRows() const;
	int GetCountColums() const;
  Matrix& operator=(const Matrix& matrix);
private:
	int** matrix_{nullptr};
	int sizeRows_{ 0 };
	int sizeColums_{ 0 };
};
#endif //matrix_