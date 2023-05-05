export module utils:print;

import <format>;
import <iostream>;
import <string_view>;
export import <string>;
import <cstdio>;

export namespace utty {

	template <typename... Args>
	void print(const std::string_view fmt_str, Args&& ... args) {
		auto fmt_args {std::make_format_args(args...)};
		std::string outstr {std::vformat(fmt_str, fmt_args)};
		fputs(outstr.c_str(), stdout);
	}

}
