from Tkinter import *
import ttk
import os

confFile="code.conf"

window = Tk()
window.title("Robotic Finger")
window.geometry("500x430")


def touch():
	write("touch")

def press(): 
	value = Secbox.get()
	write("press "+ str(value))




def moveTo():
	value = keybox.get()
	x=0
	y=0
	if int(value)==1:
		x=0
		y=0
	elif int(value)==2:
		x=0
		y=1
	elif int(value)==3:
		x=0
		y=2
	elif int(value)==4:
		x=1
		y=0
	elif int(value)==5:
		x=1
		y=1
	elif int(value)==6:
		x=1
		y=2
	elif int(value)==7:
		x=2
		y=0
	elif int(value)==8:
		x=2
		y=1
	elif int(value)==9:
		x=2
		y=2
	else:
		x=3
		y=1

	write("moveT " + str(x)+" " +str(y))


def write(writeData):
	resolution=cBox.get()
	file = open(confFile,'w')
	file.write("resolution "+ str(resolution)+"\n")
	file.write(writeData)
	file.close()
	os.system("croboticFinger -c " + confFile)


Label(window,text="Set Screen Resolution",fg="black",font="none 12 bold").place(x=80,y=0)
cBox=ttk.Combobox(window, state="readonly",values=("1", "2", "4"))
cBox.place(x=300,y=0)



keybox=Entry(window,width=4, bg="white")
keybox.place(x=70,y=230)
Label(window,text="KEY",fg="black",font="none 12 bold").place(x=100,y=230)

Secbox=Entry(window,width=4, bg="white")
Secbox.place(x=350,y=120)
Label(window,text="SECONDS",fg="black",font="none 12 bold").place(x=380,y=120)


Button(window, text ="TOUCH",command = touch, height = 10, width = 20).place(x=10,y=50)
Button(window, text ="PRESS",command = press, height = 10, width = 20).place(x=300,y=150)
Button(window, text ="MOVE TO",command = moveTo, height = 10, width = 20).place(x=10,y=260)
     
window.mainloop()
