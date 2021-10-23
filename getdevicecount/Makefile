SRCS = main.cpp 
OBJS = $(SRCS:.cpp=.o)

HIPCC    = hipcc
CXXFLAGS = -c
CXX      = $(HIPCC)

TARGET = main

$(TARGET): $(OBJS) 
	$(CXX) $(OBJS) -o $@
main.o: main.cpp
	$(CXX) $^ $(CXXFLAGS) -o $@

.PHONY: clean
clean:
	rm -f $(TARGET)
	rm -f $(OBJS)

