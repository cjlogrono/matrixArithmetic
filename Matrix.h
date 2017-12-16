#ifndef MATRIX_H
#define MATRIX_H

using namespace std;

namespace matrixFn{

	class matrixType{

	public:

		matrixType();

		matrixType(int row, int column);

		~matrixType();

		void setNumber(int row, int column, double value);

		void setRow(int value);

		void setColumn(int value);

		double getNumber(int row, int column);

		int getRow();

		int getColumn();

		const matrixType& operator=(const matrixType&);

		friend ostream& operator <<(ostream& out, const matrixType& matrix);

		friend istream& operator >>(istream& in, matrixType& matrix);

		friend matrixType operator +(matrixType& matrix1, matrixType& matrix2);

		friend matrixType operator -(matrixType& matrix1, matrixType& matrix2);

		friend matrixType operator *(matrixType& matrix1, matrixType& matrix2);

	private:

		double **number;
		int totalRows;
		int totalColumns;

	};
}
#endif //MATRIX_H

#include "Matrix.cpp"