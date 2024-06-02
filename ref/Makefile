#Compiler
CC = gcc
CXX = g++

#Compiler flags
CFLAGS = -Wall -Wextra -Wpedantic -g

#Directories
SRC_DIR = src
TEST_DIR = test
BUILD_DIR = build
LIB_DIR = $(BUILD_DIR)

#Source files
SOURCES = $(wildcard $(SRC_DIR)/*.c)
SOURCES := $(filter-out $(SRC_DIR)/miniWolfram.c, $(SOURCES))
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Source files for tests
TEST_SOURCES = $(wildcard $(TEST_DIR)/*.cc)
TEST_OBJECTS = $(TEST_SOURCES:$(TEST_DIR)/%.cc=$(BUILD_DIR)/%.o)

# GTest
GTEST_DIR = third_party/googletest/googletest
CXXFLAGS = -std=c++20 -Wall -Wextra -Wpedantic -pthread -g
CPPFLAGS = -isystem $(GTEST_DIR)/include
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
				$(GTEST_DIR)/include/gtest/internal/*.h \

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)


# miniWolfram library
LIB = $(LIB_DIR)/lib$(PROJECT_NAME)Lib.a

# Executables
EXECUTABLE = miniWolfram
TEST_EXECUTABLE = tests

all: $(EXECUTABLE) $(TEST_EXECUTABLE)

$(LIB): $(OBJECTS)
	@mkdir -p $(@D)
	ar rcs $@ $^

$(EXECUTABLE): $(SRC_DIR)/miniWolfram.c $(LIB)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(SRC_DIR) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(SRC_DIR) -c $< -o $@

# GTest

$(BUILD_DIR)/gtest-all.o: $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc -o $@

$(BUILD_DIR)/gtest_main.o: $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc -o $@

$(BUILD_DIR)/gtest.a: $(BUILD_DIR)/gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

$(BUILD_DIR)/gtest_main.a: $(BUILD_DIR)/gtest-all.o $(BUILD_DIR)/gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cc $(GTEST_HEADERS)
	@mkdir -p $(@D)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -I$(SRC_DIR) -c $< -o $@

$(TEST_EXECUTABLE): $(BUILD_DIR)/gtest_main.a $(TEST_OBJECTS) $(LIB)
	@mkdir -p $(@D)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@


# Clean

.PHONY: all clean $(EXECUTABLE) $(TEST_EXECUTABLE)

clean:
	$(RM) -r $(BUILD_DIR) $(EXECUTABLE) $(TEST_EXECUTABLE)