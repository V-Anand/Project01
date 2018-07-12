
SHAREDOBJ = libInMemDb

$(SHAREDOBJ).so : src/QBProfiler.o src/QBRecordStore.o
	$(CXX) -shared $^ -o $@ 

src/QBProfiler.o src/QBRecordStore.o : CXXFLAGS+=-fPIC -I include -std=c++11

test:
	@echo Testing
	$(CXX) -std=c++11 -I include -L . -lInMemDb -o InMemTester InMemTester.cpp
	./InMemTester
	@echo Done


