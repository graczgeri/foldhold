cmake_minimum_required (VERSION 3.0.0)

project( Document LANGUAGES NONE)

# Include useful macros
list (APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR})
include (cmake/UseLATEX.cmake)

set(EULER "${CMAKE_BINARY_DIR}/euler.png")
set(RK4  "${CMAKE_BINARY_DIR}/rk4.png")

# Target that generates documentation
add_latex_document (src/latex_template.tex
                   CONFIGURE src/latex_template.tex
                   TARGET_NAME doksi
                   INPUTS src/nyilatkozat.tex src/abeld.bst
                   BIBFILES src/references.bib
                   IMAGE_DIRS img
                   IMAGES img/elte.eps ${CMAKE_BINARY_DIR}/rk4.png ${CMAKE_BINARY_DIR}/euler.png
                   DEPENDS src/latex_template.tex plot
                   EXCLUDE_FROM_ALL)

# Process plot CMake script
add_subdirectory(plot)
