cmake_minimum_required(VERSION 3.0.0)

project (Application LANGUAGES C)

add_executable(euler src/euler.c)

add_custom_command(COMMAND euler
                    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
                    OUTPUT ${CMAKE_BINARY_DIR}/euler.dat
                    BYPRODUCTS ${CMAKE_BINARY_DIR}/euler.dat
                    DEPENDS euler
                    COMMENT "Generating euler data"
                    )
                    
add_executable(rk4 src/rk4.c)

add_custom_command(COMMAND rk4
                    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
                    OUTPUT ${CMAKE_BINARY_DIR}/rk4.dat 
                    BYPRODUCTS ${CMAKE_BINARY_DIR}/rk4.dat 
                    DEPENDS rk4
                    COMMENT "Generating rk4 data"
                    )                    

add_custom_target(data DEPENDS ${CMAKE_BINARY_DIR}/euler.dat ${CMAKE_BINARY_DIR}/rk4.dat)

# Compiler specific options
if(CMAKE_C_COMPILER_ID NOT "MSCV")
    target_link_libraries(euler PRIVATE m)
    target_link_libraries(rk4 PRIVATE m)
endif()

if(CMAKE_C_COMPILER_ID MATCHES "MSVC")
    string(REGEX REPLACE "/W[0-9]" "/W4" CMAKE_C_FLAGS ${CMAKE_C_FLAGS})
    target_compile_definitions(euler PUBLIC _CRT_SECURE_NO_WARNINGS)    
    target_compile_definitions(rk4 PUBLIC _CRT_SECURE_NO_WARNINGS)
else(CMAKE_C_COMPILER_ID MATCHES "MSVC")
    add_compile_options("-Wall")
endif(CMAKE_C_COMPILER_ID MATCHES "MSVC")
