#include <iostream>
#include "MatrixLibrary.h"
#include <vector>

using namespace std;

Matrix::Matrix(int n, int m) {
	Rows = n;
	Cols = m;
	matrix = vector<vector<double>>(Rows, vector<double>(Cols, 0));
}

Matrix::Matrix() {
	Rows = NULL;
	Cols = NULL;
	matrix = vector<vector<double>>(Rows, vector<double>(Cols, 0));
}

Matrix::Matrix(initializer_list<initializer_list<double>> list) {
	int j = 0;
	Rows = list.size();
	Cols = list.begin()->size();
	matrix = vector<vector<double>>(Rows, vector<double>(Cols, 0));
	for (auto& x : list) {
		matrix[j] = x;
		j++;
	}
}

vector<double>& Matrix::operator[] (int index) {
	return matrix[index];
}

Matrix Matrix::operator= (Matrix MyMatrix) {

	Cols = MyMatrix.Cols;
	Rows = MyMatrix.Rows;
	matrix = vector<vector<double>>(Rows, vector<double>(Cols, 0));

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			matrix[i][j] = MyMatrix.matrix[i][j];
		}
	}
	return *this;
}

Matrix Matrix::operator= (initializer_list<initializer_list<double>> list) {
	int j = 0;
	Rows = list.size();
	Cols = list.begin()->size();
	matrix = vector<vector<double>>(Rows, vector<double>(Cols, 0));
	for (auto& x : list) {
		matrix[j] = x;
		j++;
		}
	return *this;
}

void Matrix::show() {
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			printf("%25.20f", matrix[i][j]);
		}
		cout << endl;
	}
}

Matrix operator+ (Matrix MyMatrix1, Matrix MyMatrix2) {
	Matrix final(MyMatrix1.Rows, MyMatrix1.Cols);
	for (int i = 0; i < MyMatrix1.Rows; i++)
	{
		for (int j = 0; j < MyMatrix1.Cols; j++)
		{
			final.matrix[i][j] = MyMatrix1.matrix[i][j] + MyMatrix2.matrix[i][j];
		}
	}
	return final;
}


Matrix operator- (Matrix MyMatrix1, Matrix MyMatrix2) {
	Matrix final(MyMatrix1.Rows, MyMatrix1.Cols);
	for (int i = 0; i < MyMatrix1.Rows; i++)
	{
		for (int j = 0; j < MyMatrix1.Cols; j++)
		{
			final.matrix[i][j] = MyMatrix1.matrix[i][j] - MyMatrix2.matrix[i][j];
		}
	}
	return final;
}
Matrix operator* (Matrix MyMatrix1, Matrix MyMatrix2) {
	Matrix final(MyMatrix1.Rows, MyMatrix2.Cols);
	for (int i = 0; i < MyMatrix1.Rows; i++)
	{
		for (int j = 0; j < MyMatrix2.Cols; j++)
		{
			final.matrix[i][j] = 0;
			for (int k = 0; k < MyMatrix1.Cols; k++)
			{
				final.matrix[i][j] += MyMatrix1.matrix[i][k] * MyMatrix2.matrix[k][j];
			}
		}
	}
	return final;
}

Matrix operator* (Matrix MyMatrix, double k) {
	Matrix final(MyMatrix.Rows, MyMatrix.Cols);
	for (int i = 0; i < MyMatrix.Rows; i++)
	{
		for (int j = 0; j < MyMatrix.Cols; j++)
		{
			final.matrix[i][j] = MyMatrix.matrix[i][j] * k;
		}
	}
	return final;
}

Matrix operator* (double k, Matrix MyMatrix) {
	Matrix final(MyMatrix.Rows, MyMatrix.Cols);
	for (int i = 0; i < MyMatrix.Rows; i++)
	{
		for (int j = 0; j < MyMatrix.Cols; j++)
		{
			final.matrix[i][j] = MyMatrix.matrix[i][j] * k;
		}
	}
	return final;
}
Matrix Transpose(Matrix MyMatrix)
{
	Matrix Buf_matr(MyMatrix.Cols, MyMatrix.Rows);

	for (int i = 0; i < MyMatrix.Rows; i++)
		for (int j = 0; j < MyMatrix.Cols; j++)
		{
			Buf_matr[j][i] = MyMatrix[i][j];
		}
	return Buf_matr;
}
Matrix Inverse_GAUSS(Matrix MyMatrix) {
	{
		double temp;
		Matrix E(MyMatrix.Rows, MyMatrix.Rows);
		Matrix M(MyMatrix.Rows, MyMatrix.Rows);
		for (int i = 0; i < E.Rows; i++)
			for (int j = 0; j < E.Rows; j++)
			{
				M.matrix[i][j] = MyMatrix.matrix[i][j];
			}

		for (int i = 0; i < E.Rows; i++)
			for (int j = 0; j < E.Rows; j++)
			{
				E.matrix[i][j] = 0.0;

				if (i == j)
					E.matrix[i][j] = 1.0;
			}

		for (int k = 0; k < E.Rows; k++)
		{
			temp = MyMatrix.matrix[k][k];

			for (int j = 0; j < E.Rows; j++)
			{
				MyMatrix.matrix[k][j] /= temp;
				E.matrix[k][j] /= temp;
			}

			for (int i = k + 1; i < E.Rows; i++)
			{
				temp = MyMatrix.matrix[i][k];

				for (int j = 0; j < E.Rows; j++)
				{
					MyMatrix.matrix[i][j] -= MyMatrix.matrix[k][j] * temp;
					E.matrix[i][j] -= E.matrix[k][j] * temp;
				}
			}
		}

		for (int k = E.Rows - 1; k > 0; k--)
		{
			for (int i = k - 1; i >= 0; i--)
			{
				temp = MyMatrix.matrix[i][k];

				for (int j = 0; j < E.Rows; j++)
				{
					MyMatrix.matrix[i][j] -= MyMatrix.matrix[k][j] * temp;
					E.matrix[i][j] -= E.matrix[k][j] * temp;
				}
			}
		}
		for (int i = 0; i < E.Rows; i++)
			for (int j = 0; j < E.Rows; j++)
			{
				MyMatrix.matrix[i][j] = M.matrix[i][j];
			}
		return E;
	}
}


