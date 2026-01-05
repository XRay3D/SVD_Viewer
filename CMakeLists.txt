cmake_minimum_required(VERSION 3.16)

project(
  SVD_Viewer
  VERSION 0.1
  LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

include(FetchContent)
FetchContent_Declare(
  xrxml
  GIT_REPOSITORY
    git@github.com:XRay3D/XRXml.git # ${CMAKE_CURRENT_LIST_DIR}/../XRXml
  GIT_TAG master)
FetchContent_MakeAvailable(xrxml)

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  add_compile_options(-ftime-trace -fexpansion-statements -freflection-latest
                      -stdlib=libc++)
  add_link_options(-fuse-ld=lld -lc++ -lc++abi)
  add_definitions(-DCR=1)
else()
  add_definitions(-DGR=1 -D__glibcxx_reflection=202506L)
  add_compile_options(-freflection -stdlib=libc++)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)

include_directories(${Boost_INCLUDE_DIRS})

find_package(
  Qt6 6.7.0
  COMPONENTS Widgets Xml
  REQUIRED)

file(GLOB PROJECT_SOURCES *.cpp *.h *.hpp *.ui)

list(FILTER PROJECT_SOURCES EXCLUDE REGEX .*acropdf.*)

file(GLOB SVD_SOURCES svd/*.hpp svd/*.h svd/*.cpp)

qt_add_executable(SVD_Viewer MANUAL_FINALIZATION ${PROJECT_SOURCES}
                  ${SVD_SOURCES})

target_include_directories(SVD_Viewer PRIVATE svd)

target_compile_definitions(
  SVD_Viewer
  PRIVATE QT_NO_CAST_TO_ASCII
          QT_NO_CAST_FROM_ASCII
          QT_NO_URL_CAST_FROM_STRING
          QT_NO_CAST_FROM_BYTEARRAY
          QT_USE_QSTRINGBUILDER
          # QT_NO_KEYWORDS QT_NO_SIGNALS_SLOTS_KEYWORDS
          QT_USE_FAST_OPERATOR_PLUS
          QT_DISABLE_DEPRECATED_BEFORE=0x070000
          QCUSTOMPLOT_USE_OPENGL=1
          EMULATOR=1)

target_link_libraries(SVD_Viewer PRIVATE Qt6::Widgets Qt6::Xml XR::Xml)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1. If
# you are developing for iOS or macOS you should consider setting an explicit,
# fixed bundle identifier manually though.

set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.SVD_Viewer)

set_target_properties(
  SVD_Viewer
  PROPERTIES ${BUNDLE_ID_OPTION} MACOSX_BUNDLE_BUNDLE_VERSION
             ${PROJECT_VERSION} MACOSX_BUNDLE_SHORT_VERSION_STRING
             ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR} MACOSX_BUNDLE
             TRUE WIN32_EXECUTABLE
             TRUE)

include(GNUInstallDirs)
install(
  TARGETS SVD_Viewer
  BUNDLE DESTINATION .
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

qt_finalize_executable(SVD_Viewer)
