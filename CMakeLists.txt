cmake_minimum_required(VERSION 3.0.0)

project (foldhold LANGUAGES C)

add_executable(euler euler/main.c)
add_executable(rk4 rk4/main.c)

add_custom_command(COMMAND euler
                    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
                    OUTPUT ${CMAKE_BINARY_DIR}/euler.dat 
                    BYPRODUCTS ${CMAKE_BINARY_DIR}/euler.dat 
                    DEPENDS euler
                    COMMENT "dolgozok euleren"
                    )
add_custom_command(COMMAND rk4
                    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
                    OUTPUT ${CMAKE_BINARY_DIR}/rk4.dat 
                    BYPRODUCTS ${CMAKE_BINARY_DIR}/rk4.dat 
                    DEPENDS rk4
                    COMMENT "dolgozok rk4en"
                    )                    

add_custom_target(data DEPENDS ${CMAKE_BINARY_DIR}/euler.dat ${CMAKE_BINARY_DIR}/rk4.dat)

# Find Gnuplot
find_package (Gnuplot REQUIRED)

# Target that generates data file
add_custom_command(COMMAND ${GNUPLOT_EXECUTABLE} ${PROJECT_SOURCE_DIR}/script/euler_plot.plt
                   WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
                   OUTPUT ${CMAKE_BINARY_DIR}/euler.png
                   BYPRODUCTS ${CMAKE_BINARY_DIR}/euler.png
                   DEPENDS ${PROJECT_SOURCE_DIR}/script/euler_plot.plt data
                   COMMENT "Generating euler plot")


add_custom_command(COMMAND ${GNUPLOT_EXECUTABLE} ${PROJECT_SOURCE_DIR}/script/rk4_plot.plt
                   WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
                   OUTPUT ${CMAKE_BINARY_DIR}/rk4.png
                   BYPRODUCTS ${CMAKE_BINARY_DIR}/rk4_plot.png
                   DEPENDS ${PROJECT_SOURCE_DIR}/script/rk4_plot.plt data
                   COMMENT "Generating rk4 plot")

add_custom_target(plot DEPENDS ${CMAKE_BINARY_DIR}/euler.png ${PROJECT_SOURCE_DIR}/script/rk4_plot.plt data)


# Compiler specific options
if(CMAKE_C_COMPILER_ID MATCHES "MSVC")
    string(REGEX REPLACE "/W[0-9]" "/W4" CMAKE_C_FLAGS ${CMAKE_C_FLAGS})
    target_compile_definitions(euler PUBLIC _CRT_SECURE_NO_WARNINGS)    
    target_compile_definitions(rk4 PUBLIC _CRT_SECURE_NO_WARNINGS)
else(CMAKE_C_COMPILER_ID MATCHES "MSVC")
    add_compile_options("-Wall")
endif(CMAKE_C_COMPILER_ID MATCHES "MSVC")
