#include <iostream>
#include <boost/asio.hpp>

using namespace boost::asio;
using ip::tcp;

std::string create_http_response(const std::string &content)
{
    return "HTTP/1.1 200 OK\r\n"
           "Content-Type: text/plain\r\n"
           "Content-Length: " +
           std::to_string(content.size()) + "\r\n"
                                            "Connection: close\r\n"
                                            "\r\n" +
           content;
}

int main()
{
    try
    {
        io_context io;
        tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), 8080));

        std::cout << "HTTP Server is running on port 8080..." << std::endl;

        while (true)
        {
            tcp::socket socket(io);
            acceptor.accept(socket);
            std::cout << "Client connected!" << std::endl;

            char buffer[1024];
            boost::system::error_code error;
            size_t length = socket.read_some(boost::asio::buffer(buffer), error);

            if (error && error != boost::asio::error::eof)
            {
                throw boost::system::system_error(error);
            }

            std::string request(buffer, length);
            std::cout << "Received request:\n"
                      << request << std::endl;

            std::string response = create_http_response("Hello, World!");
            boost::asio::write(socket, boost::asio::buffer(response));

            std::cout << "Response sent.\n"
                      << std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
