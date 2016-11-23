import sys

originalFile = open(sys.argv[1],'r')
outputFile = open(sys.argv[2],'r')
isValid = True
outputLine = outputFile.readline()
origFileLine = originalFile.readline()

while outputLine != '':
	if outputLine == '\n':
		origFileLine = originalFile.readline()
		outputLine = outputFile.readline()
		print('\n')
		print('orig: ' + origFileLine.replace('\n',''))
		continue
	else:
		columnValue = outputLine[outputLine.index(":") + 2 : len(outputLine)]
	        columnValue = columnValue.replace('\n','')
		print('Output Element: ' + columnValue)

	if columnValue not in origFileLine:
		isValid = False
		break	
	outputLine = outputFile.readline()

if isValid:
	print('Valid Csv Parse')
else:
 	print('Invalid Csv Parse')

originalFile.close()
outputFile.close()
