print "Initializing...\n"
import math
try:
	comDoc = open("glove_comparisons.txt","r")
	comDoc.close();
	prevSave = True
except IOError:
	print "No save file detected."
	prevSave = False
saveChoice = 0
if prevSave == True:
	print "Previous save file detected."
	while saveChoice != 2 and saveChoice != -2:
		answer = raw_input("Would you like to load your previous save file?\n")
		saveChoice = 0
		if answer.lower() == "yes":
			saveChoice+=1
		elif answer.lower() == "no":
			saveChoice-=1
		else:
			continue
		answer = raw_input("CONFIRM\n")
		if answer.lower() == "yes":
			saveChoice*=2
		else:
			continue
if saveChoice == 2:
	print "\nResuming..."
	comDoc = open("glove_comparisons.txt","r")
	saveCalcs = comDoc.readlines()
	comDoc.close()
	if len(saveCalcs)==0:
		comDoc = open("glove_comparisons.txt","a")
		comDoc.write("")
		comDoc.close().
		comDoc = open("glove_comparisons.txt","r")
		saveCalcs = comDoc.readlines()
		comDoc.close
print ""
pads = ["THUMBTIP","THUMBFAT","PALM"]
fingers = ["INDEX","MIDDLE","RING","PINKY"]
points = [None] * 20
for i in xrange(20):
	points[i] = str(fingers[int(math.floor(i / 5))] + str(i%5))
connections = [None] * 60
for i in xrange(60):
	connections[i] = pads[int(math.floor(i/20))] + "_to_" + points[i%20]
comDoc = open("glove_comparisons.txt", "w")
comDoc.close()
l=[]
for i in xrange(len(connections)):
	l.append((connections[i],))
for i in xrange(len(l)-1):
	for j in xrange(1,len(l)-i):
		decision = ""
		while decision != "a" and decision != "b" and decision != "neither":
			print "---"+str(((j)*(i+1)))+"---\n"
			decision = raw_input("a: %s\nvs.\nb: %s\nchoice: " % (l[i][0],l[i+j][0]))
			if decision == "a":
				comDoc = open("glove_comparisons.txt", "a")
				l[i]=l[i]+(None,)
				comDoc.write(str(l[i][0]) + " > " + str(l[j+i][0]) + "\n")
				comDoc.close()
			elif decision == "b":
				comDoc = open("glove_comparisons.txt", "a")
				l[i+j]=l[i+j]+(None,)
				comDoc.write(str(l[i][0]) + " < " + str(l[j+i][0]) + "\n")
				comDoc.close()
			elif decision == "neither":
				comDoc = open("glove_comparisons.txt", "a")
				l[i]=l[i]+("unusable",)
				l[i+j]=l[i+j]+("unusable",)
				comDoc.write(str(l[i][0]) + " nor " + str(l[j+i][0]) + "\n")
				comDoc.close()
			else:
				print "\nPlease try again...\n"
		print ""
for i in xrange(len(l)):
	connections[len(l[i])-1] = l[i][0]
comDoc = open("glove_comparisons.txt", "a")