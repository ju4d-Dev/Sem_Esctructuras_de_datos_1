#include <iostream>
#include <string.h>

using namespace std;

class Alumnos
{
private:
    string nombre;
    string carrera;
    int promedio;

public:
    int codigo;
    Alumnos() {}
    Alumnos &operator=(const Alumnos &x)
    {
        if (this != &x)
        {
            codigo = x.codigo;
            nombre = x.nombre;
            carrera = x.carrera;
            promedio = x.promedio;
        }
        return *this;
    }

    Alumnos(const string &nombre, const string &carrera, const int &promedio, const int &codigo)
        : nombre(nombre), carrera(carrera), promedio(promedio), codigo(codigo) {}

    bool operator==(const Alumnos *p) const
    {
        return (p != nullptr) &&
               (nombre == p->nombre && codigo == p->codigo && carrera == p->carrera && promedio == p->promedio);
    }
    bool operator==(const Alumnos &p) const
    {
        return (nombre == p.nombre && codigo == p.codigo && carrera == p.carrera && promedio == p.promedio);
    }

    friend istream &operator>>(istream &o, Alumnos &p)
    {
        cout << "\n inserta codigo: ";
        o >> p.codigo;
        cout << "\n inserta nombre: ";
        cin.ignore(); 
        getline(o, p.nombre);
        cout << "\n inserta carrera: ";
        getline(o, p.carrera);
        cout << "\n inserta promedio: ";
        o >> p.promedio;
        return o;
    }

    void imprimir() const
    {
        cout << "codigo: " << codigo << "\t nombre: " << nombre << "\t carrera: " << carrera << "\t Promedio: " << promedio << endl;
    }

    friend ostream &operator<<(ostream &o, Alumnos &p)
    {
        o << "codigo: " << p.codigo << "\t nombre: " << p.nombre << "\t carrera: " << p.carrera << "\t Promedio: " << p.promedio << endl;
        return o;
    }
    bool operator!=(const Alumnos &p) const
    {
        return !(*this == p);
    }

    Alumnos *operator->()
    {
        return this;
    }
};

template <class T>
class LSLSE;

template <class T>
class node
{
private:
    T data;
    node<T> *sig;

public:
    node() : sig(nullptr){};
    friend class LSLSE<T>;
};

template <class T>
class LSLSE
{
private:
    node<T> *lista;

public:
    LSLSE() : lista(nullptr){};
    bool vacia() const;
    node<T> *ultimo() const;
    node<T> *primero() const;
    node<T> *anterior(node<T> *pos) const;
    T eliminar(node<T> *pos);
    void deque();
    void imprimir() const;
    void enque(T elem);
};

template <class T>
void LSLSE<T>::imprimir() const
{
    node<T> *aux = lista;
    while (aux != nullptr)
    {
        cout << aux->data << "";
        aux = aux->sig;
    }
}

template <class T>
T LSLSE<T>::eliminar(node<T> *pos)
{
    T elemEliminado;
    if (vacia() || pos == nullptr)
    {
        return elemEliminado;
    }
    if (pos == lista)
    {
        elemEliminado = lista->data;
        lista = lista->sig;
    }
    else
    {
        elemEliminado = pos->data;
        anterior(pos)->sig = pos->sig;
    }
    delete pos;
    return elemEliminado;
}

template <class T>
void LSLSE<T>::deque()
{
    if (!vacia())
    {
        T elemEliminado = eliminar(primero());
        cout << "\nConstancia del alumno:" << endl;
        elemEliminado.imprimir();
    }
    else
    {
        cout << "\nLa lista esta vacia" << endl;
    }
}

template <class T>
void LSLSE<T>::enque(T elem)
{
    node<T> *aux = lista;
    while (aux != nullptr)
    {
        if (aux->data.codigo == elem.codigo)
        {
            cout << "\n Codigo de alumno en uso" << endl;
            return;
        }
        aux = aux->sig;
    }

    aux = new node<T>;
    aux->data = elem;

    if (ultimo() == nullptr)
    {
        aux->sig = lista;
        lista = aux;
    }
    else
    {
        aux->sig = ultimo()->sig;
        ultimo()->sig = aux;
    }
}

template <class T>
node<T> *LSLSE<T>::anterior(node<T> *pos) const
{
    if (vacia() || pos == nullptr)
    {
        return nullptr;
    }
    node<T> *aux = lista;
    while (aux != nullptr && aux->sig != pos)
    {
        aux = aux->sig;
    }
    return aux;
}

template <class T>
node<T> *LSLSE<T>::primero() const
{
    if (vacia())
    {
        return nullptr;
    }
    return lista;
}

template <class T>
node<T> *LSLSE<T>::ultimo() const
{
    if (vacia())
    {
        return nullptr;
    }
    node<T> *aux = lista;
    while (aux->sig != nullptr)
    {
        aux = aux->sig;
    }
    return aux;
}

template <class T>
bool LSLSE<T>::vacia() const
{
    if (lista == nullptr)
        return true;
    return false;
}

int main()
{
    LSLSE<Alumnos> milista;
    Alumnos x;
    int opcion;
    do
    {
        cout << "\nMenu:" << endl;
        cout << "1. Agregar un alumno" << endl;
        cout << "2. Generar constancia" << endl;
        cout << "3. Salir" << endl;

        cout << "\nElija una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "Ingrese los datos del alumno" << endl;
            cin >> x;
            milista.enque(x);
            break;
        case 2:
            milista.deque();
            break;
        case 3:
            cout << "Saliendo del programa" << endl;
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    } while (opcion != 3);

    return 0;
}
