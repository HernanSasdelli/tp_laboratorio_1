#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "UTN_GetIn.h"
#include "parser.h"

/** \brief crea un espacio de memoria del tamaño de la estructura
 *  \param void
 * \return int (-1) error (0) si resolvio
 */
Employee* employee_new(void)
{
	Employee* pSalon=(Employee*)malloc(sizeof(Employee));
	return pSalon;
}

/** \brief recibe por punteros las variables para cargar la estructura y llama a la funcion employee_new
 *  para crear un nuevo espacio de memoria
 *  \param (char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo)
 * \return int (-1) error (0) si resolvio
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo)
{
	Employee* retorno=NULL;
	if(idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldo!=NULL)
	{
		Employee* auxEmployee=employee_new();
		if(esNumerica(idStr)==0 && esNumerica(sueldo)==0 && esNumerica(horasTrabajadasStr)==0)
		{
			int AuxId=atoi(idStr);
			int horasTrabajadas=atoi(horasTrabajadasStr);
			int auxSueldo=atoi(sueldo);
			if(employee_setId(auxEmployee,AuxId)==0 &&
			employee_setNombre(auxEmployee,nombreStr)==0 &&
			employee_setHorasTrabajadas(auxEmployee, horasTrabajadas)==0 &&
			employee_setSueldo(auxEmployee, auxSueldo)==0)
			{
				retorno=auxEmployee;
			}
		}
	}
	return retorno;
}
/** \brief buscar una estructura de la LinkedList por id
 *  \param (LinkedList* pList,int id)
 * \return int (-1) error (0) si resolvio
 */
int employee_findById(LinkedList* pList,int id)
{
	int retorno=-1;
	int iLargo;
	int i;
	if(id>=0 && pList!=NULL)
	{
		iLargo=ll_len(pList);//preguntar largo
		for(i=0;i<iLargo;i++)
		{
			Employee* aux=ll_get(pList, i);
			if(id==aux->id)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}
/** \brief carga el cammpo nombre recibido por parametros
 *  \param (Employee* this,char* nombre)
 * \return int (-1) error (0) si resolvio
 */
int employee_setNombre(Employee* this,char* nombre)
{
	int retorno=-1;
	if(this!=NULL && nombre!=NULL)
	{
		if(esNombre(nombre)==0)
		{
			retorno=0;
			strncpy(this->nombre,nombre,51);
		}
	}
	return retorno;
}
/** \brief devuelve por puntero el nombre de un empleado de la estructura
 *  \param (Employee* this,char* nombre)
 * \return int (-1) error (0) si resolvio
 */
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno=-1;
	if(this!=NULL && nombre!=NULL)
	{
		retorno=0;
		strncpy(nombre,this->nombre,51);
	}
	return retorno;
}

/** \brief carga el cammpo horastrabajadas recibido por parametros
 *  \param (Employee* this,int horasTrabajadas)
 * \return int (-1) error (0) si resolvio
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno=-1;
	if(this!=NULL && horasTrabajadas>=0)
	{
		retorno=0;
		this->horasTrabajadas=horasTrabajadas;
	}
	return retorno;
}

/** \brief devuelve por puntero las horas trabajadas de un empleado de la estructura
 *  \param (Employee* this,int* horasTrabajadas)
 * \return int (-1) error (0) si resolvio
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno=-1;
	if(this!=NULL&& horasTrabajadas!=NULL)
	{
		retorno=0;
		*horasTrabajadas=this->horasTrabajadas;
	}
	return retorno;
}

/** \brief carga el campo sueldo recibido por parametros
 *  \param Employee* this,int sueldo)
 * \return int (-1) error (0) si resolvio
 */
int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno=-1;
	if(this!=NULL && sueldo>0)
	{
		retorno=0;
		this->sueldo=sueldo;
	}
	return retorno;
}

/** \brief devuelve por puntero el sueldo de un empleado de la estructura
 *  \param (Employee* this,int* sueldo)
 * \return int (-1) error (0) si resolvio
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno =-1;
	if(this!=NULL && sueldo!=NULL)
	{
		retorno=0;
		*sueldo=this->sueldo;
	}
	return retorno;
}

/** \brief carga la ID recibido por parametros en un campo de la estructura
 *  \param (Employee* this,int id)
 * \return int (-1) error (0) si resolvio
 */
int employee_setId(Employee* this,int id)
{
	int retorno =-1;
	if(this!=NULL && id>0)
	{
		retorno=0;
		this->id=id;
	}
	return retorno;
}

/** \brief devuelve por puntero La id de un empleado de la estructura
 *  \param (Employee* this,int* id)
 * \return int (-1) error (0) si resolvio
 */
