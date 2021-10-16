/*
 * Informes.c
 *
 *  Created on: 16 oct. 2021
 *      Author: HERNAN
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "UTN_GetIn.h"
#include "ArrayEmployees.h"
#include "informes.h"

#define LIBRE 0
#define OCUPADO 1

/** \brief calcula promedio a traves de acumuladores y contadores y los devulve por punteros a direccion de memoria
 * \param lista estructura
 * \param prom puntero a direccion de memoria variable externa
 * \param total puntero a direccion de memoria variable externa
 * \param cant puntero a direccion de memoria variable externa
 * \return int(-1) parametro NULL (0) si resolvio
 */
int promedio(Employee* list, int LARGO,float* prom, float* total, int* cant)
{
	int retorno=-1;
	int i;
	float acumuladorAux=0;
	int contadorAux=0;
	if(list!=NULL && LARGO>0)
	{
		for(i=0;i<LARGO;i++)
		{
			if(list[i].isEmpty==OCUPADO)
			{
				acumuladorAux=acumuladorAux+list[i].salary;
				contadorAux++;
				retorno=0;
			}
		}
		if(contadorAux>0)
		{
			//esta misma funcion en void se puede usar solo para imprimir sin retornar

			*total=acumuladorAux;
			*cant=contadorAux;*prom=acumuladorAux/contadorAux;

		}
		else
		{
			retorno=-2;
		}

	}
	return retorno;
}


/** \brief imprime acumuladores y contadores y calculos relacionados a estos tipos de variables
 * \param lista estructura
 * \param int largo
 */
void informesPromedio(Employee* list, int LARGO)
{
	float prom;
	float total;
	int cont;
	int i;
	int contadorAuxSup=0;

	if(list!=NULL && LARGO>0)
	{
		if(promedio(list, LARGO,&prom,&total,&cont)==0)
		{
			for(i=0;i<LARGO;i++)
			{
				if(list[i].salary>prom)
				{
					contadorAuxSup++;
				}
			}
			printf("Suma Total de salarios: %.2f\n",total);
			printf("Promedio de salarios: %.2f\n",total/cont);
			printf("Cantidad de empleados que superan el promedio de sueldos: %d \nLista:\n",contadorAuxSup);
			for(i=0;i<LARGO;i++)
			{
				if(list[i].salary>prom)
				{
					printf("%s %s\n",list[i].lastName,list[i].name);
				}
			}
		}
		else
		{
			printf("No se pudo informar");
		}
	}
	else
	{
		printf("No se pudo informar");
	}
}

/** \brief ordena se mayor a menor, o menor a mayot segun dos variables dentro de la misma estructura
 * \param lista estructura
 * \param int largo
 * \param int order parametro decide forma de ordenar
 * \return int(-1) parametro NULL (0) si resolvio
 */

int sortEmployees(Employee* list, int len, int order)
{
	int retorno=-1;
	int i;
	int h;
	Employee listaAux;
	if(list!=NULL&&len>0&&(order==1||order==2))
	{
		switch(order)
		{
			case 1:
				for(i=0;i<len-1;i++)
				{
					for (h=i+1;h<len;h++)
					{
						 if(list[i].isEmpty==OCUPADO && list[h].isEmpty==OCUPADO)//me fijo que esten cargados en uso
						 {
							if(list[i].sector < list[h].sector || (list[i].sector==list[h].sector && (strcmp(list[i].lastName, list[h].lastName)) < 0)) //me perdi
							{
								listaAux = list[i];
								list[i] = list[h];
								list[h] = listaAux;
							 }
						 }
					}
				}
				retorno=0;
			break;
			case 2:
				for(i=0;i<len-1;i++)
				{
					for (h=i+1;h<len;h++)
					{
						 if(list[i].isEmpty==OCUPADO && list[h].isEmpty==OCUPADO)//me fijo que esten cargados en uso
						 {
							if(list[i].sector>list[h].sector || (list[i].sector==list[h].sector && (strcmp(list[i].lastName, list[h].lastName))>0)) //OJO con el signo, y dar vueltas las variables
							{																														//mejot corregir enunciado
								listaAux = list[i];
								list[i] = list[h];
								list[h] = listaAux;
							 }
						 }
					}
				}
				retorno=0;//lista ordenada con exito
			break;

		}
	}




	return retorno;
}


/** \brief recibe los datos de usuarios necesarios para que funcione la funcion sortEmployees
 * \param lista estructura
 * \param int largo
 */
void imprimirListaOrdenada(Employee* list, int len)
{
	int orden;
	if(list!=NULL&&len>0)
	{
		if(utn_getNumero(&orden, "\nIngrese Parametro para ordenar\n1-Descendente\n2-Ascendente\n", "\nERROR! Parametro Invalido\n", 1,2,2)==-1)
		{
			printf("\nNo se pudo ordenar\n");
		}
		else
		{
			if(sortEmployees(list,len,orden)==-1)
			{
				printf("\nNo se pudo ordenar\n");
			}
			else
			{
				if(printEmployees(list,len)==-1)
				{
					printf("\nNo se pudo imprimir\n");
				}
				else
				{
					printf("\nLista ordenada correctamente");
				}
			}
		}
	}

}

