
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "UTN_GetIn.h"
#include "parser.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout, NULL);

    int opcion;
    int flagTexto=0;
    int flagBinario=0;
    char respuesta;
    int flagAddSinCarga=0;
    int controlCargaBinario=0;
    int controlCargaTexto=0;

    LinkedList* listaEmpleados=ll_newLinkedList();
    employee_idMax("data.csv", "dataIdMaxima.txt");

    printf("\nBIENVENID@ AL PROGRAMA\n");

    do{
    	printf("\n____________________________________\nMENU PRINCIPAL\n____________________________________\n");
        printf("\n-----------CARGA DE ARCHIVOS-------------\n"
        		"1. Modo Texto\n"
        		"2. Modo Binario\n"

        		"\n-----------CARGA DATOS EMPLEADOS-------------\n"
        		"3. Alta\n"
        		"4. Modificacion de datos\n"
        		"5. Baja\n"

        		"\n-----------INFORMES-------------\n"
        		"6. Listar Empleados\n"
        		"7. Ordenar Empleados\n"

        		"\n-----------GUARDAR MODIFICACIONES-------------\n"
        		"8. Guardar en Modo Texto\n"
        		"9. Guardar en Modo Binario\n"

        		"\n10. SALIR\n");
        utn_getNumero(&opcion, "\nIngrese Opcion Deseada\n", "\nError! Ingreso Invalido\n", 1,10, 2);


        switch(opcion)
        {
            case 1:
            	if(flagAddSinCarga==1)
            	{
            		printf("\nSi tocas que si borras todo lo que cargaste manual, grava primero\n");
            		preguntarSeguir(&respuesta,1, "\nCargar Igual? s/n\n","ERROR! Ingreso Invalido");

            	}
            	if(flagTexto==1 && flagBinario==0)
            	{
            		printf("\nEl archivo ya esta en uso\n");
            	}
            	if(flagTexto==0 && flagBinario==1)
            	{
            		printf("\nEl archivo ya fue abierto en Modo Binario\n");
            	}
            	if((flagTexto==0 && flagBinario==0)/*||respuesta=='s'||respuesta=='S'*/)
            	{
            		if(controller_loadFromText("data.csv",listaEmpleados)==0)
            		{
            			flagTexto=1;
            			printf("\nCarga en Modo texto realizada con exito\n");
            		}
            		else
            		{
            			printf("\nNo se pudo cargar el archivo en modo texto\n");
            		}
            	}

            break;
            case 2:
            	if(flagTexto==0 && flagBinario==1)
            	{
            		printf("\nEl archivo ya esta en uso\n");
            	}
            	if(flagTexto==1 && flagBinario==0)
            	{
            		printf("\nEl archivo ya fue abierto en Modo Texto\n");
            	}
            	if(flagTexto==0 && flagBinario==0)
            	{
            		if(controller_loadFromBinary("data.bin",listaEmpleados)==0)
            		{
            			flagBinario=1;
            			printf("\nCarga en Modo binario realizada con exito\n");
					}
					else
					{
						flagBinario=0;
						printf("\nNo se pudo cargar el archivo en modo binario\n"
								"Si desea crearlo primero cargue en modo texto (opcion 1) y"
								"grave en Modo Binario (Opcion 9)\n");
					}
            	}

            break;
            case 3:
            	if(controller_addEmployee(listaEmpleados)==0)
            	{
            		printf("\nEmpleado cargado con exito\n");
            		if(flagBinario==0 && flagTexto==0)
            		{
            			flagAddSinCarga=1;
            		}
            	}
            	else
            	{
            		printf("\nEl Empleado no se cargo\n");
            	}
            break;
            case 4:
            	if(ll_isEmpty(listaEmpleados)==0)
            	{
            		controller_editEmployee(listaEmpleados);
            	}
            	else
            	{
            		printf("\n No existe lista para modificar o la lista esta vacia\n");
            	}
            break;
            case 5:
            	if(ll_isEmpty(listaEmpleados)==0)
				{
					if(controller_removeEmployee(listaEmpleados)==0)
					{
						printf("\n mpleado borrado con exito\n");
					}
					else
					{
						printf("\nNo se Elimino\n");
					}
				}
				else
				{
					printf("\n No existe empleado para modificar o la lista esta vacia\n");
				}
            break;
            case 6:
            	if(ll_isEmpty(listaEmpleados)==0)
				{
            		if(controller_ListEmployee(listaEmpleados)==0)
					{
						if(flagTexto!=1 && flagBinario!=1)
						{
							printf("n-----Fin de la lista-----\nLos datos impresos no provienen de ningun archivo\n");
						}
						else
						{
							printf("\n -----Fin de la lista-----\n");
						}
					}
				}
				else
				{
					printf("\n No existe lista para imprimir o la lista esta vacia\n");
				}
            break;
            case 7:
            	if(ll_isEmpty(listaEmpleados)==0)
				{
            		if(controller_sortEmployee(listaEmpleados)==0)
					{
						printf("\nEmpleados Ordenados con exito\n");
					}
            		else
            		{
            			printf("\nNo se pudo ordenar\n");
            		}
				}
				else
				{
					printf("\n No existe lista para ordenar o la lista esta vacia\n");
				}
            break;
            case 8:
            	if(flagAddSinCarga==1)
            	{
            		printf("\nSe sobreescribira la lista en modo texto existente con la lista cargada manualmente\n");
            		if(preguntarSeguir(&respuesta, 1,"\nCONTINUAR???? s/n\n", "ERROR! Ingreso Invalido")==0)
            		{
            			if(respuesta=='s'||respuesta=='S')
            			{
            				controlCargaTexto=1;
            			}
            		}
            	}
            	if(flagAddSinCarga==0 && flagBinario==0 && flagTexto==0)
            	{
            		printf("\nNo existe archivo ni datos cargados\n");
            		controlCargaTexto=0;
            	}
            	if(flagBinario==1)
            	{
            		printf("\nEl archivo fue abierto en modo Binario\n");
					if(preguntarSeguir(&respuesta, 1,"\nCONTINUAR???? s/n\n", "ERROR! Ingreso Invalido")==0)
					{
						if(respuesta=='s'||respuesta=='S')
						{
							controlCargaTexto=1;
						}
					}
				}
            	if(controlCargaTexto==1||flagTexto==1)
            	{
            		if(controller_saveAsText("data.csv", listaEmpleados)==0)
            		{
            			printf("\nDatos Cargados con Exito en Modo Texto\n");
            		}
            	}
            break;
            case 9:
            	if(flagAddSinCarga==1)
            	{
            		printf("\nSe sobreescribira la lista en modo binario existente con la lista cargada manualmente\n");
            		if(preguntarSeguir(&respuesta, 1,"\nCONTINUAR???? s/n\n", "ERROR! Ingreso Invalido")==0)
            		{
            			if(respuesta=='s'||respuesta=='S')
            			{
            				controlCargaBinario=1;
            			}
            		}
            	}
            	if(flagAddSinCarga==0 && flagBinario==0 && flagTexto==0)
            	{
            		printf("\nNo existe archivo ni datos cargados\n");
            		controlCargaBinario=0;
            	}
            	if(flagTexto==1)
            	{
            		printf("\nEl archivo fue abierto en modo Texto\n");
					if(preguntarSeguir(&respuesta, 1,"\nCONTINUAR???? s/n\n", "ERROR! Ingreso Invalido")==0)
					{
						if(respuesta=='s'||respuesta=='S')
						{
							controlCargaBinario=1;
						}
					}
				}
            	if(controlCargaBinario==1||flagBinario==1)
            	{
            		if(controller_saveAsBinary("data.bin", listaEmpleados)==0)
            		{
            			printf("\nDatos Cargados con Exito en Modo Binario\n");
            		}
            	}
            break;
        }
    }while(opcion != 10);
    return 0;
}

