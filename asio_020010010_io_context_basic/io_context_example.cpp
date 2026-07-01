#include "net_asio.h"

void foo( asio::steady_timer& t, const asio::error_code& e)        
{ 
    // 에러 체크 (타이머가 외부에서 취소되는 등의 상황 대비)
    if (e) 
	{
        std::cout << "Timer canceled or error: " << e.message() << '\n';
        return;
    }	
	
	static int count = 0;
	++count;	
	std::cout << "foo: " << count << '\n';
	
	if ( count < 3 )
	{
		t.expires_after(1s);	// 1s 뒤에 다시 타이머요청
		t.async_wait([&t](const asio::error_code& ec) { foo(t, ec);}); 
	}
	else
		std::cout << "finish\n";
}
int main()
{
	asio::io_context io;
	asio::steady_timer t(io, 1s);

//	t.async_wait( foo ); // error
	t.async_wait( [&t](const asio::error_code& ec) { foo(t, ec);} ); 

	io.run(); 
}

