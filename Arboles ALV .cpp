#include <iostream>
using namespace std;

template <typename T>
class Nodo
{
public:
    T elem;
    Nodo *izq;
    Nodo *der;
    int altura;

    Nodo(T elemento) : elem(elemento), izq(nullptr), der(nullptr), altura(1) {}
};

template <typename T>
class arbolALV
{
private:
    Nodo<T> *raiz;

    T menor(Nodo<T> *arbol) const
    {
        if (arbol == nullptr)
        {
            throw runtime_error("Arbol vacio");
        }

        if (arbol->izq != nullptr)
        {
            return menor(arbol->izq);
        }

        return arbol->elem;
    }

    T mayor(Nodo<T> *arbol) const
    {
        if (arbol == nullptr)
        {
            throw runtime_error("Arbol vacio");
        }

        if (arbol->der != nullptr)
        {
            return mayor(arbol->der);
        }

        return arbol->elem;
    }

    void anula(Nodo<T> *&arbol)
    {
        if (arbol != nullptr)
        {
            anula(arbol->izq);
            anula(arbol->der);
            delete arbol;
            arbol = nullptr;
        }
    }

    int altura(Nodo<T> *arbol) const
    {
        if (arbol == nullptr)
        {
            return 0;
        }

        int alt_izq = altura(arbol->izq);
        int alt_der = altura(arbol->der);

        if (alt_izq > alt_der)
        {
            return alt_izq + 1;
        }
        else
        {
            return alt_der + 1;
        }
    }

    void inicializa(Nodo<T> *&arbol)
    {
        arbol = nullptr;
    }

    bool vacio(Nodo<T> *arbol) const
    {
        return arbol == nullptr;
    }

    void inserta(T elem, Nodo<T> *&arbol)
    {
        if (arbol == nullptr)
        {
            Nodo<T> *aux = new Nodo<T>(elem);
            arbol = aux;
        }
        else if (elem < arbol->elem)
        {
            inserta(elem, arbol->izq);
        }
        else
        {
            inserta(elem, arbol->der);
        }

        balanceo(arbol);
    }

    T recupera(Nodo<T> *arbol, T pos) const
    {
        if (arbol == nullptr)
        {
            throw runtime_error("Posicion no valida");
        }

        if (pos == arbol->elem)
        {
            return arbol->elem;
        }
        else if (pos < arbol->elem)
        {
            return recupera(arbol->izq, pos);
        }
        else
        {
            return recupera(arbol->der, pos);
        }
    }

    bool es_hoja(Nodo<T> *arbol) const
    {
        return (arbol != nullptr) && (arbol->izq == nullptr) && (arbol->der == nullptr);
    }

    void elimina(T elem, Nodo<T> *&arbol)
    {
        if (arbol == nullptr)
        {
            throw runtime_error("Elemento no encontrado");
        }

        if (elem < arbol->elem)
        {
            elimina(elem, arbol->izq);
        }
        else if (elem > arbol->elem)
        {
            elimina(elem, arbol->der);
        }
        else
        {
            if (es_hoja(arbol))
            {
                delete arbol;
                arbol = nullptr;
            }
            else if (arbol->izq != nullptr && arbol->der == nullptr)
            {
                Nodo<T> *temp = arbol;
                arbol = arbol->izq;
                delete temp;
            }
            else if (arbol->izq == nullptr && arbol->der != nullptr)
            {
                Nodo<T> *temp = arbol;
                arbol = arbol->der;
                delete temp;
            }
            else
            {
                T mayorIzq = mayor(arbol->izq);
                arbol->elem = mayorIzq;
                elimina(mayorIzq, arbol->izq);
            }
        }

        if (arbol != nullptr)
        {
            balanceo(arbol);
        }
    }

    void recorrido_inorder(Nodo<T> *arbol) const
    {
        if (arbol != nullptr)
        {
            recorrido_inorder(arbol->izq);
            cout << arbol->elem << " ";
            recorrido_inorder(arbol->der);
        }
    }

