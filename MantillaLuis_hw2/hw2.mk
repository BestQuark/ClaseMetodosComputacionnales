Resultados_hw2.pdf: Resultados_hw2.tex TransformadaAmbasCaras.png TransformadaHibrida.png CaraHibrida.png CaraPasaAltas.png CaraPasaBajas.png posiciones.png angularMomentum.png EnergiaCinetica.png EnergiaPotencial.png EnergiaTotal.png 
	pdflatex Resultados_hw2.tex

TransformadaAmbasCaras.png: Fourier.py
	python3 Fourier.py

TransformadaHibrida.png: Fourier.py
	python3 Fourier.py

CaraHibrida.png: Fourier.py
	python3 Fourier.py

CaraPasaAltas.png: Fourier.py
	python3 Fourier.py

CaraPasaBajas.png: Fourier.py
	python3 Fourier.py

posiciones.png: Plots_hw2.py metodoEuler1.dat metodoEuler3.dat metodoEuler3.dat metodoLeapFrog1.dat metodoLeapFrog2.dat metodoLeapFrog3.dat metodoRungeKutta1.dat metodoRungeKutta2.dat metodoRungeKutta3.dat
	python3 Plots_hw2.py

angularMomentum.png: Plots_hw2.py metodoEuler1.dat metodoEuler3.dat metodoEuler3.dat metodoLeapFrog1.dat metodoLeapFrog2.dat metodoLeapFrog3.dat metodoRungeKutta1.dat metodoRungeKutta2.dat metodoRungeKutta3.dat
	python3 Plots_hw2.py

EnergiaCinetica.png: Plots_hw2.py metodoEuler1.dat metodoEuler3.dat metodoEuler3.dat metodoLeapFrog1.dat metodoLeapFrog2.dat metodoLeapFrog3.dat metodoRungeKutta1.dat metodoRungeKutta2.dat metodoRungeKutta3.dat
	python3 Plots_hw2.py

EnergiaPotencial.png: Plots_hw2.py metodoEuler1.dat metodoEuler3.dat metodoEuler3.dat metodoLeapFrog1.dat metodoLeapFrog2.dat metodoLeapFrog3.dat metodoRungeKutta1.dat metodoRungeKutta2.dat metodoRungeKutta3.dat
	python3 Plots_hw2.py

EnergiaTotal.png: Plots_hw2.py metodoEuler1.dat metodoEuler3.dat metodoEuler3.dat metodoLeapFrog1.dat metodoLeapFrog2.dat metodoLeapFrog3.dat metodoRungeKutta1.dat metodoRungeKutta2.dat metodoRungeKutta3.dat
	python3 Plots_hw2.py

metodoEuler1.dat: ODEs.cpp
	g++ ODEs.cpp
	./a.out

metodoEuler2.dat: ODEs.cpp
	g++ ODEs.cpp
	./a.out

metodoEuler3.dat: ODEs.cpp
	g++ ODEs.cpp
	./a.out

metodoLeapFrog1.dat: ODEs.cpp
	g++ ODEs.cpp
	./a.out

metodoLeapFrog2.dat: ODEs.cpp
	g++ ODEs.cpp
	./a.out

metodoLeapFrog3.dat: ODEs.cpp
	g++ ODEs.cpp
	./a.out

metodoRungeKutta1.dat: ODEs.cpp
	g++ ODEs.cpp
	./a.out

metodoRungeKutta2.dat: ODEs.cpp
	g++ ODEs.cpp
	./a.out

metodoRungeKutta3.dat: ODEs.cpp
	g++ ODEs.cpp
	./a.out



