# Flight_Simulator
This is the Flight Simulator project

We received as input a text file containing commands to pass to the flight gear simulator


First a Lexer read each line in the text file and converted it to a vector of strings.
each string represents a command to be made or an argument another command needs
after iterating all the lines and constructing the commands vector
we passed it to a Parser for execution.

The Parser iterated through the command vector 
each command was converted to the appropriate Command object we created for it.

the Parser asked the command object how many arguments it needs for execution
and gave them to the object through the execute function.

We Open a server and a client both of which connected to the flight gear simulator
providing us with the simulators current settings and a way to change them.