    void recorrido_postorder(Nodo<T> *arbol) const
    {
        if (arbol != nullptr)
        {
            recorrido_postorder(arbol->izq);
            recorrido_postorder(arbol->der);
            cout << arbol->elem << " ";
        }
    }

    void recorrido_preorder(Nodo<T> *arbol) const
    {
        if (arbol != nullptr)
        {
            cout << arbol->elem << " ";
            recorrido_preorder(arbol->izq);
            recorrido_preorder(arbol->der);
        }
    }

    Nodo<T> *localiza(T elem, Nodo<T> *arbol) const
    {
        if (arbol == nullptr)
        {
            return nullptr;
        }

        if (elem == arbol->elem)
        {
            return arbol;
        }
        else if (elem < arbol->elem)
        {
            return localiza(elem, arbol->izq);
        }
        else
        {
            return localiza(elem, arbol->der);
        }
    }

    int fact_eq(Nodo<T> *arbol) const
    {
        if (arbol == nullptr)
        {
            return 0;
        }

        int alt_izq = altura(arbol->izq);
        int alt_der = altura(arbol->der);

        return alt_der - alt_izq;
    }

    void balanceo(Nodo<T> *&arbol)
    {
        if (arbol == nullptr)
        {
            return;
        }

        int factorEquilibrio = fact_eq(arbol);

        if (factorEquilibrio < -1)
        {
            if (fact_eq(arbol->izq) == -1)
            {
                rot_sim_der(arbol);
            }
            else
            {
                rot_dob_der(arbol);
            }
        }
        
        else if (factorEquilibrio > 1)
        {
            if (fact_eq(arbol->der) == 1)
            {
                rot_sim_izq(arbol);
            }
            else
            {
                rot_dob_izq(arbol);
            }
        }
        else
        {
            return;
        }

        arbol->altura = max(altura(arbol->izq), altura(arbol->der)) + 1;
    }

    void rot_sim_der(Nodo<T> *&arbol)
    {
        Nodo<T> *aux1 = arbol->izq;
        Nodo<T> *aux2 = aux1->der;

        aux1->der = arbol;
        arbol->izq = aux2;

        arbol->altura = max(altura(arbol->izq), altura(arbol->der)) + 1;
        aux1->altura = max(altura(aux1->izq), altura(aux1->der)) + 1;

        arbol = aux1;
    }

    void rot_sim_izq(Nodo<T> *&arbol)
    {
        Nodo<T> *aux1 = arbol->der;
        Nodo<T> *aux2 = aux1->izq;

        aux1->izq = arbol;
        arbol->der = aux2;

        arbol->altura = max(altura(arbol->izq), altura(arbol->der)) + 1;
        aux1->altura = max(altura(aux1->izq), altura(aux1->der)) + 1;

        arbol = aux1;
    }

    void rot_dob_der(Nodo<T> *&arbol)
    {
        Nodo<T> *nodoAux = arbol->izq;
        arbol->izq = nodoAux->der;
        nodoAux->der = arbol;

        arbol->altura = max(altura(arbol->izq), altura(arbol->der)) + 1;
        nodoAux->altura = max(altura(nodoAux->izq), altura(nodoAux->der)) + 1;

        arbol = nodoAux;
    }

    void rot_dob_izq(Nodo<T> *&arbol)
    {
        Nodo<T> *nodoAux = arbol->der;
        arbol->der = nodoAux->izq;
        nodoAux->izq = arbol;

        arbol->altura = max(altura(arbol->izq), altura(arbol->der)) + 1;
        nodoAux->altura = max(altura(nodoAux->izq), altura(nodoAux->der)) + 1;

        arbol = nodoAux;
    }

public:
    arbolALV() : raiz(nullptr) {}

