
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "UTN_GetIn.h"
#include "parser.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (-1) se fallo (0) si resuelve
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	FILE* pArchivo;

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		pArchivo=fopen(path,"r");

		if(pArchivo!=NULL)
		{
			if(parser_EmployeeFromText(pArchivo, pArrayListEmployee)==0)
			{
				retorno=0;
			}
		}
	}
	fclose(pArchivo);
	return retorno;
}
/*
int controller_csvToBinary(char* path ,char* pathBinary)
{
	int retorno=-1;
	FILE* pArchivo;
	FILE* pArchivoBinario;
	//Employee* pAuxEmployee;
	LinkedList* pAuxLinked;

	if(path!=NULL && pathBinary==NULL)
	{
		pArchivo=fopen(path,"r");
		if(pArchivo!=NULL)
		{
			if(parser_EmployeeFromText(pArchivo, pAuxLinked)==0)
			{
				pArchivoBinario=fopen(pathBinary,"wb");
				if(parser_EmployeeFromBinary(pArchivoBinario,pAuxLinked)==0)
				{
					retorno=0;
				}
			}

		}

	}
	fclose(pArchivo);
	fclose(pArchivoBinario);
	return retorno;
}
*/

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (-1) error (0) si resolvio
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	FILE* pArchivo;

	if(path!=NULL)
	{
		pArchivo=fopen(path,"rb");
		if(pArchivo!=NULL)
		{
			if(parser_EmployeeFromBinary(pArchivo, pArrayListEmployee)==0)
			{
				retorno=0;
			}

		}
	}
	fclose(pArchivo);
	return retorno;
}

/** \brief Agregar un empleado por consola
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (-1) error (0) si resolvio
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int auxId;
	char idStr[51];
	char auxNombre[51];
	char auxSueldo[51];
	char auxHoras[51];
	Employee* pAuxEmployee;
	if(pArrayListEmployee!=NULL)
	{
		if(employee_pedirDatos(auxNombre,auxSueldo,auxHoras)==0)
		{
			if(employee_getNextId("dataIdMaxima.txt", &auxId)==0)
			{
				sprintf(idStr,"%d",auxId);
				pAuxEmployee=(Employee*)employee_newParametros(idStr,auxNombre,auxHoras,auxSueldo);
				if(pAuxEmployee!=NULL)
				{
					if(ll_add(pArrayListEmployee, pAuxEmployee)==0)
					{
						retorno=0;
					}
				}
			}
		}
	}
	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (-1) error (0) si resolvio
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int auxIdIngresada;
	int auxIdVerificion;
	char seguir;

	if(pArrayListEmployee!=NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		if(utn_getNumero(&auxIdIngresada,"\nSelecciones ID a modificar\n","\nError! Ingreso Invaludo\n", 0,90000,1)==0)
		{
			auxIdVerificion=employee_findById(pArrayListEmployee,auxIdIngresada);
			if(auxIdVerificion!=-1)
			{
				printf("\nEl cliente a modificar es el siguiente:\n");
				if(controller_ListEmployeeOnlyOne(pArrayListEmployee, auxIdVerificion)==0)
				{
					if(preguntarSeguir(&seguir, 1,"\nSeguro que desea modificar? s/n\n", "\nError! Ingreso Invaludo\n")==0)
					{
						if(seguir=='s'||seguir=='S')
						{
							int controlModificacion=controller_editEmployeeMenu(pArrayListEmployee, auxIdVerificion);
							if(controlModificacion==0)
							{
								printf("\nDatos modificados con exito\n");
							}
							else if(controlModificacion==1)
							{
								printf("\nNo se modificaron datos\n");
							}
							else
							{
								printf("\nLos datos no pudieron ser modificados\n");
							}
						}

					}
				}
			}
			else
			{
				printf("\nId Invalida\n");
			}
		}
	}
    return retorno;
}
/** \brief Modificar datos de empleado variable por variable(complemeto de controller_editEmployee()
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (-1) error (0) si resolvio
 */
