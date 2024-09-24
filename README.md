# [Next C++](https://discord.com/invite/RAxWbgR3qM)
## Brief
This is a small template project setup showing the use of C++20 Modules and CMake.
It includes:
- 2 libraries as C++20 Modules - `maths` and `utils`
  - `maths`
    - divided into two partitions, `add` and `mult`, and they are both `export import`ed.
    - it is linked to the `utils` module
  - `utils` - has a `.cppm` as the module interface and a `.cc` module implementation unit that implements it.
    - `utils` uses the [`fmt`](https://github.com/fmtlib/fmt) lib pulled in via [`vcpkg`](https://vcpkg.io/en/)
- a simple `main.cc` that consumes the `maths` module

Anyway. It isn't a full setup|template yet, but I'll work on adding more stuff [docs, testing, linting, formatting, etc.]

## Requirements [or, better: What I'm using:]
- [vcpkg](https://learn.microsoft.com/en-gb/vcpkg/get_started/get-started?pivots=shell-bash) with the `VCPKG_ROOT` environment variable set up
- Lastet [CMake](https://cmake.org/download) version [3.30.3]
- `clang++` 19.1 - see [The LLVM Project](https://github.com/llvm/llvm-project)
  - PS: `g++` didn't play well with the private module fragment and the *`import`* keyword in general :(
## Building
As of now, if you have cmake, vcpkg and clang++ set up, i.e. you should be able to build the project with a single command by making use of **CMake Presets**:

`cmake --workflow --preset lnx-config-build-dbg`   or
`cmake --workflow --preset lnx-config-build-rel`

## Plans
- [ ] Add Doxygen for Documentation
- [ ] Figure out how to get linting tools, formatting, sanitising, profiling, analysis, etc. working.
- [ ] Add the Google Test Library for Testing
- [ ] Try to make it compatible with Windows [^1]
## Remarks
- I'm no expert - I'm learning all this and experimenting with C++20 Modules myself
- I also got a book on CMake and am reading it to better understand how I should set up the Project


## Footnotes
[^1] - Regarding Windows-compatibility: at **this** point [since I'm not yet using too many Linux-specific stuff, apart from clang++], it's just a matter of changing the CMake Presets to use the `cl` or `clang-cl` compiler chains.
I guess you could use the following [Presets](https://learn.microsoft.com/en-gb/vcpkg/get_started/get-started?pivots=shell-bash) and run `cmake --preset=default && cmake --build build` command from the VS Developer PowerShell, and everything should work, if you have Ninja, vcpkg and cmake available to the system.
```json
{
  "version": 6,
  "configurePresets": [
    {
      "name": "default",
      "generator": "Ninja",
      "binaryDir": "${sourceDir}/build",
      "cacheVariables": {
        "CMAKE_TOOLCHAIN_FILE": "$env{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
      }
    }
  ]
}
```
