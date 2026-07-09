#include "net_asio.h"

class session : public std::enable_shared_from_this<session>
{
public:
    session()  
	{ 
		auto sp = shared_from_this(); // 잘못된 코드		
	}

	void start(  )
    {
		auto sp = shared_from_this();
    }	
};
int main()
{
	auto sp = std::make_shared<session>(); 

	sp->start();

}