    void hijo_Izquierdo(T elem) const
    {
        Nodo<T> *nodoBuscado = localiza(elem, raiz);

        if (nodoBuscado != nullptr)
        {
            if (nodoBuscado->izq != nullptr)
            {
                cout << "El hijo izquierdo de " << elem << " es: " << menor(nodoBuscado->izq) << endl;
            }
            else
            {
                cout << "El nodo con valor " << elem << " no tiene hijo izquierdo." << endl;
            }
        }
        else
        {
            cout << "El nodo con valor " << elem << " no se encuentra en el arbol." << endl;
        }
    }

    void hijo_Derecho(T elem)
    {
        Nodo<T> *nodoBuscado = localiza(elem, raiz);

        if (nodoBuscado != nullptr)
        {
            if (nodoBuscado->der != nullptr)
            {
                cout << "El hijo derecho de " << elem << " es: " << mayor(nodoBuscado->der) << endl;
            }
            else
            {
                cout << "El nodo con valor " << elem << " no tiene hijo derecho." << endl;
            }
        }
        else
        {
            cout << "El nodo con valor " << elem << " no se encuentra en el arbol." << endl;
        }
    }

    void inicializa()
    {
        inicializa(raiz);
    }

    bool vacio() const
    {
        return vacio(raiz);
    }

    void anula()
    {
        anula(raiz);
    }

    void inserta(T elem)
    {
        inserta(elem, raiz);
    }

    void balancear()
    {
        balanceo(raiz);
    }

    void recorrido_preorder() const
    {
        recorrido_preorder(raiz);
    }

    void recorrido_inorder() const
    {
        recorrido_inorder(raiz);
    }

    void recorrido_postorder() const
    {
        recorrido_postorder(raiz);
    }
    T menor() const
    {
        if (raiz == nullptr)
        {
            throw runtime_error("Arbol vacio");
        }
        return menor(raiz);
    }

    T mayor() const
    {
        if (raiz == nullptr)
        {
            throw runtime_error("Arbol vacio");
        }
        return mayor(raiz);
    }

    T recupera(T pos) const
    {
        return recupera(raiz, pos);
    }

    bool es_hoja() const
    {
        return es_hoja(raiz);
    }

    Nodo<T> *localiza(T elem) const
    {
        return localiza(elem, raiz);
    }

    void elimina(T elem)
    {
        elimina(elem, raiz);
    }
};

int main()
{
    arbolALV<int> miArbol;
    miArbol.inicializa();
    miArbol.inserta(7);
    miArbol.inserta(25);
    miArbol.inserta(18);
    miArbol.inserta(3);
    miArbol.inserta(15);
    miArbol.inserta(9);
    miArbol.inserta(21);
    miArbol.inserta(30);
    miArbol.inserta(14);
    miArbol.inserta(27);
    miArbol.inserta(5);
    miArbol.inserta(20);
    miArbol.inserta(8);
    miArbol.inserta(22);
    miArbol.inserta(11);

    cout << "Recorrido Preorder: ";
    miArbol.recorrido_preorder();
    cout << endl;

    cout << "Recorrido Inorder: ";
    miArbol.recorrido_inorder();
    cout << endl;

    cout << "Recorrido Postorder: ";
    miArbol.recorrido_postorder();
    cout << endl;

    cout << "Minimo: " << miArbol.menor() << endl;
    cout << "Maximo: " << miArbol.mayor() << endl;

    cout << "Arbol vacio? " << (miArbol.vacio() ? "Si" : "No") << endl;

    miArbol.hijo_Izquierdo(21);

    miArbol.hijo_Derecho(21);

    miArbol.elimina(25);

    cout << "Recorrido Inorder despues de eliminar: ";
    miArbol.recorrido_inorder();
    cout << endl;
    cout << "Borrar el arbol";
    miArbol.anula();
    cout << "Recorrido Inorder despues de anular: ";
    miArbol.recorrido_inorder();

    return 0;
}
