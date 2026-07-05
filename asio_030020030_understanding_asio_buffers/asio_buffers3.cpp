#include "net_asio.h" 

struct mutable_buffer
{
	void* data;
	std::size_t size;

	mutable_buffer(void* d, std::size_t s) : data(d), size(s) {}
};

mutable_buffer asio_buffer(void* d, std::size_t s)
{
	return mutable_buffer(d, s);
}

template<typename T, std::size_t N>
mutable_buffer asio_buffer(T(&arr)[N])
{
	return mutable_buffer(arr, N * sizeof(T));
}

mutable_buffer asio_buffer(std::string& s)
{
	return mutable_buffer(s.data(), s.size());
}

template<typename T>
mutable_buffer asio_buffer(std::vector<T>& v)
{
	return mutable_buffer(v.data(), v.size() * sizeof(T));
}






void write(mutable_buffer mb) { }

int main()
{
	char buf[] = "hello asio";
	std::string s = "hello asio";
	std::vector<int> v = { 1,2,3,4,5 };

	write(mutable_buffer(buf, sizeof(buf)));
	write(mutable_buffer(s.data(), s.size()));
	write(mutable_buffer(v.data(), v.size() * sizeof(int)));

	write(asio_buffer(buf, sizeof(buf)));
	write(asio_buffer(buf));
	write(asio_buffer(s));
	write(asio_buffer(v));
}
