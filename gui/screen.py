from Tkinter import *
import ttk
import os

window = Tk()
window.title("Robotic Finger")
window.geometry("500x430")

def touch():
	os.system("ls")

def press():
	resolution = cBox.get()
	value = Secbox.get()
	os.system("ls")


def moveTo():
	resolution=cBox.get()
	value = keybox.get()
	os.system("ls")


Label(window,text="Set Screen Resolution",fg="black",font="none 12 bold").place(x=80,y=0)
cBox=ttk.Combobox(window, state="readonly",values=(" 1:1 ", " 2:2 ", " 3:3 "))
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
