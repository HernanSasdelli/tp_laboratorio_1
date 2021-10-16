/*
 ============================================================================
 Name        : TP_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <conio.h>
#include "UTN_GetIn.h"
#include "ArrayEmployees.h"
#include "informes.h"


#define CANT_EMPLEADOS 1000

#define LIBRE 0
#define OCUPADO 1

int modificacionEmpleado(Employee* pArray, int LARGO);

int main(void)
{
	setbuf(stdout, NULL);
	Employee eEmpleados[CANT_EMPLEADOS];/*= {{1000,"Maria","Ladelbarrio",5000,1,1}, {1001,"Juan Carlos","que haces",4000,4,1}, {1005,"que haces","Juan Carlos",3000,4,1},{1003,"que haces","Juan Carlos",500,4,1}, {1006,"que haces","chupapija",4000,4,1}};*/
	int opcion;
	char respuesta;
	int controlEmpleado;
	int controlModEmpleado;
	int controlBajaEmpleado;

	printf("\n\tBIENVENID@ AL PROGRAMA\n");
	if(initEmployees(eEmpleados, CANT_EMPLEADOS)==0)
	{

		do
		{
			printf("__________________________________________\nMENU PRINCIPAL\n__________________________________________\n");
			printf("\n1. ALTA\n2. MODIFICAR\n3. BAJA\n4. INFORMAR\n");
			if(utn_getNumero(&opcion,"\nIngrese Opcion\n","ERROR! Opcion Invalida, reintente\n",1,4,2)==0)
			{
				switch (opcion)
				{
/*ALTA*/			case 1:
						printf("__________________________________________\n\tMODULO DE ALTAS\n__________________________________________\n");
						do
						{
							controlEmpleado=altaEmpleado(eEmpleados,CANT_EMPLEADOS);
							if(controlEmpleado==-2)
							{
								printf("\nNo tiene mas espacio para altas\nDebera dar de baja un empleado primero (opcion 3)\n");
								break;
							}
							else
							{
								if(preguntarSeguir(&respuesta,1,"\nDesea Ingresar nuevamente?s/n\n","\nERROR!Ingreso Invalido\n")==-1)
								{
									printf("\nNo se pudo completar el Alta\n");
									break;
								}
							}

						}while(respuesta=='s'||respuesta=='S');

					break;
/*MOD*/				case 2:
						printf("__________________________________________\n\tMODULO DE MODIFICACION\n__________________________________________\n");
						do
						{
							controlModEmpleado=modificacionEmpleado(eEmpleados,CANT_EMPLEADOS);
							if(controlModEmpleado==-2)
							{
								printf("\nNo hay empleados cargados (Opcion 1)\n");
								break;
							}
							else
							{
								switch(controlModEmpleado)
								{
									case -1:
										printf("\nEl Id Ingresado no existe o esta dado de baja\n");
									break;
									case 0:
										printf("\nSe han modificado campos en la ficha de empleado\n");
									break;
									case 1:
										printf("\nNo se han modificado campos en la ficha de empleado\n");
									break;
								}
								if(preguntarSeguir(&respuesta,1,"\nDesea Ingresar Id nuevamente para modificar?s/n\n","\nERROR!Ingreso Invalido\n")==-1)
								{
									printf("\nNo se pudo Continuar\n");
									break;
								}

							}
						}while(respuesta=='s'||respuesta=='S');
					break;
/*BAJA*/			case 3:
						printf("__________________________________________\n\tMODULO DE BAJAS\n__________________________________________\n");
						do
						{
							controlBajaEmpleado=bajaEmpleado(eEmpleados, CANT_EMPLEADOS);
							if(controlBajaEmpleado==-2)
							{
								printf("\nNo hay empleados cargados (Opcion 1)\n");
								break;
							}
							else
							{
								switch(controlBajaEmpleado)
								{
									case -1:
										printf("\nEl Id Ingresado no existe o esta dado de baja\n");
									break;
									case 0:
										printf("\nSe ha completado la baja con exito\n");
									break;
									case 1:
										printf("\nEl empleado no se dio de baja\n");
									break;

								}
								if(preguntarSeguir(&respuesta,1,"\nDesea Ingresar Id nuevamente para dar de baja?s/n\n","\nERROR!Ingreso Invalido\n")==-1)
								{
									printf("\nNo se pudo Continuar\n");
									break;
								}
							}
						}while(respuesta=='s'||respuesta=='S');
					break;
/*INFORMES*/		case 4:
						printf("__________________________________________\n\tMODULO DE INFORMES\n__________________________________________\n");
						if(buscarOcupado(eEmpleados, CANT_EMPLEADOS)==-1)
						{
							printf("\nNo hay empleados cargados (Opcion 1)\n");
							break;
						}
						else
						{
							do
							{
								if(utn_getNumero(&opcion,"\nIngrese Opcion de informe\n1-Empleados Ordenados Alfabeticamente\n2-Sueldos\n",
										"ERROR! Opcion Invalida, reintente\n",1,2,2)==0)
								{
									switch(opcion)
									{
										case 1:
											imprimirListaOrdenada(eEmpleados,CANT_EMPLEADOS);
										break;
										case 2:
											informesPromedio(eEmpleados, CANT_EMPLEADOS);
										break;
									}
								}
								else
								{
									printf("No se pudo realizar el informe");
								}

								if(preguntarSeguir(&respuesta,1,"\nDesea realizar otro informe?s/n\n","\nERROR!Ingreso Invalido\n")==-1)
								{
									printf("\nNo se pudo Continuar\n");
									break;
								}
							}while(respuesta=='s'||respuesta=='S');
						}
						informesPromedio(eEmpleados,CANT_EMPLEADOS);
					break;
				}
			}
			else
			{
				puts("No ha ingresado opcion valida");
			}

			if(preguntarSeguir(&respuesta,2,"\nDesea Continuar en el Programa?s/n\n","\nERROR!Ingreso Invalido\n")==-1)
			{
				printf("ERROR! Opcion invalida el programa se cerrara");
				break;
			}


		} while (respuesta=='s' ||respuesta=='S');
	}
	else
	{
		printf("ERROR! No se pudo inicializar, el programa se cerrara");

	}

	printf("________________________________________\nGRACIAS POR UTILIZAR EL TP 2\n________________________________________\nPRESIONE CUALQUIER TECLA PARA SALIR");
	getch();

	return EXIT_SUCCESS;
}
