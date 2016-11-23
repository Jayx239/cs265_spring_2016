#!/usr/bin/python

# You can output an entire html page just using a hash

hash = {"fname":"First Name", 
		"lname":"Last Name", 
		"random":"Random String"}

html = """<html><head><title>Dynamic String HTML</title></head>\n\
		  <form action='html_str.py'>First Name:\n\
		  <input type='text' name='fname' value='%(fname)s'><br>\
		  Last Name:\n<input type='text' name='lname' value='%(lname)s'>\n\
		  </form><p>That was created dynamically by a hash.\
		  An this word (<strong>%(random)s</strong>) was as well.\n\
		  You can put anything into the page that you like.</p>\
		  </body></html>""" % hash

print html

