/*
 * ArrayEmployees.h
 *
 *  Created on: 16 oct. 2021
 *      Author: HERNAN
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;

}Employee;

//funciones pedidas
int initEmployees(Employee* list, int len);
int addEmployee(Employee* list, int len, int id, char name[],char
lastName[],float salary,int sector);
int printEmployees(Employee* list, int length);
int findEmployeeById(Employee* list, int len,int id);
int removeEmployee(Employee* list, int len, int id);

//funciones hechas
int buscarLibre(Employee* estructura,int LARGO);
int buscarOcupado(Employee* estructura,int LARGO);
int altaEmpleado(Employee* estructura, int LARGO);
void mostrarUnaPosicion(Employee* list,int posicion);
int modificacionEmpleado(Employee* pArray, int LARGO);
int bajaEmpleado(Employee* list, int len);



#endif /* ARRAYEMPLOYEES_H_ */
