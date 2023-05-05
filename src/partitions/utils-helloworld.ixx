export module utils:helloworld;

import :print;

export namespace utty::hw {
	void hello_world();
}



void utty::hw::hello_world() {
	utty::print("Hello, World");
}

/*
PS: since there's an export in the first line, you could actually implement utty::hw::hello_world right there where you declare it
I just wanted to show this is also possible.

Question: why couldn't you write in line, say, 9, `module:private;` and then write the function implementation below it?
*/
