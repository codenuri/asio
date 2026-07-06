#include "net_asio.h"
namespace ip = asio::ip;
using asio::ip::tcp;

int main()
{
    try
    {
        asio::io_context io;

        tcp::acceptor acceptor(io, tcp::v4());
        acceptor.set_option(asio::socket_base::reuse_address(true));        
		acceptor.bind(tcp::endpoint(tcp::v4(), 7777));
        acceptor.listen();

        std::cout << "server: listening on 7777\n";

        while (1)
        {
            tcp::socket s(io);
            acceptor.accept(s);

            std::cout << "server: client connected\n";

            std::array<char, 1024> buf;

            asio::error_code ec;
            std::size_t n = s.read_some(asio::buffer(buf), ec);

            if (ec == asio::error::eof)
            {
                std::cout << "server: client closed\n";
                continue;
            }

            if (ec)
                throw asio::system_error(ec);

            asio::write(s, asio::buffer(buf.data(), n));
        }
    }
    catch (const asio::system_error& e)
    {
        std::cerr << "server error: " << e.what() << '\n';
    }
}
