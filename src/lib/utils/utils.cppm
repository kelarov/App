module;
#include <string>
#include <iostream>
#include <fmt/core.h>
export module utils;

export namespace utils {
	void print_hi(); // defined in a module implementation unit
	void print_msg(std::string_view msg); // defined in the private mod fragment
}

module:private;
/* you could declare stuff here for private/internal use in the
implementations below & they wouldn't even be in the module interface above */
void utils::print_msg(std::string_view msg) {
	fmt::println("{}", msg);
}
