#include<bits/stdc++.h>
using namespace std;

template<class T>
class matrix
{
	private:
		template <typename TE> friend matrix<TE> operator+(const matrix<TE>& a, const matrix<TE>& b);
		template <typename TE> friend ostream& operator<<(ostream &os, const matrix<TE>& x);
		vector<vector<T>> mat;
		int N,M;

	public:
		matrix<T>(int N,int M,T init=0)
		{
			this->N=N;
			this->M=M;
			mat.resize(N);
			for(int i=0;i<N;i++)
			{
				mat[i].resize(M);
				fill(mat[i].begin(),mat[i].end(),init);
			}
		}
		matrix<T>(const std::vector<std::vector<T>> &m)
		{
			int c=0;
			if(m.size()>0)
			{
				c=m[0].size();
				for (int i=1; i<m.size();i++)
					if(m[i].size()!=c)
						cout<<("Not a matrix");
			}
			mat=m;
			N=m.size();
			M=c;
		}

		T Det(const matrix<T>&x);


};


template <typename TE> 
ostream& operator<<(ostream &os, const matrix<TE>& d)
{
	//cout<<d.N<<d.M;
	for(int i=0;i<d.N;i++)
	{
		os<<"[";
		for(int j=0;j<d.M;j++)
			os<<d.mat[i][j]<<" ";
		os<<"]\n";
	}
	return os;
}
template <typename TE>
matrix<TE> operator+(const matrix<TE>& a, const matrix<TE>& b)
{
	if(a.N!=b.N||a.M!=b.M){
		cout<<"Cannot add the Matrices...they should be of same order\n";
		exit(0);
	}
	else{
		matrix<TE>res(a.N,a.M,0);
		for(int i=0;i<a.N;i++)
		{
			for(int j=0;j<a.M;j++)
			{
				res.mat[i][j]=a.mat[i][j]+b.mat[i][j];
			}
		}
		return res;
	}
}

template <class T>
T Det(const matrix<T>&x)
{
	return 5;
}
int main()
{
	matrix<int> a(3,3,1);
	cout<<"Matrix a"<<a<<endl;
	vector<vector<int>> v={{1,2,3},{4,5,6},{7,8,9}};
	matrix<int>b(v);
	cout<<"Matrix b"<<b<<endl;
	matrix<int>sum=a+b;
	cout<<"Sum of the matrices"<<sum<<endl;
	cout<<"Determinant value of matrix b"<<Det(b)<<endl;
}

