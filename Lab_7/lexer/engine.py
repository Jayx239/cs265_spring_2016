#!/usr/bin/env python

from lexer import *

while get_expression():
	t = get_next_token()
	while t:
		print 'Got token: ' + t
		t = get_next_token()

