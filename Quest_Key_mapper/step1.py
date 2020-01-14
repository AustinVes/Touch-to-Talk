try:
	comDoc = open("glove_comparisons.txt","r")
	comDoc.close();
	prevSave = True
except IOError:
	print "No save file detected."
	prevSave = False
print prevSave