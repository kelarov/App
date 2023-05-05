import utils;

int main() {

	utty::print("If you see this, then utty::print is ok;\n");
	utty::print("What about utty::greet()?\n");
	utty::greet();
	utty::print("\nWhat about utty::print_a_truth()?\n");
	utty::print_a_truth();
	utty::print("Testing utty::print(utty::my_int(false)) - do we get 42?\n");
	utty::print(std::to_string(utty::my_int(false)));
	utty::print("\nThat's it. Bye!");
}

// Challenge:
// Implement println() so that we avoid endl, \n, etc.
