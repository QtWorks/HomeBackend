#include "tcpserverhandlerfactory.h"

using Poco::Net::StreamSocket;
TCPServerHandlerFactory::TCPServerHandlerFactory(const Poco::Net::StreamSocket& s):
    TCPServerConnection(s)
{

}

void TCPServerHandlerFactory::run() {
    std::cout << "New connection from: " << socket().peerAddress().host().toString() <<  std::endl << std::flush;
    bool isOpen = true;
    Poco::Timespan timeOut(10,0);
    unsigned char incommingBuffer[1000];
    while(isOpen){
        if (socket().poll(timeOut,Poco::Net::Socket::SELECT_READ) == false){
            std::cout << "TIMEOUT!" << std::endl << std::flush;
        }
        else{
            std::cout << "RX EVENT!!! ---> "   << std::flush;
            int nBytes = -1;

            try {
                nBytes = socket().receiveBytes(incommingBuffer, sizeof(incommingBuffer));
            }
            catch (Poco::Exception& exc) {
                //Handle your network errors.
                std::cerr << "Network error: " << exc.displayText() << std::endl;
                isOpen = false;
            }


            if (nBytes==0){
                std::cout << "Client closes connection!" << std::endl << std::flush;
                isOpen = false;
            }
            else{
                std::cout << "Receiving nBytes: " << nBytes << std::endl << std::flush;
            }
        }
    }
    std::cout << "Connection finished!" << std::endl << std::flush;
}
