#include "net_asio.h" 
using asio::ip::tcp;

constexpr std::size_t CLIENT_COUNT = 4;
constexpr std::size_t ECHO_COUNT   = 10;

void client(asio::io_context& io, int id)
{
	std::string name = "client " + std::to_string(id);

	try
	{
		tcp::socket socket(io);
		socket.connect(tcp::endpoint(asio::ip::make_address("127.0.0.1"), 7777));
		std::cout << name << ": connected server\n";

		for (int i = 0; i < ECHO_COUNT; i++)
		{
			std::string msg = "hello asio";
			asio::write(socket, asio::buffer(msg));

			std::array<char, 1024> buf;
			std::size_t n = socket.read_some(asio::buffer(buf));

			sleep(100ms);
		}
	}
	catch (std::exception& e)
	{
		std::cerr << name << " error: " << e.what() << '\n';
	}
}

int main()
{
	asio::io_context io;

	std::vector<std::thread> v;

	for (int i = 0; i < CLIENT_COUNT; i++)
	{
		v.emplace_back([&io, i]() { client(io, i); });
	}

	for (auto& t : v)
	{
		t.join();
	}
}