#Importamos los paquetes necesarios de python3
import numpy as np
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt


#Importamos los datos generados por el script de c++
euler1 = np.genfromtxt("metodoEuler1.dat")
rungeK1 = np.genfromtxt("metodoRungeKutta1.dat")
leapF1 = np.genfromtxt("metodoLeapFrog1.dat")

euler2 = np.genfromtxt("metodoEuler2.dat")
rungeK2 = np.genfromtxt("metodoRungeKutta2.dat")
leapF2 = np.genfromtxt("metodoLeapFrog2.dat")

euler3 = np.genfromtxt("metodoEuler3.dat")
rungeK3 = np.genfromtxt("metodoRungeKutta3.dat")
leapF3 = np.genfromtxt("metodoLeapFrog3.dat")


xE1 = euler1[:,0]
yE1 = euler1[:,1]
vxE1 = euler1[:,2]
vyE1 = euler1[:,3]
lE1 = euler1[:,4]
uE1 = euler1[:,5]
tE1 = euler1[:,6]

xRK1 = rungeK1[:,0]
yRK1 = rungeK1[:,1]
vxRK1 = rungeK1[:,2]
vyRK1 = rungeK1[:,3]
lRK1 = rungeK1[:,4]
uRK1 = rungeK1[:,5]
tRK1 = rungeK1[:,6]

xLF1 = leapF1[:,0]
yLF1 = leapF1[:,1]
vxLF1 = leapF1[:,2]
vyLF1 = leapF1[:,3]
lLF1 = leapF1[:,4]
uLF1 = leapF1[:,5]
tLF1 = leapF1[:,6]

xE2 = euler2[:,0]
yE2 = euler2[:,1]
vxE2 = euler2[:,2]
vyE2 = euler2[:,3]
lE2 = euler2[:,4]
uE2 = euler2[:,5]
tE2 = euler2[:,6]

xRK2 = rungeK2[:,0]
yRK2 = rungeK2[:,1]
vxRK2 = rungeK2[:,2]
vyRK2 = rungeK2[:,3]
lRK2 = rungeK2[:,4]
uRK2 = rungeK2[:,5]
tRK2 = rungeK2[:,6]

xLF2 = leapF2[:,0]
yLF2 = leapF2[:,1]
vxLF2 = leapF2[:,2]
vyLF2 = leapF2[:,3]
lLF2 = leapF2[:,4]
uLF2 = leapF2[:,5]
tLF2 = leapF2[:,6]

xE3 = euler3[:,0]
yE3 = euler3[:,1]
vxE3 = euler3[:,2]
vyE3 = euler3[:,3]
lE3 = euler3[:,4]
uE3 = euler3[:,5]
tE3 = euler3[:,6]

xRK3 = rungeK3[:,0]
yRK3 = rungeK3[:,1]
vxRK3 = rungeK3[:,2]
vyRK3 = rungeK3[:,3]
lRK3 = rungeK3[:,4]
uRK3 = rungeK3[:,5]
tRK3 = rungeK3[:,6]

xLF3 = leapF3[:,0]
yLF3 = leapF3[:,1]
vxLF3 = leapF3[:,2]
vyLF3 = leapF3[:,3]
lLF3 = leapF3[:,4]
uLF3 = leapF3[:,5]
tLF3 = leapF3[:,6]

figR, axR = plt.subplots(3,3)

figR.suptitle("x vs y [AU]")

axR[0,0].scatter(xE1,yE1,c='r', s=2)
axR[0,0].set_ylabel("Euler")
axR[0,0].set_title("dt1")
axR[0,1].scatter(xE2,yE2,c='r', s=2)
axR[0,1].set_title("dt2")
axR[0,2].scatter(xE3,yE3,c='r', s=2)
axR[0,2].set_title("dt3")
axR[1,0].scatter(xRK1,yRK1,c='g', s=2)
axR[1,0].set_ylabel("RK")
axR[1,1].scatter(xRK2,yRK2,c='g', s=2)
axR[1,2].scatter(xRK3,yRK3,c='g', s=2)
axR[2,0].scatter(xLF1,yLF1,c='b', s=2)
axR[2,0].set_ylabel("LF")
axR[2,1].scatter(xLF2,yLF2,c='b', s=2)
axR[2,2].scatter(xLF3,yLF3,c='b', s=2)

plt.savefig("posiciones.png")

figL, axL = plt.subplots(3,3)

figL.suptitle("Momento Angular")

axL[0,0].scatter(tE1,lE1,c='r', s=2)
axL[0,0].set_ylabel("Euler")
axL[0,0].set_title("dt1")
axL[0,1].scatter(tE2,lE2,c='r', s=2)
axL[0,1].set_title("dt2")
axL[0,2].scatter(tE3,lE3,c='r', s=2)
axL[0,2].set_title("dt3")
axL[1,0].scatter(tRK1,lRK1,c='g', s=2)
axL[1,0].set_ylabel("RK")
axL[1,1].scatter(tRK2,lRK2,c='g', s=2)
axL[1,2].scatter(tRK3,lRK3,c='g', s=2)
axL[2,0].scatter(tLF1,lLF1,c='b', s=2)
axL[2,0].set_ylabel("LF")
axL[2,1].scatter(tLF2,lLF2,c='b', s=2)
axL[2,2].scatter(tLF3,lLF3,c='b', s=2)

plt.savefig("angularMomentum.png")

figU, axU = plt.subplots(3,3)

figU.suptitle("Energia Potencial")

axU[0,0].scatter(tE1,uE1,c='r', s=2)
axU[0,0].set_ylabel("Euler")
axU[0,0].set_title("dt1")
axU[0,1].scatter(tE2,uE2,c='r', s=2)
axU[0,1].set_title("dt2")
axU[0,2].scatter(tE3,uE3,c='r', s=2)
axU[0,2].set_title("dt3")
axU[1,0].scatter(tRK1,uRK1,c='g', s=2)
axU[1,0].set_ylabel("RK")
axU[1,1].scatter(tRK2,uRK2,c='g', s=2)
axU[1,2].scatter(tRK3,uRK3,c='g', s=2)
axU[2,0].scatter(tLF1,uLF1,c='b', s=2)
axU[2,0].set_ylabel("LF")
axU[2,1].scatter(tLF2,uLF2,c='b', s=2)
axU[2,2].scatter(tLF3,uLF3,c='b', s=2)

plt.savefig("EnergiaPotencial.png")













