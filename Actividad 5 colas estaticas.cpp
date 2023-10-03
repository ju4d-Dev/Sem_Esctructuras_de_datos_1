#include <iostream>
#include <string>
const int TAM = 100;

using namespace std;
class Alumnos
{
private:
    string nombre;
    string carrera;
    int materias;
    int promedio;

public:
    Alumnos() {}
    void operator=(Alumnos &x)
    {
        nombre = x.nombre;
        carrera = x.carrera;
        materias = x.materias;
        promedio = x.promedio;
    }

    Alumnos(const string &nombre, const string &carrera, const int &materias, const int &promedio)
        : nombre(nombre), carrera(carrera), materias(materias), promedio(promedio) {}

    bool operator==(const Alumnos &p) const
    {
        return (carrera == p.carrera && nombre == p.nombre && materias == p.materias && promedio == p.promedio);
    }

    friend ostream &operator<<(ostream &o, Alumnos &p)
    {
        o << "nombre: " << p.nombre << "\t carrera: " << p.carrera << "\t materias: " << p.materias << "\t promedio: " << p.promedio << endl;
        return o;
    }

    friend istream &operator>>(istream &o, Alumnos &p)
    {
        cout << "\n inserta nombre: ";
        o >> p.nombre;
        cout << "\n inserta carrera: ";
        cin.ignore();
        o >> p.carrera;
        cout << "\n inserta las materias aprobadas: ";
        cin.ignore();
        o >> p.materias;
        cout << "\n inserta promedio: ";
        cin.ignore();
        o >> p.promedio;
        return o;
    }

    bool operator!=(const Alumnos &p) const
    {
        return !(*this == p);
    }

    bool operator<(const Alumnos &p) const
    {
        return carrera < p.carrera;
    }

    bool operator>(const Alumnos &p) const
    {
        return carrera > p.carrera;
    }
};

class Cola
{
private:
    Alumnos datos[TAM];
    int ult;

    bool elimina(int pos)
    {
        if (vacia() || pos < 0 || pos > ult)
        {
            cout << "\n error de eliminacion";
            return true;
        }
        int i = pos;
        while (i < ult)
        {
            datos[i] = datos[i + 1];
            i++;
        }
        ult--;
        return false;
    }

    int inserta(Alumnos &elem, int pos)
    {
        if (llena() || pos < 0 || pos > ult + 1)
        {
            cout << "\n Error de insercion";
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

public:
    Cola() : ult(-1) {}

    bool vacia() const
    {
        if (ult == -1)
            return true;
        return false;
    }

    bool llena() const
    {
        if (ult == TAM - 1)
            return true;
        return false;
    }

    int ultimo() const
    {
        return ult;
    }

    friend ostream &operator<<(ostream &o, Cola &L);

    void enqueue(Alumnos &elem)
    {
        inserta(elem, 0);
    }

    Alumnos &dequeue()
    {
        if (vacia())
        {
            cout << "\n La cola esta vacia" << endl;
            static Alumnos empty;
            return empty;
        }
        else
        {
            ult--;
            return datos[ult + 1];
        }
    }
};

int main()
{
    Cola miCola;
    Alumnos x;
    int opcion;
    do
    {
        cout << "\nMenu:" << endl;
        cout << "1. Agregar alumno (encolar)" << endl;
        cout << "2. Contancia de alumno (desencolar)" << endl;
        cout << "3. Salir" << endl;
        cout << "\nElija una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "ingrese los datos del alumno\n";
            cin >> x;
            miCola.enqueue(x);
            break;
        case 2:
            cout << miCola.dequeue();
            break;
        case 3:
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    } while (opcion != 3);

    return 0;
}