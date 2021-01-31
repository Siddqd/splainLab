#include "Matrix.h"

void showMat(vector <vector <double>> S) {
	for (int i = 0; i < S[0].size(); ++i)
	{
		for (int j = 0; j < S[0].size(); ++j)
			cout << setw(6) << S[i][j] << "  ";
		cout << '\n';
	}
}

vector<vector <double>> getMat(const char* fileName) {
	double bar;
	int n=0,m=0,k=0;
	

	vector <vector <double>> mat;
	vector <double> vecx, vecy, vect;
	ifstream fin(fileName);
	
	cout << "������� ���������� �� ����� source.txt :\n";
	cout << setw(6) << 'X' << " " << setw(6) << 'Y' << '\n';
	for (int i = 0;!fin.eof();i++) {
		fin >> bar;
		vecx.push_back(bar);
		fin >> bar;
		vecy.push_back(bar);
		cout << setw(6) << vecx[i] <<" " <<setw(6) <<vecy[i]<<'\n';
	}

	m = vecx.size();
	n = (m - 1) * 4; //����� ��������� � �������, � ������ ������� ������� n*n 
	
	for (int i = 0;i < n;++i)	//�������������� 0-������ �������� n
		vect.push_back(0);
	
	for (int i = 0;i < n;++i) //���������(� ��������) ������� 0-��� ��������
		mat.push_back(vect);
		
	for (int i = 0,j=0,fo;i < m;++i) { //��������� ������ ������ �������
		if (i == m - 1) --j;		
		fo = 4 * j;
		mat[i][fo+0] = 1; 
		mat[i][fo+1] = vecx[i]; 
		mat[i][fo+2] = vecx[i] * vecx[i]; 
		mat[i][fo+3] = mat[i][fo+2] * vecx[i];
		++j;
		++k;
	}
	
	for (int i = k,j=0,fo,foo; i < k-i + m-2; ++i) { //��������� ������� �� ������������� �������� 
		fo = 4 * j; foo = 4 * (j + 1);			  //����� ��������� S[i-1][xi]=S[i][xi] ..
		mat[i][fo + 0] = 1; 
		mat[i][foo + 0] = -1;
		mat[i][fo + 1] = vecx[j+1];
		mat[i][foo + 1] = -vecx[j+1];
		mat[i][fo + 2] = vecx[j+1] * vecx[j+1];
		mat[i][foo + 2] = -mat[i][fo + 2];
		mat[i][fo + 3] = mat[i][2] * vecx[j+1];
		mat[i][foo + 3] = -mat[i][fo + 3];
		++j;
		++k;
	}

	for (int i = k, j = 0, fo, foo; i < k-i + m - 2; ++i) 
	{											   //��������� ������� �� ������������� �������� 
		fo = 4 * j; foo = 4 * (j + 1);			  //����� ��������� ��� ����������� �������
		mat[i][fo + 1] = 1;						 //�������  S'[i-1][xi]=S'[i][xi] ..
		mat[i][foo + 1] = -1;
		mat[i][fo + 2] = 2*vecx[j+1];
		mat[i][foo + 2] = -2*vecx[j+1];
		mat[i][fo + 3] = 3*vecx[j+1] * vecx[j+1];
		mat[i][foo + 3] = -3*mat[i][fo + 3];
		
		++j;
		++k;
	}

	for (int i = k, j = 0, fo, foo; i < k-i + m - 2; ++i)
	{											   //��������� ������� �� ������������� �������� 
		fo = 4 * j; foo = 4 * (j + 1);			  //����� ��������� ��� ����������� �������
		mat[i][fo + 2] = 1;						 //�������  S''[i-1][xi]=S''[i][xi] ..
		mat[i][foo + 2] = -1;
		mat[i][fo + 3] = 3 * vecx[j+1];
		mat[i][foo + 3] = -3 * vecx[j+1];
		
		++j;
		++k;
	}

	for (int i = k, j = 0, fo, foo; i < k-i + m - 2; ++i)
	{											   //��������� ������� ��������� ������� 
		fo = 4 * j; foo = 4 * (j + 1);			  //�� ������� �������� ����� ����������� 
		mat[i][fo + 2] = 1;						 //������� �������  S''[0][x0]=0, S''[n-1][xn]=0 ..
		mat[i][foo + 2] = -1;					//���������
		mat[i][fo + 3] = 3 * vecx[j+1];
		mat[i][foo + 3] = -3 * vecx[j+1];

		++j;
		++k;
	}
		
	return mat;
}

/*int detMat(vector <vector <double>> S) {
	return;
}

vector <vector <double>> invMat(vector <vector <double>>) {
	return;
}

vector <vector <double>> mulMat(vector <vector <double>>) {
	return ;
}
*/