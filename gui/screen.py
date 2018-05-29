from Tkinter import *
import ttk
import os

confFile="../Interpreter/code.conf"   #configuration file

lastPos = 10

window = Tk()
window.title("Robotic Finger")
window.geometry("500x430")

#if press touch
def touch():
	write("moveS " + str(lastPos) +"\ntouch") #call the write out fuction
	global lastPos
	lastPos = 10
#if press press
def press(): 
	value = Secbox.get()#get the seconds to press
	if str(value)!="":
		write("moveS " + str(lastPos) +"\npress "+ str(value))
		global lastPos
		lastPos = 10
	else:
		print("Not input detected: seconds")#call the write out fuction



#if press move to
def moveTo():
	value = keybox.get()# get the key to move to
	if str(value)=="":
		print("Not input detected: position")
		return
	global lastPos
	lastPos = value
	write("move " + str(value))#call the write out fuction 
		

# write the configuration file
def write(writeData):
	resolution=cBox.get()# gests the resolution
	if str(resolution)!="":
		file = open(confFile,'w')# open file
		file.write("resolution "+ str(resolution)+"\n")# write the resolucion
		file.write(writeData)#write the data form buttons
		file.close()# close the file 
		os.chdir("../Interpreter/")# move to the interpreter file position
		os.system("./roboticFinger -c " + confFile)# call the interpreter
	else:
		print("Not input detected: resolution")

		

#to set the resolution with combobox
Label(window,text="Set Screen Resolution",fg="black",font="none 12 bold").place(x=80,y=0)
cBox=ttk.Combobox(window, state="readonly",values=("1", "2", "4"))
cBox.place(x=300,y=0)


#entry for numbre to move to 
keybox=Entry(window,width=4, bg="white")
keybox.place(x=70,y=230)
Label(window,text="KEY",fg="black",font="none 12 bold").place(x=100,y=230)

#entry for seconds to press
Secbox=Entry(window,width=4, bg="white")
Secbox.place(x=350,y=120)
Label(window,text="SECONDS",fg="black",font="none 12 bold").place(x=380,y=120)

# deifne the buttons
Button(window, text ="TOUCH",command = touch, height = 10, width = 20).place(x=10,y=50)
Button(window, text ="PRESS",command = press, height = 10, width = 20).place(x=300,y=150)
Button(window, text ="MOVE TO",command = moveTo, height = 10, width = 20).place(x=10,y=260)
     
window.mainloop()
