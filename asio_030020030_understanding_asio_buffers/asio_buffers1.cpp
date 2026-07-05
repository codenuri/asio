#include "net_asio.h" 

void write(void* p, std::size_t bytes) { }

int main()
{
	char buf[] = "hello asio";
	write(buf, sizeof(buf));

	std::string s = "hello asio";
	write(s.data(), s.size());

	std::vector<int> v = { 1, 2, 3, 4, 5 };
	write(v.data(), v.size() * sizeof(int));
}