int controller_editEmployeeMenu(LinkedList* pArrayListEmployee,int position)
{
	int retorno=-1;
	int opcion;
	char auxNombre[51];
	int auxHoras;
	int auxSueldo;
	int flag=0;
	Employee* pAuxEmployee;
	if(pArrayListEmployee!=NULL)
	{
		pAuxEmployee=(Employee*)ll_get(pArrayListEmployee, position);
		if(pAuxEmployee!=NULL)
		{
			do
			{
				if(utn_getNumero(&opcion,"\nIngrese el campo que desea modificar\n1.Nombre\n2.Horas trabajadas\n3.Sueldo\n4.Volver al Menu principal\n",
				"Error! Ingreso Invalido", 1, 4,1)==0)
				{
					switch(opcion)
					{
					case 1:
						if(utn_getNombre(auxNombre, 51, "\nIngrese Nombre a modificar\n","ERROR! Ingreso Invalido", 1)==0)
						{
							if(employee_setNombre(pAuxEmployee,auxNombre)==0)
							{
								printf("\nNombre modificado con Exito\n");
								flag=1;
							}
						}
					break;
					case 2:
						if(utn_getNumero(&auxHoras,"\nIngrese Horas trabajadas\n","ERROR! Ingreso Invalido",1, 150, 1)==0)
						{
							if(employee_setHorasTrabajadas(pAuxEmployee,auxHoras)==0)
							{
								printf("\nHoras Trabajadas modificadas con Exito\n");
								flag=1;
							}

						}
					break;
					case 3:
						if(utn_getNumero(&auxSueldo,"\nIngrese nuevo Sueldo\n","ERROR! Ingreso Invalido",1, 900000, 1)==0)
						{
							if(employee_setSueldo(pAuxEmployee,auxSueldo)==0)
							{
								printf("\nSueldo Modificado con Exito\n");
								flag=1;
							}
						}

					break;

					}
				}

			}while(opcion!=4);

			if(flag==0)
			{
				;
				retorno=1;
			}
			if(flag==1)
			{
				ll_set(pArrayListEmployee, position, pAuxEmployee);
				retorno=0;
			}
		}
	}
	return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (-1) error (0) si resolvio
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int auxIdIngresada;
	int auxIdVerificion;
	char seguir;
	Employee* pAuxEmployee;

	if(pArrayListEmployee!=NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		if(utn_getNumero(&auxIdIngresada,"\nSelecciones ID a borrar\n","\nError! Ingreso Invaludo\n", 0,90000,1)==0)
		{
			auxIdVerificion=employee_findById(pArrayListEmployee,auxIdIngresada);
			if(auxIdVerificion!=-1)
			{
				printf("\nEl cliente a eliminar es el siguiente:\n");
				if(controller_ListEmployeeOnlyOne(pArrayListEmployee, auxIdVerificion)==0)
				{
					if(preguntarSeguir(&seguir, 1,"\nSeguro que desea eliminarlo? s/n\n", "\nError! Ingreso Invaludo\n")==0)
					{
						if(seguir=='s'||seguir=='S')
						{
							pAuxEmployee=(Employee*)ll_get(pArrayListEmployee, auxIdVerificion);
							employee_delete(pAuxEmployee);
							if(ll_remove(pArrayListEmployee, auxIdVerificion)==0)
							{
								retorno=0;
							}
						}
					}
				}
			}
		}
	}
	return retorno;
}


/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (-1) error (0) si resolvio
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int i;
	int auxLen;

	if(pArrayListEmployee!=NULL)
	{
		auxLen=ll_len(pArrayListEmployee);
		printf("\n| ID | Nombre y Apellido | Horas trabajadas | Sueldo |\n");
		for(i=0;i<auxLen;i++)
		{
			if(controller_ListEmployeeOnlyOne(pArrayListEmployee, i)!=0)
			{
				printf("\nHubo un error en la impresion\n");
				break;
			}
			else
			{
				retorno=0;
			}
		}
	}
    return retorno;
}

/** \brief Listar un empleado
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (-1) error (0) si resolvio
 */
