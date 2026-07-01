// net_asio.h
#pragma once

// standalone Asio 사용
#ifndef ASIO_STANDALONE
#define ASIO_STANDALONE
#endif

#if defined(_WIN32)
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#ifndef NOMINMAX
#define NOMINMAX
#endif

#ifndef WINVER
#define WINVER 0x0A00
#endif

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0A00
#endif
#endif

// Asio
#include <asio.hpp>

// C++ standard library
#include <array>
#include <chrono>
#include <cstdint>
#include <cstdlib>
#include <deque>
#include <exception>
#include <iostream>
#include <memory>
#include <string>
#include <string_view>
#include <system_error>
#include <thread>
#include <utility>
#include <vector>
#include <iomanip>
#include <functional>

// C++20 coroutine support
#if __cplusplus >= 202002L
#include <coroutine>
#endif
using namespace std::literals;	
using namespace std::placeholders;


void sleep(std::chrono::milliseconds ms)
{
	std::this_thread::sleep_for(ms);
}

void __log(std::string_view where, std::string_view what)
{
	std::cout << "[tid: " << std::setw(3) << std::this_thread::get_id() << "] " << where;
	
	if (what.size() == 0)
		std::cout << '\n';
	else 
		std::cout << " | " << what << '\n';	
}

#define log()			  __log(__func__, "")
#define log_and_sleep(ms) do { __log(__func__, "enter"); sleep(ms); __log(__func__, "exit"); } while(0)


