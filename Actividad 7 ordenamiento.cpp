#include <iostream>
#include <string>
const int TAM = 100;

using namespace std;

class Alumnos
{
private:
    string nombre;
    string carrera;
    string prepa;
    int promedio;

public:
    Alumnos() {}
    void operator=(Alumnos &x)
    {
        nombre = x.nombre;
        carrera = x.carrera;
        prepa = x.prepa;
        promedio = x.promedio;
    }

    Alumnos(const string &nombre, const string &carrera, const string &prepa, const int &promedio)
        : nombre(nombre), carrera(carrera), prepa(prepa), promedio(promedio) {}

    bool operator==(const Alumnos &p) const
    {
        return (carrera == p.carrera && nombre == p.nombre && prepa == p.prepa && promedio == p.promedio);
    }

    friend ostream &operator<<(ostream &o, Alumnos &p)
    {
        o << "nombre: " << p.nombre << "\t carrera: " << p.carrera << "\t prepa: " << p.prepa << "\t promedio: " << p.promedio << endl;
        return o;
    }

    friend istream &operator>>(istream &o, Alumnos &p)
    {
        cout << "\n inserta nombre: ";
        o >> p.nombre;
        cout << "\n inserta carrera: ";
        o >> p.carrera;
        cout << "\n inserta la preparatoria de proscedencia: ";
        o >> p.prepa;
        cout << "\n inserta promedio: ";
        o >> p.promedio;
        return o;
    }

    bool operator!=(const Alumnos &p) const
    {
        return !(*this == p);
    }
    bool operator<(const Alumnos &p) const
    {
        return promedio < p.promedio;
    }

    bool operator>(const Alumnos &p) const
    {
        return promedio > p.promedio;
    }
    bool operator<=(const Alumnos &p) const
    {
        return promedio <= p.promedio;
    }

    bool operator>=(const Alumnos &p) const
    {
        return promedio >= p.promedio;
    }
};

class Lista
{
private:
    Alumnos datos[TAM];
    int ult;

public:
    Lista() : ult(-1) {}

    bool vacia() const
    {
        return ult == -1;
    }

    bool llena() const
    {
        return ult == TAM - 1;
    }

    int inserta(Alumnos elem, int pos)
    {
        if (llena() || pos < 0 || pos > ult + 1)
        {
            std::cout << "\n Error de insercion";
            return 0;
        }
        int i = ult + 1;
        while (i > pos)
        {
            datos[i] = datos[i - 1];
            i--;
        }
        datos[pos] = elem;
        ult++;
        return 1;
    }
    void muestra()
    {
        if (vacia())
        {
            cout << "La lista esta vacia." << endl;
            return;
        }
        for (int i = 0; i <= ult; i++)
        {
            cout << datos[i] << endl;
        }
    }

    int ultimo() const
    {
        return ult;
    }

    friend ostream &operator<<(ostream &o, Lista &L)
    {
        int i = 0;
        cout << "\n";
        while (i <= L.ultimo())
        {
            o << L.datos[i];
            i++;
        }
        return o;
    }

    int busquedaBinaria(Alumnos &elem)
    {
        if (vacia())
        {
            cout << "la cola esta vacia" << endl;
            return -1;
        }
        int i = 0;
        int j = ult;

        while (i <= j)
        {
            int mit = (i + j) / 2;

            if (datos[mit] == elem)
            {
                return mit;
            }
            else if (elem > datos[mit])
            {
                j = mit - 1;
            }
            else
            {
                i = mit + 1;
            }
        }

        return -1;
    }

    void intercambiar(Alumnos &a, Alumnos &b)
    {
        Alumnos temp = a;
        a = b;
        b = temp;
    }

    void quicksort(int izq, int der)
    {
        if (izq >= der)
        {
            return;
        }
        intercambiar(datos[(izq + der) / 2], datos[der]);
        int i = izq;
        int j = der;
        while (i < j)
        {
            while (i < j && datos[i] >= datos[der])
            {
                i = i + 1;
            }
            while (i < j && datos[j] <= datos[der])
            {
                j = j - 1;
            }
            if (i != j)
            {
                intercambiar(datos[i], datos[j]);
            }
        }
        if (i != der)
        {
            intercambiar(datos[i], datos[der]);
        }
        quicksort(izq, i - 1);
        quicksort(i + 1, der);
    }
};

int main()
{
    Lista milista;
    Alumnos x;
    int opcion;
    do
    {
        cout << "\nMenu:" << endl;
        cout << "1. Agregar alumno" << endl;
        cout << "2. Buscar un alumno" << endl;
        cout << "3. mostrar todos los alumnos" << endl;
        cout << "4. Salir" << endl;
        cout << "\nElija una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "Ingrese los datos del alumno\n";
            cin >> x;
            milista.inserta(x, milista.ultimo() + 1);
            milista.quicksort(0,milista.ultimo());
            break;
        case 2:
            milista.quicksort(0,milista.ultimo());
            cout << "\nIngrese el alumno a buscar" << endl;
            cin >> x;

            if (milista.busquedaBinaria(x) == -1)
            {
                cout << "\nEse alumno no se encuentra en la lista" << endl;
            }
            else
            {
                milista.quicksort(0, milista.ultimo());
                cout << "\nEl alumno tiene la posicion: " << milista.busquedaBinaria(x) + 1 << endl;
            }
            break;
        case 3:
            milista.quicksort(0, milista.ultimo());
            milista.muestra();
            break;
        case 4:
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    } while (opcion != 4);

    return 0;
}