Vector::Vector(int n) {
	size = n;
	MyVector = vector<double> (size, 0);
}
Vector::Vector() {
	size = NULL;
	MyVector = vector<double>(size, 0);
}

Vector::Vector(initializer_list<double> list) {
	int i = 0;
	size = list.size();
	MyVector = vector<double>(size, 0);
	for (auto& element : list) {
		MyVector[i] = element;
		i++;
	}
}

double& Vector::operator[] (int index) {
	return MyVector[index];
}

Vector Vector::operator= (Vector vectoR) {
	size = vectoR.size;
	MyVector = vector<double> (size, 0);

	for (int i = 0; i < size; i++) {
		MyVector[i] = vectoR.MyVector[i];
	}
	return *this;
}

Vector Vector::operator= (initializer_list<double> list) {
	int i = 0;
	size = list.size();
	MyVector = vector<double>(size, 0);
	for (auto &element:list) {
		MyVector[i] = element;
		i++;
	}
	return *this;
}

Vector operator* (double k, Vector vector) {
	Vector final(vector.size);
	for (int i = 0; i < vector.size; i++) {
		final.MyVector[i] = vector.MyVector[i] * k;
	}
	return final;
}

Vector operator* (Vector vector, double k) {
	Vector final(vector.size);
	for (int i = 0; i < vector.size; i++) {
		final.MyVector[i] = vector.MyVector[i] * k;
	}
	return final;
}

Vector operator+ (Vector vector1, Vector vector2) {
	Vector final(vector1.size);
	if (vector1.size == vector2.size) {
		for (int i = 0; i < vector1.size; i++) {
			final.MyVector[i] = vector1.MyVector[i] + vector2.MyVector[i];
		}
	}
	else {
		cout << "vectors of different lengths cannot be added" << endl;
	}
	return final;
}

Vector operator+ (double k, Vector vector) {
	Vector final(vector.size);
	for (int i = 0; i < vector.size; i++) {
		final.MyVector[i] = vector.MyVector[i] + k;
	}
	return final;
}

Vector operator+ (Vector vector, double k) {
	Vector final(vector.size);
	for (int i = 0; i < vector.size; i++) {
		final.MyVector[i] = vector.MyVector[i] + k;
	}
	return final;
}

Vector operator- (Vector vector1, Vector vector2) {
	Vector final(vector1.size);
	for (int i = 0; i < vector1.size; i++) {
		final.MyVector[i] = vector1.MyVector[i] - vector2.MyVector[i];
	}
	return final;
}

Vector operator- (Vector vector, double k) {
	Vector final(vector.size);
	for (int i = 0; i < vector.size; i++) {
		final.MyVector[i] = vector.MyVector[i] - k;
	}
	return final;
}

Vector operator- (double k, Vector vector) {
	Vector final(vector.size);
	for (int i = 0; i < vector.size; i++) {
		final.MyVector[i] = vector.MyVector[i] - k;
	}
	return final;
}

Vector operator* (Matrix MyMatrix, Vector vector) {
	Vector final(vector.size);
	for (int i = 0; i < MyMatrix.Rows; i++)
	{
		final.MyVector[i] = 0;
		for (int k = 0; k < MyMatrix.Cols; k++)
		{
			final.MyVector[i] += MyMatrix.matrix[i][k] * vector.MyVector[k];
		}
	}
	return final;
}
void Vector::show() {
	for (int i = 0; i < size; i++)
	{
		printf("%25.20f", MyVector[i]);
		cout << endl;
	}
}

Vector Vector::add(double element) {
	MyVector.push_back(element);
	size += 1;
	return *this;
}

Vector Vector::add(Vector vector) {
	for (int i = 0; i < vector.size; i++) {
		MyVector.push_back(vector.MyVector[i]);
		size++;
	}
	return *this;
}

Vector Vector::get_elements(int n, int m ) {
	Vector final;
	for (int i = n; i <= m; i++) {
		final.MyVector.push_back(MyVector[i]);
		final.size++;
	}
	return final;
}

Vector CrossProduct(Vector vector1, Vector vector2) {
	if (vector1.size > 3 or vector2.size > 3) {
		cout << "Size of vector must be smaller than 3 or equal" << endl;
		return 0;
	}
	else {
		return Vector({ (vector1[1] * vector2[2] - vector1[2] * vector2[1]),
						(vector1[2] * vector2[0] - vector1[0] * vector2[2]),
						(vector1[0] * vector2[1] - vector1[1] * vector2[0]) });
	}
}

double DotProduct(Vector vector1, Vector vector2) {
	double Equal = 0.0;
	for (int i = 0; i < vector1.size; i++) {
		Equal += vector1[i] * vector2[i];
	}
	return Equal;
}