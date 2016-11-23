import sys
class Csv():
	inputLine = ''
	fullInput = ''
	inputFile = None	
	outputFile = None
	delimeter = ","
	csvData = {0:{None}}

	def openFile(self, fileName):
		self.inputFile = open(fileName,'r')

	def openOutputFile(self, fileName):
		self.outputFile = open(fileName,'w')
	
	def closeInputFile(self):
		self.inputFile.close()

	def closeOutputFile(self):
		self.outputFile.close()
	
	def parseCsv(self):
		index = 0
		line = self.inputFile.readline()
		while line != '':
			self.csvData[index] = line.replace("\"","").split(self.delimeter,line.count(self.delimeter))
			index = index+1
			line = self.inputFile.readline()

	def writeParsedCsv(self):
		rowIndex = 0
		for row in self.csvData.keys():
			columnIndex = 0;
			for column in self.csvData[row]:
				self.outputFile.write('[row ' + str(rowIndex + 1) + ', column ' + str(columnIndex + 1) + "]: " + self.csvData[row][columnIndex] + "\n")
				columnIndex = columnIndex + 1
			rowIndex = rowIndex + 1


c = Csv()
c.openFile(sys.argv[1])
c.openOutputFile(sys.argv[2])
c.parseCsv()
c.writeParsedCsv()
c.closeOutputFile()
c.closeInputFile()

