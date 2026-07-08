#include "net_asio.h"
using asio::ip::tcp;
namespace ip = asio::ip;

asio::io_context io;
tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), 7777));
tcp::socket   s(io);
std::array<char, 1024> buf;

void on_write(const asio::error_code& ec, std::size_t bytes)
{
    if (ec)
    {
        std::cout << "read error: " << ec.message() << '\n';
        return;
    }
    std::cout << "[on_write ]: write " << bytes << "bytes\n";
}


void on_read(const asio::error_code& ec, std::size_t bytes)
{
    if (ec)
    {
        std::cout << "read error: " << ec.message() << '\n';
        return;
    }
    std::cout << "[on_read  ]: read  " << bytes << "bytes\n";
    asio::async_write(s, asio::buffer(buf), on_write);
}

void on_accept(const asio::error_code& ec)
{
    if (ec)
    {
        std::cout << "accept error: " << ec.message() << '\n';
        return;
    }
    std::cout << "client connected\n";
    s.async_read_some(asio::buffer(buf), on_read);
}

int main()
{
    acceptor.async_accept(s, on_accept);
				
    io.run();	
}



