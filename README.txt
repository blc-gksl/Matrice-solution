The code take a matrice A and its result b to find the solution matrice x ==> A.x=b
The code file name is source with .cpp extension(source.cpp)

In order to use source.cpp file you need to have two matrices:
1-)the main matrice that named A with .txt extension (A.txt)
2-)the result matrice as b with .txt extension (b.txt)
and it will give the solution  matrice(x) as a .txt file (x.txt)

To be an example you will have an 'A' and a 'b' matrice in GÖKSEL BÝLÝCÝ file with zip extension (GÖKSEL BÝLÝCÝ.zip)
You can create your own matrices or change the value of given matrices to use the algorithm

If your A matrice is in 2x2 form, the program will also give condition of A both in 1-norm and in infintiy-norm by printing them on the screen.

--> PROCESS STEPS:
1 - Reading A.txt file and decide matrice's form (finding n's value)
2 - Form two matrices by dynamic allocation
3 - Reading both A.txt and b.txt and fill formed matrices 'A' and 'b'(matrisA[n][n],matrisb[n][1])
4 - If matrice have 2x2 form (means if n=2),find condition of A in both 1-norm and infinity-form
5 - Making needed row exchanges while also doing partial pivoting
6 - Checking if 'A' matrice (matrisA[n][n]) is singular or not by flagk variable
7 - Forming 'x' solution matrice (matrisx) and determine its elements
8 - Writing matrice 'x' into a txt file (x.txt)
9 - Deleting dynamically formed matrices 'A' and 'b'