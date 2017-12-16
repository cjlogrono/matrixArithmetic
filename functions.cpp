#include <iostream>
#include <fstream>
#include <string>
#include "Matrix.h"

using namespace matrixFn;

namespace functions{
	
	bool validoresFunciones(int choice, char character){

		bool truefalse;

		switch(choice){

			case 1:

				if(character == 'Y' || character == 'y' || character == 'N' || character == 'n'){

					truefalse = false;

				}else{

					truefalse = true;
					cout << "\n**Introdujo un caracter invalido**\n";

				}

				break;

			case 2:

				if(character == 'Y' || character == 'y'){

					truefalse = true;

				}
				else{

					truefalse = false;

				}

				break;

			case 3:

				if(character == '1' || character == '2' || character == '3'){

					truefalse = false;

				}
				else{

					truefalse = true;
					cout << "\n\n**Introdujo un caracter invalido**\n\n";
				}

				break;

		}

		return truefalse;
	}

	bool seguir(){

		char contestacion;

			do{

				cout << "\n\nDesea seguir usando el programa? (Y/N)\n";
				cout << "Contestacion: ";
				cin >> contestacion;

			}while(validoresFunciones(1, contestacion));

			return validoresFunciones(2, contestacion);
	}

	void introduccion(){

		cout << "\n\nBienvenidos, este programa grabara dos matrices que usted introduzira.\n";
	 	cout << "Luego le dara opciones para aniadir, restar o multiplicar estas matrices.\n";
	}

	void menu(matrixType matrix[]){

		char opcion;

		do{

			cout << "\nQue operacion deseas hacer?\n";
			cout << "1) Sumar ( + )\n";
			cout << "2) Restar ( - )\n";
			cout << "3) Multiplicar ( x )\n";
			cout << "Operacion: ";
			cin >> opcion;

		}while(validoresFunciones(3, opcion));

		cout << "\n\nCuales son las dimensiones de la primera matriz? [n x m]";
		cin >> matrix[0];

		cout << "\n\nCuales son las dimensiones de la segunda matriz? [n x m]";
		cin >> matrix[1];

		switch(opcion){

			case '1':

				if( (matrix[0].getRow() == matrix[1].getRow()) && (matrix[0].getColumn() == matrix[1].getColumn()) ){

					matrixType totalMatrix(matrix[0].getRow(), matrix[0].getColumn());

					totalMatrix = matrix[0] + matrix[1];

					cout << "\n\nMatriz resultante: \n" << totalMatrix;

				}else{

					cout << "\n\n--Las matrices no tienen las mismas dimensiones, por ende no se pueden sumar.";
				}
				break;

			case '2':
	
				if( (matrix[0].getRow() == matrix[1].getRow()) && (matrix[0].getColumn() == matrix[1].getColumn()) ){

					matrixType totalMatrix(matrix[0].getRow(), matrix[0].getColumn());
					totalMatrix = matrix[0] - matrix[1];
					cout << "\n\nMatriz resultante: \n" << totalMatrix;

				}else{

					cout << "\n\n--Las matrices no tienen las mismas dimensiones, por ende no se pueden restar.";
				}
				break;	

			case '3':

				if( (matrix[0].getColumn() == matrix[1].getRow()) ){

					matrixType totalMatrix(matrix[0].getRow(), matrix[1].getColumn());
					totalMatrix = matrix[0] * matrix[1];
					cout << "\n\nMatriz resultante: \n" << totalMatrix;

				}else{

					cout << "\n\n--El producto de la matrices no esta definida ya que el numero de columnas de\n la primera matriz no es igual al numero de filas en la segunda matriz--.";
				}
				break;			
		}

		
	}

}