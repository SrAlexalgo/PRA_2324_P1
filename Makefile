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

bin/testRectangle: testRectangle.cpp Rectangle.o Shape.o Point2D.o
	g++ -c testRectangle.cpp
	mkdir -p bin
	g++ -o bin/testRectangle testRectangle.o Rectangle.o Shape.o Point2D.o

bin/testSquare: testSquare.cpp Square.o Shape.o Point2D.o
	g++ -c testSquare.cpp
	mkdir -p bin
	g++ -o bin/testSquare testSquare.o Square.o Shape.o Point2D.o

bin/testDrawing: testDrawing.cpp Drawing.o Square.o Rectangle.o Circle.o Shape.o Point2D.o
	mkdir -p bin
	g++ -o bin/testDrawing testDrawing.cpp Drawing.o Square.o Rectangle.o Circle.o Shape.o Point2D.o

Point2D.o: Point2D.h Point2D.cpp
	g++ -c Point2D.cpp

Shape.o: Shape.cpp Shape.h
	g++ -c -o Shape.o Shape.cpp

Circle.o: Circle.cpp Circle.h Shape.h Point2D.h
	g++ -c -o Circle.o Circle.cpp

Rectangle.o: Rectangle.cpp Rectangle.h Shape.h Point2D.h
	g++ -c -o Rectangle.o Rectangle.cpp

Square.o: Square.cpp Square.h Shape.h Point2D.h
	g++ -c -o Square.o Square.cpp

Drawing.o: Drawing.cpp Drawing.h Shape.h List.h ListArray.h
	g++ -c -o Drawing.o Drawing.cpp

clean:
	rm -r *.o *.gch bin