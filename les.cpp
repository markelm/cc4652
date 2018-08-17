#include <iostream>
#define MAX 100

using namespace std;

class Les{
private:
	int n;
	int les[MAX];
public:
	Les():n(0){};
	bool insere(int valor){
		if(n==0){
			les[n] = valor;
			n++;
		}
		else{
			if(valor >= les[n-1]){
				les[n] = valor;
			}
			else{
				int i;
				for(i=0;i<n && les[i] <= valor;i++){}
					if(valor < les[i]){
						int j;
						for(j=n;j>i;j--){
							les[j] = les[j-1];
						}
						les[i] = valor;
					}
			}
		n = n + 1;
		}
		return true;
	}

	int busca(int valor){
		int i;
		for(i=0;i<n;i++){
			if(les[i] == valor){
				cout << "Indice do valor consultado: " << i << endl;
				return i;
			}
		}
		cout << "O valor consultado nao consta no vetor" << endl;
		return -1;
	}

	int buscaSemImpressao(int valor){
		int i;
		for(i=0;i<n;i++){
			if(les[i] == valor){
				return i;
			}
		}
		return -1;
	}

	bool remove(int valor){
		int v = this->buscaSemImpressao(valor);
		if(v!=-1){
			if(valor == les[n-1]){
				les[n-1] = 0;
				n -= 1;
			}
			else{
				int i;
				for(i=v;i<n-1;i++){
					les[i] = les[i+1];
				}
				n -= 1;
			}
		}return true;
	}

	void imprime(){
		for(int i=0;i<n;i++){
			cout << this->les[i] << " ";
		}
		cout <<  endl;
	}
};

int main(){
	Les a;
	a.insere(1);
	a.insere(10);
	a.insere(14);
	a.insere(7);
	a.insere(12);
	a.insere(20);

	a.imprime();

	a.remove(20);
	a.remove(10);

	a.imprime();

	a.remove(1);

	a.imprime();

	a.busca(1);
	a.busca(7);

	return 0;

}