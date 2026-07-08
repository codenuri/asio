#include "net_asio.h"
using asio::ip::tcp;
namespace ip = asio::ip;

void on_read(const asio::error_code& ec, std::size_t bytes) 
{
}

void on_accept(const asio::error_code& ec)
{
    // socket 변수 s 와 버퍼 buf 를 사용할수 있어야 한다.
    s.async_read_some(asio::buffer(buf), on_read);	// error
}

int main()
{
    asio::io_context io;
    tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), 7777));
    tcp::socket   s(io);
    std::array<char, 1024> buf;

    acceptor.async_accept(s, on_accept);

    io.run();	
}



