#include <iostream>
#include <cctype>
#include "Matrix.h"
#include "functions.cpp"
#define MAX_MATRIXES 2

using namespace std;
using namespace functions;
using namespace matrixFn;

int main(){

	introduccion();

	do{

		matrixType matrix[MAX_MATRIXES];

		menu(matrix);

	}while(seguir());

	cout << "\n\nGracias por usar el programa. Tenga un buen dia.\n\n";

	return 0;
}