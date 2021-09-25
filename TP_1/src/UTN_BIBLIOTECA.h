/*
 * UTN_BIBLIOTECA.h
 *
 *  Created on: 9 sept 2021
 *      Author: HERNAN
 */


#include <stdio.h>
#include <stdlib.h>
#ifndef UTN_BIBLIOTECA_H_
#define UTN_BIBLIOTECA_H_

void inicializarProgramas();
int getIntMaxYMin(int* pNumero,int max,int min,char* mensaje);
int sumarFloat(float* suma,float sumandoUno,float sumandoDos);
void finalizarProgramas();
int restarFloat(float* resta,float minuendo,float sustraendo);
int multiplicarFloat(float* producto,float factorUno,float factorDos);
int dividirFloat(float* cociente,float dividendo,float divisor);
int factorialFloat(int* factorial, float numero);
int utn_PreguntaContinuar(char* pRespuesta,char opcionUno, char opcionDos, char* mensaje);
int getFloat(float* pNumero,char* mensaje);

int getInt(int* pNumero,char* mensaje);
void inicializarProgramas();
int getIntMaxYMin(int* pNumero,int max,int min,char* mensaje);
int sumarInt(int* suma,int sumandoUno,int sumandoDos);
void finalizarProgramas();
int restarInt(int* resta,int minuendo,int sustraendo);
int multiplicarInt(int* producto,int factorUno,int factorDos);
int dividirInt(float* cociente,int dividendo,int divisor);
int factorialInt(int* factorial, int numero);
int utn_PreguntaContinuar(char* pRespuesta,char opcionUno, char opcionDos, char* mensaje);

#endif /* UTN_BIBLIOTECA_H_ */
