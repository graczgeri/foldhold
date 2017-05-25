cmake_minimum_required(VERSION 3.0.0)

project (foldhold LANGUAGES C)

add_executable(euler euler/main.c)

add_custom_command(COMMAND euler
                    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
                    OUTPUT ${CMAKE_BINARY_DIR}/euler.dat 
                    BYPRODUCTS ${CMAKE_BINARY_DIR}/euler.dat 
                    DEPENDS euler
                    COMMENT "dolgozok euleren"
                    )

add_custom_target(data DEPENDS ${CMAKE_BINARY_DIR}/euler.dat)

# Compiler specific options
if(CMAKE_C_COMPILER_ID MATCHES "MSVC")
    string(REGEX REPLACE "/W[0-9]" "/W4" CMAKE_C_FLAGS ${CMAKE_C_FLAGS})
    target_compile_definitions(euler PUBLIC _CRT_SECURE_NO_WARNINGS)    
else(CMAKE_C_COMPILER_ID MATCHES "MSVC")
    add_compile_options("-Wall")
endif(CMAKE_C_COMPILER_ID MATCHES "MSVC")