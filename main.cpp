#include <iostream>
#include <iomanip>

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
	x=argv[1][0]-'0';
	y=argv[1][2]-'0';
	matrix=new int*[x];
	for (int i = 0; i < x; i++)
		matrix[i]= new int [y];
	for(int i=0,k=2; i<x; i++)
		for(int j=0; j<y; j++,k++) {
			if(k<argc)
				matrix[i][j]=atoi(argv[k]);
			else
				matrix[i][j]=0;
		}
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
   while(1){
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
