#!/usr/bin/env python

from matrix_print import display_matrix

m = [
		['a', 'b', 'c', 'd'],
		[3, 4, 5, 6],
		['we', 'like', 'to', 'party'],
		[1.23, 5.0, 6.09, 42.01]
	]

header = ['node', 'node', 'node', 'node']

display_matrix(m)

print

display_matrix(m, header)
