# App
This all started with me showcasing how to use the C++20 Modules feature, but now I'm going to use this repo as my all-things-swe-with-cpp learning ground.

## About
- I have a simple module called `utils` which provides some functionality that gets imported into|used in `main.cpp`|`main()`
- I use CMake Presets to manage my build. I just learned how to use this, so, I'm no pro yet, but that's what I'm going to use from now on. That's reaaally neat | `CMakePresets.json`
- I use vcpkg as my package manager | `vcpkg.json`
- The testing is done with Google Test, pulled and made available via `vcpkg`
- `doxygen` handles the documentation

## How to build
### Requirements:
#### What I'm currently using:
- CMake 3.26.3 (make sure it's in your path variable)
	+ you could also use 3.26; just modify the root CMake listfile (`... 3.26.3 -> 3.26`)
- VS 2022 Preview 5 | MSVC 19.36.32530.0
- vcpkg - latest version \[You need this. We're using the `gtest` library and this dependency is handled by `vcpkg`\]
	+ Make sure to set the `VCPKG_INSTALLATION_ROOT` environment variable. We use it in the CMake Presets.
	+ It should point to the location where the `vcpkg.exe` is located
- Read the disclaimers
### Building
- Go to your `PowerShell` or `Developer PowerShell for VS22`
- Run `cmake --workflow --preset config-build-test` [1]
	+ you'll get an `App.exe`, and a `utils_tests.exe`
	+ The tests will run automatically, and you'll see the output right away, after executing the workflow
	+  Both tests should both pass.
- [1] is just a workflow example. If you want to remove the testing part, replace `config-build-test` with `config-build`
- PS: I don't really like the way `ctest` displays the stuff haha. You can run `.\build\release\tests\utils\Release\utils_tests.exe` and get the test results displayed more nicely.
#### Notes
- The way I implemented `utils` is just one of the possible ways to do it.
- There's also something called **partition module implementation unit**, where you write `module A:C;` instead of `export module A:C;` and perform, as you may have guessed, implementations.
- There's also something I have seen people call *submodules* that are just primary module interface units for a named module, as we had before, but that helps one to logically understand the module organisation. So, this can be a nice way for you to organise things. You would have, for instance, `export module myorg.components.video;` and then, somewhere else, `export module myorg.components.audio;`. These two modules don't have to have anything to do with one another, technically. But I could read them as being logically interconnected, by seeing how they were named. Since they're individual primary module interface units, you could import them into your `main` separately, (e.g `import myorg.components.audio;`). Or, you could also have another module, called, say, `myorg.components`, that would `export import` these 2 submodules, and, by `import`ing `myorg.components`, you would have access to those two other modules' functionality (as long as they make stuff available for outsiders, of course).
- `utils.ttxt` is just `utils.ixx` with some notes/comments, for those who want to have an idea about the working of modules. Make it `utils.cpp`, for example, to see it syntax-highlighted with your code editor.
- `./docs/` - for now, it's not meant to document the entire code, it's is just so that you can have an example on how to use doxygen to document your code. When I really turn this into an real project, we'll have proper documentation.
	+ If you clone the repo, start working on it and want to generate your docs, then `doxygen` needs to be installed and "findable". It's an easy install, so, a simple google search should be enough. After that, it's as easy as going to `./docs/` and running `doxygen` [you might need to modify the input paths, though, in case you add more directories]
- pre-commit-config makes sure the formatter and linters checks pass when you request a pull
	+ for now deactivated, since it requires a file that only Maker's and Ninja Files provide (`compile_commands.json`), but for now, I won't use Ninja, due to the fact I not only import my own modules, but also system header as modules, and Ninja can't handle that yet. But, it's in the workflows folder to be triggered on PRs, for when I port this to Linux, start accepting PRs, and so on.

##### Extending the example

I kept the example here simple, so that beginners could understand it right after the famous `Hello, World`. For example, I didn't introduce Classes and/or complicated stuff. However, if you already know about, say, Classes, just think that you could have:

```cpp
module;
/*
include the non-importable stuff you need
*/

export module myclasses;

/*
import the stuff that you need
*/

// exporting the entire class my_class
export class my_class {
	// ...

}

// Exporting only ns::exported_class
namespace ns {
	export class exported_class {
		// ...
	}
	class non_exported_class {
		// ...
	}
	const int non_exported_int{42};
}
```

So, yeah...
It's new, g++ and clang support still suck, not many people have been using it, but there's no way I am going back to headers ^^

## Future Endeavours
- When `g++` implements [P1689R5](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2022/p1689r5.html), so that I can work with it and CMake, I'll make `App` Linux+Windows compatible, probably by using MSVC|g++ and Ninja.
- I am planning on\[as soon as possible\] updating `App` to use C++23's `import std;` feature, so we don't need to individually import the headers. Then I guess we would be able to use Ninja without any workarounds.
- `App` is gonna be my testing/learning ground, so, I intend to build upon it and have Unit Testing using `Google Test`, Dependency Management using `vcpkg`, auto-formatting, static analysis and linting using cmake-format, clang-format, clang-tidy, CI/CD|GH Actions|Workflows stuff (e.g. using pre-commit hooks), as well as Github Pages, Test Coverage, Documentation (using Doxygen) and so on, so that in the end we have a full-blown Template for CMake C++ Projects.
- My final goal is to have a small GUI App (maybe using wxWidgets or Dear ImGui). If not, some other nice, interesting project.
- By the end of this I should have mastered the Modules feature [everything from my side will be modularised ("from my side" because I can't force the 3rd-party stuff to have theirs in form of modules haha)], some other newer features like Ranges, Concepts, etc., but also some DevOps and/or some general Software Engineering, like how to work with Git|Github|CI/CD, how to unit-test, how to document my code, and how to have some neat stuff like Github Pages.
## Getting involved
- We also have a small Discord [Server](https://discord.gg/RAxWbgR3qM) where we learn about C++. Feel free to join.
- For example, if you don't know how to use CMake yet, you can look for tutorials or Youtube videos, of course; but if you want to know about my specific `CMakeLists.txt` approach, you can hop into the Server and I'll try to explain the basics to you - CMake is a real beast, so, it's really just enough to get it up and running.
