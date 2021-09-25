/*
 * UTN_BIBLIOTECA.c
 *
 *  Created on: 9 sept 2021
 *      Author: HERNAN
 */

#include "UTN_BIBLIOTECA.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//brief Pide un char al usuario y lo verifica entre dos opciones y muestra un mensaje del tipo de dato que se espera
/*//param pRespuesta: puntero a direccion de memoria de variable del tipo char del Main, donde almacena el valor char  ingresado por el usuario, luego de verificar
	param mensaje: puntero a mensaje escrito en el main, al momento de invocar la funcion
	param opcionUno, opcionDos: valores de variables char, con las dos opciones que quieren validarse
*/
//return retorna un valor int -1, en caso de que la funcion no haya podido ejecutarse correctamente, o un 0, en caso de que se haya ejecutado de forma correcta
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int utn_PreguntaContinuar(char* pRespuesta,char opcionUno, char opcionDos, char* mensaje)
{
	int retorno=-1;
	char seguir;

	if(pRespuesta!=NULL)
	{
		printf("\n%s\n",mensaje);
		fflush(stdin);
		scanf("%c",&seguir);
		if(seguir==opcionUno||seguir==opcionDos)
		{
			retorno=0;
			*pRespuesta=seguir;
		}
	}
	return retorno;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//brief Pide un float al usuario y muestra un mensaje del tipo de dato que se espera
/*//param pRespuesta: puntero a direccion de memoria de variable del tipo float del Main, donde almacena el valor float ingresado por el usuario, luego de verificar que
 * el scanf haya concretado de forma correcta el ingreso de datos, y que los punteros sean distintos de NULL.
	param mensaje: puntero a mensaje escrito en el main, al momento de invocar la funcion
*/
//return retorna un valor int -1, en caso de que la funcion no haya podido ejecutarse correctamente, o un 0, en caso de que se haya ejecutado de forma correcta
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int getFloat(float* pNumero,char* mensaje)
{
	int retorno;
	float numero;
	retorno=-1;

	if(pNumero!=NULL && mensaje!= NULL)
	{
		printf("\n%s\n",mensaje);
		fflush(stdin);
		if(scanf("%f",&numero)==1)
		{
			retorno=0;
			*pNumero = numero;
		}
	}

	return retorno;
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//brief Pide un int al usuario y muestra un mensaje del tipo de dato que se espera
/*//param pNumero: puntero a direccion de memoria de variable del tipo int del Main, donde almacena el valor int ingresado por el usuario, luego de verificar que
 * el scanf haya concretado de forma correcta el ingreso de datos, y que los punteros sean distintos de NULL.
	param mensaje: puntero a mensaje escrito en el main, al momento de invocar la funcion
	param max, min: indica los limites con que va a comparar el numero ingresado
*/
//return retorna un valor int -1, en caso de que la funcion no haya podido ejecutarse correctamente, o un 0, en caso de que se haya ejecutado de forma correcta
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int getIntMaxYMin(int* pNumero,int max,int min,char* mensaje)
{
	int retorno;
	int numero;
	retorno=-1;

	if(pNumero!=NULL && mensaje!=NULL)
	{
		printf("\n%s\n",mensaje);
		fflush(stdin);
		if(scanf("%d",&numero)==1)
		{
			if(numero<max && numero>min)
			{
				retorno=0;
				*pNumero = numero;
			}
		}

	}
	return retorno;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//brief No recibe parametros ni retorna ningun valor, solo se invoca para dar un mensaje de despedida al usuario
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void finalizarProgramas()
{
	puts("\nGracias por utilizar este programa");
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//brief No recibe parametros ni retorna ningun valor, solo se invoca para dar un mensaje de bienvenida al usuario
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void inicializarProgramas()
{
	puts("\t Bienvenid@\n \t Comencemos\n\t");
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//brief recibe por parametros dos float, los suma y graba el resultado en una variable float a traves de un puntero
/*//param suma: puntero a direccion de memoria de variable del tipo float del Main, donde almacena el valor float resultante de la operacion
	param sumandoUno, sumandoDos: variables del tipo float, recibidas por parametros
*/
//return retorna un valor int -1, en caso de que la funcion no haya podido ejecutarse correctamente, o un 0, en caso de que se haya ejecutado de forma correcta
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int sumarFloat(float* suma,float sumandoUno,float sumandoDos)
{
	int retorno;
	float resultado;
	retorno=-1;

	if(suma !=NULL)
	{
		retorno=0;
		resultado=sumandoUno+sumandoDos;
	}
	*suma=resultado;
	return retorno;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//brief recibe por parametros dos float, divide el primero, por el segundo(si este es distinto de 0) y graba el resultado en una variable float a traves de un puntero
/*//param cociente: puntero a direccion de memoria de variable del tipo float del Main, donde almacena el valor float resultante de la operacion
	param dividendo, divisor: variables del tipo float, recibidas por parametros
*/
//return retorna un valor int -1, en caso de que la funcion no haya podido ejecutarse correctamente, o un 0, en caso de que se haya ejecutado de forma correcta
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int dividirFloat(float* cociente,float dividendo,float divisor)
{
	int retorno;
	float resultado;
	retorno=-1;

	if(cociente != NULL)
	{
		if(divisor==0)
		{
			retorno=1;

		}
		else
		{

			retorno=0;
			resultado= dividendo/divisor;
		}
	}
	*cociente=resultado;
	return retorno;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//brief recibe por parametros dos float, resta el primero, por el segundo y graba el resultado en una variable float a traves de un puntero
/*//param resta: puntero a direccion de memoria de variable del tipo float del Main, donde almacena el valor float resultante de la operacion
	param minuendo, sustraendo: variables del tipo float, recibidas por parametros
*/
//return retorna un valor int -1, en caso de que la funcion no haya podido ejecutarse correctamente, o un 0, en caso de que se haya ejecutado de forma correcta
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int restarFloat(float* resta,float minuendo,float sustraendo)
{
	int retorno;
	float resultado;
	retorno=-1;

	if(resta != NULL)
	{
		retorno=0;
		resultado=minuendo-sustraendo;
	}
	*resta=resultado;
	return retorno;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//brief recibe por parametros dos float, los multiplica y graba el resultado en una variable float a traves de un puntero
/*//param producto: puntero a direccion de memoria de variable del tipo float del Main, donde almacena el valor float resultante de la operacion
	param factorUno, factorDos: variables del tipo float, recibidas por parametros
*/
//return retorna un valor int -1, en caso de que la funcion no haya podido ejecutarse correctamente, o un 0, en caso de que se haya ejecutado de forma correcta
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int multiplicarFloat(float* producto,float factorUno,float factorDos)
{
	int retorno;
	float resultado;
	retorno=-1;

	if(producto != NULL)
	{
		retorno=0;
		resultado=factorUno*factorDos;
	}
	*producto=resultado;
	return retorno;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//brief recibe por parametros una variable del tipo float, y calcula el factorial solo de la parte entera, si es positivo y distinto de cero, por lo que devuelve a traves
//del puntero, un valor del tipo int, luego de casterlo.
/*//param factorial: puntero a direccion de memoria de variable del tipo int del Main, donde almacena el valor int resultante de la operacion
	param numero: variable del tipo float, recibidas por parametros
*/
//return retorna un valor int -1, en caso de que la funcion no haya podido ejecutarse correctamente, o un 0, en caso de que se haya ejecutado de forma correcta
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int factorialFloat(int* factorial, float numero)
{
	int retorno;
	int i;
	int acumulador;

	acumulador=1;

	retorno=-1;
	if(factorial!=NULL)
	{
		if(numero>=1)
		{
			numero=(int) numero;
			for(i=numero;i>1;i--)
			{
				acumulador=acumulador*i;
				retorno=0;
			}
		}
	}
	*factorial=acumulador;
	return retorno;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//brief recibe por parametros dos int, los suma y graba el resultado en una variable int a traves de un puntero
/*//param suma: puntero a direccion de memoria de variable del tipo int del Main, donde almacena el valor int resultante de la operacion
	param sumandoUno, sumandoDos: variables del tipo int, recibidas por parametros
*/
//return retorna un valor int -1, en caso de que la funcion no haya podido ejecutarse correctamente, o un 0, en caso de que se haya ejecutado de forma correcta
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int sumarInt(int* suma,int sumandoUno,int sumandoDos)
{
	int retorno;
	int resultado;
	retorno=-1;

	if(suma !=NULL)
	{
		retorno=0;
		resultado=sumandoUno+sumandoDos;
	}
	*suma=resultado;
	return retorno;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//brief recibe por parametros dos int, divide el primero, por el segundo(si este es distinto de 0) y graba el resultado en una variable float a traves de un puntero, luego
//de castear uno de las variables recibidas
/*//param cociente: puntero a direccion de memoria de variable del tipo float del Main, donde almacena el valor float resultante de la operacion
	param dividendo, divisor: variables del tipo int, recibidas por parametros
*/
//return retorna un valor int -1, en caso de que la funcion no haya podido ejecutarse correctamente, o un 0, en caso de que se haya ejecutado de forma correcta
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int dividirInt(float* cociente,int dividendo,int divisor)
{
	int retorno;
	float resultado;
	retorno=-1;

	if(cociente != NULL)
	{
		if(divisor==0)
		{
			retorno=1;

		}
		else
		{
			printf("\n%d %d\n",dividendo, divisor);
			retorno=0;
			resultado= dividendo/(float)divisor;
		}
	}
	*cociente=resultado;
	return retorno;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//brief recibe por parametros dos int, resta el primero, por el segundo y graba el resultado en una variable int a traves de un puntero
/*//param resta: puntero a direccion de memoria de variable del tipo int del Main, donde almacena el valor int resultante de la operacion
	param minuendo, sustraendo: variables del tipo int, recibidas por parametros
*/
//return retorna un valor int -1, en caso de que la funcion no haya podido ejecutarse correctamente, o un 0, en caso de que se haya ejecutado de forma correcta
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int restarInt(int* resta,int minuendo,int sustraendo)
{
	int retorno;
	int resultado;
	retorno=-1;

	if(resta != NULL)
	{
		retorno=0;
		resultado=minuendo-sustraendo;
	}
	*resta=resultado;
	return retorno;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//brief recibe por parametros dos int, los multiplica y graba el resultado en una variable int a traves de un puntero
/*//param producto: puntero a direccion de memoria de variable del tipo int del Main, donde almacena el valor int resultante de la operacion
	param factorUno, factorDos: variables del tipo int, recibidas por parametros
*/
//return retorna un valor int -1, en caso de que la funcion no haya podido ejecutarse correctamente, o un 0, en caso de que se haya ejecutado de forma correcta
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int multiplicarInt(int* producto,int factorUno,int factorDos)
{
	int retorno;
	int resultado;
	retorno=-1;

	if(producto != NULL)
	{
		retorno=0;
		resultado=factorUno*factorDos;
	}
	*producto=resultado;
	return retorno;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//brief recibe por parametros una variable del tipo int, si es positivo y distinto de cero, por lo que devuelve a traves del puntero, un valor del tipo int
/*//param factorial: puntero a direccion de memoria de variable del tipo int del Main, donde almacena el valor int resultante de la operacion
	param numero: variable del tipo int, recibidas por parametros
*/
//return retorna un valor int -1, en caso de que la funcion no haya podido ejecutarse correctamente, o un 0, en caso de que se haya ejecutado de forma correcta
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int factorialInt(int* factorial, int numero)
{
	int retorno;
	int i;
	int acumulador;

	acumulador=1;

	retorno=-1;
	if(factorial!=NULL)
	{
		if(numero>0)
		{
			for(i=numero;i>1;i--)
			{
				acumulador=acumulador*i;
				retorno=0;
			}
		}
	}
	*factorial=acumulador;
	return retorno;
}

