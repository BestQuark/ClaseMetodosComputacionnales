import numpy as np
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt

datos = np.genfromtxt("posiciones.dat")



x = datos[:200,0]
y0 = datos[:200,1]
y1 = datos[600:800,2]
y2 = datos[1200:1400,2]
y3 = datos[1800:2000,2]
y4 = datos[2200:2400,2]

z1 = datos[600:800,3]
z2 = datos[1200:1400,3]
z3 = datos[1800:2000,3]
z4 = datos[2200:2400,3]






plt.figure()
plt.title("Solucion ecuacion usando C++")
plt.plot(x,y0,c = 'g', label = "posicion inicial")
plt.plot(x,y1,c = 'r', label = "posicion 1")
plt.plot(x,y2,c = 'b', label = "posicion 2")
plt.plot(x,y3,c = 'black', label = "posicion 3")
plt.plot(x,y4,c = 'c', label = "posicion final")


plt.xlabel("posicion [m]")
plt.ylabel("posicion [m]")
plt.legend()
plt.savefig("Caso1.pdf")






plt.figure()
plt.title("Solucion ecuacion usando C++")
plt.plot(x,y0,c = 'g', label = "posicion inicial")
plt.plot(x,z1,c = 'r', label = "posicion 1")
plt.plot(x,z2,c = 'b', label = "posicion 2")
plt.plot(x,z3,c = 'black', label = "posicion 3")
plt.plot(x,z4,c = 'c', label = "posicion final")


plt.xlabel("posicion [m]")
plt.ylabel("posicion [m]")
plt.legend()
plt.savefig("Caso2.pdf")


