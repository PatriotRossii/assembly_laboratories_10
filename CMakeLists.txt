cmake_minimum_required(VERSION 3.2)

project(assembly_laboratories_10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mavx -std=c++20 -O3")

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})
set(SOURCE_FILES
	${PROJECT_SOURCE_DIR}/src/main.cpp	
)
set(ASSEMBLY_FILES
	${PROJECT_SOURCE_DIR}/src/calculate.asm
)

enable_language(ASM_NASM)
set(CMAKE_ASM_NASM_COMPILE_OBJECT "nasm -f elf64 -o <OBJECT> <SOURCE>")
set_source_files_properties(${ASSEMBLY_FILES} PROPERTIES LANGUAGE ASM_NASM)

add_executable(assembly_laboratories_10 ${ASSEMBLY_FILES} ${SOURCE_FILES})
target_link_libraries(assembly_laboratories_10)