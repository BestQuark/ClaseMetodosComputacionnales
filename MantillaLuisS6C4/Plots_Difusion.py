import numpy as np
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from mpl_toolkits.mplot3d import Axes3D

datos = np.genfromtxt("temps.dat")
promeds = np.genfromtxt("temperaturaMean.dat")

posx = datos[:10000,0]
posy = datos[:10000,1]
temp = datos[:10000,2]
tempPer = datos[:10000,3]
tempAb =datos[:10000,4]
tempB =datos[:10000,5]

posx1 = datos[10000:20000,0]
posy1 = datos[10000:20000,1]
temp1 = datos[10000:20000,2]
temp1Per = datos[10000:20000,3]
temp1Ab =  datos[10000:20000,4]
temp1B =  datos[10000:20000,5]

posx2 = datos[20000:30000,0]
posy2 = datos[20000:30000,1]
temp2 = datos[20000:30000,2]
temp2Per = datos[20000:30000,3]
temp2Ab = datos[20000:30000,4]
temp2B = datos[20000:30000,5]
##########################################
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
######################################################

figtp = plt.figure()
axtp = figtp.add_subplot(111,projection='3d')


axtp.plot_trisurf(posx,posy,tempPer, cmap = 'plasma')
axtp.set_xlabel("x [m]")
axtp.set_ylabel("y [m]")
axtp.set_zlabel("Temperatura")
plt.savefig("temp0sPeriodica.png")



figt1p = plt.figure()
axt1p = figt1p.add_subplot(111,projection='3d')


axt1p.plot_trisurf(posx1,posy1,temp1Per,cmap = 'plasma')
axt1p.set_xlabel("x [m]")
axt1p.set_ylabel("y [m]")
axt1p.set_zlabel("Temperatura")
plt.savefig("temp100sPeriodica.png")


figt2p = plt.figure()
axt2p = figt2p.add_subplot(111,projection='3d')


axt2p.plot_trisurf(posx2,posy2,temp2Per, cmap = 'plasma')
axt2p.set_xlabel("x [m]")
axt2p.set_ylabel("y [m]")
axt2p.set_zlabel("Temperatura")
plt.savefig("temp2500sPeriodica.png")

#############################################################
##########################################
figta = plt.figure()
axta = figta.add_subplot(111,projection='3d')


axta.plot_trisurf(posx,posy,tempAb, cmap = 'plasma')
axta.set_xlabel("x [m]")
axta.set_ylabel("y [m]")
axta.set_zlabel("Temperatura")
plt.savefig("temp0sAbierto.png")



figt1a = plt.figure()
axt1a = figt1a.add_subplot(111,projection='3d')


axt1a.plot_trisurf(posx1,posy1,temp1Ab,cmap = 'plasma')
axt1a.set_xlabel("x [m]")
axt1a.set_ylabel("y [m]")
axt1a.set_zlabel("Temperatura")
plt.savefig("temp100sAbierto.png")


figt2a = plt.figure()
axt2a = figt2a.add_subplot(111,projection='3d')


axt2a.plot_trisurf(posx2,posy2,temp2Ab, cmap = 'plasma')
axt2a.set_xlabel("x [m]")
axt2a.set_ylabel("y [m]")
axt2a.set_zlabel("Temperatura")
plt.savefig("temp2500sAbierto.png")
######################################################
figtb = plt.figure()
axtb = figtb.add_subplot(111,projection='3d')


axtb.plot_trisurf(posx,posy,tempB, cmap = 'plasma')
axtb.set_xlabel("x [m]")
axtb.set_ylabel("y [m]")
axtb.set_zlabel("Temperatura")
plt.savefig("temp0sBono.png")



figt1b = plt.figure()
axt1b = figt1b.add_subplot(111,projection='3d')


axt1b.plot_trisurf(posx1,posy1,temp1B,cmap = 'plasma')
axt1b.set_xlabel("x [m]")
axt1b.set_ylabel("y [m]")
axt1b.set_zlabel("Temperatura")
plt.savefig("temp100sBono.png")


figt2b = plt.figure()
axt2b = figt2b.add_subplot(111,projection='3d')


axt2b.plot_trisurf(posx2,posy2,temp2B, cmap = 'plasma')
axt2b.set_xlabel("x [m]")
axt2b.set_ylabel("y [m]")
axt2b.set_zlabel("Temperatura")
plt.savefig("temp2500sBono.png")
#############################################

pro1 = promeds[:,0]
pro2 = promeds[:,1]
pro3 = promeds[:,2]


plt.figure()
plt.plot(pro1, c='r', label ='Fijas')
plt.plot(pro2, c='g', marker ='o', label ='Periodicas')
plt.plot(pro3, c='b', label ='Abiertas')
plt.title("Temperatura promedio")
plt.xlabel("tiempo*10 [s]")
plt.ylabel("Temperatura [C]")
plt.tight_layout()
plt.legend()
plt.savefig("TemperaturasPromedio.png")











