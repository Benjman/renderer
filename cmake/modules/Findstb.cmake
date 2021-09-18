find_path(STB_INCLUDE names "stb_truetype.h" PATHS "${CMAKE_CURRENT_LIST_DIR}/../../lib/stb")

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(stb DEFAULT_MSG STB_INCLUDE)
