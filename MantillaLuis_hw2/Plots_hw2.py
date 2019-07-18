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

#una escala para multiplicar las energias ya que en las unidades de Masa Solar y AU el valor del momento angular, la energia cinetica y la energia potencial son muy bajos.
escala = 100000


#para los 9 archivos tomamos los valores de posiciones, velocidades, momento angular, energia potencial, cinetica y el tiempo que ha transcurrido (No usamos las velocidades pero pueden llegar a ser utiles si queremos graficar la velocidad en cada punto)

xE1 = euler1[:,0]
yE1 = euler1[:,1]
vxE1 = euler1[:,2]
vyE1 = euler1[:,3]
lE1 = escala*euler1[:,4]
uE1 = escala*euler1[:,5]
kE1 = escala*euler1[:,6]
tE1 = euler1[:,7]

xRK1 = rungeK1[:,0]
yRK1 = rungeK1[:,1]
vxRK1 = rungeK1[:,2]
vyRK1 = rungeK1[:,3]
lRK1 = escala*rungeK1[:,4]
uRK1 = escala*rungeK1[:,5]
kRK1 = escala*rungeK1[:,6]
tRK1 = rungeK1[:,7]

xLF1 = leapF1[:,0]
yLF1 = leapF1[:,1]
vxLF1 = leapF1[:,2]
vyLF1 = leapF1[:,3]
lLF1 = escala*leapF1[:,4]
uLF1 = escala*leapF1[:,5]
kLF1 = escala*leapF1[:,6]
tLF1 = leapF1[:,7]

xE2 = euler2[:,0]
yE2 = euler2[:,1]
vxE2 = euler2[:,2]
vyE2 = euler2[:,3]
lE2 = escala*euler2[:,4]
uE2 = escala*euler2[:,5]
kE2 = escala*euler2[:,6]
tE2 = euler2[:,7]

xRK2 = rungeK2[:,0]
yRK2 = rungeK2[:,1]
vxRK2 = rungeK2[:,2]
vyRK2 = rungeK2[:,3]
lRK2 = escala*rungeK2[:,4]
uRK2 = escala*rungeK2[:,5]
kRK2 = escala*rungeK2[:,6]
tRK2 = rungeK2[:,7]

xLF2 = leapF2[:,0]
yLF2 = leapF2[:,1]
vxLF2 = leapF2[:,2]
vyLF2 = leapF2[:,3]
lLF2 = escala*leapF2[:,4]
uLF2 = escala*leapF2[:,5]
kLF2 = escala*leapF2[:,6]
tLF2 = leapF2[:,7]

xE3 = euler3[:,0]
yE3 = euler3[:,1]
vxE3 = euler3[:,2]
vyE3 = euler3[:,3]
lE3 = escala*euler3[:,4]
uE3 = escala*euler3[:,5]
kE3 = escala*euler3[:,6]
tE3 = euler3[:,7]

xRK3 = rungeK3[:,0]
yRK3 = rungeK3[:,1]
vxRK3 = rungeK3[:,2]
vyRK3 = rungeK3[:,3]
lRK3 = escala*rungeK3[:,4]
uRK3 = escala*rungeK3[:,5]
kRK3 = escala*rungeK3[:,6]
tRK3 = rungeK3[:,7]

xLF3 = leapF3[:,0]
yLF3 = leapF3[:,1]
vxLF3 = leapF3[:,2]
vyLF3 = leapF3[:,3]
lLF3 = escala*leapF3[:,4]
uLF3 = escala*leapF3[:,5]
kLF3 = escala*leapF3[:,6]
tLF3 = leapF3[:,7]


#Hacemos un subplot para graficar las posiciones obtenidas para los 3 distintos valores de dt y los 3 metodos distintos

#Aqui graficamos x en el eje horizontal y y en el eje vertical para los 9 casos TODOS LOS VALORES ESTAN EN UNIDADES ASTRONOMICAS (X Y Y) (no lo pongo en la grafica para no sobrecargar los subplots)
figR, axR = plt.subplots(3,3, figsize=(10,10))

