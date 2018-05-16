from Tkinter import *

window = Tk()
window.title("Robotic Finger")
window.geometry("500x430")

def touch():
    return

def press():
    return

def moveTo():
    return

Label(window,text="Set Screen Resolution",fg="black",font="none 12 bold").place(x=100,y=0)




keybox=Entry(window,width=4, bg="white").place(x=70,y=230)
Label(window,text="KEY",fg="black",font="none 12 bold").place(x=100,y=230)

Secbox=Entry(window,width=4, bg="white").place(x=350,y=120)
Label(window,text="SECONDS",fg="black",font="none 12 bold").place(x=380,y=120)


Button(window, text ="TOUCH",command = touch, height = 10, width = 20).place(x=10,y=50)
Button(window, text ="PRESS",command = press, height = 10, width = 20).place(x=300,y=150)
Button(window, text ="MOVE TO",command = moveTo, height = 10, width = 20).place(x=10,y=260)
     
window.mainloop()
