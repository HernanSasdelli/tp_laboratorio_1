#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"
#include "../testing/inc/main_test.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 *///1
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this=NULL;
    this=(LinkedList*)malloc(sizeof(LinkedList));
    if(this!=NULL)
    {
    	this->size=0;
    	this->pFirstNode=NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *///2
int ll_len(LinkedList* this)
{
    int retorno=-1;
    if(this!=NULL)
    {
    	retorno=this->size;
    }
    return retorno;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *///3
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNodeRetorno=NULL;
	int i;
	if(this!=NULL && nodeIndex>=0 && nodeIndex<ll_len(this))//menor porque el anterior tiene la direccion del siguiente
	{
		pNodeRetorno=this->pFirstNode;
		for(i=0;i<nodeIndex;i++)
		{
			pNodeRetorno=pNodeRetorno->pNextNode;
		}
	}
    return pNodeRetorno;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 *///4
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
     int retorno=-1;
     Node* pNodoNuevo;
     Node* pNodoAnterior;

     if(this!=NULL && nodeIndex>=0 && nodeIndex<=ll_len(this))//this->size
     {
    	pNodoNuevo=(Node*)malloc(sizeof(Node));
 		if(pNodoNuevo!=NULL)
 		{
 			pNodoNuevo->pElement=pElement;
 			if(nodeIndex==0)//el primer nodo
 			{
 				pNodoNuevo->pNextNode=this->pFirstNode;
 				this->pFirstNode=pNodoNuevo;
 			}
 			else
 			{
 				pNodoAnterior=getNode(this,(nodeIndex-1));//la posicion que me dieron menos uno
 				pNodoNuevo->pNextNode=pNodoAnterior->pNextNode;//si es el ultimo apunta a null
 				pNodoAnterior->pNextNode=pNodoNuevo;
 			}
 			this->size++;
 			retorno=0;
 		}
      }
     return retorno;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 *///5
int ll_add(LinkedList* this, void* pElement)
{
    int retorno=-1;
    if(this!=NULL)
    {
    	retorno=addNode(this,ll_len(this),pElement);
    }

    return retorno;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 *///6
void* ll_get(LinkedList* this, int index)
{
    void* pNodoRetorno=NULL;

    if(this!=NULL && index>=0 && index<ll_len(this))
    {
    	Node* auxNodo=getNode(this, index);
    	if(auxNodo!=NULL)
    	{
    		pNodoRetorno=auxNodo->pElement;
    	}
    }
    return pNodoRetorno;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 *///7
int ll_set(LinkedList* this, int index,void* pElement)
{
    int retorno=-1;
    Node* pAuxNodo;

    if(this!=NULL && index>=0 && index<ll_len(this))
    {
    	pAuxNodo=getNode(this, index);
    	if(pAuxNodo!=NULL)
    	{
    		pAuxNodo->pElement=pElement;
    		retorno=0;
    	}
    }

    return retorno;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 *///8
int ll_remove(LinkedList* this,int index)
{
    int retorno=-1;
    Node* pAuxThis;
    Node* pAuxAnterior;

    if(this!=NULL && index>=0 && index<ll_len(this))
    {
    	pAuxThis=getNode(this, index);
    	pAuxAnterior=getNode(this, index-1);

    	if(pAuxThis!=NULL && index==0)
    	{
    		this->pFirstNode=pAuxThis->pNextNode;
    	}
    	else if(pAuxThis!=NULL && pAuxAnterior!=NULL)
    	{
    		pAuxAnterior->pNextNode=pAuxThis->pNextNode;
    	}
    	free(pAuxThis);
    	this->size--;
    	retorno=0;
    }
    return retorno;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 *///9
int ll_clear(LinkedList* this)
{
    int retorno=-1;
    int i;
    if(this!=NULL)
    {
    	for(i=0;i<ll_len(this);i++)
    	{
    		ll_remove(this, i);
    	}
    	retorno=0;
    }
    return retorno;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 *///10
int ll_deleteLinkedList(LinkedList* this)
{
    int retorno=-1;
    if(this!=NULL)
    {
    	ll_clear(this);//sin esto tambien da 100% pero deja los zombies
    	free(this);
    	retorno=0;
    }

    return retorno;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 *///11
int ll_indexOf(LinkedList* this, void* pElement)
{
    int retorno=-1;
    int i;
    Node* pAuxNode;

    if(this!=NULL)
    {
    	for(i=0;i<ll_len(this);i++)
    	{
    		pAuxNode=getNode(this, i);
    		if(pAuxNode->pElement==pElement)
    		{
    			retorno=i;
    			break;
    		}
    	}
    }
    return retorno;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 *///12
int ll_isEmpty(LinkedList* this)
{
    int retorno=-1;
    if(this!=NULL && ll_len(this)>0)
    {
    	retorno=0;
    }
    else if(this!=NULL)
    {
    	retorno=1;
    }
    return retorno;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int retorno=-1;
    if(this!=NULL && index>=0 && index<=ll_len(this))
    {
    	retorno=addNode(this,index,pElement);
    }
    return retorno;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 *///14
void* ll_pop(LinkedList* this,int index)
{
    void* pAuxRetorno=NULL;
    if(this!=NULL && index>=0 && index<=ll_len(this))
    {
    	pAuxRetorno=ll_get(this, index);
    	if(pAuxRetorno!=NULL)
    	{
    		ll_remove(this, index);
    	}
    }
    return  pAuxRetorno;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*///15
int ll_contains(LinkedList* this, void* pElement)
{
    int retorno=-1;
    int i;
    Node* pAuxNodo;

    if(this!=NULL)
    {
    	retorno=0;//en el else no funciona
    	for(i=0;i<ll_len(this);i++)
    	{
    		pAuxNodo=getNode(this, i);
    		if(pAuxNodo!=NULL && ll_indexOf(this, pElement)>-1)
    		{
    			retorno=1;
    			break;
    		}
    	}
    }
    return retorno;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*///16
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int retorno=-1;
    int i;
    int control;
    Node* pAuxNodo;

    if(this!=NULL && this2!=NULL)
    {
    	retorno=0;
    	for(i=0;i<ll_len(this2);i++)
    	{
    		pAuxNodo=ll_get(this2, i);
    		if(pAuxNodo!=NULL)
    		{
        		control=ll_contains(this, pAuxNodo);
        		if(control==0)
        		{
        			retorno=0;
        			break;
        		}
        		else if(control==1)
        		{
        			retorno=1;
        		}
    		}

    	}
    }
    return retorno;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*///17
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* pCloneArray=NULL;
    int i;
    //void* pAux;

    if(this!=NULL && from>=0 && from<to && to<=ll_len(this))
    {
    	pCloneArray=ll_newLinkedList();
    	for(i=from;i<to;i++)
    	{
    		//pAux=ll_get(this, i);
    		ll_add(pCloneArray,ll_get(this, i));
    	}
    }
    return pCloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*///18
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* pCloneLista=NULL;

    if(this!=NULL)
    {
    	pCloneLista=ll_subList(this, 0, ll_len(this));
    }

    return pCloneLista;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 *///19
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int retorno=-1;
    int i;
    int flag=0;
    void* auxThis;
    void* auxSiguente;

    if(this!=NULL && pFunc!=NULL && (order==0||order==1) && ll_len(this)>0)//con un solo elemento no tiene con que comparar
    {
    	do
    	{
    		flag=0;
			for(i=0;i<ll_len(this)-1;i++)//el swap para no pasarme
			{
				auxThis=ll_get(this, i);
				auxSiguente=ll_get(this, i+1);

				if(auxThis!=NULL && auxSiguente!=NULL)
				{
					if((pFunc(auxThis,auxSiguente)>0 && order==1) || (pFunc(auxThis,auxSiguente)<0 && order==0))
					{
                        ll_set(this,i,auxSiguente);
                        ll_set(this,i+1,auxThis);
                        flag=1;
					}
				}
			}
    	}while(flag==1);
    	retorno=0;
    }

    return retorno;

}
/** \brief Elimina elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 *//*
int ll_filter(LinkedList* this, int (*pFunc)(void*))
{
	int retorno=-1;
	int i;
	void* pAuxiliar;

	if(this != NULL && pFunc != NULL)
	{
		for(i=ll_len(this)-1;i>=0;i--)//al reves no anda
		{
			pAuxiliar=ll_get(this, i);
			if(pFunc(pAuxiliar)==0)
			{
				retorno=ll_remove(this, i);//remove retorna -1 o 0
			}
		}
	}
	return retorno;
}*/

/** \brief Elimina elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 *//*
int ll_map(LinkedList* this, void (*pFunc)(void*))
{
	int retorno=-1;
	void* pAuxiliar;
	int i;

	if(this != NULL && pFunc != NULL)
	{
		for(i=0;i<ll_len(this);i++)
		{
			pAuxiliar=ll_get(this, i);
			if(pAuxiliar!=NULL)
			{
				pFunc(pAuxiliar);
			}
		}
		retorno=0;
	}
	return retorno;
}*/
