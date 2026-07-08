#include "net_asio.h"
using asio::ip::tcp;
namespace ip = asio::ip;

void on_read(const asio::error_code& ec, std::size_t bytes)
{}

// socket 변수 s 와 버퍼 buf 를 인자로 추가
void on_accept(const asio::error_code& ec, tcp::socket& s, std::array<char, 1024>& buf)
{
    s.async_read_some(asio::buffer(buf), on_read);	
}

int main()
{
    asio::io_context io;
    tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), 7777));
    tcp::socket   s(io);
    std::array<char, 1024> buf;

    acceptor.async_accept(s, std::bind(on_accept, _1, std::ref(s), std::ref(buf)));
    //acceptor.async_accept(s, [&s, &buf](const asio::error_code& ec) { on_accept(ec, s, buf); });

    io.run();
}



