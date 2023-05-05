if(BUILD_SAMPLES)
	add_executable(App main.cpp)
	target_link_libraries(App PRIVATE utils_md)
endif()
