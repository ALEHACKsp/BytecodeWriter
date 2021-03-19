#include "writer.hpp"

void luau::bytecode_writer::write_compressed(std::uint32_t value)
{
	do
	{
		auto temp = (value & 127);
		value >>= 7;

		*this << static_cast<std::uint8_t>(value ? temp | 128 : temp);
	} while (value);
}

void luau::bytecode_writer::write_string(const char* const string, const std::size_t size)
{
	write_compressed(size);
	bytecode.insert(bytecode.end(), reinterpret_cast<const std::uint8_t*>(string), reinterpret_cast<const std::uint8_t*>(string) + size);
}
