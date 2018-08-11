#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	int T,N,M,i,j,k,n,p,flag;
	string input,output;
	while (cin >> T) {
		for (i = 0; i < T; ++i) {
			cin >> N;
			vector<string> fore(N, " ");
			vector<string> address(N, " ");
			for (p = 0; p < N; ++p) {
				cin >> fore[p];
				cin >> address[p];
			}
			cin >> M;
			for (n = 0; n < M; ++n) {
				cin >> input;
				for (j = 0; j < fore.size(); ++j) {
					flag = 0;
					for (k = 0; k < input.size(); ++k) {
						if (input[k] != fore[j][k] && fore[j][k] != 'x') {
							flag = 1;
							break;
						}
					}
					if (flag == 0) { 
						output = address[j];
						break;
					}	
				}
				if (flag == 1) output = "unknown";
				cout << output << endl;
			}
		}
	}
	return 0;
}