cmake_minimum_required (VERSION 3.0.0)

project(Plots)

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
                   BYPRODUCTS ${CMAKE_BINARY_DIR}/rk4.png
                   DEPENDS ${PROJECT_SOURCE_DIR}/script/rk4_plot.plt data 
                   COMMENT "Generating rk4 plot")

add_custom_target(plot ALL DEPENDS ${CMAKE_BINARY_DIR}/euler.png ${CMAKE_BINARY_DIR}/rk4.png)
