#include "net_asio.h"
namespace ip = asio::ip;
using asio::ip::tcp;

int main()
{
    asio::io_context io;

    tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), 7777));
    std::cout << "server: listening on 7777\n";

    tcp::socket s(io);

    acceptor.async_accept(s, [&s](const asio::error_code& ec) 
            {
                std::cout << "server: client connected\n";
                
//				std::array<char, 1024> buf;	// lifetime 문제 발생
                auto buf = std::make_shared<std::array<char, 1024>>();

                s.async_read_some(asio::buffer(*buf), [buf, &s](const asio::error_code& ec, std::size_t bytes) 
                    {
                        asio::async_write(s, asio::buffer(buf->data(), bytes), [](const asio::error_code& ec, std::size_t bytes) { });
                    });
            });

    io.run();

}