all : euler.pdf leapfrog.pdf rungekutta2.pdf rungekutta4.pdf

euler.pdf: plotEuler.py plotEuler.dat
	python3 plotEuler.py 

leapfrog.pdf: plotLeap.py plotLeapFrog.dat
	python3 plotLeap.py

rungekutta2.pdf: plotRunge2.py plotRunge2.dat
	python3 plotRunge2.py

rungekutta4.pdf: plotRunge4.py plotRunge4.dat
	python3 plotRunge4.py  

plotEuler.dat: eulermethod.cpp
	g++ eulermethod.cpp
	./a.out

plotLeapFrog.dat: leapfrog.cpp
	g++ leapfrog.cpp
	./a.out

plotRunge4.dat: rungekutta4.cpp
	g++ rungekutta4.cpp
	./a.out

plotRunge2.dat: rungekutta2.cpp
	g++ rungekutta2.cpp
	./a.out