int employee_getId(Employee* this,int* id)
{
	int retorno =-1;
	if(this!=NULL && id!=NULL)
	{
		retorno=0;
		*id=this->id;
	}
	return retorno;
}
/*int employee_setIdChar(Employee* this,char* id)
{
	int retorno =-1;
	if(this!=NULL && id!=NULL)
	{
		retorno=0;
		strccpy(this->id,id,51);
	}
	return retorno;
}

int employee_getIdChar(Employee* this,char* id)
{
	int retorno =-1;
	if(this!=NULL && id!=NULL)
	{
		retorno=0;
		strccpy(id,this->id,51);
	}
	return retorno;
}*/

/** \brief pide datos y los devuelve por punteros
 *  \param (char* name, char* sueldo ,char* horasTrabajadas)
 * \return int (-1) error (0) si resolvio
 */
int employee_pedirDatos(char* name, char* sueldo ,char* horasTrabajadas)
{
	int retorno=-1;

	char auxNombre[51];
	char auxSueldo[51];
	char auxHoras[51];

	if(name!=NULL && sueldo!=NULL && horasTrabajadas!=NULL /*&& id!=NULL*/)
	{
		if(utn_getNombre(auxNombre,51,"\nINgrese Nombre\n","\nERROR! Ingreso Invalido",1)==0)
		{
			if(utn_getNumeroChar(auxHoras,"\nIngrese Horas Trabajadas\n ","\nERROR! Ingreso Invalido", 0, 150, 1)==0)
			{
				if(utn_getNumeroChar(auxSueldo,"\nIngrese Sueldo\n ","\nERROR! Ingreso Invalido", 0, 200000, 1)==0)
				{
					retorno=0;
					strncpy(name,auxNombre,51);
					strncpy(sueldo,auxSueldo,51);
					strncpy(horasTrabajadas,auxHoras,51);

				}
			}
		}
	}
	if(retorno==-1)
	{
		printf("\nLos datos no han sido ingresados correctamente\n");
	}
	return retorno;
}

/** \brief busca el ID mas alto de un archivo, y genera otro donde lo guarda, una vez que lo genero no vuelve a ingresar
 *  \param (char* path,char* pathId)
 * \return int (-1) error (0) si resolvio
 */
int employee_idMax(char* path,char* pathId)
{
	int retorno=-1;
	if(path!=NULL && pathId!=NULL)
	{

		LinkedList* auxlista=ll_newLinkedList();
		Employee* pAuxEmpleado=employee_new();
		FILE* pArchivo=fopen(path,"r");
		FILE* pArchivoId=fopen(pathId,"r");
		int idAuxMax=0;
		int flag=0;
		int idMax;

		if(pArchivoId==NULL)
		{
			pArchivoId=fopen(pathId,"w");
			if(parser_EmployeeFromText(pArchivo, auxlista)==0)
			{
				for(int i=0;i<ll_len(auxlista);i++)
				{
					pAuxEmpleado=(Employee*)ll_get(auxlista,i);
					employee_getId(pAuxEmpleado, &idAuxMax);
					if(flag==0||idAuxMax>idMax)
					{
						flag=1;
						idMax=idAuxMax;
					}
				}
				fprintf(pArchivoId,"%d",idMax);
				retorno=0;
			}
		}
		fclose(pArchivo);
		fclose(pArchivoId);
		}
	return retorno;
}

/** \brief genera un ID nuevo a partir de un archivo que guarda el ultimo ID pasado
 *  \param (char* path,int* nextId)
 * \return int (-1) error (0) si resolvio
 */
int employee_getNextId(char* path,int* nextId)
{
	int retorno=-1;
	FILE* pArchivo;
	int auxNextId;

	if(path!=NULL && nextId!=NULL)
	{
		pArchivo=fopen(path,"r");
		if(pArchivo!=NULL)
		{
			fscanf(pArchivo,"%d",&auxNextId);
			pArchivo=fopen(path,"w");
			auxNextId++;
			*nextId=auxNextId;
			fprintf(pArchivo,"%d",auxNextId);
			{
				retorno=0;
			}
		}
		else
			printf("el archivo no esta!");

		fclose(pArchivo);
	}
	return retorno;
}

/** \brief ordena alfabeticamente dos elementos de la lista
 *  \param (void* elemento1, void* elemento2)
 * \param
 * \return int (-1) error (0) si resolvio
 */
int employee_sortNombre(void* elemento1, void* elemento2)
{
	int retorno=-1;
	char nombre1[51];
	char nombre2[51];
	if(elemento1!=NULL && elemento2!=NULL)
	{
		Employee* pAuxEmployee1=(Employee*) elemento1;
		Employee* pAuxEmployee2=(Employee*) elemento2;
		if(employee_getNombre(pAuxEmployee1, nombre1)==0 && employee_getNombre(pAuxEmployee2, nombre2)==0)
		{
			retorno=strcmp(nombre1,nombre2);
		}
	}
	return retorno;
}

/** \brief libera el espacio de memoria correspondiente a un empleado
 *  \param (Employee* this)
 * \return int (-1) error (0) si resolvio
 */
void employee_delete(Employee* this)
{
	if(this!=NULL)
	{
		free(this);
	}
}
















