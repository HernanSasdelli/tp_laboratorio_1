/*
 ============================================================================
 Name        : TP_1.c
 Author      : Hernan Sasdelli
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ===================================ss=========================================
 */

#include "UTN_BIBLIOTECA.h"

int main(void)
{
	setbuf(stdout,NULL);

	float operadorUno;
	float operadorDos;
	int opcion;
	char respuesta;

	int banderaOpeUno;
	int banderaOpeDos;
	int banderaResultados;

	int validar;
	int validarSum;
	int validarRes;
	int validarDiv;
	int validarFac1;
	int validarFac2;
	int validarMul;

	float suma;
	float resta;
	float producto;
	float cociente;
	int factorialUno;
	int factorialDos;

	operadorUno=0;
	operadorDos=0;
	banderaOpeUno =0;
	banderaOpeDos=0;
	banderaResultados=0;

	inicializarProgramas();
		do
		{
			puts("_______________________________\n");
			printf("1-Ingrese Operador A\tA=%.2f\n",operadorUno);
			printf("2-Ingrese Operador B\tB=%.2f\n",operadorDos);
			puts("3-Calcular Operadores");
			puts("4-Mostrar Resultados");
			puts("5-Salir");
			puts("_______________________________");

			validar=getIntMaxYMin(&opcion,6,0,"Ingrese opcion:");

			if(validar == -1)
			{
				puts("\nERROR: Por favor ingrese opcion valida\n");
			}
			else
			{
				switch(opcion)
				{
					case 1:
						do
						{
							validar=getFloat(&operadorUno,"Ingrese Operador A");
							if(validar==-1)
							{
								puts("\nERROR: Por Favor, Ingrese Numero Valido\n");
							}
							else
							{
								banderaOpeUno=1;
								banderaResultados=0;
							}
						}while(validar!=0);


					break;
					case 2:
						do
						{
							validar=getFloat(&operadorDos,"Ingrese Operador B");
							if(validar==-1)
							{
								puts("\nERROR: Por Favor Ingrese Numero Valido\n");
							}
							else
							{
								banderaOpeDos=1;
								banderaResultados=0;
							}
						}while(validar!=0);
					break;
					case 3:

						do
						{
							if(banderaOpeUno == 0)
							{
								puts("\nERROR: Falta ingresar el operador A\n");
							}
							else
							{
								if(banderaOpeDos == 0)
								{
									puts("\nERROR: Falta ingresar el operador B\n");
								}
								else
								{
									validarSum=sumarFloat(&suma,operadorUno,operadorDos);
									validarDiv=dividirFloat(&cociente,operadorUno,operadorDos);
									validarRes=restarFloat(&resta,operadorUno,operadorDos);
									validarMul=multiplicarFloat(&producto,operadorUno,operadorDos);
									validarFac1=factorialFloat(&factorialUno,operadorUno);
									validarFac2=factorialFloat(&factorialDos,operadorDos);
									banderaResultados=1;

									puts("\nVisualice los resultados en opcion 4\n");

								}
							}
						}while(validar!=0);
					break;
					case 4:
						if(banderaResultados==0)
						{

							puts("Debe primero hacer los calculos en la opcion 3\n");
						}
						else
						{
							if(validarSum==-1)
							{
								printf("\nNo se pudo realizar la suma");
							}
							else
							{
								printf("\nEl resultado de la suma es: %.2f",suma);
							}

							if(validarRes==-1)
							{
								printf("\nNo se pudo realizar la resta");
							}
							else
							{
								printf("\nEl resultado de la resta es: %.2f",resta);
							}

							if(validarMul==-1)
							{
								printf("\nNo se pudo realizar la Multiplicacion");
							}
							else
							{
								printf("\nEl resultado de la multiplicacion es: %.2f",producto);
							}

							if(validarDiv==-1)
							{
								printf("\nNo se pudo realizar la Division");
							}
							else
							{
								if(validarDiv==1)
								{
									printf("\nNo se puede dividir por cero");
								}
								else
								{
									printf("\nEl resultado de la division es: %.2f",cociente);
								}
							}

							if(validarFac1==-1)
							{
								printf("\nNo se pudo realizar el factorial del numero negativo %.2f",operadorUno);
							}
							else
							{
								printf("\nEl factorial de %d es: %d",(int)operadorUno,factorialUno);
							}

							if(validarFac2==-1)
							{
								printf("\nNo se pudo realizar el factorial del numero negativo %.2f",operadorDos);
							}
							else
							{
								printf("\nEl factorial de %d es: %d",(int)operadorDos,factorialDos);
							}

							banderaResultados=0;

							do
							{
								validar=utn_PreguntaContinuar(&respuesta,'s','n', "\nDesea seguir Ingresando? s/n");

								if(validar==-1)
								{
									puts("\nPor favor,ingrese opcion valida s/n");
								}
								else
								{
									if(validar==0)
									{
										if(respuesta=='s')
										{
											operadorUno=0;
											operadorDos=0;
											banderaOpeUno =0;
											banderaOpeDos=0;
										}
										else
										{
											if(respuesta=='n')
											{
												opcion=5;
											}

										}
									}

								}
							}while(validar==-1);
						}
					break;
				}
			}

		}while(opcion!=5);

	finalizarProgramas();

	return EXIT_SUCCESS;
}
