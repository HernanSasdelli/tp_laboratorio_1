/*
 * ArrayEmployees.c
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

static int generadorId(void);

/** \brief Busca en un estructura la posicion libre con la variable bandera isEmpty como parametro
 * \param Lista estructura
 * \param int Largo
 * \return int(-1) campos NUll int (posicion libre) si resuelve
 */
int buscarLibre(Employee* estructura,int LARGO)
{
	int retorno=-1;
	//int buffer;
	int i;
	if(estructura!=NULL && LARGO>0)
	{
		for(i=0;i<LARGO;i++)
		{
			if(estructura[i].isEmpty==LIBRE)
			{
				//buffer=i;
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}
/** \brief busca posiciones ocupadas para chequear que la lista este cargada
 * \param Lista Estructura
 * \param int Largo
 * \return int(-1) si falla int (0) si resuelve
 */
int buscarOcupado(Employee* estructura,int LARGO)
{
	int retorno=-1;
	int i;
	if(estructura!=NULL && LARGO>0)
	{
		for(i=0;i<LARGO;i++)
		{
			if(estructura[i].isEmpty==OCUPADO)
			{
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}
/** \brief Busca una plantilla de empleado a traves del campo de ID
 * \param Lista estructura
 * \param int largo
 * \param int ID
 * \return int(-1) falla, int (ID) si resuelve
 */
int findEmployeeById(Employee* list,int len,int id)
{
	int retorno=-1;
	int i;
	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].id==id && list[i].isEmpty==OCUPADO)
			{
				retorno=i;
				break;
			}
		}
	}

	return retorno;
}
/** \brief Imprime por pantalla los campos de una sola plantila en una posicion especifica sin verificar si hay datos cargados
 * \param LIsta estructura
 * \param int posicion donde se encuentra la plantilla
 * \return no retorna, solo imprime
 */
void mostrarUnaPosicion(Employee* list,int posicion)
{
	printf("_______________________________\n| S | Apellido - Nombre | Salario\n_______________________________\n");
	if(list!=NULL && posicion>-1)
	{
		//printf("%d\t",list[control].id);
		printf("| %d |",list[posicion].sector);
		printf(" %s - ",list[posicion].lastName);
		printf("%s |",list[posicion].name);
		printf(" $%.2f \n",list[posicion].salary);


	}
	else
	{
		printf("No se encontro ID");
	}
}


/** \brief Imprime una estructura completa y las variables de cada plantilla siempre que esten en uso
 * \param Lista estructura
 * \param int largo
 * \return int(-1) si los parametros son NULL (0) su resolvio
 */
int printEmployees(Employee* list, int length)
{
	int retorno=-1;
	int i;
	if(list!=NULL&&length>0)
	{
		printf("ID   Sector  Apellido y Nombre   Salario\n___________________________________________\n");
		for(i=0;i<length;i++)
		{
			if(list[i].isEmpty==OCUPADO)
			{
				retorno=0;
				printf("%d |",list[i].id);
				printf(" %d |",list[i].sector);
				printf(" %s -",list[i].lastName);
				printf(" %s ",list[i].name);
				printf(" | $%.2f \n",list[i].salary);

				//printf("%d\t\n",list[i].isEmpty);
			}
		}
	}
	return retorno;
}

/** \brief Inicializa en 0, o LIBRE, toda las variables isEmpty de la estructura
 * \param Lista estructura
 * \param int largo
 * \return int(-1) si fallo (0)si resolvio
 */
int initEmployees(Employee* list, int len)
{
	int i;
	int retorno=-1;
	if (list!=NULL && len>0)
	{
		retorno=0;
		for (i=0;i<len; i++)
		{
			list[i].isEmpty=LIBRE;
		}

	}
	return retorno;
}

/** \brief Inicializa en 0, o LIBRE, toda las variables isEmpty de la estructura
 * \param Lista estructura
 * \param int largo
 * \return  int(-1) si fallo (0)si resolvio
 */
void inicializarArray(Employee array[], int LARGO)
{
	int i;
	if (array!=NULL && LARGO>0)
	{
		for (i=0;i<LARGO; i++)
		{
			array[i].isEmpty=LIBRE;
		}
	}
}

/** \brief funcion estatica para generar id sin que se repita dentro del programa
 * \return retorna la proxima ID generada
 */
static int generadorId(void)
{
	static int c=1000;
	c++;
	return c;
}

/** \brief Carga todas las variables de una estructura
 * \param Lista estructura
 * \param  int largo
 * \return int(-1) si falla (-2) si la estructura esta llena (0) si se pudieron cargar los datos corectamente
 */
int altaEmpleado(Employee* estructura, int LARGO)
{
	int retorno=-1;
	int disponible=buscarLibre(estructura, LARGO);
	int id=0;
	char name[51];
	char lastName[51];
	float salary;
	int sector;

	if(estructura!=NULL && LARGO>0)
	{
		if(disponible>=0)
		{
			if(utn_getTexto(name,sizeof(name),"Ingrese el Nombre del Empleado\n","\nError! Ingreso invalido\n",2)==0)
			{
				if(utn_getTexto(lastName,sizeof(lastName),"Ingrese el Apellido del Empleado\n","\nError! Ingreso invalido\n",2)==0)
				{
					if(utn_getNumeroFloat(&salary,"Ingrese el Salario (0/99999)\n","\nError! Importe invalido\n",0,99999,2)==0)
					{
						if(utn_getNumero(&sector,"Sector\n1-FRONT END\n2-BACK END\n3-JAVASCRIPT\nIngrese: ","\nError! Opcion Invalida\n",1,3,2)==0)
						{
							id=generadorId();
							if(addEmployee(estructura,disponible,id,name,lastName,salary,sector)==0)
							{
								printf("\nAlta empleado cargada con exito\n");
								mostrarUnaPosicion(estructura, disponible);
								retorno=0;
							}
						}
					}
				}
			}
		}
		else
		{
			//no hay mas espacio
			retorno=-2;
		}
	}
	return retorno;
}

/** \brief agrega las variables recolectadas por otra funcion a una estructura
 * \param Lista estructura
 * \param int Posicion de la estructura donde cargar los datos
 *  \param int id nuevo id generado por otra funcion
 *  \param char name[] y char Last Name [] cargan los nombre y apellido que recibieron por parametros las variables de una estructura
 * \return int(-1) si algun parametro es NULL (0) si logro copiar
 */
int addEmployee(Employee* list, int len, int id, char name[],char
		lastName[],float salary,int sector)
{
	int retorno=-1;
	if(list!=NULL && len>=0 && id>=0 && name!=NULL && lastName!=NULL && salary>=0 && sector>0)
	{
		retorno=0;
		list[len].id=id;
		strcpy(list[len].name,name);
		strcpy(list[len].lastName,lastName);
		list[len].salary=salary;
		list[len].sector=sector;
		list[len].isEmpty=OCUPADO;
	}
	return retorno;
}

/** \brief a traves de un menu permite modificar por separados todas las variables de una posicion de las estructura
 * \param Lista Estructura
 * \param int LArgo
 * \return int (-1) si algun parametro es NULL, (-2) si no existen datos por modificar (0) si logra moficar al menos una variable de toda la plantilla (1)si no se modifica ninguna variable
 */
int modificacionEmpleado(Employee* pArray, int LARGO)
{
	int retorno=-1;
	int id;
	int posId;
	char auxRespuesta;
	int auxOpcion;
	int flagCarga=0;
	char nameMod[51];
	char lastNameMod[51];
	float salaryMod;
	int sectorMod;

	Employee auxiliarArray[LARGO];//recordar pasar el dato de LARGO con un strlen o define para que las cadenas queden iguales

	if(pArray!=NULL && LARGO>0)
	{
		if(printEmployees(pArray,LARGO)==-1)
		{
			//no hay empleados cargados
			retorno=-2;
		}
		else
		{

			if(utn_getNumero(&id,"\nSeleccione ID que desea modificar: \n", "\nERROR! No esta ingresando un valor de ID\n",0,3000,2)==0)
				{
					posId=findEmployeeById(pArray,LARGO,id);//el find ya verificaba que no este dado de baja
					if(posId<0)
					{
						//el id ingresado no existe
						retorno=-1;

					}
					else
					{
						auxiliarArray[posId]=pArray[posId];

						printf("El ID %d tiene cargados los siguientes datos:\n ",id);
						mostrarUnaPosicion(pArray,posId);
						if(preguntarSeguir(&auxRespuesta,1,"\nEsta seguro de modificar?s/n\n","\nERROR!Ingreso Invalido\n")==-1)
						{
							printf("\nNo se pudo completar la modificacion\n");
							retorno=-1;
						}
						else
						{
							if(auxRespuesta=='s' || auxRespuesta=='S')
							{
								do{

									if(utn_getNumero(&auxOpcion,"\nQue dato desea modificar? \n1-Nombre\n2-Apellido\n3-Salario\n4-Sector\nIngrese: ", "\nERROR! No esta ingresando un valor de opcion valida\n",1,4,2)==0)
									{
										switch(auxOpcion)
										{
											case 1:
												if(utn_getTexto(nameMod,sizeof(nameMod),"Modifique el Nombre del Empleado\n","Error! Ingreso invalido\n",2)==0)
												{
													strcpy(auxiliarArray[posId].name,nameMod);
													printf("\nCampo Nombre modificado con exito\n");
													flagCarga=1;


												}
												else
												{
													printf("\nEste campo no se pudo modificar\n");
												}
											break;
											case 2:
												if(utn_getTexto(lastNameMod,sizeof(lastNameMod),"Modifique Apellido del Empleado\n","Error! Ingreso invalido\n",2)==0)
												{
													strcpy(auxiliarArray[posId].lastName,lastNameMod);
													printf("\nCampo Apellido modificado con exito\n");
													flagCarga=1;

												}
												else
												{
													printf("\nEste campo no se pudo modificar\n");
												}
											break;
											case 3:
												if(utn_getNumeroFloat(&salaryMod,"Ingrese el nuevo Salario (0/99999)\n","Error! Importe invalido\n",0,99999,2)==0)
												{
													auxiliarArray[posId].salary = salaryMod;
													printf("\nCampo Salario modificado con exito\n");
													flagCarga=1;
												}
												else
												{
													printf("\nEste campo no se pudo modificar\n");
												}
											break;
											case 4:
												if(utn_getNumero(&sectorMod,"Ingrese nuevo sector\n1-FRONT END\n2-BACK END\n3-JAVASCRIPT\nIngrese: ","Error! Opcion Invalida\n",1,3,2)==0)
												{
													auxiliarArray[posId].sector = sectorMod;
													printf("\nCampo Sector modificado con exito\n");
													flagCarga=1;
												}
												else
												{
													printf("\nEste campo no se pudo modificar\n");

												}
											break;
										}
										pArray[posId]=auxiliarArray[posId];
										//copio el auxiliar en el array original para no romper
									}
									else
									{
										retorno=1;
										if(flagCarga==1)
										{
											retorno=0;
										}
										printf("\nNo se pudo completar la modificacion\n");
										break;
									}
									if(preguntarSeguir(&auxRespuesta,1,"\nDesea Modificar otros campos?s/n\n","\nERROR!Ingreso Invalido\n")==-1)
									{
										retorno=1;
										if(flagCarga==1)
										{
											retorno=0;
										}
										printf("\nNo se pudo completar la modificacion\n");

									}
									else
									{
										if(auxRespuesta=='n' || auxRespuesta=='N')
										{
											retorno=1;
											if(flagCarga==1)
											{
												retorno=0;
												printf("\nEl ID %d, ahora tiene los siguientes datos: \n",id);
												mostrarUnaPosicion(pArray, posId);
											}


										}
									}

								}while(auxRespuesta=='s' || auxRespuesta=='S');
							}
							else
							{
								retorno=1;
							}

						}

					}
				}
				else
				{
					printf("\nERROR! No se pudo completar la operacion\n");
				}
		}
	}
	return retorno;
}


/** \brief baja logica a traves de bandera isEmpty de un empleado encontrado por ID
 * \param lista estructura
 * \param int largo
 * \return int(-1) por parametros NULL, (-2) si no existen plantillas para modificar (0) si desea continuar
 */
int bajaEmpleado(Employee* list, int len)
{
	int retorno=-1;
	int id;
	int posicion;
	char auxRespuesta;

	if(list!=NULL && len>0)
	{
		if(printEmployees(list,len)==-1)
		{
			//no hay empleados cargados
			retorno=-2;
		}
		else
		{
			if(utn_getNumero(&id,"\nSeleccione ID que desea dar de baja: \n", "\nERROR! No esta ingresando un valor de ID\n",0,3000,2)==0)
			{
				posicion=findEmployeeById(list,len,id);
				if(posicion<0)
				{
					//el id ingresado no existe
					retorno=-1;
				}
				else
				{
					printf("El ID %d tiene cargados los siguientes datos:\n ",id);
					mostrarUnaPosicion(list,posicion);
					if(preguntarSeguir(&auxRespuesta,1,"\nEsta seguro de dar de baja?s/n\n","\nERROR!Ingreso Invalido\n")==-1)
					{
						//no se decide si seguir
						retorno=-1;
					}
					else
					{
						if(auxRespuesta=='s' || auxRespuesta=='S')
						{
							if(removeEmployee(list, len, id)==0)
							{
								retorno=0;
							}

						}
						else
						{
							retorno=1;
						}
					}
				}
			}
		}
	}
	return retorno;
}

/** \brief hace la baja logica de la plantilla y sus variables, solo mofifica la bandera isEmpty
 * \param LIsta Empleado
 * \param Largo
 * \param int id del la plantilla que desea cambiar la bandera a disponible
 * \return
 */
int removeEmployee(Employee* list, int len, int id)
{
	int retorno=-1;
	int i;

	if(list!=NULL && len>0 && id>=0)
	{
		i=findEmployeeById(list, len, id);
		if(i>-1)
		{
			list[i].isEmpty=LIBRE;
			retorno=0;
		}
		else
		{
			retorno=-2;
		}
	}
	else
	{
		retorno=-2;
	}

	return retorno;
}

