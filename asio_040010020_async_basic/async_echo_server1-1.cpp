#include "net_asio.h"
using asio::ip::tcp;
namespace ip = asio::ip;

asio::io_context io;
tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), 7777));
tcp::socket   s(io);
std::array<char, 1024> buf;

void on_write(const asio::error_code& ec, std::size_t bytes)
{
    // 이후 모든 비동기 작업이 종료되었으므로 "main: io.run()" 은 반환되고 프로그램은 종료
}

void on_read(const asio::error_code& ec, std::size_t bytes)
{
	// 현재 상태 : 읽기 작업이 완료되어서 buf 에 데이터가 있음 
    // 핵심 : buf 에 있는 데이터를 client 에게 다시 전송 - 비동기 요청
    asio::async_write(s, asio::buffer(buf, bytes), on_write);
}

void on_accept(const asio::error_code& ec)
{
	// 현재 상태 : 접속 요청이 허락(accept) 되어서 "통신 소켓 s 와 client 소켓이 연결" 된 상태
    // 핵심 : 다시 비동기로 읽기 요청
    s.async_read_some(asio::buffer(buf), on_read);
}

int main()
{
    //  acceptor.accept(s);    // 동기 accept : 클라이언트의 접속 요청이 있을때 까지 대기

    acceptor.async_accept(s, on_accept);
				// 1. 클라이언트의 접속 요청이 없어도 바로 반환
				// 3. 클라이언트가 접속 요청을 요청하면 허락( 통신용 소켓 s 와 client socket 연결)후
				// 4. on_accept 함수를 io_context 에 post

    io.run();	// 2. Q 에 아직 작업은 없지만 종료되지 않은 비동기 작업(async_accept) 때문에 대기
    			// 5. Q 에 post 된 on_accept() 함수를 꺼내서 실행
    			// 6. 이후 비동기 요청에 따른 handler 를 모두 수행후 종료
}



