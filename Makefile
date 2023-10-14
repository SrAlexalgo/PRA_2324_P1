bin/testListArray: testListArray.cpp ListArray.h List.h
	mkdir -p bin
	g++ -o bin/testListArray testListArray.cpp ListArray.h

bin/testListLinked: testListLinked.cpp ListLinked.h List.h
	mkdir -p bin
	g++ -o bin/testListLinked testListLinked.cpp ListLinked.h

bin/testNode: testNode.cpp Node.h
	mkdir -p bin
	g++ -o bin/testNode testNode.cpp Node.h

bin/testPoint2D: testPoint2D.cpp Point2D.o
	g++ -c testPoint2D.cpp
	mkdir -p bin
	g++ -o bin/testPoint2D testPoint2D.o Point2D.o

bin/testCircle: testCircle.cpp Circle.o Shape.o Point2D.o
	g++ -c testCircle.cpp
	mkdir -p bin
	g++ -o bin/testCircle testCircle.o Circle.o Shape.o Point2D.o

Point2D.o: Point2D.h Point2D.cpp
	g++ -c Point2D.cpp

Shape.o: Shape.cpp Shape.h
	g++ -c -o Shape.o Shape.cpp

Circle.o: Circle.cpp Circle.h Shape.h Point2D.h
	g++ -c -o Circle.o Circle.cpp

clean:
	rm -r *.o *.gch bin