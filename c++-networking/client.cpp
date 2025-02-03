#include <iostream>
#include <boost/asio.hpp>

using namespace boost::asio;
using ip::tcp;

int main()
{
    try
    {
        io_context io;
        tcp::socket socket(io);
        socket.connect(tcp::endpoint(ip::address::from_string("127.0.0.1"), 5000));

        std::cout << "Connected to the server!" << std::endl;

        while (true)
        {
            std::cout << "Enter message: ";
            std::string message;
            std::getline(std::cin, message);

            if (message == "exit")
            {
                std::cout << "Closing connection..." << std::endl;
                break;
            }

            boost::system::error_code error;
            write(socket, buffer(message), error);

            if (error)
            {
                throw boost::system::system_error(error);
            }
        }
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
