CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(driver
    src/main.cpp

)

ADD_EXECUTABLE(searchTest
    tests/searchTest.cpp
    src/BookRepository.cpp
    src/Book.cpp
    src/Date.cpp
    src/BookItem.cpp
    src/LibraryCatalog.cpp
    src/SearchAND.cpp
    src/SearchContains.cpp
    src/SearchOR.cpp
) 

ADD_EXECUTABLE(SearchDriver
 	src/SearchAND.cpp
	src/SearchOR.cpp
	src/SearchContains.cpp
	src/SearchQueryTest.cpp
	src/BookRepository.cpp
	src/Date.cpp
	src/BookItem.cpp
	src/Book.cpp
	src/LibraryCatalog.cpp
)

ADD_EXECUTABLE(LibrarySystem src/BookRepositoryTest.cpp src/BookRepository.cpp
        src/Book.cpp src/BookItem.cpp src/Date.cpp
        src/LibraryCatalog.cpp )

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
