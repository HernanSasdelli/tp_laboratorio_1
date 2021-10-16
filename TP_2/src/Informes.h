/*
 * Informes.h
 *
 *  Created on: 16 oct. 2021
 *      Author: HERNAN
 */

#ifndef INFORMES_H_
#define INFORMES_H_

int promedio(Employee* list, int LARGO,float* prom, float* total, int* cant);
void informesPromedio(Employee* list, int LARGO);
void imprimirListaOrdenada(Employee* list, int len);


//funcion pedida
int sortEmployees(Employee* list, int len, int order);

#endif /* INFORMES_H_ */
