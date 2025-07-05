CXX = g++
CXXFLAGS = -Wall

proj3: Metro.o Passenger.o Line.o Stop.o proj3.cpp
	$(CXX) $(CXXFLAGS) Metro.o Passenger.o Line.o Stop.o proj3.cpp -o proj3

Metro.o: Metro.h Metro.cpp Passenger.o Line.o Stop.o
	$(CXX) $(CXXFLAGS) -c Metro.cpp

Passenger.o: Passenger.h Passenger.cpp
	$(CXX) $(CXXFLAGS) -c Passenger.cpp

Line.o: Line.h Line.cpp Stop.o
	$(CXX) $(CXXFLAGS) -c Line.cpp

Stop.o: Stop.h Stop.cpp
	$(CXX) $(CXXFLAGS) -c Stop.cpp

clean:
	rm *.o
	rm *~

run0:
	./proj3 proj3_stations.txt proj3_data0.txt

run1:
	./proj3 proj3_stations.txt proj3_data1.txt

run2:
	./proj3 proj3_stations.txt proj3_data2.txt

run3:
	./proj3 proj3_stations.txt proj3_data3.txt

val0:
	valgrind ./proj3 proj3_stations.txt proj3_data0.txt

val1:
	valgrind ./proj3 proj3_stations.txt proj3_data1.txt

val2:
	valgrind ./proj3 proj3_stations.txt proj3_data2.txt

val3:
	valgrind ./proj3 proj3_stations.txt proj3_data3.txt

submit:
	cp Stop.h Stop.cpp Line.h Line.cpp Passenger.h Passenger.cpp Metro.h Metro.cpp proj3.cpp ~/cs202proj/proj3
