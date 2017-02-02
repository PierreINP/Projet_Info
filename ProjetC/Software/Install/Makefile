CC = g++					#Compilater used

all: binary_files

$(EXEC_NAME): binary_files

binary_fsm : object_files binary_files
	$(CC) -o Binaries/FSM_entity Object/syntaxConstraints.o Object/Lexeme.o Source/FSM_entity.cpp
	$(CC) -o Binaries/FSM_port Object/syntaxConstraints.o Object/Lexeme.o Source/FSM_port.cpp
	$(CC) -o Binaries/FSM_library Object/syntaxConstraints.o Object/Lexeme.o Source/FSM_library.cpp
	$(CC) -o Binaries/FSM_libUse Object/syntaxConstraints.o Object/Lexeme.o Source/FSM_libUse.cpp
	$(CC) -o Binaries/FSM_signal Object/syntaxConstraints.o Object/Lexeme.o Source/FSM_signal.cpp
	$(CC) -o Binaries/FSM_variable Object/syntaxConstraints.o Object/Lexeme.o Source/FSM_variable.cpp
	$(CC) -o Binaries/FSM_assignation Object/syntaxConstraints.o Object/Lexeme.o Source/FSM_assignation.cpp
	$(CC) -o Binaries/FSM_architecture Object/syntaxConstraints.o Object/Lexeme.o Source/FSM_architecture.cpp
	$(CC) -o Binaries/FSM_component Object/syntaxConstraints.o Object/Lexeme.o Source/FSM_component.cpp
	$(CC) -o Binaries/FSM_declaration Object/syntaxConstraints.o Object/Lexeme.o Source/FSM_declaration.cpp
	$(CC) -o Binaries/FSM_process Object/syntaxConstraints.o Object/Lexeme.o Source/FSM_process.cpp
	
binary_files: object_files
	$(CC) -o Binaries/Error Object/Lexeme.o Object/syntaxConstraints.o Object/Error.o Test/testError.cpp 
	$(CC) -o Binaries/Lexeur Object/Error.o Object/syntaxConstraints.o Object/Lexeme.o Object/Lexeur.o Source/main.cpp
	$(CC) -o Binaries/Lexeme Object/Error.o Object/syntaxConstraints.o Object/Lexeme.o Test/testLexeme.cpp
	$(CC) -o Binaries/Node -g Object/syntaxConstraints.o Object/Lexeme.o Object/Lexeur.o Object/Node.o Object/Node_root.o Object/Node_library.o Object/Node_libraryUse.o Object/Node_entity.o Object/Node_port.o Object/Node_portScalaire.o Object/Node_portComposite.o Object/Node_architecture.o Object/Node_declaration.o Object/Node_signal.o Object/Node_signalScalaire.o Object/Node_signalComposite.o Object/Node_variable.o Object/Node_variableScalaire.o Object/Node_variableComposite.o Object/Node_component.o Object/Node_type.o Object/Node_assignment.o Object/Node_process.o Object/Node_ifCondition.o Object/Node_caseCondition.o Test/testNode.cpp 

	

object_files: clean
	$(CC) -c -o Object/Error.o Source/Error.cpp
	$(CC) -c -o Object/syntaxConstraints.o Source/syntaxConstraints.cpp
	$(CC) -c -o Object/Lexeme.o Source/Lexeme.cpp
	$(CC) -c -o Object/Lexeur.o Source/Lexeur.cpp
	$(CC) -c -o Object/Node.o Source/Node.cpp
	$(CC) -c -o Object/Node_root.o Source/Node_root.cpp
	$(CC) -c -o Object/Node_library.o Source/Node_library.cpp
	$(CC) -c -o Object/Node_libraryUse.o Source/Node_libraryUse.cpp
	$(CC) -c -o Object/Node_entity.o Source/Node_entity.cpp
	$(CC) -c -o Object/Node_port.o Source/Node_port.cpp
	$(CC) -c -o Object/Node_portScalaire.o Source/Node_portScalaire.cpp
	$(CC) -c -o Object/Node_portComposite.o Source/Node_portComposite.cpp
	$(CC) -c -o Object/Node_architecture.o Source/Node_architecture.cpp
	$(CC) -c -o Object/Node_declaration.o Source/Node_declaration.cpp
	$(CC) -c -o Object/Node_signal.o Source/Node_signal.cpp
	$(CC) -c -o Object/Node_signalScalaire.o Source/Node_signalScalaire.cpp
	$(CC) -c -o Object/Node_signalComposite.o Source/Node_signalComposite.cpp
	$(CC) -c -o Object/Node_variable.o Source/Node_variable.cpp
	$(CC) -c -o Object/Node_variableScalaire.o Source/Node_variableScalaire.cpp
	$(CC) -c -o Object/Node_variableComposite.o Source/Node_variableComposite.cpp
	$(CC) -c -o Object/Node_component.o Source/Node_component.cpp
	$(CC) -c -o Object/Node_type.o Source/Node_type.cpp
	$(CC) -c -o Object/Node_assignment.o Source/Node_assignment.cpp
	$(CC) -c -o Object/Node_process.o Source/Node_process.cpp
	$(CC) -c -o Object/Node_ifCondition.o Source/Node_ifCondition.cpp
	$(CC) -c -o Object/Node_caseCondition.o Source/Node_caseCondition.cpp
	

clean:
	rm -f Object/*.o
	rm -f Binaries/*
