
SHAREDOBJ = libInMemDb

$(SHAREDOBJ).so : src/QBProfiler.o src/QBRecordStore.o src/QBRecord.o
	$(CXX) -shared $^ -o $@ 

src/QBProfiler.o src/QBRecordStore.o src/QBRecord.o : CXXFLAGS+=-fPIC -I include -std=c++11

clean:
	@echo Cleaning
	rm -rf InMemTester libInMemDb.so src/*.o
	@echo Done

test:
	@echo Testing
	$(CXX) -std=c++11 -I include -L . -lInMemDb -o InMemTester InMemTester.cpp
	./InMemTester
	@echo Done


