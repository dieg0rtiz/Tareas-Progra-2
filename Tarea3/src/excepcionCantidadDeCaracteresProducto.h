#ifndef ExcepcionCantidadDeCaracteresProducto_H
#define ExcepcionCantidadDeCaracteresProducto_H

#include <exception>

class ExcepcionCantidadDeCaracteresProducto : public std::exception
{
    public:
    ExcepcionCantidadDeCaracteresProducto() noexcept = default;
    ~ExcepcionCantidadDeCaracteresProducto() = default;

    virtual const char* what() const noexcept {
        return "La cantidad de caracteres permitida ha sido excedida. Para el nombre del producto se permiten máximo 20 caracteres";
    }

};

#endif