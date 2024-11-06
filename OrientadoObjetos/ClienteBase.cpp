#include <iostream>
#include <string>
#include <arpa/inet.h>
#include <unistd.h>

class ClienteBase
{
protected:
    int clienteSocket;
    std::string cabecera;

public:
    ClienteBase(const std::string &cabecera) : cabecera(cabecera)
    {
        clienteSocket = socket(AF_INET, SOCK_STREAM, 0);
    }

    virtual ~ClienteBase()
    {
        close(clienteSocket);
    }

    bool conectar(const std::string &ip, int puerto)
    {
        sockaddr_in servidorAddr;
        servidorAddr.sin_family = AF_INET;
        servidorAddr.sin_port = htons(puerto);
        inet_pton(AF_INET, ip.c_str(), &servidorAddr.sin_addr);

        return connect(clienteSocket, (struct sockaddr *)&servidorAddr, sizeof(servidorAddr)) == 0;
    }

    void enviarMensaje(const std::string &mensaje)
    {
        std::string mensajeCompleto = cabecera + ": " + mensaje;
        send(clienteSocket, mensajeCompleto.c_str(), mensajeCompleto.size(), 0);
    }
};
