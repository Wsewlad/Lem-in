# Lem-in
The goal of this project is to find the quickest way to get n ants across the farm.

1. This project runs on the command line (UNIX).
2. You must compile this project (run `make`)

![make](./1.png)

3. Run it as follows (run `./lem-in < [map name]`)
	1.	For example (map `test_map1`)

	![make](./2.png)

	Where:
	*	10 - is number of ants;
	*	##start - is command and set roomt that follows as start;
	*	##end - set roomt that follows as end;
	*	#comment - is a comment thet may be any text;
	*	1, 2, 3, 4, 5, 6, 7 and 0 - are names of rooms whith coordinates:
		*	1 - start room
		*	0 - end room
	*	4-2 ... are links between rooms ('corridors')
	2.	And result is:

	![make](./3.png)

	
