# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/admin/Desktop/МАИ/второй/ооп/oop_labs/lab04/build/_deps/googletest-src"
  "/Users/admin/Desktop/МАИ/второй/ооп/oop_labs/lab04/build/_deps/googletest-build"
  "/Users/admin/Desktop/МАИ/второй/ооп/oop_labs/lab04/build/_deps/googletest-subbuild/googletest-populate-prefix"
  "/Users/admin/Desktop/МАИ/второй/ооп/oop_labs/lab04/build/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "/Users/admin/Desktop/МАИ/второй/ооп/oop_labs/lab04/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "/Users/admin/Desktop/МАИ/второй/ооп/oop_labs/lab04/build/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "/Users/admin/Desktop/МАИ/второй/ооп/oop_labs/lab04/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/admin/Desktop/МАИ/второй/ооп/oop_labs/lab04/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/admin/Desktop/МАИ/второй/ооп/oop_labs/lab04/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
