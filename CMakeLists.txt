cmake_minimum_required(VERSION 2.8)

project( eagle )

find_package( OpenCV REQUIRED )



set(SOURCE_FILES 
	main.cpp
)

set(LIBRARY_FILES 
	includes/filters.hpp
	includes/filters.cpp
	includes/eagle.hpp
	includes/utils.cpp
	includes/utils.hpp
)

add_executable( main ${SOURCE_FILES} )
target_link_libraries( main ${OpenCV_LIBS} )