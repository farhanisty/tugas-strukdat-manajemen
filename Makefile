# Compiler
CXX := g++

# Compiler flags
CXXFLAGS := -std=c++17 -Wall -Wextra -O2

# Direktori sumber dan output
SRC_DIR := src
DIST_DIR := dist

# Nama output executable
TARGET := $(DIST_DIR)/main

# Cari semua file sumber .cpp di dalam src/ (termasuk sub-folder)
SRCS := $(shell find $(SRC_DIR) -type f -name '*.cpp')

# Buat daftar file objek (.o) di dist/ dengan struktur yang sama
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(DIST_DIR)/%.o)

# Aturan default
all: $(TARGET)

# Aturan untuk membangun executable
$(TARGET): $(OBJS)
	@mkdir -p $(DIST_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Aturan untuk mengompilasi file .cpp menjadi .o
$(DIST_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Aturan untuk membersihkan build
clean:
	rm -rf $(DIST_DIR)

# Aturan phony untuk target yang tidak sesuai dengan file
.PHONY: all clean
