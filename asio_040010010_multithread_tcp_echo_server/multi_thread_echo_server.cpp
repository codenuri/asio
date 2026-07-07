#include "net_asio.h"
namespace ip = asio::ip;
using asio::ip::tcp;

void handle_client(tcp::socket s)
{
    try
    {
        std::cout << "server: client connected\n";

        std::array<char, 1024> buf;

        asio::error_code ec;
        std::size_t n = s.read_some(asio::buffer(buf), ec);

        if (ec == asio::error::eof)
        {
            std::cout << "server: client closed\n";
            return;
        }

        if (ec)
            throw asio::system_error(ec);

        asio::write(s, asio::buffer(buf.data(), n));
    }
    catch (const asio::system_error& e)
    {
        std::cerr << "client error: " << e.what() << '\n';
    }
}

int main()
{
    try
    {
        asio::io_context io;

		// #1. 대기용 소켓 생성
        tcp::acceptor acceptor(io, tcp::v4());
        acceptor.set_option(asio::socket_base::reuse_address(true));
        acceptor.bind(tcp::endpoint(tcp::v4(), 7777));
        acceptor.listen();
        std::cout << "server: listening on 7777\n";

        while (1)
        {
			// #2. 접속 허락
            tcp::socket s(io);
            acceptor.accept(s);

			// #3. 새로운 스레드를 생성해서 echo 기능 수행
            std::thread t(handle_client, std::move(s));
            t.detach();
        }
    }
    catch (const asio::system_error& e)
    {
        std::cerr << "server error: " << e.what() << '\n';
    }
}