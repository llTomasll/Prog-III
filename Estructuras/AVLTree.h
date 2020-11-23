#ifndef U06_ARBOL_ARBOL_AVLTREE_H_
#define U06_ARBOL_ARBOL_AVLTREE_H_

#include "TreeNode.h"
#include <iostream>
#include <string>

template<class T>
class AVLTree {
private:
    TreeNode<T> *root;

    TreeNode<T> *put(T data, TreeNode<T> *r);

    void print(bool isRight, std::string ident, TreeNode<T> *r);

    T search(T data, TreeNode<T> *r);

    void preorder(TreeNode<T> *r);

    void inorder(TreeNode<T> *r);

    void postorder(TreeNode<T> *r);

    TreeNode<T> *remove(T data, TreeNode<T> *r);

    T findMax(TreeNode<T> *r);

    void clear(TreeNode<T> *r);

    // AVL added
    int height(TreeNode<T> *r);

    TreeNode<T> *findMax(TreeNode<T> *r, bool *found);

    TreeNode<T> *rotateLeft(TreeNode<T> *k2);

    TreeNode<T> *rotateRight(TreeNode<T> *k1);

    TreeNode<T> *doubleRotateLeft(TreeNode<T> *k3);

    TreeNode<T> *doubleRotateRight(TreeNode<T> *k1);

    int max(int a, int b);

public:
    AVLTree();

    void put(T data);

    T search(T data);

    void remove(T data);

    void preorder();

    void inorder();

    void postorder();

    ~AVLTree();

    bool isEmpty();

    void print();
};

/**
 * Constructor del Arbol
 * @tparam K Clave por la cual va a ordenar el árbol
 * @tparam T Valor guardado por el árbol
 */
template<class T>
AVLTree<T>::AVLTree() { root = nullptr; }

/**
 * Destructor del Arbol
 */
template<class T>
AVLTree<T>::~AVLTree() { clear(root); }

template<class T>
void AVLTree<T>::clear(TreeNode<T> *r) {
    if (r == nullptr)
        return;

    clear(r->getLeft());
    clear(r->getRight());
    delete r;
}

/**
 * Busca un dato en el árbol. Si no esta el dato en el árbol
 * tira una excepción
 * @param clave Valor a buscar
 * @return el valor buscado
 */
template<class T>
T AVLTree<T>::search(T data) { return search(data, root); }

template<class T>
T AVLTree<T>::search(T data, TreeNode<T> *r) {
    if (r == nullptr)
        throw 404;

    if (data > r->getData()) {
        return search(data, r->getRight());
    } else if (data < r->getData()) {
        return search(data, r->getLeft());
    } else {
        return r->getData();
    }
}

/**
 * Agrega un dato al árbol
 * @param clave Clave para agregar el dato
 * @param data Dato a agregar
 */
template<class T>
void AVLTree<T>::put(T data) { root = put(data, root); }

template<class T>
TreeNode<T> *AVLTree<T>::put(T data, TreeNode<T> *r) {

    if (r == nullptr)
        return new TreeNode<T>(data);

    if (data > r->getData()) {
        r->setRight(put(data, r->getRight()));
        if (height(r->getRight()) - height(r->getLeft()) == 2) {
            if (data > r->getRight()->getData())
                r = rotateRight(r);
            else
                r = doubleRotateRight(r);
        }
    } else if (data < r->getData()) {
        r->setLeft(put(data, r->getLeft()));
        if (height(r->getLeft()) - height(r->getRight()) == 2) {
            if (data < r->getLeft()->getData())
                r = rotateLeft(r);
            else
                r = doubleRotateLeft(r);
        }
    } else {
        throw 302;
    }

    if (height(r->getLeft()) > height(r->getRight()))
        r->setHeight(height(r->getLeft()) + 1);
    else
        r->setHeight(height(r->getRight()) + 1);

    return r;
}

/**
 * Elimina un dato del árbol
 * @param clave Clave para identificar el nodo a borrar
 */
template<class T>
void AVLTree<T>::remove(T data) {
    root = remove(data, root);
}

template<class T>
TreeNode<T> *AVLTree<T>::remove(T data, TreeNode<T> *r) {
    TreeNode<T> *aux;
    if (r == nullptr)
        throw 404;

    if (data > r->getData()) {
        r->setRight(remove(data, r->getRight()));
    } else if (data < r->getData()) {
        r->setLeft(remove(data, r->getLeft()));
    } else {
        // Remover el nodo
        if (r->getLeft() == nullptr && r->getRight() == nullptr) {
            delete r;
            return nullptr;
        } else if (r->getLeft() != nullptr && r->getRight() == nullptr) {
            aux = r->getLeft();
            delete r;
            return aux;
        } else if (r->getLeft() == nullptr && r->getRight() != nullptr) {
            aux = r->getRight();
            delete r;
            return aux;
        } else {
            T tmp = findMax(r->getLeft());
            r->setLeft(remove(tmp, r->getLeft()));
            r->setData(tmp);
        }
    }

    return r;
}

