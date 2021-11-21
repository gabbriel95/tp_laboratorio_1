#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;
    this = (LinkedList*) malloc(sizeof(LinkedList));

    if(this != NULL)
    {
    	this->size = 0;
    	this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
    	returnAux = this->size;
    }



    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o
 * (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode = NULL;
	if(this!=NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
	{
		pNode = this->pFirstNode;
		//printf("%p\n",pNode);
		for(int i=0; i<nodeIndex;i++)
		{
			pNode = pNode->pNextNode;
			//printf("%p\n",pNode);
		}
	}
    return pNode;
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
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pNodoAnterior = NULL;
    Node* pNodoNuevo = NULL;
    int tamanioLista = ll_len(this);

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= tamanioLista)
    {
    	pNodoNuevo = (Node*) malloc(sizeof(Node));

    	if(pNodoNuevo != NULL)
    	{
    		pNodoNuevo->pElement = pElement;//puede ser null cuando le paso NULL no me da al 100%
    		pNodoNuevo->pNextNode = NULL;

    		if(nodeIndex == 0)
    		{
    			pNodoNuevo->pNextNode = this->pFirstNode;//se asigna el primer nodo, al nuevo nodo creado
    			this->pFirstNode = pNodoNuevo;//El primer nodo va a ser el nuevo
    		}
    		else
    		{
    			pNodoAnterior = getNode(this, nodeIndex - 1);

    			if(pNodoAnterior != NULL)
    			{
    				pNodoNuevo->pNextNode = pNodoAnterior->pNextNode;// el nuevo nodo apunta a NULL
    				pNodoAnterior->pNextNode = pNodoNuevo;//el anterior nodo apunta al nuevo nodo
    			}
    		}
    		this->size++;// CUANDO VERIFICO QUE EL pElement no sea null, me dice que Error en el valor de size de la lista se debe incrementar al agregar nodos
    		returnAux = 0;
    	}
    }

    return returnAux;//OK
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
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int tamaniLista = ll_len(this);
    if(this != NULL)
    {
    	returnAux = addNode(this,tamaniLista, pElement);
    }

    //debe incrementar el size de la lista, pero en teoria lo hace la funcion
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)//Devuelve un elemento de la lista, con el indice
{											//para llegar al nodo necesito su direccion
	//Verifica retorno con parametros correctos KO
	//Solicita el primer elemento ---> direccion
	//Solicita el ultimo elemento
	//Solicita elementos fuera del indice
	//Solicitar elementos pasando una lista null
	void* returnAux = NULL;//Retorna el puntero al elemento
	Node* pNode = NULL;//  = getNode(this);
	int tamanioLista = ll_len(this);

	if(this != NULL && index >= 0 && index <= tamanioLista)
	{
		pNode = getNode(this, index);//getnode devuelve la direccion del nodo del indice

		if(pNode != NULL)
		{
			returnAux = pNode->pElement;
		}
	}

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)//Reemplaza un elemento de la lista
{
    int returnAux = -1;//verifica retorno con parametros correctos
    Node* pNode = NULL;
    int tamanioLista = ll_len(this);

    if(this!= NULL && index >= 0 && index <= tamanioLista)//intenta setear un elemento fuera del indice y NULL
    {
    	pNode = getNode(this, index);//getnode devuelve la direccion del nodo por indice
    		//puede ser null el Pelement
    	if(pNode != NULL)
    	{
    		pNode->pElement = pElement;
    		returnAux = 0;
    	}
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pNodoIndex = NULL;
    Node* pNodoPrev = NULL;
    int tamanioLista = ll_len(this);

    if(this != NULL && index >= 0 && index < tamanioLista)
    {
    	pNodoIndex = getNode(this, index);
    	if(pNodoIndex != NULL)
    	{
    		if(index > 0)
    		{
    			pNodoPrev = getNode(this, index-1);
    			if(pNodoPrev != NULL)
    			{
					pNodoPrev->pNextNode = pNodoIndex->pNextNode;
					free(pNodoIndex);
					this->size--;
					returnAux = 0;
    			}
    		}
    		else
    		{
    			this->pFirstNode = pNodoIndex->pNextNode;
    			free(pNodoIndex);
    			this->size--;
    			returnAux = 0;
    		}
    	}
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int tamanio = ll_len(this);

    if(this != NULL)
    {
    	for(int i=0; i<tamanio; i++)
    	{
    		ll_remove(this, 0);
    	}

    	returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	if(ll_clear(this) == 0)
    	{
			free(this);
			returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro(retorna el indice del elemento)
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* pNode = NULL;
    int tamanioLista;

    if(this != NULL)
    {
    	tamanioLista = ll_len(this);
    	for(int i=0;i<tamanioLista; i++)
    	{
    		pNode = getNode(this, i);
    		if(pNode != NULL && pNode->pElement == pElement)
    		{
    			returnAux = i;
    			break;
    		}
    	}
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    int tamanio;

    if(this != NULL)
    {
    	tamanio = ll_len(this);

    	if(tamanio > 0)
    	{
    		returnAux = 0;
    	}
    	else
    	{
    		returnAux = 1;
    	}
    }

    return returnAux;
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
    int returnAux = -1;
    int tamanio = ll_len(this);

    if(this != NULL && index >= 0 && index <= tamanio)
    {
    	returnAux = addNode(this, index, pElement);
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    Node* pNode = NULL;
    int tamanio = ll_len(this);

    if(this != NULL && index >= 0 && index < tamanio)
    {
    	pNode = ll_get(this, index);

    	if(pNode != NULL)
    	{
    		if(ll_remove(this, index) == 0)
    		{
    			returnAux = pNode;
    		}

    	}
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int tamanio = ll_len(this);

    if(this != NULL)
    {
    	returnAux = 0;
    	for(int i=0; i<tamanio; i++)
    	{
    		if(ll_indexOf(this, pElement) == i)
    		{
    			returnAux = 1;
    		}
    	}
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    void* pElemento = NULL;
    int tamanioLista = ll_len(this2);

    if(this != NULL && this2 != NULL)
    {
    	returnAux = 1;
    	for(int i=0; i<tamanioLista; i++)
    	{
    		pElemento = ll_get(this2, i);

    		if(pElemento != NULL)
    		{
    			if(ll_contains(this, pElemento) == 0)
    			{
    				returnAux = 0;
    				break;
    			}
    		}
    	}
    }

    return returnAux;
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
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* pElement = NULL;
    int tamanioLista = ll_len(this);

    if(this != NULL && from >=0 && from <= tamanioLista && to<= tamanioLista)
    {
    	cloneArray = ll_newLinkedList();

    	if(cloneArray != NULL)
    	{
    		for(int i=from; i<to; i++)
    		{
    			pElement = ll_get(this, i);

    			ll_add(cloneArray, pElement);
    		}
    	}
    }


    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int tamaniList = ll_len(this);

    if(this != NULL)
    {
    	cloneArray = ll_subList(this, 0, tamaniList);
    }


    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;

    return returnAux;

}

