#pragma once
#include <stdexcept>  // std::domain_error
#include <utility>    // std::move

template <typename T>
class queue_eda {
protected:
    static const int TAM_INICIAL = 10; // tamaño inicial del array dinámico
    // número de elementos en la pila
    size_t nelems;
    // tamaño del array
    size_t capacidad;
    size_t posInicio;
    // puntero al array que contiene los datos (redimensionable)
    T* array;

public:

    // constructor: pila vacía
    queue_eda() : nelems(0), posInicio(0), capacidad(TAM_INICIAL), array(new T[capacidad]) {}

    // destructor
    ~queue_eda() {
        libera();
    }

    // constructor por copia
    queue_eda(queue_eda<T> const& other) {
        copia(other);
    }

    // operador de asignación
    queue_eda<T>& operator=(queue_eda<T> const& other) {
        if (this != &other) {
            libera();
            copia(other);
        }
        return *this;
    }

    // apilar un elemento
    void push(T const& elem) {
        array[(posInicio + nelems) % capacidad] = elem;
        ++nelems;
        // es mejor ampliar la memoria del array despues de copiar el elemento
        // El motivo es que el elemento puede ser una referencia al propio 
        // array y este se elimina cuando se amplia.
        // Por ejemplo si se hace push(top()), para duplicar el elemento de la cima. top() devuelve una referencia a este elemento. 
        // al propio array.  
        if (nelems + 1 == capacidad)
            amplia();

    }

    // consultar la cima
    T const& front() const {
        if (empty())
            throw std::domain_error("la cola vacia no tiene cima");
        return array[posInicio];
    }

    // desapilar el elemento en la cima
    void pop() {
        if (empty())
            throw std::domain_error("desapilando de la cola vacia");
        posInicio = (posInicio+1)%capacidad;
        --nelems;
    }

    // consultar si la pila está vacía
    bool empty() const {
        return nelems == 0;
    }

    // consultar el tamaño de la pila
    size_t size() const {
        return nelems;
    }

protected:

    void libera() {
        delete[] array;
    }

    // this está sin inicializar
    void copia(queue_eda const& other) {
        capacidad = other.nelems + TAM_INICIAL;
        nelems = other.nelems;
        array = new T[capacidad];
        for (size_t i = 0; i < nelems; ++i)
            array[i] = other.array[i];
    }

    void amplia() {
        T* viejo = array;
        array = new T[capacidad*2];

        size_t posAntigua = posInicio;
        posInicio = 0;

        for (int i = 0; i < nelems; i++) {
            array[i] = std::move(viejo[(posAntigua+i)%capacidad]);
        }   

        capacidad *= 2;
        delete[] viejo;
    }
};