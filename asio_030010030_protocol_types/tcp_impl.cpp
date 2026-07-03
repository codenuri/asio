// asio 와 유사하게 구현된 tcp 클래스
// => 완전히 동일하지는 않지만, 대부분의 구현이 거의 유사
namespace asio
{
	namespace ip
	{
		class tcp
		{
			int family_;

			explicit tcp(int protocol_family) noexcept  : family_(protocol_family)
			{}
		public:
			typedef basic_endpoint<tcp> 	 	endpoint;
			typedef basic_stream_socket<tcp> 	socket;
			typedef basic_socket_acceptor<tcp> 	acceptor;
			typedef basic_resolver<tcp> 		resolver;

			static tcp v4() noexcept { return tcp(AF_INET);	}
			static tcp v6() noexcept { return tcp(AF_INET6); }

			int type() const noexcept 	  { return SOCK_STREAM; }
			int protocol() const noexcept { return IPPROTO_TCP); }
			int family() const noexcept   { return family_;	}

			// ==, !=
			friend bool operator==(const tcp& p1, const tcp& p2) { return p1.family_ == p2.family_; }
			friend bool operator!=(const tcp& p1, const tcp& p2) { return p1.family_ != p2.family_;	}
		};
	}
}

