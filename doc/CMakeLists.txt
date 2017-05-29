cmake_minimum_required (VERSION 3.0.0)

project(Document LANGUAGES NONE)

# Include useful macros
list (APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR})
include (cmake/UseLATEX.cmake)

set(EULER "${CMAKE_BINARY_DIR}/euler.png")
set(RK4  "${CMAKE_BINARY_DIR}/rk4.png")

# Target that generates documentation
add_latex_document (src/doksi.tex
                   BIBFILES src/references.bib
                   INPUTS src/nyilatkozat.tex src/abeld.bst
                   IMAGE_DIRS img
                   IMAGES img/elte.eps
                   CONFIGURE src/doksi.tex
                   DEPENDS src/doksi.tex plot
                   USE_BIBLATEX
                   USE_INDEX
                   TARGET_NAME doksi
                   FORCE_PDF                  
                   EXCLUDE_FROM_ALL
                   )

# Process plot CMake script
add_subdirectory(plot)