axR[0,0].plot(xE1,yE1,c='r')
axR[0,0].set_ylabel("Euler Posicion Y [AU]")
axR[0,0].set_title("dt1")
axR[0,1].plot(xE2,yE2,c='r')
axR[0,1].set_title("dt2")
axR[0,2].plot(xE3,yE3,c='r')
axR[0,2].set_title("dt3")
axR[1,0].plot(xRK1,yRK1,c='g')
axR[1,0].set_ylabel("RungeKutta Posicion Y [AU]")
axR[1,1].plot(xRK2,yRK2,c='g')
axR[1,2].plot(xRK3,yRK3,c='g')
axR[2,0].plot(xLF1,yLF1,c='b')
axR[2,0].set_ylabel("LeapFrog Posicion Y [AU]")
axR[2,0].set_xlabel("Posicion X [AU]")
axR[2,1].plot(xLF2,yLF2,c='b')
axR[2,1].set_xlabel("Posicion X [AU]")
axR[2,2].plot(xLF3,yLF3,c='b')
axR[2,2].set_xlabel("Posicion X [AU]")
plt.tight_layout()
plt.savefig("posiciones.png")

figL, axL = plt.subplots(3,3,figsize=(10,10))

#Hacemos un subplot para graficar los momentos angulares obtenidos para los 3 distintos valores de dt y los 3 metodos distintos
#Grafico los momentos angulares (eje vertical) y multiplicados por 100000 para no tener valores tan chicos pues las unidades que estamos trabajando son de AU*MASASOLAR*AU/YR
axL[0,0].plot(tE1,lE1,c='r')
axL[0,0].set_ylabel("Euler [MS*AU*AU/YR]*100000")
axL[0,0].set_title("dt1")
axL[0,1].plot(tE2,lE2,c='r')
axL[0,1].set_title("dt2")
axL[0,2].plot(tE3,lE3,c='r')
axL[0,2].set_title("dt3")
axL[1,0].plot(tRK1,lRK1,c='g')
axL[1,0].set_ylim(ymin=1.88, ymax=1.89)
axL[1,0].set_ylabel("RK [MS*AU*AU/YR]*100000")
axL[1,1].plot(tRK2,lRK2,c='g')
axL[1,1].set_ylim(ymin=1.88, ymax=1.89)
axL[1,2].plot(tRK3,lRK3,c='g')
axL[1,2].set_ylim(ymin=1.88, ymax=1.89)
axL[2,0].plot(tLF1,lLF1,c='b')
axL[2,0].set_ylabel("LF [MS*AU*AU/YR]*100000")
axL[2,0].set_ylim(ymin=1.88, ymax=1.89)
axL[2,0].set_xlabel("tiempo [YR]")
axL[2,1].plot(tLF2,lLF2,c='b')
axL[2,1].set_ylim(ymin=1.88, ymax=1.893)
axL[2,1].set_xlabel("tiempo [YR]")
axL[2,2].plot(tLF3,lLF3,c='b')
axL[2,2].set_ylim(ymin=1.86, ymax=1.92)
axL[2,2].set_xlabel("tiempo [YR]")

plt.tight_layout()
plt.savefig("angularMomentum.png")

figU, axU = plt.subplots(3,3,figsize=(10,10))


#Hacemos un subplot para graficar las energias potenciales obtenidas para los 3 distintos valores de dt y los 3 metodos distintos
#Graficamos la energia potencial (eje vertical) multiplicadas por 100000 por el mismo motivo anterior (UNIDADES = MASASOLAR*AU*AU/YR**2)
axU[0,0].plot(tE1,uE1,c='r')
axU[0,0].set_title("dt1")
axU[0,0].set_ylabel("Euler [MS*AU*AU/YR**2]*100000")
axU[0,1].plot(tE2,uE2,c='r')
axU[0,1].set_title("dt2")
axU[0,2].plot(tE3,uE3,c='r')
axU[0,2].set_title("dt3")
axU[1,0].plot(tRK1,uRK1,c='g')
axU[1,0].set_ylabel("RK [MS*AU*AU/YR**2]*100000")
axU[1,1].plot(tRK2,uRK2,c='g')
axU[1,2].plot(tRK3,uRK3,c='g')
axU[2,0].plot(tLF1,uLF1,c='b')
axU[2,0].set_ylabel("LF [MS*AU*AU/YR**2]*100000")
axU[2,0].set_xlabel("tiempo [YR]")
axU[2,1].plot(tLF2,uLF2,c='b')
axU[2,1].set_xlabel("tiempo [YR]")
axU[2,2].plot(tLF3,uLF3,c='b')
axU[2,2].set_xlabel("tiempo [YR]")

