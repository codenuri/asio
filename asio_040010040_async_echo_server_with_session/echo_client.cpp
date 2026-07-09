#include "net_asio.h" 
using asio::ip::tcp;

int main()
{
    try
    {
        asio::io_context io;

        tcp::socket socket(io);
        socket.connect(tcp::endpoint(asio::ip::make_address("127.0.0.1"), 7777));

        std::cout << "client: connected server\n";

		while(true)
		{
			std::cout << "input message : ";
			std::string msg;
			std::cin >> msg;

			asio::write(socket, asio::buffer(msg));

			std::array<char, 1024> buf;
			asio::error_code ec;
			std::size_t n = socket.read_some(asio::buffer(buf), ec);

			if (ec == asio::error::eof)
			{
				std::cout << "client: server closed\n";
				return 0;
			}

			if (ec)
				throw asio::system_error(ec);

			std::cout << "echo: " << std::string_view(buf.data(), n) << '\n';
		}

    }
    catch (std::exception& e)
    {
        std::cerr << "client error: " << e.what() << '\n';
    }
}