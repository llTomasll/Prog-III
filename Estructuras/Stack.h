#ifndef U03_PILAS_PILA_STACK_H_
#define U03_PILAS_PILA_STACK_H_

#include "Node.h"
/**
 * Clase que implementa una Pila generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */
template <class T> class Stack {
private:
  Node<T> *top;

public:
  Stack();

  Stack(const Stack<T> &li);

  ~Stack();

  void push(T dato);

  T pop();

  bool isEmpty();
};

/**
 * Constructor de la clase Pila
 * @tparam T
 */
template <class T> Stack<T>::Stack() { top = nullptr; }
/**
 * Constructor por copia de la clase Stack
 * @tparam T
 * @param li
 */
template <class T> Stack<T>::Stack(const Stack<T> &li) {}

/**
 * Destructor de la clase Lista, se encarga de liberar la memoria de todos los
 * nodos utilizados en la lista
 * @tparam T
 */
template <class T> Stack<T>::~Stack() {
  while (!isEmpty()) {
    pop();
  }
}

/**
 * Inserta un dato en la pila
 * @tparam T
 * @param dato  dato a insertar
 */
template <class T> void Stack<T>::push(T dato) {
  auto aux = new Node<T>(dato, top);
  //  Node<T> *aux = new Node<T>;
  //  aux->setData(dato);
  //  aux->setNext(top);
  top = aux;
}

/**
 * Obtener el dato de la pila
 * @tparam T
 * @return dato almacenado en el nodo
 */
template <class T> T Stack<T>::pop() {
  if (top == nullptr)
    throw 404;

  T data = top->getData();
  Node<T> *toDelete = top;
  top = top->getNext();
  delete toDelete;
  return data;
}

/**
 * Responde si la pila se encuentra Vacía
 * @tparam T
 * @return
 */
template <class T> bool Stack<T>::isEmpty() { return (top == nullptr); }

#endif // U03_PILAS_PILA_STACK_H_
