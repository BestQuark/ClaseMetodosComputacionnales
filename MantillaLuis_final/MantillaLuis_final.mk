all: Canal.png filtro.pdf

Canal.png: MantillaLuis_canal_ionico.py
	python3 MantillaLuis_canal_ionico.py

filtro.pdf: MantillaLuis_Fourier.py
	python3 MantillaLuis_Fourier.py
