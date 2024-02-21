JC = javac
JVM = java

.SUFFIXES: .java .class

.java.class:
	$(JC) $*.java

CLASSES = \
    Client.java \
    MainView.java

MAIN = Client

default: run

run: $(CLASSES:.java=.class)
	@$(JVM) $(MAIN)
	@rm -f *.class  # Supprime les fichiers .class après l'exécution

clean:
	@rm -f *.class