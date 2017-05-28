cmake_minimum_required(VERSION 3.0.0)

project (foldhold LANGUAGES C)

add_executable(euler euler/main.c)
add_executable(rk4 rk4/main.c)

add_custom_command(COMMAND euler
                    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/euler
                    OUTPUT ${CMAKE_BINARY_DIR}/euler/euler.dat 
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

# Compiler specific options
if(CMAKE_C_COMPILER_ID MATCHES "MSVC")
    #string(REGEX REPLACE "/W[0-9]" "/W4" CMAKE_C_FLAGS ${CMAKE_C_FLAGS})
    target_compile_definitions(euler PUBLIC _CRT_SECURE_NO_WARNINGS)    
    target_compile_definitions(rk4 PUBLIC _CRT_SECURE_NO_WARNINGS)
else(CMAKE_C_COMPILER_ID MATCHES "MSVC")
    add_compile_options("-Wall")
endif(CMAKE_C_COMPILER_ID MATCHES "MSVC")


# Find Gnuplot
find_package (Gnuplot REQUIRED)

# Target that generates data file
add_custom_command(COMMAND ${GNUPLOT_EXECUTABLE} ${CMAKE_BINARY_DIR}/doc/plot/script/euler_plot.plt
                   WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/euler
                   OUTPUT ${CMAKE_BINARY_DIR}/doc/img/euler_plot.png
                   BYPRODUCTS ${CMAKE_BINARY_DIR}/doc/img/euler_plot.png
                   DEPENDS ${CMAKE_BINARY_DIR}/doc/plot/script/euler_plot.plt data
                   COMMENT "Generating euler plot")


add_custom_command(COMMAND ${GNUPLOT_EXECUTABLE} ${CMAKE_BINARY_DIR}/doc/plot/script/rk4_plot.plt
                   WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/rk4
                   OUTPUT ${CMAKE_BINARY_DIR}/doc/img/rk4_plot.png
                   BYPRODUCTS ${CMAKE_BINARY_DIR}/doc/img/rk4_plot.png
                   DEPENDS ${CMAKE_BINARY_DIR}/doc/plot/script/rk4_plot.plt data
                   COMMENT "Generating rk4 plot")


add_custom_target(plot DEPENDS ${CMAKE_BINARY_DIR}/doc/img/euler_plot.png ${CMAKE_BINARY_DIR}/doc/img/rk4_plot.png)

# Include useful macros
list (APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/doc/cmake)
include (doc/cmake/UseLATEX.cmake)

set(EULER "${CMAKE_BINARY_DIR}/euler.png")
set(RK4  "${CMAKE_BINARY_DIR}/rk4.png")

# Target that generates documentation
add_latex_document (doc/src/latex_template.tex
                   CONFIGURE doc/src/latex_template.tex
                   TARGET_NAME doksi
                   INPUTS doc/src/nyilatkozat.tex doc/src/abeld.bst
                   BIBFILES doc/src/references.bib
                   IMAGE_DIRS doc/img
                   IMAGES doc/img/elte.eps 
                   DEPENDS doc/src/latex_template.tex plot
                   EXCLUDE_FROM_ALL)

    