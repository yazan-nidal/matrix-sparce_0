#include<iostream>
using namespace std;

struct node{int row; int col; int val; node *nextR; node *nextC;};//node type data for matrix

struct matrix{ node *hedaer;};//matrix sparce

void cleaR(matrix &MTX){MTX.hedaer=NULL;}//clear matrix

bool emptY(matrix &MTX){if(MTX.hedaer==NULL){return true;}else{return false;}}//test if empty Matrix

void instaLMTX(matrix &MTX,int &roW,int &coL){//build hedar && index matrix
cleaR(MTX);
while((roW<=0)&&(coL<=0)){
cout<<"	Enter number Row Matrix --> "; cin>>roW;
cout<<"	Enter number Colom Matrix --> "; cin>>coL;
cout<<"\n\n";
if((roW<=0)&&(coL<=0)){cout<<"	Error :	\n	Matrix dimensions invalid  !!! \n\n";}
}
node *m=NULL; node *R=NULL; node *C;
m=new node;
m->col=m->row=m->val=0; 
m->nextC=m->nextR=m;
R=m;
for (int i=1; i<=coL; i++)
{// create the hedar row for the columns
	C=new node; C->col=i; C->val=C->row=0;
	C->nextR=C;
	C->nextC=m;
	R->nextC=C;
	R=C;
}
R=m;
for (int i=1; i<=roW; i++)
  { // create the hedar column for the rows
	C=new node; C->row=i; C->val=C->col=0;
	C->nextC=C;
	C->nextR=m;
	R->nextR=C;
	R=C;
}
MTX.hedaer=m;
}//end build

void insertVM(matrix &MTX,int val,int row,int colom){//insert in matrix
	node *m=new node;
	m->val=val;
	m->row=row;
	m->col=colom;
	node *R=MTX.hedaer;
	node *C=MTX.hedaer;
	node *TMC=NULL;
	node *TMR=NULL;
for(int i=0;i<row;i++){R=R->nextR;}//find row
TMR=R;
while(R->nextC!=TMR){R=R->nextC;}//find colom want in row
	//link
	m->nextC=TMR;
	R->nextC=m;
	//finish link
for(int i=0;i<colom;i++){C=C->nextC;}	
TMC=C;
while(C->nextR!=TMC){C=C->nextR;}//find colom want in row
	//link
	m->nextR=TMC;
	C->nextR=m;
	//finish link
	}// end insert in matrix
void readMAtrix(matrix &MTX,int &row,int &colom){//read matrix
	if(emptY(MTX)==1){instaLMTX(MTX,row,colom);}//instal matrix : you can instal in main or in function read as you like
	int val=0;
	cout<<"	Read Matrix : \n";
for(int i=1;i<=row;i++){// for1
	cout<<"	Row "<<i<<" : \n";
for(int j=1;j<=colom;j++){//for 2
	cout<<"	Enter Value colom "<<j<<" : ";
	cin>>val;
	if(val!=0){insertVM(MTX,val,i,j);}
	}//end for 2
	}//end for 1
	}//end read matrix
void printMV(matrix &MTX,int row,int colom){// print matrix
	if(!emptY(MTX)){
	cout<<"	The Matrix : \n";
	node *R=MTX.hedaer->nextR;
for(int i=1;i<=row;i++){//for 1
	node *CH=R;
	cout<<"	";
	CH=CH->nextC;
for(int j=1;j<=colom;j++){//for 2
	if((j==(CH->col))){cout<<CH->val<<" "; CH=CH->nextC;}//if node insert in this location
	else{
		cout<<"0 ";}//else if not insert node in this location
	}//end for 2
	cout<<"\n";
	R=R->nextR;
	}// end for 1
	}else{cout<<"	ERROR EMPTY MATRIX !!! \n";}
}//end print matrix

int valMTR(matrix &MTX,int row,int colom){// find value in pointed node py row and colom
	node *R=MTX.hedaer;
	node *m=NULL;
	for(int i=0;i<row;i++){R=R->nextR;}//find row
	for(int i=0;i<colom;i++){m=R;
		R=R->nextC;
		if(R->col-1!=i){R=m;}}//find colom want in row
	if((R->col==colom)){return R->val;}
	else{return 0;}

}//end fun find

matrix multiplicatioN(matrix &MTX1,int row1,int colom1,matrix &MTX2,int row2,int colom2){//multiplicatioN 2 matrix
	matrix MTX3;
	cleaR(MTX3);
	instaLMTX(MTX3,row1,colom2);
	int val=0;
	for(int i=1;i<=row1;i++){//for 1
	for(int j=1;j<=colom2;j++){// for 2
	for(int l=1;l<=colom1;l++){//for 3
	val +=(valMTR(MTX1,i,l))*valMTR(MTX2,l,j);
	}//end for 3
	if(val==0){val=0;}
	else{insertVM(MTX3,val,i,j); val=0;}
	}// end for 2
	}// end for 1
	return MTX3;
	}// end multiplicatioN 2 matrix
void main(){//main

	matrix MTX1,MTX2,MTX3;
cleaR(MTX1); cleaR(MTX2); cleaR(MTX2);
int colom1=0,colom2=0,colom3=0,row1=0,row2=0,row3=0;
readMAtrix(MTX1,row1,colom1); 
cout<<'\n';
readMAtrix(MTX2,row2,colom2); 
system("cls");
cout<<"\n	Matrix 1 : \n";
printMV(MTX1,row1,colom1);
cout<<"\n	Matrix 2 : \n";
printMV(MTX2,row2,colom2);
cout<<'\n';
if(colom1==row2){//cheek if valid multiplicatioN
cout<<"	Matrix1 * Matrix2 : \n";
colom3=colom2;
row3=row1;
MTX3=multiplicatioN(MTX1,row1,colom1,MTX2,row2,colom2);
printMV(MTX3,row3,colom3);
}
else{

if(colom2==row1){//cheek if valid multiplicatioN
cout<<"	Matrix2 * Matrix1 : \n";
colom3=colom1;
row3=row2;
MTX3=multiplicatioN(MTX2,row2,colom2,MTX1,row1,colom1);
printMV(MTX3,row3,colom3);
}

else{cout<<"	Error : can't do MultiplicatioN \n\n"; }
}

cout<<"	END OF PrOGrAM \n";




}//main