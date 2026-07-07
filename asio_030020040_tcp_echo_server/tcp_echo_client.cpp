#include "net_asio.h" 
namespace ip = asio::ip;
using asio::ip::tcp;

int main()
{
	try
	{
		asio::io_context io;
		
		tcp::socket s(io);
		s.connect(tcp::endpoint(ip::make_address("127.0.0.1"), 7777));
		std::cout << "client: connected\n";

		std::string msg = "hello asio";
		asio::write(s, asio::buffer(msg));

		std::array<char, 1024> buf;
		asio::error_code ec;
		std::size_t n = s.read_some(asio::buffer(buf), ec);

		if (ec == asio::error::eof)
		{
			std::cout << "client: server closed\n";
			return 0;
		}

		if (ec)
			throw asio::system_error(ec);		

		std::cout << "echo: " << std::string_view(buf.data(), n) << '\n';
    }
    catch (asio::system_error& e)
    {
        std::cerr << "client error: " << e.what() << '\n';
    }	
}
