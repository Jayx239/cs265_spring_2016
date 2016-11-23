import random
import sys

class PrefixTable:
	def __init__(self, val, val2):
		self.table = val
		self.match = val2	
		
def build_markov(data):

	data = [i for i in data.split(' ') if  i != '']
	data = [i.lower() for i in data if i.isalpha()]

	val = {i:[] for i in data}

	l = 0

	while l < len(data) - 1:
			
		val[data[l]].append(data[l+1])
		l += 1

	val2 = {k:v for k,v in zip(range(len(val)), list(val))}	

	prefixTable = PrefixTable(val, val2)

	print generate(prefixTable)

def generate(prefixTable):

	sentence_length = random.randint(15,20)

	seed = random.randint(0, len(prefixTable.match) - 1)

	data = [prefixTable.match[0]]
	word = prefixTable.match[0]

	while len(data) < sentence_length:
		index = random.randint(0,len(prefixTable.table[word]) - 1)
		nextWord = prefixTable.table[word][index]
		data.append(nextWord)
		word = nextWord

	return ' '.join([i for i in data])

with open('alice30.txt') as f:
	data = f.read()	

build_markov(data)

