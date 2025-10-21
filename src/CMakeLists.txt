# Create a static library.
add_library(FilenameValidator STATIC FilenameValidator.cpp)
target_include_directories(FilenameValidator 
	                   PUBLIC 
			   ${CMAKE_SOURCE_DIR}/include)

# Create an executable file by consuming the library.
add_executable(FilenameValidatorApp main.cpp)
target_link_libraries(FilenameValidatorApp PRIVATE FilenameValidator)
# Dont need to target_include for include dir.

#include this to use the standard install directory names.
include(GNUInstallDirs)

# install the created library to be consumed by other project or directories in the same build tree.
install(TARGETS FilenameValidator EXPORT FilenameValidatorTarget
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
	LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
	RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# install the include directory.
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/
	DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
