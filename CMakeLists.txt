cmake_minimum_required (VERSION 3.16.0)
project (Raytracer)
set_property (DIRECTORY PROPERTY VS_STARTUP_PROJECT Raytracer)

# Download automatically
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
   message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
   file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.14/conan.cmake"
                 "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

set (CXX_STANDARD_REQUIRED ON)

# Provides unit test library in global scope
conan_cmake_run(REQUIRES 
	glm/0.9.9.5@g-truc/stable
	jsonformoderncpp/3.7.3@vthiery/stable
	lodepng/1.0@int010h/stable
	
	BASIC_SETUP
	CMAKE_TARGETS
	BUILD missing
)

file(GLOB_RECURSE SOURCE_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/source/*.cxx
	${CMAKE_CURRENT_SOURCE_DIR}/source/*.h
	${CMAKE_CURRENT_SOURCE_DIR}/source/*.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/source/*.hxx
)

add_executable (${PROJECT_NAME} ${SOURCE_FILES})

set_target_properties (${PROJECT_NAME} PROPERTIES 
	CXX_STANDARD 17
)

target_link_libraries(${PROJECT_NAME}
	PUBLIC CONAN_PKG::glm
	PUBLIC CONAN_PKG::jsonformoderncpp
	PUBLIC CONAN_PKG::lodepng
)

target_include_directories(${PROJECT_NAME} 
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/source
)

target_compile_definitions(${PROJECT_NAME} 
	PUBLIC -DGLM_ENABLE_EXPERIMENTAL
)

# Copy runtime data
file (COPY ${CMAKE_CURRENT_SOURCE_DIR}/data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})