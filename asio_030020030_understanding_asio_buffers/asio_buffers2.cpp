#include "net_asio.h" 

struct mutable_buffer
{
	void* data;			// 주소 
	std::size_t size;	// 크기(bytes)

	mutable_buffer(void* d, std::size_t s) 
		: data(d), size(s) {}
};

void write(mutable_buffer mb) { }

int main()
{
	char buf[] = "hello asio";
	std::string s = "hello asio";
	std::vector<int> v = { 1,2,3,4,5 };

	write(mutable_buffer(buf, sizeof(buf)));
	write(mutable_buffer(s.data(), s.size()));
	write(mutable_buffer(v.data(), v.size() * sizeof(int)));
}
