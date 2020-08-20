#pragma once
#ifndef TEMPCLASS_H
#define TEMPCLASS_H
#include <iostream>
#include <vector>

using namespace std;

class Matrix
{
public:
	int Rows,
		Cols;
	vector<vector<double>> matrix;

	Matrix(int n, int m); //Matrix constructor
	Matrix(); //default Matrix contructor
	Matrix (initializer_list<initializer_list<double>> list); //Matrix contructor for initialization as {{...},{...},...}
	vector<double>& operator[] (int index); //Row of the Matrix
	Matrix operator= (Matrix MyMatrix);
	Matrix operator= (initializer_list<initializer_list<double>> list); //matrix initialization as {{...},{...},...} in code
	void show();
};
////Basic arithmetic operations with Matrixes
Matrix operator* (double k, Matrix MyMatrix);
Matrix operator* (Matrix MyMatrix, double k);
Matrix operator+ (Matrix MyMatrix1, Matrix MyMatrix2);
Matrix operator- (Matrix MyMatrix1, Matrix MyMatrix2);
Matrix operator* (Matrix MyMatrix1, Matrix MyMatrix2);
////
Matrix Inverse_GAUSS(Matrix MyMatrix); //inverse matrix
Matrix Transpose(Matrix MyMatrix); //transpose matrix


class Vector
{
public:
	
	int size;
	vector<double> MyVector;
	
	Vector(int n); // Vector constructor
	Vector();
	double& operator[] (int index);
	Vector operator= (Vector vector);
	Vector operator= (initializer_list<double> list);
	Vector(initializer_list<double> list); //vector initialization as {...}
	void show(); //show vector in console
	Vector add(double element); //add an element at the back of the vector
	Vector add(Vector vector); //add a vector at the back of the vector
	Vector get_elements(int n, int m); //get some elements of the vector between n and m positions
};
////Basic arithmethic operations with Vectors
Vector operator* (double k, Vector vector);
Vector operator* (Vector vector, double k);
Vector operator+ (Vector vector1, Vector vector2);
Vector operator+ (double k, Vector vector);
Vector operator+ (Vector vector1, double k);
Vector operator- (Vector vector1, Vector vector2);
Vector operator- (double k, Vector vector);
Vector operator- (Vector vector, double k);
Vector operator* (Matrix MyMatrix, Vector vector);
Vector CrossProduct(Vector vector1, Vector vector2); //Cross Product of two vectors
double DotProduct(Vector vector1, Vector vector2); //Dot Product of two vectors
////
#endif