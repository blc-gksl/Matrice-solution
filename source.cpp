#include<iostream>
#include<fstream>// using fstream library to read from and write on files
#include<string> //using string library to read lines and find n value of matrix in reading file
#include<cmath> //using cmath library to use abs function
#define Emaschine 0.0000001 //defining Emaschine to detect singularity
using namespace std;

int main(){
	// line 10 to 20 reading A.txt file and decide matrice's form (finding n's value)
	int n=0;
string line; 
  ifstream projectfileA("A.txt");    //Making projectfileA to read A.txt file
  if (projectfileA.is_open()){       //opening A.txt file
    while ( getline (projectfileA,line) )  //counting lines to find n
    {
      n++;
    }
    projectfileA.close();  //closing A.txt file
  }
  else { cout << "Unable to open file A (first try)";} //to warn what if program fail to read txt
//	line 22 to 28 form two matrices by dynamic allocation
	int i,j;
	double **matrisA=new double*[n];// forming A matrice(matrice A)
	for(i=0;i<n;i++)
	matrisA[i]=new double[n];	
	double **matrisb=new double*[n]; // forming b matrice(matrisb) instead of vector for next operations but a vector can be formed instead
	for(i=0;i<n;i++)
	matrisb[i]=new double[1];
/// line 30 to 44 reading both A.txt and b.txt and fill formed matrices 'A' and 'b'(matrisA[n][n],matrisb[n][1])
	ifstream projectfileb("b.txt");	// Making projectfileb to read b.txt file
	if(projectfileb.is_open()){
	ifstream projectfileA("A.txt");
	if(projectfileA.is_open()){
		
	for(i= 0; i < n; i++){	
    for(j = 0; j < n; j++){
    	projectfileA>>matrisA[i][j]; 	// line 37 and 38 get matrices' elements' value through reading files
	}   projectfileb>>matrisb[i][0];
	}   projectfileA.close();	
	}
	else { cout << "Unable to open file A (second try)"<<endl;}
	    projectfileb.close();
    }   
    else { cout << "Unable to open file b (first try)"<<endl;}
   
 // line 47 to 86 ýf matrice have 2x2 form (means if n=2),find condition of A in both 1-norm and infinity-form
if(n==2){
   	double g1,k1,g2,k2,condAfornorm1,condAfornormInfinity; // defining needed variables
   	double reverseA[2][2];
   	double oneoverdetA=1/(matrisA[1][1]*matrisA[0][0]-matrisA[1][0]*matrisA[0][1]);// calculating A's determinant and taking its reverse
   	reverseA[0][0]= oneoverdetA*matrisA[1][1];  //line 51 to 54 forming matrice reverse A (A^-1)
   	reverseA[0][1]= -oneoverdetA*matrisA[0][1];
   	reverseA[1][0]= -oneoverdetA*matrisA[1][0];
   	reverseA[1][1]= oneoverdetA*matrisA[0][0];
   	// line 56 to 68 finding |A| and |A^-1| (g1 and k1 respectively) in 1-norm
   	if((abs(matrisA[0][0])+abs(matrisA[1][0]))>(abs(matrisA[0][1])+abs(matrisA[1][1]))){
   		g1=abs(matrisA[0][0])+abs(matrisA[1][0]);
	   }
	else{
		g1=abs(matrisA[0][1]) + abs(matrisA[1][1]);
	}	
	if((abs(reverseA[0][0])+abs(reverseA[1][0]))>(abs(reverseA[0][1])+abs(reverseA[1][1]))){
   		k1=abs(reverseA[0][0])+abs(reverseA[1][0]);
	   }
	else{
		k1=abs(reverseA[0][1])+abs(reverseA[1][1]);
	}
		condAfornorm1=g1*k1;
	// line 70 to 82 finding |A| and |A^-1| (g2 and k2 respectively) in infinity-norm
	if((abs(matrisA[0][0])+abs(matrisA[0][1]))>(abs(matrisA[1][0])+abs(matrisA[1][1]))){
   		g2=abs(matrisA[0][0])+abs(matrisA[0][1]);
	   }
	else{
		g2=abs(matrisA[1][0])+abs(matrisA[1][1]);
	}	
	if((abs(reverseA[0][0])+abs(reverseA[0][1]))>(abs(reverseA[1][0])+abs(reverseA[1][1]))){
   		k2=abs(reverseA[0][0])+abs(reverseA[0][1]);
	   }
	else{
		k2=abs(reverseA[1][0])+abs(reverseA[1][1]);
	}
		condAfornormInfinity=g2*k2;
	// line 84 and 85 printing condition numbers in both 1-norm and infinity-norm
	cout<<"The condition number is "<<condAfornorm1<<" while using 1-norm"<<endl;
	cout<<"The condition number is "<<condAfornormInfinity<<" while using infinity-norm"<<endl;
   }
   // line 88 to 111 making needed row exchanges while also doing partial pivoting
int l,m,x,y;
   double temp,temp2,temp3; 
   for(i=0;i<n;i++){ 		
   	   for(l=0;l<n-1;l++){ // the for's in line 91 and 92 used to exchanges row properly
   	   for(j=i;j<n-1;j++){
   	   if(abs(matrisA[j+1][i])>abs(matrisA[j][i])){
   	   	    for(m=0;m<n;m++){
   	   	  	   temp=matrisA[j+1][m];
   	   	  	   matrisA[j+1][m]=matrisA[j][m];
   	   	  	   matrisA[j][m]=temp;	   
       }
	           temp2=matrisb[j+1][0]; // not taking in for with m variable(line 94)because matrice b is like a vector
   	   	  	   matrisb[j+1][0]=matrisb[j][0];
   	   	  	   matrisb[j][0]=temp2;
	   }}}
     // line 104 to 110 partial pivoting
   	    for(j=i+1;j<n;j++){
   			temp3=(matrisA[j][i])/(matrisA[i][i]);
   			for(m=i;m<n;m++){
   			matrisA[j][m]=matrisA[j][m]-temp3*matrisA[i][m];
   			}
   			matrisb[j][0]=matrisb[j][0]-temp3*matrisb[i][0];
		}	 	
	}   	
    //	line 113 to 120 checking if 'A' matrice (matrisA[n][n]) is singular or not by flagk variable
	int flagk=0;
	for(i=0;i<n;i++){
		if(abs(matrisA[n-1][i])>Emaschine) flagk=1;
	}
	if(flagk==0){
		cout<<"[Error]The 'A' matris is singular"<<endl; // line 118 and 119 if matrice is NOT unique(means singular) gives error and quit
				return 0;
		}
    // line 122 to 131 forming 'x' solution matrice (matrisx) and determine its elements
	double matrisx[n][1];
	matrisx[n-1][0]=matrisb[n-1][0] / matrisA[n-1][n-1];// to substitute in back order properly,first finding last variable of solution matrice 'x'
	double rateb=matrisx[n-1][0]; // to use cleaning upward of found variable of x
	for(i=n-2;i>=0;i--){       // line 125 to 131 to find other variable of solution matrice systematise the function
		for(j=i;j>=0;j--){
			matrisb[j][0]=matrisb[j][0]-rateb*matrisA[j][i+1];
		}
		    matrisx[i][0]=matrisb[i][0] / matrisA[i][i];
			rateb=matrisx[i][0];
		}
   // line 133 to 138 writing matrice 'x' into a txt file (x.txt)
   ofstream projectfilex("x.txt");
   if (projectfilex.is_open()){
    for(i = 0; i < n; i++){
	    projectfilex<<matrisx[i][0]<<endl; // *here again a vector can be used
	}
  }
   else { cout << "Unable to open file x"<<endl;}
   
   // line 142 to 150 deleting dynamically formed matrices 'A' and 'b'
   for(i=0;i<n;i++){     // line 142-144 first delete one of two dimensions then line 145 delete other dimension
   	delete[] matrisA[i];
   }
   delete[] matrisA;
   
   for(i=0;i<n;i++){
   	delete[] matrisb[i];
   }
   delete[] matrisb;
   
	return 0;
}
