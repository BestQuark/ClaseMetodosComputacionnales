#Importamos los paquetes necesarios de python3
import numpy as np
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt

#Importamos los datos generados por el script de c++
datos = np.genfromtxt("posiciones.dat")

xE = datos[:,0]
yE = datos[:,1]

xR = datos[:,2]
yR = datos[:,3]

xL = datos[:,4]
yL = datos[:,5]


plt.figure()
plt.title("Posicion Orbita")
plt.xlabel("x [AU]")
plt.ylabel("y [AU]")
plt.scatter(xR,yR, s=7, label ="RungeKutta")
plt.scatter(xE,yE,c='r', s=2, label = "Euler")
plt.scatter(xL,yL, c='black', s=1, label = "LeapFrog")
plt.legend()
plt.savefig("posiciones.png")
