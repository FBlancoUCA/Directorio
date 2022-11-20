#include <iostream>
#include <string>
#include <string.h>
#include <cstdlib>
using namespace std;

struct Nodo
{
    string nombre;
    int edad;
    int telefono;
    Nodo *siguiente;
};

Nodo *lista = NULL;

void Insertar(string name, int age, int num);
void imprimir();
void eliminar(Nodo *&lista, string a, int b, int c);

void busqueda(string nombre);

bool validacion(string nombre);

bool validacionVacia(string nombre);

int main()
{

    string nombre, aux;

    int edad, opt, telefono;
    bool flag = false;

    double numero;

    do
    {
        cout << "____________________________________" << endl;
        cout << "1. Insertar nuevo dato" << endl;
        cout << "2. Mostrar datos de la lista" << endl;
        cout << "3. Eliminar un dato en especifico" << endl;
        cout << "4. Buscar Elemento por nombre" << endl;
        cout << "5. salir" << endl;
        cout << "_____________________________________" << endl;
        cout << "Ingrese el numero que desea realizar: " << endl;
        cin >> opt;

        switch (opt)
        {
        case 1:
            getline(cin, aux);
            cout << "Ingresar nombre: " << endl;
            getline(cin, nombre);
            while ((!validacion(nombre))||(!validacionVacia(nombre)))
            {
                cout << "No has ingresado nada o has puesto un caracter invalido,pon el nombre" << endl;
                getline(cin, nombre);
            }

            cout << "Ingrese edad: " << endl;
            cin >> edad;

            cout << "\ttienes que poner el guion (-)*\n";

            cout << "Ingresar el numero telefonico: " << endl;
            cin >> telefono;

            Insertar(nombre, edad, telefono);
            break;

        case 2:
            imprimir();
            break;

        case 3:
            getline(cin, aux);
            cout << "Ingresar nombre de la lista que desea eliminar: " << endl;
            getline(cin, nombre);
            eliminar(lista, nombre, edad, telefono);
            break;

        case 4:
            cout << "\tSolo se puede ingresar palabras*\n";

            getline(cin, aux);
            cout << "Ingresar nombre: " << endl;
            getline(cin, nombre);

            // con un while evalua la funcion booleana en el que si es diferente 
            while (!validacion(nombre)||(!validacionVacia(nombre)))
            {
                // imprima este mensaje
              cout << "No has ingresado nada o has puesto un caracter invalido,pon el nombre" << endl;
                getline(cin, nombre);
            }
            busqueda(nombre);
            break;

        case 5:
            flag = true;
            break;

        default:
            cout << "El numero ingresado no es valido, Intentar nuevamente" << endl;
            break;
        }

    } while (flag == false);
    return 0;
}

void Insertar(string name, int age, int num)
{
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->nombre = name;
    nuevoNodo->edad = age;
    nuevoNodo->telefono = num;
    nuevoNodo->siguiente = NULL;

    if (lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        Nodo *p = lista;
        Nodo *q = NULL;
        while (p != NULL)
        {
            q = p;
            p = p->siguiente;
        }
        q->siguiente = nuevoNodo;
    }
}

void imprimir()
{
    Nodo *aux = lista;
    while (aux != NULL)
    {
        cout << "_______________________________" << endl;
        cout << "Nombre: " << aux->nombre << endl;
        cout << "Edad: " << aux->edad << endl;
        cout << "Telefono: " << aux->telefono << endl;
        cout << "_______________________________" << endl;
        aux = aux->siguiente;
    }
}

void eliminar(Nodo *&lista, string a, int b, int c)
{
    if (lista != NULL)
    {
        Nodo *aux_borrar;
        Nodo *anterior = NULL;

        aux_borrar = lista;

        while ((aux_borrar != NULL) && (aux_borrar->nombre != a) && (aux_borrar->edad != b) && (aux_borrar->telefono != c))
        {
            anterior = aux_borrar;
            aux_borrar = aux_borrar->siguiente;
        }

        if (aux_borrar == NULL)
        {
            cout << "Elemento no encontrado" << endl;
        }
        else if (anterior == NULL)
        {
            lista = lista->siguiente;
            delete aux_borrar;
        }
        else
        {
            anterior->siguiente = aux_borrar->siguiente;
        }
    }
}
void busqueda(string nombre)
{

    // crear un valor boleaano que inicializae con falso
    bool found = false, status = true;
    // crear el nodo auxiliar
    Nodo *aux = lista;

    string nameMayus = nombre, nameMinus = nombre;
    // convertir a minusculas el nombre a buscar
    for (int i = 0; i < nombre.length(); i++)
    {
        // se hace el cambio a minusculas
        nameMinus[i] = tolower(nombre[i]);
    }

    while (aux != NULL)
    {
        // convertir a minusculas el nombre almacenado
        for (int i = 0; i < aux->nombre.length(); i++)
        {
            aux->nombre[i] = tolower(aux->nombre[i]);
        }

        // se hace un recorrido en donde se accede
        for (int i = 0; i < nombre.length(); i++)
        {

            // si el nombre que se busca es igual al nombre que se inserta
            if (nameMinus[i] == aux->nombre[i])
            { // es verdadera
                status = true;
            }
            else
            {

                // es falsa
                status = false;
            }
        }

        // si es verdadera entonce se muestra la informacion
        if (status)
        {
            cout << "----------------------------------" << endl;
            cout << "Nombre: " << aux->nombre << endl;
            cout << "Edad: " << aux->edad << endl;
            cout << "Telefono: " << aux->telefono << endl;
            cout << "----------------------------------" << endl;
            found = true;
        }
        aux = aux->siguiente;
    }

    if (found == false)
    {
        cout << "No se ha encontrado" << endl;
    }
}

bool validacion(string nombre)
{

    // se inicia el valor booleano valida en true;
    bool validar = true;

    // se crea un varialble tipo entero la cual es el tamaño de la variable nombre
    int tam = nombre.length();
    // se hace el recorrido del tamaño de la variable nombre
    for (int i = 0; i < tam; i++)
    {
        // se crea una condicional a partir de la tabla ASCII
        if ((nombre[i] < 97 || nombre[i] > 122) && (nombre[i] < 65 || nombre[i] > 90) && (nombre[i] > 32 || nombre[i] < 32))
        {
            // si el nombre ha ingresar no esta entre los numeros de 97 y 122 entonces retorna en falso
            validar = false;
        }
    }
    // si no se cumple lo anterior se retorna true
    return validar;
}

bool validacionVacia(string nombre)
{
    bool validacion = true;

    if ((nombre.length()) == 0)
    {

        validacion = false;
    }
    return validacion;
}