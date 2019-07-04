import numpy as np
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt

datos = np.genfromtxt("plotLeapFrog.dat")



x = datos[:,0]
y = datos[:,1]



plt.figure()
plt.title("LeapFrog Method usando C++")
plt.plot(x,y,c = 'g', label = "Solucion")
plt.xlabel("x")
plt.ylabel("$f(x)$")
plt.legend()
plt.savefig("leapfrog.pdf")
