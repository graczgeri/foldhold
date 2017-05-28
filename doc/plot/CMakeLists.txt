cmake_minimum_required (VERSION 3.0.0)

project(Plots LANGUAGES NONE)

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

add_custom_target(plot DEPENDS ${CMAKE_SOURCE_DIR}/img/euler_plot.png ${PROJECT_SOURCE_DIR}/img/rk4_plot.png)
