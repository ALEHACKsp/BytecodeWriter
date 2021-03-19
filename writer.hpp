#pragma once

#include <vector>
#include <cstdint>

namespace luau
{
	struct bytecode_writer
	{
		std::vector<std::uint8_t> bytecode;

		template <class type>
		bytecode_writer& operator<< (const type& value)
		{
			bytecode.insert(bytecode.end(), reinterpret_cast<const std::uint8_t*>(&value), reinterpret_cast<const std::uint8_t*>(&value) + sizeof(type));
			return *this;
		}

		void write_compressed(std::uint32_t value);
		void write_string(const char* const string, const std::size_t size);
	};
}
