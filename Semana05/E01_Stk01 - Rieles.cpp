#include <iostream>
using namespace std;

//Clase Padre: Pila
template<typename E> class Pila{
public:
    Pila(){}
    ~Pila(){}
    virtual void limpiar() = 0;
    virtual void push(E var) = 0;
    virtual E pop() = 0;
    virtual E valorTop() = 0;
    virtual int longitud() = 0;
};

//Clase hija: Pila Arreglo: Arreglo Pila (APila)
template<typename E> class APila : public Pila<E>{
private:
    E *arregloLista;
    int tamMaximo;
    int cima; //top
public:
    APila(int tam = 100){
        this->tamMaximo = tam;
        this->cima = 0;
        this->arregloLista = new E[this->tamMaximo];
    }

    ~APila(){
        delete[] this->arregloLista;
    }

    //En tiempo O(1): borrado logico
    void limpiar() {
        this->cima = 0;
    }

    //En tiempo O(1)
    void push(E elemento) {
        this->arregloLista[this->cima++] = elemento;
    }

    //En tiempo O(1): retorna el valor top y SI lo borra de la pila
    E pop() {
        return this->arregloLista[--this->cima];
    }

    //En tiempo O(1): retorna el valor top pero NO lo borra de la pila
    E valorTop() {
        return this->arregloLista[this->cima-1];
    }

    //En tiempo O(1)
    int longitud() {
        return this->cima;
    }

    bool isEmpty() {
        if(this->cima == 0) return true;
        return false;
    }
};


void ejercicioRieles() {
    APila<int> *pila = new APila<int>();
    int N, i, coche, k;
    
    while (true) {
        cin>>N;
        if (!N) {
            break;
        }

        while (true) {

            while (!pila->isEmpty()) {
                pila->pop();
            }

            for (k = i = 0; i < N; i++) {

                cin>>coche;

                if (!coche) {
                    break;
                }

                while (k < N && k != coche) {
                    if (pila->longitud() > 0 && pila->valorTop() == coche) {
                        break;
                    }

                    pila->push(++k);
                }

                if (pila->valorTop() == coche) {
                    pila->pop();
                }

            }

            if (!coche) {
                break;
            }

            if (!pila->longitud()) {
                cout<<"SI"<<endl;
            } else {
                cout<<"NO"<<endl;
            }
        }

    }
    delete pila;
}


int main() {
    ejercicioRieles();
    return 0;
}