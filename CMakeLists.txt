cmake_minimum_required(VERSION 3.0.0)

project (foldhold LANGUAGES C)

add_executable(euler euler/main.c)
add_executable(rk4 rk4/main.c)

add_custom_command(COMMAND euler
                    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/euler
                    OUTPUT ${CMAKE_BINARY_DIR}//euler/euler.dat 
                    BYPRODUCTS ${CMAKE_BINARY_DIR}/euler/euler.dat 
                    DEPENDS euler
                    COMMENT "dolgozok euleren"
                    )
add_custom_command(COMMAND rk4
                    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/rk4/
                    OUTPUT ${CMAKE_BINARY_DIR}/rk4/rk4.dat 
                    BYPRODUCTS ${CMAKE_BINARY_DIR}/rk4/rk4.dat 
                    DEPENDS rk4
                    COMMENT "dolgozok rk4en"
                    )                    

add_custom_target(data DEPENDS ${CMAKE_BINARY_DIR}/euler/euler.dat ${CMAKE_BINARY_DIR}/rk4/rk4.dat)

add_subdirectory (doc)

# Compiler specific options
if(CMAKE_C_COMPILER_ID MATCHES "MSVC")
    string(REGEX REPLACE "/W[0-9]" "/W4" CMAKE_C_FLAGS ${CMAKE_C_FLAGS})
    target_compile_definitions(euler PUBLIC _CRT_SECURE_NO_WARNINGS)    
    target_compile_definitions(rk4 PUBLIC _CRT_SECURE_NO_WARNINGS)
else(CMAKE_C_COMPILER_ID MATCHES "MSVC")
    add_compile_options("-Wall")
endif(CMAKE_C_COMPILER_ID MATCHES "MSVC")
