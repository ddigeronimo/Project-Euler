CXX = g++
CXXFLAGS = -Wall -Werror
CXX_FILE = $(wildcard *.cpp)
TARGET =$(patsubst %.cpp,%,$(CXX_FILE))

all:
	$(CXX) $(CXXFLAGS) $(CXX_FILE) -o $(TARGET)

clean:
	rm -f $(TARGET) $(TARGET).exe