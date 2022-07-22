#ifndef EXCEPCIONPRODUCTOEXISTENTE_H
#define EXCEPCIONPRODUCTOEXISTENTE_H

#include <string>
#include <exception>

using namespace std;

class ExcepcionProductoExistente : public std::exception
{
    public:
    ExcepcionProductoExistente() noexcept = default;
    ~ExcepcionProductoExistente() = default;

    virtual const char* what() const noexcept {
        string mensajeError {};
        mensajeError = mensajeError + "Ya existe un producto con el ID ingresado.";
        const char* charMensaje = mensajeError.c_str();
        return charMensaje;
    }

};

#endif // EXCEPCIONPRODUCTOEXISTENTE_H

