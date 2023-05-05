module;

export module utils;

export import :print;
import :helloworld;
import :mynumber;

export namespace utty {
	void greet();
	int my_int(bool use_secret);
	void print_a_truth();
}

namespace utty::vars {
	export int an_available_int = 666;
	int my_secret_number{1234};
	const std::string my_fav_line{"\"Someone has to do the hard job. -B. Stroustrup\"\n"};
}

module:private;

int my_fav_number{42};

void utty::greet() {
	utty::hw::hello_world();
}

void utty::print_a_truth() {
	utty::print(utty::vars::my_fav_line);
}

int utty::my_int(bool use_secret) {
	if(use_secret) {
		return utty::mn::my_int(utty::vars::my_secret_number);
	}
	return utty::mn::my_int(my_fav_number);
}
