/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas
LinkedList* ll_newLinkedList(void);//Construye la lista en el heap
int ll_len(LinkedList* this);//Cuenta cuantos elementos
Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);
int ll_add(LinkedList* this, void* pElement);//Agrega un elemento a la lista, (un puntero de cualquier tipo)
void* ll_get(LinkedList* this, int index);//Devuelve un elemento de la lista, con el indice
int ll_set(LinkedList* this, int index,void* pElement);//Reemplaza un elemento de la lista
int ll_remove(LinkedList* this,int index);// Remueve un elemento de la lista
int ll_clear(LinkedList* this);//Limpia la lista
int ll_deleteLinkedList(LinkedList* this);//Elimina la lista
int ll_indexOf(LinkedList* this, void* pElement);//Devuelve la posicion adentro de la lista, de un elemento en particular
int ll_isEmpty(LinkedList* this);//Me dice si la lista esta llena o no
int ll_push(LinkedList* this, int index, void* pElement);//Pone un elemento adentro dee la lista entre dos elementos
void* ll_pop(LinkedList* this,int index);//Elimina un elemento de la lista y lo devuelve
int ll_contains(LinkedList* this, void* pElement);//El elemento que yo pase esta contenido dentro de la lista
int ll_containsAll(LinkedList* this,LinkedList* this2);//Si una lista esta contenida en otra
LinkedList* ll_subList(LinkedList* this,int from,int to);//devuelve un pedazo de la lista
LinkedList* ll_clone(LinkedList* this);//devuelve una copia de la lista
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);//