plt.tight_layout()
plt.savefig("EnergiaPotencial.png")

#Hacemos un subplot para graficar las energias cineticas obtenidas para los 3 distintos valores de dt y los 3 metodos distintos
#Graficamos la energia cinetica (eje vertical) multiplicadas por 100000 por el mismo motivo anterior (UNIDADES = MASASOLAR*AU*AU/YR**2)
figK, axK = plt.subplots(3,3,figsize=(10,10))


axK[0,0].plot(tE1,kE1,c='r')
axK[0,0].set_title("dt1")
axK[0,0].set_ylabel("Euler [MS*AU*AU/YR**2]*100000")
axK[0,1].plot(tE2,kE2,c='r')
axK[0,1].set_title("dt2")
axK[0,2].plot(tE3,kE3,c='r')
axK[0,2].set_title("dt3")
axK[1,0].plot(tRK1,kRK1,c='g')
axK[1,0].set_ylabel("RK [MS*AU*AU/YR**2]*100000")
axK[1,1].plot(tRK2,kRK2,c='g')
axK[1,2].plot(tRK3,kRK3,c='g')
axK[2,0].plot(tLF1,kLF1,c='b')
axK[2,0].set_ylabel("LF [MS*AU*AU/YR**2]*100000")
axK[2,0].set_xlabel("tiempo [YR]")
axK[2,1].plot(tLF2,kLF2,c='b')
axK[2,1].set_xlabel("tiempo [YR]")
axK[2,2].plot(tLF3,kLF3,c='b')
axK[2,2].set_xlabel("tiempo [YR]")

plt.tight_layout()
plt.savefig("EnergiaCinetica.png")

#Hacemos un subplot para graficar las energias totales obtenidas para los 3 distintos valores de dt y los 3 metodos distintos
#Graficamos la energia total (eje vertical) multiplicadas por 100000 por el mismo motivo anterior (UNIDADES = MASASOLAR*AU*AU/YR**2)
figE, axE = plt.subplots(3,3,figsize=(10,10))


axE[0,0].plot(tE1,kE1+uE1,c='r')
axE[0,0].set_ylabel("Euler [MS*AU*AU/YR**2]*100000")
axE[0,0].set_title("dt1")
axE[0,1].plot(tE2,kE2+uE2,c='r')
axE[0,1].set_title("dt2")
axE[0,2].plot(tE3,kE3+uE3,c='r')
axE[0,2].set_title("dt3")
axE[1,0].plot(tRK1,kRK1+uRK1,c='g')
axE[1,0].set_ylim(ymin=-5.936, ymax=-5.938)
axE[1,0].set_ylabel("RK [MS*AU*AU/YR**2]*100000")
axE[1,1].plot(tRK2,kRK2+uRK2,c='g')
axE[1,1].set_ylim(ymin=-5.936, ymax=-5.938)
axE[1,2].plot(tRK3,kRK3+uRK3,c='g')
axE[1,2].set_ylim(ymin=-5.936, ymax=-5.938)
axE[2,0].plot(tLF1,kLF1+uLF1,c='b')
axE[2,0].set_ylim(ymin=-5.936, ymax=-5.938)
axE[2,0].set_ylabel("LF [MS*AU*AU/YR**2]*100000")
axE[2,0].set_xlabel("tiempo [YR]")
axE[2,1].plot(tLF2,kLF2+uLF2,c='b')
axE[2,1].set_ylim(ymin=-5.87, ymax=-5.99)
axE[2,1].set_xlabel("tiempo [YR]")
axE[2,2].plot(tLF3,kLF3+uLF3,c='b')
axE[2,2].set_ylim(ymin=-5.8, ymax=-5.99)
axE[2,2].set_xlabel("tiempo [YR]")

plt.tight_layout()
plt.savefig("EnergiaTotal.png")


















