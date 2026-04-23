CXX = g++
CXXFLAGS = -std=c++17 -O2

code: solution.cpp
	$(CXX) $(CXXFLAGS) -o code solution.cpp

clean:
	rm -f code
