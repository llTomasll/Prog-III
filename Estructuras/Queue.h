#ifndef U04_COLAS_COLA_QUEUE_H_
#define U04_COLAS_COLA_QUEUE_H_

#include "Node.h"
/**
 * Clase que implementa una Cola generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */
template <class T> class Queue {
private:
  Node<T> *front;
  Node<T> *back;

public:
  Queue();

  ~Queue();

  void enqueue(T dato);

  T dequeue();

  /*
   * T getFront();
   *
   * unsigned int size();
   */

  bool isEmpty();
};

/**
 * Constructor de la clase Cola
 * @tparam T
 */
template <class T> Queue<T>::Queue() { front = back = nullptr; }

/**
 * Destructor de la clase Cola, se encarga de liberar la memoria de todos los
 * nodos utilizados en la Cola
 * @tparam T
 */
template <class T> Queue<T>::~Queue() {}

/**
 * Inserta un dato en la Cola
 * @tparam T
 * @param dato  dato a insertar
 */
template <class T> void Queue<T>::enqueue(T dato) {
  Node<T> *aux = new Node<T>(dato, nullptr);

  if (back != nullptr) // por si está vacia
    back->setNext(aux);
  else
    front = aux;

  back = aux;
}

/**
 * Obtener el dato de la Cola
 * @tparam T
 * @return dato almacenado en el nodo
 */
template <class T> T Queue<T>::dequeue() {
  if (front == nullptr)
    throw 404;

  T data = front->getData();
  Node<T> *toDelete = front;
  front = front->getNext();
  delete toDelete;

  if (front == nullptr)
    back = front;

  return data;
}

/**
 * Responde si la Cola se encuentra Vacía
 * @tparam T
 * @return
 */
template <class T> bool Queue<T>::isEmpty() { return front == nullptr; }

#endif // U04_COLAS_COLA_QUEUE_H_
