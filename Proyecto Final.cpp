#include <iostream>
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

int main()
{ 
    string nombre, aux;
    int edad, opt, telefono;
    bool flag = false;

    do
    {
        cout<<"_____________________________________________"<<endl;
        cout<<"1. Insertar nuevo dato"<<endl;
        cout<<"2. Mostrar datos de la lista"<<endl;
        cout<<"3. Eliminar un dato en especifico"<<endl;
        cout<<"4. salir"<<endl;
        cout<<"_____________________________________________"<<endl;
        cout<<"Ingrese el numero que desea realizar: "<<endl;
        cin>>opt;

        switch (opt)
        {
        case 1:
            getline(cin, aux);
            cout<<"Ingresar nombre: "<<endl;
            getline(cin, nombre);
            cout<<"Ingrese edad: "<<endl;
            cin>>edad;
            getline(cin, aux);
            cout<<"Ingresar el numero telefonico: "<<endl;
            cin>> telefono;
            Insertar(nombre, edad, telefono);
            break;

        case 2:
            imprimir();
            break;

        case 3:
            getline(cin, aux);
            cout<<"Ingresar nombre de la lista que desea eliminar: "<<endl;
            getline(cin, nombre);
            eliminar(lista, nombre, edad, telefono);
            break;
        
        case 4:
            flag = true;
            break;

            default:
            cout<<"El numero ingresado no es valido, Intentar nuevamente"<<endl;
            break;
        }
        
    }while(flag == false);
    return 0;
}

void Insertar (string name, int age, int num)
{
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->nombre = name;
    nuevoNodo->edad = age;
    nuevoNodo->telefono = num;
    nuevoNodo->siguiente = NULL;

    if(lista == NULL){
        lista = nuevoNodo;
    } else{
        Nodo *p = lista;
        Nodo *q = NULL;
        while(p != NULL){
            q = p;
            p = p->siguiente;
        }
        q->siguiente = nuevoNodo;
    }
}

void imprimir()
{
    Nodo *aux = lista;
    while(aux != NULL){
        cout<<"----------------------------------"<<endl;
        cout<<"Nombre: "<<aux->nombre<<endl;
        cout<<"Edad: "<<aux->edad<<endl;
        cout<<"Telefono: "<<aux->telefono<<endl;
        cout<<"----------------------------------"<<endl;
        aux = aux->siguiente;
        
    }
}

void eliminar(Nodo *&lista, string a, int b, int c){
    if (lista != NULL){
        Nodo *aux_borrar;
        Nodo *anterior = NULL;

        aux_borrar = lista;

        while((aux_borrar != NULL)&&(aux_borrar->nombre != a)&&(aux_borrar->edad != b)&&(aux_borrar->telefono !=c)){
            anterior = aux_borrar;
            aux_borrar = aux_borrar->siguiente;
        }

        if (aux_borrar == NULL){
            cout<<"*Elemento no encontrado*"<<endl;
        }else if(anterior == NULL){
            lista = lista->siguiente;
            delete aux_borrar;
        }else{
            anterior->siguiente = aux_borrar->siguiente;
        }
    }
}

//---------------------Buscador sin funcionamiento----------------------

/*void buscar(){
    int num, i;
    if(pilao==NULL){
        cout<<"La pila esta vacia"<<endl;
        return;
    }
    int buscardatos;
    bool encontrado=false;
    pilaaux=pilao;
    cout<<"Ingrese dato a buscar"<<endl;
    cin>>buscardatos;

    num=buscardatos;
    cout<<num<<endl;

    while(pilaaux!=NULL){

        if(buscardatos==pilaaux->valor){
            cout<<"Encontrador, el valor es; "<<pilaaux->valor<<endl;
            encontrado=true;
        if(num%num==0) //extraer los datos divisibles por el valor ingresado
        {
        for(i=0; i<num; i++)
        {

        pilaaux=new(pilas);
        pilaaux=pilao;
        cout<<"Elemento eliminado "<<pilaaux->valor<<endl;
        pilao=pilaaux->direccionA;
        delete(pilaaux);
        }
        }
        else
        {
        cout<<"No hay numeeros divisibles"<<endl;
        }
            break;
        }
        pilaaux=pilaaux->direccionA;

    if(encontrado==false){
    cout<<"No se encontro el valor"<<endl;
    }
}*/

