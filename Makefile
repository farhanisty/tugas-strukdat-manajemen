# Compiler
CXX := g++

# Compiler flags
CXXFLAGS := -std=c++17 -Wall -Wextra -O2 -g

# Direktori sumber dan output
SRC_DIR := src
DIST_DIR := dist

# Nama output executable
TARGET := $(DIST_DIR)/main

# Cari semua file sumber .cpp di dalam src/ (termasuk sub-folder)
SRCS := $(wildcard $(SRC_DIR)/**/*.cpp)

# Buat daftar file objek (.o) di dist/ dengan struktur yang sama
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(DIST_DIR)/%.o)

# Deteksi OS (default ke UNIX jika tidak diketahui)
ifeq ($(OS),Windows_NT)
    MKDIR := mkdir
    RM := rmdir /S /Q
    SEP := \ # Windows separator
    OBJ_DIRS := $(subst /,$(SEP),$(dir $(OBJS)))
else
    MKDIR := mkdir -p
    RM := rm -rf
    SEP := / # UNIX separator
    OBJ_DIRS := $(dir $(OBJS))
endif

# Aturan default
all: $(DIST_DIR) $(TARGET)

# Buat folder dist jika belum ada
$(DIST_DIR):
	@$(MKDIR) $(subst /,$(SEP),$(DIST_DIR))

# Aturan untuk membangun executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Aturan untuk mengompilasi file .cpp menjadi .o
$(DIST_DIR)/%.o: $(SRC_DIR)/%.cpp
	@$(MKDIR) $(subst /,$(SEP),$(dir $@))
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Aturan untuk membersihkan build
clean:
	$(RM) $(subst /,$(SEP),$(DIST_DIR))

# Aturan phony untuk target yang tidak sesuai dengan file
.PHONY: all clean