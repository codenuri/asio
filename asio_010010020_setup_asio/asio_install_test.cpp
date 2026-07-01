#define ASIO_STANDALONE

#define WINVER       0x0A00        
#define _WIN32_WINNT 0x0A00  
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX

#include <asio.hpp> 
#include <iostream> 

int main() 
{ 
	std::cout << "ASIO_VERSION = " 
			  << ASIO_VERSION << '\n'; 
}

