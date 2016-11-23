javaC=javac
javaR=java
OPT=-deprecation
TARGET=Markov
INFILE=../alice30.txt
OUTFILE=../output/markov_java_out.txt

$(TARGET).class: Markov.java 
	$(javaC) Markov.java 
clean:
	rm -f *.class $(OUTFILE)
run: $(TARGET).class
	$(javaR) $(TARGET) < $(INFILE) > $(OUTFILE)
