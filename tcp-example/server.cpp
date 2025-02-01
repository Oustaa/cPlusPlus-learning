#include <iostream>
#include <boost/asio.hpp>
#include <cstring>

using namespace boost::asio;
using ip::tcp;

int main()
{
    try
    {
        io_context io;
        tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), 5000));

        std::cout << "Server is listening on port 5000..." << std::endl;

        while (true)
        {
            tcp::socket socket(io);
            acceptor.accept(socket);
            std::cout << "Client connected!" << std::endl;

            char buffer[1024];

            while (true)
            {
                std::memset(buffer, 0, sizeof(buffer));
                boost::system::error_code error;

                size_t length = socket.read_some(boost::asio::buffer(buffer, sizeof(buffer)), error);

                if (error == boost::asio::error::eof)
                {
                    std::cout << "Client disconnected." << std::endl;
                    break;
                }
                else if (error)
                {
                    throw boost::system::system_error(error);
                }

                std::cout << "Received: " << std::string(buffer, length) << std::endl;
            }
        }
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
