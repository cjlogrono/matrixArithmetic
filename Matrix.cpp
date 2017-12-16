#ifndef MATRIX_CPP
#define MATRIX_CPP

#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <iomanip>
#include "Matrix.h"

using namespace std;

namespace matrixFn{
	
	matrixType::matrixType(){

		number = NULL;
		totalRows = 0;
		totalColumns = 0;
	}
	
	matrixType::matrixType(int row, int column){

		totalRows = row;
		totalColumns = column;

		number = new double*[row];
		for(int i = 0; i < row; i++){

			number[i]= new double[column];
		}
	}

	matrixType::~matrixType(){

		for (int i = 0; i < totalRows; i++){

			delete [] number[i];
		}
	}

	void matrixType::setNumber(int row, int column, double value){

		number[row][column] = value;
	}

	void matrixType::setRow(int value){

		totalRows = value;
	}

	void matrixType::setColumn(int value){

		totalColumns = value;
	}

	double matrixType::getNumber(int row, int column){


		return number[row][column];
	}

	int matrixType::getRow(){

		return totalRows;
	}

	int matrixType::getColumn(){

		return totalColumns;
	}

	istream& operator >>(istream& in, matrixType& matrix){

			int row, column;
			bool invalid;
			double value;

			do{

				cout << "\nFilas = ";
				cin >> row;

				if(cin.fail()){

					cin.clear();
					cin.ignore();
					invalid = true;

					cout << "\n\n** Introdujo un caracter invalido, tratelo denuevo **\n\n";

				}else if(row < 0){

					invalid = true;
					cout << "\n\n** Introdujo un numero negativo, tratelo denuevo **\n\n";

				}else{

					invalid = false;
				}

			}while(invalid);

			matrix.setRow(row);

			do{

				cout << "\n\nColumnas = ";
				cin >> column;

				if(cin.fail()){

					cin.clear();
					cin.ignore();
					invalid = true;

					cout << "\n\n** Introdujo un caracter invalido, tratelo denuevo **\n\n";
				}else if(column < 0){

					invalid = true;
					cout << "\n\n** Introdujo un numero negativo, tratelo denuevo **\n\n";

				}else{

					invalid = false;
				}

			}while(invalid);

			matrix.setColumn(column);

			matrix.number = new double*[row];
			for(int i = 0; i < row; i++){

				matrix.number[i]= new double[column];
			}

			for(int i = 0; i < matrix.getRow(); i++){
				for(int x = 0; x < matrix.getColumn(); x++){

					cout << "\nCual es el valor de el element en la fila " << (i + 1 ) << " y columna " << (x + 1) << "?\n";
					cout << "Valor: ";
					cin >> value;

					matrix.setNumber(i, x, value);
				}
			}

			return in;
	}

	ostream& operator <<(ostream& out, const matrixType& matrix){

			for(int i = 0; i < matrix.totalRows; i++){
				
				for(int x = 0; x < matrix.totalColumns; x++){

					cout << setw(3) << matrix.number[i][x] << ' ';
				}

				cout << endl;
			}

			return out;
	}

	matrixType operator +(matrixType& matrix1, matrixType& matrix2){

			matrixType dummyMatrix(matrix1.getRow(), matrix1.getColumn());
			double total = 0;

				for (int i = 0; i < matrix1.getRow(); i++){
					for (int x = 0; x < matrix1.getColumn(); x++){
						
						total = matrix1.getNumber(i, x) + matrix2.getNumber(i, x);
						dummyMatrix.setNumber(i, x, total);
					}
				}

			return dummyMatrix;
	}

	matrixType operator -(matrixType& matrix1, matrixType& matrix2){

			matrixType dummyMatrix(matrix1.getRow(), matrix1.getColumn());
			double total = 0;

				for (int i = 0; i < matrix1.getRow(); i++){
					for (int x = 0; x < matrix1.getColumn(); x++){
						
						total = matrix1.getNumber(i, x) - matrix2.getNumber(i, x);
						dummyMatrix.setNumber(i, x, total);
					}
				}

			return dummyMatrix;
	}

	matrixType operator *(matrixType& matrix1, matrixType& matrix2){

			matrixType dummyMatrix(matrix1.getRow(), matrix2.getColumn());
			double total;

			for(int i = 0; i < matrix1.getRow(); i++){

				for(int x = 0; x < matrix2.getColumn(); x++){

					total = 0;

					for(int z = 0; z < matrix1.getColumn(); z++){

						total += matrix1.getNumber(i, z) * matrix2.getNumber(z, x);
					}

					dummyMatrix.setNumber(i, x, total);
				}
			}

			return dummyMatrix;
	}

	const matrixType& matrixType::operator=(const matrixType& rightObject){

		this->totalRows = rightObject.totalRows;
		this->totalColumns = rightObject.totalColumns;

		for(int i = 0; i < totalRows; i++){
			
			for(int x = 0; x < totalColumns; x++){
			
				this->number[i][x] = rightObject.number[i][x];
			}
		}

		return *this;
	}
}

#endif //MATRIX_CPP