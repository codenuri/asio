#include "net_asio.h"
using asio::ip::tcp;
namespace ip = asio::ip;

asio::awaitable<void> session(tcp::socket socket)
{
	// <= 컴파일러가 추가한 코드 =>

    std::array<char, 1024> buffer;

    while (true)
    {
        std::size_t bytes = co_await socket.async_read_some(asio::buffer(buffer), asio::use_awaitable);
        co_await asio::async_write(socket, asio::buffer(buffer, bytes), asio::use_awaitable);
    }
}

asio::awaitable<void> start_accept(asio::io_context& io)
{
	// <= 컴파일러가 추가한 코드 =>

    tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), 7777));
    std::cout << "server : listening on 7777\n";

    while (true)
    {
        tcp::socket socket = co_await acceptor.async_accept(asio::use_awaitable);
									// 3. 비동기 accept 요청후 suspend
		
        asio::co_spawn(io, session(std::move(socket)), asio::detached);
									// 이후 R/W 작업은 동일한 coroutine 방식 사용
    }
}
int main()
{
    try
    {
        asio::io_context io;
        asio::co_spawn(io, start_accept(io), asio::detached);
					// 1. aw = start_accept() 후에 aw 를 io 에 보관

        io.run();	// 2. aw.resume() 으로 coroutine 의 사용자 코드 시작
					// 4. 비동기 accept() 완료시 aw.resume()
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }
}