int controller_ListEmployeeOnlyOne(LinkedList* pArrayListEmployee,int position)
{
	int retorno=-1;
	int auxId;
	char auxNombre[51];
	int auxSueldo;
	int auxHoras;
	Employee * pThisPosition;

	if(pArrayListEmployee!=NULL && position>=0)
	{
		pThisPosition=(Employee*)ll_get(pArrayListEmployee,position);
		if(employee_getId(pThisPosition, &auxId)==0)
		{
			if(employee_getNombre(pThisPosition, auxNombre)==0)
			{
				if(employee_getSueldo(pThisPosition, &auxSueldo)==0)
				{
					if(employee_getHorasTrabajadas(pThisPosition, &auxHoras)==0)
					{
						printf("|%d| %s | %d | $%d | \n",auxId,auxNombre,auxSueldo,auxHoras);
						retorno=0;
					}
				}
			}
		}
	}
	return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (-1) error (0) si resolvio
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int criterio;
	if(pArrayListEmployee!=NULL)
	{
		if(utn_getNumero(&criterio,"\nCriterio de ordenamiento\n"
		"0.Descendente\n1.Ascendente\nIngrese :  ","\nError! Ingreso Invaludo\n",0, 1, 1)==0)
		{
			retorno=ll_sort(pArrayListEmployee,employee_sortNombre,criterio);
		}
	}
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (-1) error (0) si resolvio
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int auxId;
    char auxNombre[51];
    int auxHoras;
    int auxSueldo;
    Employee* pEmployee;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
    	FILE* pArchivo=fopen(path,"w");
		fprintf(pArchivo, "id,nombre,horasTrabajadas,sueldo\n");
		for(int i=0;i<ll_len(pArrayListEmployee);i++)
		{
			pEmployee=(Employee*)ll_get(pArrayListEmployee,i);
			if(employee_getId(pEmployee,&auxId)==0)
			{
				if(employee_getNombre(pEmployee,auxNombre)==0)
				{
					if(employee_getHorasTrabajadas(pEmployee,&auxHoras)==0)
					{
						if(employee_getSueldo(pEmployee,&auxSueldo)==0)
						{
							fprintf(pArchivo, "%d,%s,%d,%d\n",auxId,auxNombre,auxHoras,auxSueldo);
						}
					}
				}
			}
		}
		retorno = 0;
		fclose(pArchivo);
    }
    return retorno;
}



/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (-1) error (0) si resolvio
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int i;
    FILE* pArchivo;
    Employee* pAuxEmployee;
    int len=ll_len(pArrayListEmployee);;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
    	pArchivo=fopen(path,"wb");
    	if(pArchivo!=NULL)
        {
        	for(i=0;i<len;i++)
            {
        		pAuxEmployee=ll_get(pArrayListEmployee,i);
                fwrite(pAuxEmployee,sizeof(Employee),1,pArchivo);
            }
            retorno = 0;
        }
    }
    fclose(pArchivo);
    return retorno;
}

//Intento de guardar los empleados cargados sin antes cargar el archivo en el ultimo lugar
/*
int controller_saveAsTextSinCarga(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int auxId;
	char auxNombre[51];
	int auxHoras;
	int auxSueldo;
	Employee* pEmployee;

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		FILE* pArchivo=fopen(path,"w");
		fprintf(pArchivo, "id,nombre,horasTrabajadas,sueldo\n");
		for(int i=0;i<ll_len(pArrayListEmployee);i++)
		{

			pEmployee=(Employee*)ll_get(pArrayListEmployee,i);
			if(employee_getId(pEmployee,&auxId)==0)
			{
				if(employee_getNombre(pEmployee,auxNombre)==0)
				{
					if(employee_getHorasTrabajadas(pEmployee,&auxHoras)==0)
					{
						if(employee_getSueldo(pEmployee,&auxSueldo)==0)
						{
							ll_add(pArrayListEmployee, i);
						}
					}
				}
			}
		}
		retorno=0;
		fclose(pArchivo);
	}
	return retorno;
}
int controller_saveAsBinarySinCarga(char* path , LinkedList* pArrayListEmployee)
{
	return 1;
}*/
