CXX = clang++
CXXAFL = afl-clang-fast++

SAN = -fsanitize=address,undefined

CXXFLAGS += -Wall
CXXFLAGS += -Wextra
CXXFLAGS += -pedantic
# CXXFLAGS += -Werror
CXXFLAGS += -Wmissing-declarations
CXXFLAGS += -fstack-protector-all

OPT = -Ofast

SRC_DIR=src
DEBUG = -g

.PHONY: default
default: fmt lint build clean

.PHONY: fmt
fmt: src/*.hpp src/*.cpp
	@clang-format -i -style=file src/*.hpp src/*.cpp
	@echo "============================================================================"

.PHONY: lint
lint: src/*
	@cppcheck --enable=all src/
	@echo "============================================================================"

.PHONY: build
build: src/*.hpp src/*.cpp
	@$(CXX) $(CXXFLAGS) $(SAN) $(DEBUG) src/*.cpp -o task.out
	@echo "============================================================================"

.PHONY: clean
clean:
	-@rm src/*.gch &> /dev/null || true
	-@rm tests/*.a tests/*.o tests/*.out &> /dev/null || true
	-@rm -r docs/ &> /dev/null || true
