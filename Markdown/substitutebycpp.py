import sys
import re

md = sys.argv[1]

with open(md,'r') as mymd:
	txt = mymd.read()
	#print(txt)
	cpp = re.search("(((.*)\n)*)\%\%INCLUDE\((.*)\)(((.*)\n)*)",txt)
	
	#for i in range(50):
		#print(i,"..",cpp.group(i))
	#exit()
	cppfile = ""
	try:
		cppfile = cpp.group(4)
		cppfile = "../" + cppfile
		with open(cppfile,'r') as mycpp:
			cppcode = mycpp.read()
		print(cpp.group(1),end='')
		print(cppcode,end='')
		print(cpp.group(5),end='')
	except:
		print(txt)

	
	
