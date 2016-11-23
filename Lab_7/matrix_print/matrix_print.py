def display_matrix(matrix, header = None):
	h = len(matrix)
	output = "Pretty-printed %(h)d x %(h)d matrix:\n      " % {'h':h}
	for i in range(h):
		if header:
			output += "%(d)5s " % {'d':str(header[i])}
		else:
			output += "%(d)5s " % {'d':str(i)}
	for i in range(h):
		if header:
			output += "\n%(i)5s|" % {'i':str(header[i])}
		else:
			output += "\n%(i)5s|" % {'i':str(i)}
		for j in range(h):
			output += "%(x)5s|" % {'x':str(matrix[i][j])}
	print output
		
	
