cmake_minimum_required(VERSION 2.8)

project( eagle )

find_package( OpenCV REQUIRED )
set(SOURCE_FILES )

add_executable( main ${SOURCE_FILES} )
target_link_libraries( DisplayImage ${OpenCV_LIBS} )