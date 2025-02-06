#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#include <iostream>
#include <vector>
#include <thread>
#include <cstring>
#include <mutex>

#define PORT 8080

std::vector<int> sockets;
std::mutex sockets_mutex;

// Function to handle each client
void handle_client(int client_socket)
{
    char buffer[1024];
    while (true)
    {
        memset(buffer, 0, sizeof(buffer));
        int bytes_received = read(client_socket, buffer, 1024);
        if (bytes_received <= 0)
        {
            std::cout << "Client disconnected\n";
            close(client_socket);
            return;
        }
        std::cout << "Message from client: " << buffer << std::endl;
    }
}

int main()
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Create server socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0)
    {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // Bind socket to address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if (listen(server_fd, 10) < 0) // Increased backlog to allow more clients
    {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    std::cout << "Server is listening on port " << PORT << std::endl;

    while (true)
    {
        // Accept a new client connection
        new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
        if (new_socket < 0)
        {
            perror("Accept failed");
            continue; // Continue accepting other clients
        }

        // Add new socket to list (thread-safe)
        {
            std::lock_guard<std::mutex> lock(sockets_mutex);
            sockets.push_back(new_socket);
        }

        std::cout << "New client connected\n";

        // Create a new thread to handle the client
        std::thread client_thread(handle_client, new_socket);
        client_thread.detach(); // Detach the thread to run independently
    }

    // Close the server socket (not reachable in infinite loop)
    close(server_fd);
    return 0;
}
