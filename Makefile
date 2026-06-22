CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
SRC = src/main.cpp src/core/encoder.cpp src/storage/file_store.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = url_shortener
all: $(TARGET)
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
clean:
	rm -f src/*.o src/core/*.o src/storage/*.o $(TARGET) urls.db