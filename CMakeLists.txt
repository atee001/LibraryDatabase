CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(driver
    src/main.cpp

)

ADD_EXECUTABLE(bookRepository
    src/BookRepositoryTest.cpp
  
)

add_executable(LibrarySystem src/BookRepositoryTest.cpp header/Book.hpp src/BookRepository.cpp
        header/BookRepository.hpp src/Book.cpp src/BookItem.cpp header/BookItem.hpp src/Date.cpp
        header/Date.hpp header/User.hpp header/Person.hpp src/LibraryCatalog.cpp header/LibraryCatalog.h)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
