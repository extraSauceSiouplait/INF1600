CXX = g++
INCLUDES= -I./
CXXFLAGS = -g $(INCLUDES)
SRCM= ../Vector.cpp ../Stack.cpp
OBJM = $(SRCM:.cpp=.o)
LINKFLAGS= -lcppunit

tests: main.cpp $(OBJM)
	$(CXX) $(CXXFLAGS) -o $@ main.cpp $(OBJM) $(LINKFLAGS) $(LINKFLAGSLOG4) $(LIBLOG)

# Default compile

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf *.o

mrproper: clean
	rm -rf tests
