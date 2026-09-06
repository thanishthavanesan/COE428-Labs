
Comments: 
Everything in the code worked correctly as intended.


Question: Suppose that towers(5, 2, 3) is invoked. 

1. How will the first recursive call to towers() be invoked? Answer this question in the form: towers(x, y, z) where you give the actual values to the three parameters. 

	The first recursive call to towers() will be: towers(4,2,1).


2. How many recursive calls to towers() will be made before this first recursive call actually returns to the initial invocation?

	5 recursive calls to towers() will be made before the first recursive call returns to the initial invocation.


3. Once towers(5, 2, 3) has invoked its first recursive call to towers() and this invocation has returned, what will be printed to stdout? (i.e. What actual move will be made by towers(5, 2, 3) ?)

	2 3 will be printed out to stdout


4. How will the second recursive call to towers() be invoked? Answer this question in the form: towers(x, y, z) where you give the actual values to the three parameters. 

	The 2nd recursive call to towers() will be towers(4,1,3).


Question: Suppose that towers(8, 1, 2) is invoked. How many lines will be printed to stdout? 

	255 lines will be printed out since the number of moves=2^n-1, so s^8-1 will be 255. So 255 moves will need 255 lines.

