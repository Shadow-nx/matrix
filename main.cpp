#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

void show_matrix(int **matrix,int x,int y) {
	if(matrix==nullptr) {
		cout<<"matrix is empty"<<endl;
		return;
	}
	for(int i=0; i<x; i++) {
		for(int j=0; j<y; j++)
			cout<<setw(4)<<matrix[i][j];
		cout<<endl;
	}
}
void create_matrix(int **&matrix,int &x,int &y,int argc,char *argv[]) {
	int z=0;
	bool arg=false;
	while(z<strlen(argv[1])) {
		if(argv[1][z]=='x' || argv[1][z]=='X') {
			arg=true;
		}
		if(arg==false && (argv[1][z]>='0' && argv[1][z]<='9')) {
			x=x*10+argv[1][z]-'0';
		} else if(arg==true && (argv[1][z]>='0' && argv[1][z]<='9')) {
			y=y*10+argv[1][z]-'0';
		}
		z++;
	}
	z=0;
	if(x!=0 && y!=0) {
		matrix=new int*[x];
		for (int i = 0; i < x; i++)
			matrix[i]= new int [y];
		for(int i=0; i<x; i++)
			for(int j=0; j<y; j++)
				matrix[i][j]=0;
		if(argc>3) {
			for(int i=0,k=2; i<x; i++)
				for(int j=0; j<y; j++,k++) {
					if(k<argc)
						matrix[i][j]=atoi(argv[k]);
				}
		} else if(argc==3) {
			for(int i=0; i<x && argv[2][z]!='\0'; i++) {
				for(int j=0; j<y && argv[2][z]!='\0'; j++) {
					while(argv[2][z]>='0' && argv[2][z]<='9') {
						matrix[i][j]=matrix[i][j]*10+argv[2][z]-'0';
						z++;
					}
					z++;
				}
			}
		}
	} else
		cout<<"incorrect size! matrix can't be created"<<endl;
}
void print_menu() {
	cout<<endl;
	cout<<"choise operation"<<endl;
	cout<<"1: show matrix"<<endl;
	cout<<"2: add up matrix"<<endl;
	cout<<"3: multiply matrix"<<endl;
	cout<<"4: transpose matrix"<<endl;
	cout<<"5: save the matrix to a file"<<endl;
	cout<<"6: load matrix from file"<<endl;
	cout<<"7: sort matrix"<<endl;
	cout<<"8: exit"<<endl;
	cout<<endl;
}
int main(int argc,char *argv[]) {
	int **matrix=nullptr;
	int x=0;
	int y=0;
	if(argc>=2)
		create_matrix(matrix,x,y,argc,argv);
	int choice_exit;
	while(1) {
		int choice;
		print_menu();
		cin>>choice;
		switch(choice) {
			case 1:
				show_matrix(matrix,x,y);
				break;
			case 8:
				return 0;
		}
	}
	return 0;
}
