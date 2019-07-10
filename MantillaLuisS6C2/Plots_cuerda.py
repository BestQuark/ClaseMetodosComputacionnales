import numpy as np
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
import matplotlib.animation as animation


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

l0 = datos[:200,4]
lp = datos[200:400,4]
l1 = datos[600:800,4]
l2 = datos[1200:1400,4]
l3 = datos[1800:2000,4]
l4 = datos[2200:2400,4]






plt.figure()

plt.title("Solucion ecuacion usando C++")

plt.plot(x,y0,c = 'g', label = "posicion inicial")

for i in range(23):
	plt.plot(x, datos[200*i:200*(i+1),2], c= 'c')


plt.xlabel("posicion [m]")
plt.ylabel("posicion [m]")
plt.legend()
plt.savefig("Caso1.pdf")










def update_line(num, data, line, caso):
    line.set_data(x,data[200*num:200*(num+1),caso+1])
    return line,

fig1 = plt.figure()


l, = plt.plot([], [], c= 'g')

plt.ylim(-0.011,0.011)

plt.title('Caso 1')
line_ani = animation.FuncAnimation(fig1, update_line, 119, fargs=(datos, l,1),interval=300, blit=True)
line_ani.save('Caso1.gif')














plt.figure()
plt.title("Solucion ecuacion usando C++")
plt.plot(x,y0,c = 'g', label = "posicion inicial")

for i in range(23):
	plt.plot(x, datos[200*i:200*(i+1),3], c= 'c')



plt.xlabel("posicion [m]")
plt.ylabel("posicion [m]")
plt.legend()
plt.savefig("Caso2.pdf")



fig2 = plt.figure()


l, = plt.plot([], [], c= 'r')

plt.ylim(-0.011,0.011)

plt.title('Caso 2')
line_ani = animation.FuncAnimation(fig2, update_line, 119, fargs=(datos, l,2),interval=100, blit=True)
line_ani.save('Caso2.gif')




plt.figure()
plt.title("Solucion ecuacion usando C++")
plt.plot(x,l0,c = 'g', label = "posicion inicial")
plt.plot(x,lp,c = 'r', label = "posicion 1")
plt.plot(x,l2,c = 'b', label = "posicion 2")
plt.plot(x,l3,c = 'black', label = "posicion 3")
plt.plot(x,l4,c = 'c', label = "posicion final")


plt.xlabel("posicion [m]")
plt.ylabel("posicion [m]")
plt.legend()
plt.savefig("Caso3.pdf")



fig3 = plt.figure()


l, = plt.plot([], [], c= 'r')

plt.ylim(-0.6,0.6)

plt.title('Caso 3')
line_ani = animation.FuncAnimation(fig3, update_line, 119, fargs=(datos, l,3),interval=100, blit=True)
line_ani.save('Caso3.gif')



