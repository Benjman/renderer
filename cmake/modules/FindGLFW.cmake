find_library(GLFW_LIBRARY
			 NAMES glfw glfw3
			 PATHS
			 /usr/lib
			 /usr/local/lib)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(GLFW DEFAULT_MSG GLFW_LIBRARY)
