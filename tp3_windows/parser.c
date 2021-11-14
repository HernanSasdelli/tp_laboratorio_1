#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "UTN_GetIn.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
	Employee* pAuxEmployee;
    char auxId[51];
    char auxNombre[51];
    char auxSueldos[51];
    char auxHoras[51];

    if(pFile!=NULL)
    {
       fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxSueldos,auxHoras);
       do
        {
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxSueldos,auxHoras)==4)
            {
               pAuxEmployee=employee_newParametros(auxId,auxNombre,auxHoras,auxSueldos);

                if(pAuxEmployee!=NULL)
                {
                   	if(ll_add(pArrayListEmployee,pAuxEmployee)==0)
                   	{
                   		retorno=0;
                   	}
                }
            }
          /*  else
            {
            	employee_delete(pFile);
            	retorno=-1;
            	break;
            }*/
        }while(feof(pFile)==0);


    }
    return retorno;
}
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
    	Employee* pAuxEmployee;

        do
        {
        	pAuxEmployee=employee_new();
            if(fread(pAuxEmployee,sizeof(Employee),1,pFile)==1)
            {
                if(ll_add(pArrayListEmployee,pAuxEmployee)==0)
                {
                	retorno=0;
                }
            }
            /*else
            {
                employee_delete(pAuxEmployee);
                break;
            }*/
        }while(feof(pFile)==0);
    }
    return retorno;
}

