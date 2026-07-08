#include "net_asio.h"
using asio::ip::tcp;
namespace ip = asio::ip;

void on_write(const asio::error_code& ec, std::size_t bytes, tcp::socket& s, std::array<char, 1024>& buf)
{
}


void on_read(const asio::error_code& ec, std::size_t bytes, tcp::socket& s, std::array<char, 1024>& buf)
{
    asio::async_write(s, asio::buffer(buf), std::bind(on_write, _1, _2, std::ref(s), std::ref(buf)));
}

void on_accept(const asio::error_code& ec, tcp::socket& s, std::array<char, 1024>& buf)
{
    s.async_read_some(asio::buffer(buf), std::bind(on_read, _1, _2, std::ref(s), std::ref(buf)));
}

int main()
{
    asio::io_context io;
    tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), 7777));
    tcp::socket   s(io);
    std::array<char, 1024> buf;

    acceptor.async_accept(s, std::bind(on_accept, _1, std::ref(s), std::ref(buf)));

    io.run();	
}
