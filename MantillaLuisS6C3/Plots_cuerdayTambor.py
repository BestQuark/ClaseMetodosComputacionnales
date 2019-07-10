import numpy as np
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.cm as cm


datos = np.genfromtxt("posiciones.dat")

datosMembrana = np.genfromtxt("posicionesTambor.dat", delimiter=" ")

def update_line(num, data, line, caso):
    line.set_data(x,data[200*num:200*(num+1),caso+1])
    return line,


x = datos[:200,0]


posxMemb = datosMembrana[:2500,0]
posyMemb = datosMembrana[:2500,1]
poszMemb1 = datosMembrana[:2500,2]


figt = plt.figure()
axt = figt.add_subplot(111,projection='3d')
axt.set_xlim3d(0, 1)
axt.set_ylim3d(0,1)
axt.set_zlim3d(-0.01,0.01)


t = np.arange(2500)
axt.scatter(posxMemb,posyMemb,poszMemb1,c = t, cmap = 'viridis')
axt.set_xlabel("x [m]")
axt.set_ylabel("y [m]")
axt.set_zlabel("amplitud [m]")
plt.savefig("tamborInicial.png")

#------------------------------------------------

for i in range(20):
	poszMemb2 = datosMembrana[2500*i:2500*(i+1),3]
	figt = plt.figure()
	axt = figt.add_subplot(111,projection='3d')
	axt.set_xlim3d(0, 1)
	axt.set_ylim3d(0,1)
	axt.set_zlim3d(-0.01,0.01)


	t = np.arange(2500)
	axt.scatter(posxMemb,posyMemb,poszMemb2,c = t, cmap = 'viridis')
	axt.set_xlabel("x [m]")
	axt.set_ylabel("y [m]")
	axt.set_zlabel("amplitud [m]")
	plt.savefig("tambor"+ str(i)+".png")













plt.figure()
plt.title("Caso 1")

for i in range(30):
	plt.plot(x, datos[200*i:200*(i+1),2], c= 'black')


plt.xlabel("posicion [m]")
plt.ylabel("amplitud [m]")
plt.tight_layout()
plt.savefig("Caso1.pdf")


fig1 = plt.figure()
l, = plt.plot([], [], c= 'r')

plt.ylim(-0.011,0.011)

plt.title('Caso 1')
plt.xlabel("posicion [m]")
plt.ylabel("amplitud [m]")
line_ani = animation.FuncAnimation(fig1, update_line, 119, fargs=(datos, l,1),interval=100, blit=True)
line_ani.save('Caso1.gif')


#--------------------------------------------------------

plt.figure()
plt.title("Caso 2")

for i in range(30):
	plt.plot(x, datos[200*i:200*(i+1),3], c= 'black')



plt.xlabel("posicion [m]")
plt.ylabel("amplitud [m]")
plt.tight_layout()
plt.savefig("Caso2.pdf")



fig2 = plt.figure()
l, = plt.plot([], [], c= 'r')

plt.ylim(-0.011,0.011)

plt.title('Caso 2')
plt.xlabel("posicion [m]")
plt.ylabel("amplitud [m]")
line_ani = animation.FuncAnimation(fig2, update_line, 119, fargs=(datos, l,2),interval=100, blit=True)
line_ani.save('Caso2.gif')

#--------------------------------------------------------



plt.figure()
plt.title("Caso 3")

for i in range(30):
	plt.plot(x, datos[200*i:200*(i+1),4], c= 'black')



plt.xlabel("posicion [m]")
plt.ylabel("amplitud [m]")
plt.tight_layout()
plt.savefig("Caso3.pdf")




fig3 = plt.figure()
l, = plt.plot([], [], c= 'r')

plt.ylim(-0.4,0.4)

plt.title('Caso 3')
plt.xlabel("posicion [m]")
plt.ylabel("amplitud [m]")
line_ani = animation.FuncAnimation(fig3, update_line, 119, fargs=(datos, l,3),interval=100, blit=True)
line_ani.save('Caso3.gif')



