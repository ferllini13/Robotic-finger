from Tkinter import *
import ttk
import os

confFile="code.conf"   #configuration file

window = Tk()
window.title("Robotic Finger")
window.geometry("500x430")

#if press touch
def touch():
	write("touch") #call the write out fuction

#if press press
def press(): 
	value = Secbox.get()#get the seconds to press
	if str(value)!="":
		write("press "+ str(value))
	else:
		print("not input detected:seconds")#call the write out fuction



#if press move to
def moveTo():
	value = keybox.get()# get the key to move to
	if str(value)=="":
		print("not input detected:position")
		return
	x=0
	y=0
	# ifs to convert key to x,y 
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
	
	write("moveT " + str(x)+" " +str(y))#call the write out fuction 
		

# write the configuration file
def write(writeData):
	resolution=cBox.get()# gests the resolution
	if str(resolution)!="":
		file = open(confFile,'w')# open file
		file.write("resolution "+ str(resolution)+"\n")# write the resolucion
		file.write(writeData)#write the data form buttons
		file.close()# close the file 
		os.system("croboticFinger -c " + confFile)# call the interpreter
	else:
		print("not input detected:resolution")
		

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
