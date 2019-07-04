import numpy as np
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt

datos = np.genfromtxt("plotRunge2.dat")



x = datos[:,0]
y = datos[:,1]



plt.figure()
plt.title("RK 2th Order Method usando C++")
plt.plot(x,y,c = 'g', label = "Solucion")
plt.xlabel("x")
plt.ylabel("$f(x)$")
plt.legend()
plt.savefig("rungekutta2.pdf")
