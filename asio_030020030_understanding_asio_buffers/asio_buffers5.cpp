#include "net_asio.h" 

// asio::write() 
// 데이타 전송이므로 버퍼의 내용을 읽기만 하면 된다
// => 인자로 const_buffer 를 사용
void asio_write(asio::const_buffer cb) { }

// asio::read()
// 수신된 내용으로 버퍼를 채워야 하므로 mutable_buffer를 인자로 받도록 구현
// => 인자로 mutable_buffer 를 사용
void asio_read(asio::mutable_buffer mb) { }

int main()
{
	char mbuf[32];
	const char cbuf[] = "hello asio";
	
	asio_write(asio::buffer(cbuf)); // 
	asio_write(asio::buffer(mbuf)); // ok. mutable buffer -> const buffer

	asio_read(asio::buffer(cbuf)); // error
	asio_read(asio::buffer(mbuf)); // 
}
