CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(driver
    src/main.cpp

)

#ADD_EXECUTABLE(bookRepository
#    src/BookRepositoryTest.cpp
  
#)

ADD_EXECUTABLE(LibrarySystem src/BookRepositoryTest.cpp src/BookRepository.cpp
        src/Book.cpp src/BookItem.cpp src/Date.cpp
        src/LibraryCatalog.cpp )

#TARGET_LINK_LIBRARIES(test gtest)
#TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
