import numpy as np
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from mpl_toolkits.mplot3d import Axes3D

datos = np.genfromtxt("temps.dat")

posx = datos[:10000,0]
posy = datos[:10000,1]
temp = datos[:10000,2]

posx1 = datos[10000:20000,0]
posy1 = datos[10000:20000,1]
temp1 = datos[10000:20000,2]

posx2 = datos[20000:30000,0]
posy2 = datos[20000:30000,1]
temp2 = datos[20000:30000,2]

figt = plt.figure()
axt = figt.add_subplot(111,projection='3d')


axt.plot_trisurf(posx,posy,temp, cmap = 'plasma')
axt.set_xlabel("x [m]")
axt.set_ylabel("y [m]")
axt.set_zlabel("Temperatura")
plt.savefig("temp0s.png")



figt1 = plt.figure()
axt1 = figt1.add_subplot(111,projection='3d')


axt1.plot_trisurf(posx1,posy1,temp1,cmap = 'plasma')
axt1.set_xlabel("x [m]")
axt1.set_ylabel("y [m]")
axt1.set_zlabel("Temperatura")
plt.savefig("temp100s.png")


figt2 = plt.figure()
axt2 = figt2.add_subplot(111,projection='3d')


axt2.plot_trisurf(posx2,posy2,temp2, cmap = 'plasma')
axt2.set_xlabel("x [m]")
axt2.set_ylabel("y [m]")
axt2.set_zlabel("Temperatura")
plt.savefig("temp2500s.png")