template<class T>
T AVLTree<T>::findMax(TreeNode<T> *r) {
    TreeNode<T> *aux = r;

    while (r->getRight() != nullptr) {
        r = r->getRight();
    }
    return r->getData();
}

/**
 * Informa si un árbol esta vacío
 * @return
 */
template<class T>
bool AVLTree<T>::isEmpty() { return root == nullptr; }

/**
 * Recorre un árbol en preorden
 */
template<class T>
void AVLTree<T>::preorder() { preorder(root); }

template<class T>
void AVLTree<T>::preorder(TreeNode<T> *r) {
    if (r == nullptr)
        return;

    std::cout << r->getData() << " ";
    preorder(r->getLeft());
    preorder(r->getRight());
}

/**
 * Recorre un árbol en orden
 */
template<class T>
void AVLTree<T>::inorder() { inorder(root); }

template<class T>
void AVLTree<T>::inorder(TreeNode<T> *r) {
    if (r == nullptr)
        return;

    inorder(r->getLeft());
    std::cout << r->getData() << " ";
    inorder(r->getRight());
}

/**
 * Recorre un árbol en postorden
 */
template<class T>
void AVLTree<T>::postorder() {}

template<class T>
void AVLTree<T>::postorder(TreeNode<T> *r) {
    if (r == nullptr)
        return;

    postorder(r->getLeft());
    postorder(r->getRight());
    std::cout << r->getData() << " ";
}

/**
 * Muestra un árbol por consola
 */
template<class T>
void AVLTree<T>::print() { print(true, "", root); }

template<class T>
void AVLTree<T>::print(bool isRight, std::string ident, TreeNode<T> *r) {
    if (isEmpty())
        return;
    if (r->getRight() != nullptr) {
        print(true, ident + (isRight ? "     " : "|    "), r->getRight());
    }
    std::cout << ident;
    if (isRight) {
        std::cout << " /";
    } else {
        std::cout << " \\";
    }
    std::cout << "-- ";
    std::cout << r->getData() << std::endl;
    if (r->getLeft() != NULL) {
        print(false, ident + (isRight ? "|    " : "     "), r->getLeft());
    }
}

// Métodos del AVL

template<class T>
TreeNode<T> *AVLTree<T>::findMax(TreeNode<T> *r, bool *found) {
    TreeNode<T> *ret;
    *found = false;

    if (r->getRight() == nullptr) {
        *found = true;
        return r;
    }

    ret = buscarMax(r->getRight(), found);
    if (*found) {
        r->getRight() = nullptr;
        *found = false;
    }

    return ret;
}

template<class T>
int AVLTree<T>::height(TreeNode<T> *r) {
    if (r == nullptr)
        return -1;
    else
        return r->getHeight();
}

template<class T>
TreeNode<T> *AVLTree<T>::rotateLeft(TreeNode<T> *k2) {
    TreeNode<T> *k1 = k2->getLeft();
    k2->setLeft(k1->getRight());
    k1->setRight(k2);
    k2->setHeight(max(height(k2->getLeft()), height(k2->getRight())) + 1);
    k1->setHeight(max(height(k1->getLeft()), k2->getHeight()) + 1);
    return k1;
}

template<class T>
TreeNode<T> *AVLTree<T>::rotateRight(TreeNode<T> *k1) {
    TreeNode<T> *k2 = k1->getRight();
    k1->setRight(k2->getLeft());
    k2->setLeft(k1);
    k1->setHeight(max(height(k1->getLeft()), height(k1->getRight())) + 1);
    k2->setHeight(max(height(k2->getRight()), k1->getHeight()) + 1);
    return k2;
}

template<class T>
TreeNode<T> *AVLTree<T>::doubleRotateLeft(TreeNode<T> *k3) {
    k3->setLeft(rotateRight(k3->getLeft()));
    return rotateLeft(k3);
}

template<class T>
TreeNode<T> *AVLTree<T>::doubleRotateRight(TreeNode<T> *k1) {
    k1->setRight(rotateLeft(k1->getRight()));
    return rotateRight(k1);
}

template<class T>
int AVLTree<T>::max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

#endif // U06_ARBOL_ARBOL_AVLTREE_H_
