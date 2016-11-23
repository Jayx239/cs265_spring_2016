import java.util.*;
import java.io.*;
import java.nio.file.*;
class Chain {
	static final int NPREF = 2; // size of prefix
	static final String NONWORD = "\n";
	Hashtable preftab = new Hashtable();
	// "word" that can't appear
	Hashtable statetab = new Hashtable();
	// key = Prefix, value = suffix Vector
	Prefix prefix = new Prefix(NPREF, NONWORD);
	// initial prefix
	Random rand = new Random();
//	PrinterWriter fileprinter;
	// Chain build: build State table from input stream
	void build(InputStream in) throws IOException
	{
//		FileInputStream fs = new FileInputStream(new File("output.txt"));
//		Files.copy(in, new Path("output.txt"));
//		IOUtils.copy(in,out);
//		fs.close();
		StreamTokenizer st = new StreamTokenizer(in);

		st.resetSyntax(); // remove default rules
		st.wordChars(0, Character.MAX_VALUE); // turn on all chars
		st.whitespaceChars(0, ' '); // except up to blank
		while (st.nextToken() != st.TT_EOF){
			add(st.sval);
			if(preftab.containsKey(st.sval))
                                preftab.put(st.sval,((int)preftab.get(st.sval))+1);
                        else
                                preftab.put(st.sval,1);	
		}
		add(NONWORD);
	}
	// Chain add: add word to suffix list, update prefix
	void add(String word)
	{
		Vector suf = (Vector) statetab.get(prefix);
		if (suf == null) {
			suf = new Vector();
			statetab.put(new Prefix(prefix), suf);
		}
		suf.addElement(word);
		prefix.pref.removeElementAt(0);
		prefix.pref.addElement(word);
	}
	// Chain generate: generate output words
	boolean generate(int nwords) throws IOException
	{
		boolean validated = true;
        	File inputFile = new File("output.txt");
                FileWriter fileprinter = new FileWriter(inputFile,true);
		prefix = new Prefix(NPREF, NONWORD);
		for (int i = 0; i < nwords; i++) {
			Vector s = (Vector) statetab.get(prefix);
			if (s == null) {
				System.err.println("Markov: internal error: no state");
				System.exit(1); 
			}
			int r = Math.abs(rand.nextInt()) % s.size();
			String suf = (String) s.elementAt(r);
			if (suf.equals(NONWORD))
				break;
			System.out.println(suf);
			prefix.pref.removeElementAt(0);
			prefix.pref.addElement(suf);

			if(!preftab.containsKey(suf))
				validated = false;
			else{
				int numsuf = (int)preftab.get(suf);
				System.out.println(numsuf);
					fileprinter.write(suf + ": " + numsuf +  "\n");
				
			}
		}			
		fileprinter.close();
		
		return validated;
	}
} 
